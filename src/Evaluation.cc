#include "Evaluation.h"
#include <iostream>
#include <algorithm>
#include <TTree.h>
#include <TFile.h>
#include <TMath.h>
#include <TRandom3.h>
#include <RooStats/SPlot.h>
#include <RooStats/RooStatsUtils.h>
#include <TMVA/GeneticAlgorithm.h>
#include <TMVA/Factory.h>
#include <TMVA/Tools.h>
#include <TMVA/Reader.h>

void Evaluation::EvaluateModel(const TString& modelFile) {
    LoadModelData(modelFile);
    SelectTopFeatures();
    RunGeneticAlgorithm();
    OptimizeFigureOfMerit();
    PerformSPlotAnalysis("controlRegion", "signalRegion", "backgroundRegion");
    DataMCComparison();
    SaveResults();
}

void Evaluation::LoadModelData(const TString& modelFile) {
    TFile* file = TFile::Open(modelFile);
    if (!file) {
        std::cerr << "Error: Could not open file " << modelFile << std::endl;
        return;
    }

    tree = (TTree*)file->Get("dataset/TestTree");
    if (!tree) {
        std::cerr << "Error: Could not find TestTree in file" << std::endl;
        return;
    }

    tree->SetBranchAddress("BDTG", &BDTG);
    tree->SetBranchAddress("RF", &RF);
    tree->SetBranchAddress("DNN", &DNN);
    tree->SetBranchAddress("weight", &weight);
    tree->SetBranchAddress("isSignal", &isSignal);
    tree->SetBranchAddress("f_lept1_pt", &f_lept1_pt);
    tree->SetBranchAddress("f_lept1_eta", &f_lept1_eta);
    tree->SetBranchAddress("f_lept1_phi", &f_lept1_phi);
    tree->SetBranchAddress("f_lept2_pt", &f_lept2_pt);
    tree->SetBranchAddress("f_lept2_eta", &f_lept2_eta);
    tree->SetBranchAddress("f_lept2_phi", &f_lept2_phi);
    tree->SetBranchAddress("f_lept3_pt", &f_lept3_pt);
    tree->SetBranchAddress("f_lept3_eta", &f_lept3_eta);
    tree->SetBranchAddress("f_lept3_phi", &f_lept3_phi);
    tree->SetBranchAddress("f_lept4_pt", &f_lept4_pt);
    tree->SetBranchAddress("f_lept4_eta", &f_lept4_eta);
    tree->SetBranchAddress("f_lept4_phi", &f_lept4_phi);
    tree->SetBranchAddress("f_jet1_pt", &f_jet1_pt);
    tree->SetBranchAddress("f_jet1_eta", &f_jet1_eta);
    tree->SetBranchAddress("f_jet1_phi", &f_jet1_phi);
    tree->SetBranchAddress("f_jet2_pt", &f_jet2_pt);
    tree->SetBranchAddress("f_jet2_eta", &f_jet2_eta);
    tree->SetBranchAddress("f_jet2_phi", &f_jet2_phi);
}

void Evaluation::SelectTopFeatures() {
    // Automatically select top 10 features based on their ranking
    std::vector<std::pair<float, TString>> featureRanking = {
        {f_lept1_pt, "f_lept1_pt"}, {f_lept1_eta, "f_lept1_eta"}, {f_lept1_phi, "f_lept1_phi"},
        {f_lept2_pt, "f_lept2_pt"}, {f_lept2_eta, "f_lept2_eta"}, {f_lept2_phi, "f_lept2_phi"},
        {f_lept3_pt, "f_lept3_pt"}, {f_lept3_eta, "f_lept3_eta"}, {f_lept3_phi, "f_lept3_phi"},
        {f_lept4_pt, "f_lept4_pt"}, {f_lept4_eta, "f_lept4_eta"}, {f_lept4_phi, "f_lept4_phi"},
        {f_jet1_pt, "f_jet1_pt"}, {f_jet1_eta, "f_jet1_eta"}, {f_jet1_phi, "f_jet1_phi"},
        {f_jet2_pt, "f_jet2_pt"}, {f_jet2_eta, "f_jet2_eta"}, {f_jet2_phi, "f_jet2_phi"}
    };

    std::sort(featureRanking.begin(), featureRanking.end(), std::greater<>());
    for (int i = 0; i < 10; ++i) {
        topFeatures.push_back(featureRanking[i].first);
    }
}

void Evaluation::RunGeneticAlgorithm() {
    // Implement a genetic algorithm inspired by ROOT TMVA
    TMVA::GeneticAlgorithm ga;
    // Configure and run the genetic algorithm
    // This is a placeholder implementation
}

void Evaluation::OptimizeFigureOfMerit() {
    // Optimize the figure of merit S/sqrt(S+B)
    // This is a placeholder implementation
}

void Evaluation::PerformSPlotAnalysis(const TString& controlRegion, const TString& signalRegion, const TString& backgroundRegion) {
    // Perform sPlot analysis using RooStats
    // This is a placeholder implementation
}

void Evaluation::DataMCComparison() {
    // Perform Data/MC comparison
    // This is a placeholder implementation
}

void Evaluation::SaveResults() {
    // Save the results: table of selections and figure of merit, data-MC overlayed plots
    // This is a placeholder implementation
}