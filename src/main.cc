#include <iostream>
#include "DataLoader.h"
#include "ManifoldGeometry.h"
#include "BDTTrainer.h"
#include "ConcurrencyManager.h"
#include "Evaluation.h"

void RunTraining(const std::vector<TString>& inputFiles, const TString& signalFile) {
    // Load ROOT Data
    DataLoader signalLoader(signalFile);
    signalLoader.ApplyPreFilters();
    TMatrixD signalFeatures = signalLoader.GetFeatureMatrix();
    TVectorD signalLabels = signalLoader.GetLabels();

    TMatrixD backgroundFeatures;
    TVectorD backgroundLabels;

    for (const auto& inputFile : inputFiles) {
        if (inputFile != signalFile) {
            DataLoader backgroundLoader(inputFile);
            backgroundLoader.ApplyPreFilters();
            TMatrixD features = backgroundLoader.GetFeatureMatrix();
            TVectorD labels = backgroundLoader.GetLabels();

            backgroundFeatures.ResizeTo(backgroundFeatures.GetNrows() + features.GetNrows(), features.GetNcols());
            backgroundLabels.ResizeTo(backgroundLabels.GetNrows() + labels.GetNrows());

            for (int i = 0; i < features.GetNrows(); ++i) {
                for (int j = 0; j < features.GetNcols(); ++j) {
                    backgroundFeatures[backgroundFeatures.GetNrows() - features.GetNrows() + i][j] = features[i][j];
                }
                backgroundLabels[backgroundLabels.GetNrows() - labels.GetNrows() + i] = labels[i];
            }
        }
    }

    // Combine signal and background features and labels
    TMatrixD features(signalFeatures.GetNrows() + backgroundFeatures.GetNrows(), signalFeatures.GetNcols());
    TVectorD labels(signalLabels.GetNrows() + backgroundLabels.GetNrows());

    for (int i = 0; i < signalFeatures.GetNrows(); ++i) {
        for (int j = 0; j < signalFeatures.GetNcols(); ++j) {
            features[i][j] = signalFeatures[i][j];
        }
        labels[i] = signalLabels[i];
    }

    for (int i = 0; i < backgroundFeatures.GetNrows(); ++i) {
        for (int j = 0; j < backgroundFeatures.GetNcols(); ++j) {
            features[signalFeatures.GetNrows() + i][j] = backgroundFeatures[i][j];
        }
        labels[signalLabels.GetNrows() + i] = backgroundLabels[i];
    }

    // Riemannian Metrics & Curvature
    ManifoldGeometry geom(features);
    TMatrixD fisherMetric = geom.ComputeFisherMetric();
    TMatrixD curvatureMap = geom.ComputeCurvatureMap();

    // Train models with GPU Support
    BDTTrainer trainer(true);  // Enable GPU
    trainer.SetModelFlags(true, true, true);  // Enable GBDT, DNN, and RF
    trainer.InitializeTMVA();
    trainer.TrainKFold(features, labels, curvatureMap, 5);  // Perform 5-fold cross-validation

    // Save the models
    trainer.SaveModel("TrainedModels");

    // Evaluate & Plot
    Evaluation eval;
    eval.ComputeROC();
    eval.PlotCurvatureVsAccuracy();
}

int main() {
    std::vector<TString> inputFiles = {
        "/Users/am/Documents/06.Tracking/4mu/GluGluHToZZTo4L.root",
        "/Users/am/Documents/06.Tracking/4mu/VBF_HToZZTo4L.root",
        "/Users/am/Documents/06.Tracking/4mu/WH_HToZZTo4L.root",
        "/Users/am/Documents/06.Tracking/4mu/ZZTo4L.root",
        "/Users/am/Documents/06.Tracking/4mu/ttH_HToZZ_4L.root"
    };
    TString signalFile = "/Users/am/Documents/06.Tracking/4mu/WH_HToZZTo4L.root";

    RunTraining(inputFiles, signalFile);
    return 0;
}