#include "DataLoader.h"

DataLoader::DataLoader(const TString& inputFile) : inputFile(inputFile) {
    file = TFile::Open(inputFile);
    tree = (TTree*)file->Get("HZZ4LeptonsAnalysisReduced");
    selectedVariables = {"f_lept1_pt", "f_lept1_eta", "f_lept1_phi",
                         "f_lept2_pt", "f_lept2_eta", "f_lept2_phi",
                         "f_lept3_pt", "f_lept3_eta", "f_lept3_phi",
                         "f_lept4_pt", "f_lept4_eta", "f_lept4_phi",
                         "f_jet1_pt", "f_jet1_eta", "f_jet1_phi",
                         "f_jet2_pt", "f_jet2_eta", "f_jet2_phi"};
}

void DataLoader::ApplyPreFilters() {
    // Apply any necessary pre-filters to the data
}

TMatrixD DataLoader::GetFeatureMatrix() {
    TMatrixD features(tree->GetEntries(), selectedVariables.size());
    for (size_t i = 0; i < selectedVariables.size(); ++i) {
        tree->SetBranchAddress(selectedVariables[i], &features[i][0]);
    }
    for (int i = 0; i < tree->GetEntries(); ++i) {
        tree->GetEntry(i);
        for (size_t j = 0; j < selectedVariables.size(); ++j) {
            features(i, j) = features[j][0];
        }
    }
    return features;
}

TVectorD DataLoader::GetLabels() {
    TVectorD labels(tree->GetEntries());
    tree->SetBranchAddress("isSignal", &labels[0]);
    for (int i = 0; i < tree->GetEntries(); ++i) {
        tree->GetEntry(i);
        labels[i] = labels[0];
    }
    return labels;
}