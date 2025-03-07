#ifndef BDTTRAINER_H
#define BDTTRAINER_H

#include <TMatrixD.h>
#include <TVectorD.h>
#include <TMVA/Factory.h>
#include <TMVA/DataLoader.h>
#include "CurvatureRegularizer.h"
#include <chrono>

class BDTTrainer {
public:
    BDTTrainer(bool useGPU);
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

#endif // BDTTRAINER_H