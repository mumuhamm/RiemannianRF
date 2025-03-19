/*    Purpose: Load and preprocess data for training and evaluation.
    Responsibilities:
        Load features, labels, and curvature maps from input files.
        Split data into training, validation, and test sets.
        Normalize or preprocess data as needed.
    Dependencies:
        None (data loading and preprocessing).      
*/

#ifndef DATALOADER_H
#define DATALOADER_H

#include <TString.h>
#include <TMatrixD.h>
#include <TVectorD.h>
#include <TFile.h>
#include <TTree.h>
#include <vector>

class DataLoader {
public:
    DataLoader(const TString& inputFile);
    void ApplyPreFilters();
    TMatrixD GetFeatureMatrix();
    TVectorD GetLabels();

private:
    TString inputFile;
    TFile* file;
    TTree* tree;
    std::vector<TString> selectedVariables;
};

#endif // DATALOADER_H