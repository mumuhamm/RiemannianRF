/*Curvature-Related Metrics
    Curvature tensors or geodesic distances.
    Effect of curvature regularization on model performance (e.g., accuracy, loss).
    Comparison of curvature-aware models vs. non-curvature-aware models.
GPU/Concurrency Performance Metrics
    Training time vs. batch size.
    Speedup vs. number of threads (for CPU/GPU).
    Memory usage and power consumption (if available).
    Comparison of GPU-accelerated vs. CPU-only performance.
Model Performance Metrics
    Accuracy, ROC-AUC, F1-score, etc.
    Training and validation loss curves.
    Feature importance (for tree-based models).

    TrainedModels.root
├── dataset/TestTree          # Test data with model predictions
├── CurvatureMetrics          # Curvature-related metrics
│   ├── hCurvature            # Histogram of curvature values
│   ├── gCurvatureEffect      # Graph of curvature effect on accuracy
├── PerformanceMetrics        # GPU/Concurrency performance metrics
│   ├── gGPUSpeedup           # Graph of GPU speedup vs. threads
│   ├── hTrainingTime         # Histogram of training time
│   ├── hMemoryUsage          # Histogram of memory usage
├── ModelMetrics              # Model performance metrics
│   ├── hAccuracy             # Histogram of accuracy
│   ├── gROCCurves            # Graph of ROC curves
│   ├── hFeatureImportance    # Histogram of feature importance

void SaveMetrics() {
    TFile* file = new TFile("TrainedModels.root", "UPDATE");

    // Save curvature metrics
    TH1F* hCurvature = new TH1F("hCurvature", "Curvature Distribution", 100, 0, 1);
    hCurvature->FillRandom("gaus", 1000);
    hCurvature->Write();

    TGraph* gCurvatureEffect = new TGraph();
    for (int i = 0; i < 10; ++i) {
        gCurvatureEffect->SetPoint(i, i, TMath::Gaus(i, 5, 2));
    }
    gCurvatureEffect->Write("gCurvatureEffect");

    // Save GPU/concurrency performance metrics
    TGraph* gGPUSpeedup = new TGraph();
    for (int i = 1; i <= 10; ++i) {
        gGPUSpeedup->SetPoint(i - 1, i, i * 0.8); // Example speedup
    }
    gGPUSpeedup->Write("gGPUSpeedup");

    TH1F* hTrainingTime = new TH1F("hTrainingTime", "Training Time", 10, 0, 10);
    hTrainingTime->FillRandom("gaus", 100);
    hTrainingTime->Write();

    // Save model performance metrics
    TH1F* hAccuracy = new TH1F("hAccuracy", "Model Accuracy", 100, 0, 1);
    hAccuracy->FillRandom("gaus", 1000);
    hAccuracy->Write();

    file->Close();
}


*/



void plotCurvature() {
    TFile* file = TFile::Open("TrainedModels.root");
    TH1F* hCurvature = (TH1F*)file->Get("hCurvature");
    TGraph* gGPUSpeedup = (TGraph*)file->Get("gGPUSpeedup");

    TCanvas* c1 = new TCanvas("c1", "Curvature Metrics", 800, 600);
    hCurvature->Draw();
    c1->SaveAs("Curvature_Metrics.png");

    TCanvas* c2 = new TCanvas("c2", "GPU Speedup", 800, 600);
    gGPUSpeedup->Draw("AL");
    c2->SaveAs("GPU_Speedup.png");

    file->Close();
}