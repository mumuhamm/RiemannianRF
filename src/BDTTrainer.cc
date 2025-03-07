#include "BDTTrainer.h"

BDTTrainer::BDTTrainer(bool useGPU) : useGPU(useGPU) {
    factory = new TMVA::Factory("TMVAClassification", nullptr, "!V:!Silent:Color:DrawProgressBar:Transformations=I;D;P;G,D:AnalysisType=Classification");
    dataloader = new TMVA::DataLoader("dataset");
}

void BDTTrainer::InitializeBDT() {
    // Initialize TMVA with GPU support if enabled
    if (useGPU) {
        factory->BookMethod(dataloader, TMVA::Types::kBDT, "BDTG",
                            "!H:!V:NTrees=850:MinNodeSize=2.5%:MaxDepth=3:BoostType=Grad:Shrinkage=0.10:UseBaggedBoost:BaggedSampleFraction=0.5:nCuts=20:UseRandomisedTrees=True:UseNVars=10:UseGPU=True");
    } else {
        factory->BookMethod(dataloader, TMVA::Types::kBDT, "BDTG",
                            "!H:!V:NTrees=850:MinNodeSize=2.5%:MaxDepth=3:BoostType=Grad:Shrinkage=0.10:UseBaggedBoost:BaggedSampleFraction=0.5:nCuts=20:UseRandomisedTrees=True:UseNVars=10");
    }
}

void BDTTrainer::InitializeRandomForest() {
    // Initialize TMVA with GPU support if enabled
    if (useGPU) {
        factory->BookMethod(dataloader, TMVA::Types::kRandomForest, "RF",
                            "!H:!V:NTrees=850:MinNodeSize=2.5%:MaxDepth=3:BoostType=Grad:Shrinkage=0.10:UseBaggedBoost:BaggedSampleFraction=0.5:nCuts=20:UseRandomisedTrees=True:UseNVars=10:UseGPU=True");
    } else {
        factory->BookMethod(dataloader, TMVA::Types::kRandomForest, "RF",
                            "!H:!V:NTrees=850:MinNodeSize=2.5%:MaxDepth=3:BoostType=Grad:Shrinkage=0.10:UseBaggedBoost:BaggedSampleFraction=0.5:nCuts=20:UseRandomisedTrees=True:UseNVars=10");
    }
}

void BDTTrainer::InitializeDNN() {
    // Initialize TMVA with GPU support if enabled
    if (useGPU) {
        factory->BookMethod(dataloader, TMVA::Types::kDNN, "DNN",
                            "!H:!V:VarTransform=N:ErrorStrategy=CROSSENTROPY:WeightInitialization=XAVIERUNIFORM:Layout=TANH|100,TANH|50,TANH|10,LINEAR");
    } else {
        factory->BookMethod(dataloader, TMVA::Types::kDNN, "DNN",
                            "!H:!V:VarTransform=N:ErrorStrategy=CROSSENTROPY:WeightInitialization=XAVIERUNIFORM:Layout=TANH|100,TANH|50,TANH|10,LINEAR");
    }
}

void BDTTrainer::TrainBDT(const TMatrixD& features, const TVectorD& labels, const TMatrixD& curvatureMap) {
    regularizer = new CurvatureRegularizer(curvatureMap);
    TMatrixD regularizedFeatures = features;
    regularizer->ApplyRegularization(regularizedFeatures);
    for (int i = 0; i < regularizedFeatures.GetNcols(); ++i) {
        dataloader->AddVariable(Form("var%d", i), 'F');
    }
    dataloader->AddSignalTree(features, 1.0);
    dataloader->AddBackgroundTree(labels, 1.0);

    // Train the BDT
    factory->TrainAllMethods();
    factory->TestAllMethods();
    factory->EvaluateAllMethods();
}

void BDTTrainer::TrainRandomForest(const TMatrixD& features, const TVectorD& labels, const TMatrixD& curvatureMap) {
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

    // Train the Random Forest
    factory->TrainAllMethods();
    factory->TestAllMethods();
    factory->EvaluateAllMethods();
}

void BDTTrainer::TrainDNN(const TMatrixD& features, const TVectorD& labels, const TMatrixD& curvatureMap) {
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

    // Train the DNN
    factory->TrainAllMethods();
    factory->TestAllMethods();
    factory->EvaluateAllMethods();
}