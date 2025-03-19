#include <iostream>
#include "DataLoader.h"
#include "ManifoldGeometry.h"
#include "ModelTrainer.h"
#include "ConcurrencyManager.h"
#include "Evaluation.h"
#include "Config.h"

void RunTraining() {
    // Load ROOT Data
    DataLoader signalLoader(Config::SIGNAL_FILE);
    signalLoader.ApplyPreFilters();
    TMatrixD signalFeatures = signalLoader.GetFeatureMatrix();
    TVectorD signalLabels = signalLoader.GetLabels();

    TMatrixD backgroundFeatures;
    TVectorD backgroundLabels;

    for (const auto& inputFile : Config::INPUT_FILES) {
        if (inputFile != Config::SIGNAL_FILE) {
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
    ModelTrainer trainer(Config::USE_GPU);  // Enable GPU
    trainer.SetModelFlags(Config::USE_GBDT, Config::USE_DNN, Config::USE_RF);  // Enable GBDT, DNN, and RF
    trainer.InitializeTMVA();
    trainer.TrainKFold(features, labels, curvatureMap, Config::K_FOLDS);  // Perform k-fold cross-validation

    // Save the models
    trainer.SaveModel(Config::OUTPUT_MODEL_PATH);

    // Evaluate & Plot
    Evaluation eval;
    eval.ComputeROC();
    eval.PlotCurvatureVsAccuracy();
}

int main() {
    RunTraining();
    return 0;
}