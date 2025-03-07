#include "DataLoader.h"

DataLoader::DataLoader(const TString& inputFile) : inputFile(inputFile) {
    file = TFile::Open(inputFile);
    tree = (TTree*)file->Get("HZZ4LeptonsAnalysisReduced");
    selectedVariables = {"f_angle_phi", "f_angle_phistar1", "f_pt4l", "f_eta4l", "f_mass4l", 
                         "f_mass4lErr", "f_njets_pass", "f_deltajj", "f_massjj", "f_D_jet"};
}

void DataLoader::ApplyPreFilters() {
    // Apply any necessary pre-filters to the data
}

TMatrixD DataLoader::GetFeatureMatrix() {
    TMatrixD features(tree->GetEntries(), selectedVariables.size());
    for (size_t i = 0; i < selectedVariables.size(); ++i) {
        tree->SetBranchAddress(selectedVariables[i], &features[i][0]);
    }
    tree->GetEntry(0);
    return features;
}

TVectorD DataLoader::GetLabels() {
    TVectorD labels(tree->GetEntries());
    tree->SetBranchAddress("label", &labels[0]);
    tree->GetEntry(0);
    return labels;
}