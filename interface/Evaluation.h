#ifndef EVALUATION_H
#define EVALUATION_H

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <TFile.h>
#include <TTree.h>
#include <ROOT/RDataFrame.hxx>
#include <TMVA/GeneticAlgorithm.h>
#include <RooWorkspace.h>
#include <RooDataSet.h>
#include "Config.h"

class Evaluation {
public:
    explicit Evaluation(const std::string &inputFile);
    void RunEvaluation();
    void RunGeneticAlgorithm();
    void PerformSPlotAnalysis();
    void CompareDataMC();

private:
    std::unique_ptr<TFile> file_;
    std::unique_ptr<TTree> tree_;
    ROOT::RDataFrame dataframe_;

    void LoadData();
    void SelectTopFeatures(size_t numFeatures = 10);
    void ApplySelectionCuts();
    void SetupWorkspace(RooWorkspace &ws);
};

#endif // EVALUATION_H
