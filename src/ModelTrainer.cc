#include "ModelTrainer.h"
#include <iostream>

ModelTrainer::ModelTrainer(bool useGPU) : useGPU(useGPU), useGBDT(false), useDNN(false), useRF(false) {
    factory = new TMVA::Factory("TMVAClassification", nullptr, "!V:!Silent:Color:DrawProgressBar:Transformations=I;D;P;G,D:AnalysisType=Classification");
    dataloader = new TMVA::DataLoader("dataset");
}

void ModelTrainer::InitializeTMVA() {
    if (useGBDT) {
        factory->BookMethod(dataloader, TMVA::Types::kBDT, "BDTG",
                            "!H:!V:NTrees=850:MinNodeSize=2.5%:MaxDepth=3:BoostType=Grad:Shrinkage=0.10:UseBaggedBoost:BaggedSampleFraction=0.5:nCuts=20:UseRandomisedTrees=True:UseNVars=10" + std::string(useGPU ? ":UseGPU=True" : ""));
    }
    if (useRF) {
        factory->BookMethod(dataloader, TMVA::Types::kRandomForest, "RF",
                            "!H:!V:NTrees=850:MinNodeSize=2.5%:MaxDepth=3:BoostType=Grad:Shrinkage=0.10:UseBaggedBoost:BaggedSampleFraction=0.5:nCuts=20:UseRandomisedTrees=True:UseNVars=10" + std::string(useGPU ? ":UseGPU=True" : ""));
    }
    if (useDNN) {
        factory->BookMethod(dataloader, TMVA::Types::kDNN, "DNN",
                            "!H:!V:VarTransform=N:ErrorStrategy=CROSSENTROPY:WeightInitialization=XAVIERUNIFORM:Layout=TANH|100,TANH|50,TANH|10,LINEAR:TrainingStrategy=LearningRate=1e-1,Momentum=0.9,Repetitions=1,ConvergenceSteps=20,BatchSize=256,TestRepetitions=10,WeightDecay=1e-4,Regularization=L2,DropConfig=0.0+0.5+0.5+0.5" + std::string(useGPU ? ":UseGPU=True" : ""));
    }
}

void ModelTrainer::TrainModels(const TMatrixD& features, const TVectorD& labels, const TMatrixD& curvatureMap) {
    StartTimer();

    // Apply curvature regularization
    regularizer = new CurvatureRegularizer(curvatureMap);
    TMatrixD regularizedFeatures = features;
    regularizer->ApplyRegularization(regularizedFeatures);

    // Load data into TMVA DataLoader
    for (int i = 0; i < regularizedFeatures.GetNcols(); ++i) {
        dataloader->AddVariable(Form("var%d", i), 'F');
    }
    dataloader->AddSignalTree(regularizedFeatures, 1.0);
    dataloader->AddBackgroundTree(labels, 1.0);

    // Train the models
    factory->TrainAllMethods();
    factory->TestAllMethods();
    factory->EvaluateAllMethods();

    StopTimer();
    PrintElapsedTime();
}

void ModelTrainer::TrainKFold(const TMatrixD& features, const TVectorD& labels, const TMatrixD& curvatureMap, int k) {
    int nEntries = features.GetNrows();
    int foldSize = nEntries / k;

    for (int i = 0; i < k; ++i) {
        TMatrixD trainFeatures(nEntries - foldSize, features.GetNcols());
        TVectorD trainLabels(nEntries - foldSize);
        TMatrixD testFeatures(foldSize, features.GetNcols());
        TVectorD testLabels(foldSize);

        int trainIndex = 0;
        int testIndex = 0;

        for (int j = 0; j < nEntries; ++j) {
            if (j >= i * foldSize && j < (i + 1) * foldSize) {
                for (int col = 0; col < features.GetNcols(); ++col) {
                    testFeatures[testIndex][col] = features[j][col];
                }
                testLabels[testIndex] = labels[j];
                testIndex++;
            } else {
                for (int col = 0; col < features.GetNcols(); ++col) {
                    trainFeatures[trainIndex][col] = features[j][col];
                }
                trainLabels[trainIndex] = labels[j];
                trainIndex++;
            }
        }

        // Apply curvature regularization
        regularizer = new CurvatureRegularizer(curvatureMap);
        TMatrixD regularizedTrainFeatures = trainFeatures;
        regularizer->ApplyRegularization(regularizedTrainFeatures);

        // Load data into TMVA DataLoader
        for (int col = 0; col < regularizedTrainFeatures.GetNcols(); ++col) {
            dataloader->AddVariable(Form("var%d", col), 'F');
        }
        dataloader->AddSignalTree(regularizedTrainFeatures, 1.0);
        dataloader->AddBackgroundTree(trainLabels, 1.0);

        // Train the models
        factory->TrainAllMethods();
        factory->TestAllMethods();
        factory->EvaluateAllMethods();
    }
}

void ModelTrainer::SaveModel(const TString& modelName) {
    factory->Save(modelName);
}

void ModelTrainer::SetModelFlags(bool useGBDT, bool useDNN, bool useRF) {
    this->useGBDT = useGBDT;
    this->useDNN = useDNN;
    this->useRF = useRF;
}

void ModelTrainer::StartTimer() {
    startTime = std::chrono::high_resolution_clock::now();
}

void ModelTrainer::StopTimer() {
    endTime = std::chrono::high_resolution_clock::now();
}

void ModelTrainer::PrintElapsedTime() {
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
    std::cout << "Elapsed time: " << duration << " ms" << std::endl;
}