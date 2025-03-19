/*    Purpose: Central class for training models (BDT, RF, DNN) with Riemannian 
curvature regularization.
    Responsibilities:
        Initialize TMVA and configure training settings.
        Train models (BDT, RF, DNN) using the provided features, labels, and curvature map.
        Perform k-fold cross-validation.
        Save trained models to disk
        Manage GPU acceleration (if enabled).
        Use CurvatureRegularizer to incorporate Riemannian curvature into the training process.
    Dependencies:
        TMVA::Factory, TMVA::DataLoader (for TMVA integration).
        CurvatureRegularizer (for curvature regularization).
        ConcurrencyManager (for parallel training).
*/


#ifndef MODELTRAINER_H
#define MODELTRAINER_H

#include <TMatrixD.h>
#include <TVectorD.h>
#include <TMVA/Factory.h>
#include <TMVA/DataLoader.h>
#include "CurvatureRegularizer.h"
#include <chrono>

class BDTTrainer {
public:
    ModelTrainer(bool useGPU);
    void InitializeTMVA();
    void TrainModels(const TMatrixD& features, const TVectorD& labels, const TMatrixD& curvatureMap);
    void TrainKFold(const TMatrixD& features, const TVectorD& labels, const TMatrixD& curvatureMap, int k);
    void SaveModel(const TString& modelName);
    void SetModelFlags(bool useGBDT, bool useDNN, bool useRF);

private:
    bool useGPU;
    bool useGBDT;
    bool useDNN;
    bool useRF;
    TMVA::Factory* factory;
    TMVA::DataLoader* dataloader;
    CurvatureRegularizer* regularizer;
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
    std::chrono::time_point<std::chrono::high_resolution_clock> endTime;

    void StartTimer();
    void StopTimer();
    void PrintElapsedTime();
};

#endif // MODELTRAINER_H