#include <iostream>
//Main : Execution Flow (main.cc)
#include "DataLoader.h"
#include "ManifoldGeometry.h"
#include "BDTTrainer.h"
#include "ConcurrencyManager.h"
#include "Evaluation.h"

void RunBDTTraining(const TString& inputFile) {
    // Load ROOT Data
    DataLoader loader(inputFile);
    loader.ApplyPreFilters();
    TMatrixD features = loader.GetFeatureMatrix();
    TVectorD labels = loader.GetLabels();

    // Riemannian Metrics & Curvature
    ManifoldGeometry geom(features);
    TMatrixD fisherMetric = geom.ComputeFisherMetric();
    TMatrixD curvatureMap = geom.ComputeCurvatureMap();

    // Train BDT with GPU Support
    BDTTrainer trainer(true);  // Enable GPU
    trainer.InitializeBDT();
    tariner.TrainBDT(features, labels, curvatureMap );
    trainer.SaveModel("BDT_GPU");
    trainer.InitializeRandomForest();
    trainer.TrainRandomForest(features, labels, curvatureMap);
    trainer.TrainBDT(features, labels);

    // Evaluate & Plot
    Evaluation eval;
    eval.ComputeROC();
    eval.PlotCurvatureVsAccuracy();
}

int main() {
    RunBDTTraining("/Users/am/Documents/06.Tracking/4mu/WH_HToZZTo4L.root");
    return 0;
}