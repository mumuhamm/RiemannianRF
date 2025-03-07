#ifndef BDTTRAINER_H
#define BDTTRAINER_H

#include <TMatrixD.h>
#include <TVectorD.h>
#include <TMVA/Factory.h>
#include <TMVA/DataLoader.h>

class BDTTrainer {
public:
    BDTTrainer(bool useGPU);
    void InitializeBDT();
    void InitializeRandomForest();
    void InitializeDNN();
    void TrainBDT(const TMatrixD& features, const TVectorD& labels, const TMatrixD& curvatureMap);
    void TrainRandomForest(const TMatrixD& features, const TVectorD& labels, const TMatrixD& curvatureMap);
    void TrainDNN(const TMatrixD& features, const TVectorD& labels, const TMatrixD& curvatureMap);
    void SaveModel(const TString& modelName);

private:
    bool useGPU;
    TMVA::Factory* factory;
    TMVA::DataLoader* dataloader;
};

#endif // BDTTRAINER_H