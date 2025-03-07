#ifndef DATALOADER_H
#define DATALOADER_H

#include <TFile.h>
#include <TTree.h>
#include <TMatrixD.h>
#include <TVectorD.h>
class DataLoader {
public:
    DataLoader(const TString& filename);
    void ApplyPreFilters();
    TMatrixD GetFeatureMatrix();
    TVectorD GetLabels();
private:
    TFile* inputFile;
    TTree* inputTree;
    TMatrixD features;
    TVectorD labels;
    std::vector<TString> selectedVariables;

};
#endif //DATALOADER_H