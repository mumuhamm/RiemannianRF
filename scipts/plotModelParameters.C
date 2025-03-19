#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TGraph.h>
#include <TMultiGraph.h>
#include <TMath.h>

void plotROC() {
    TFile* file = TFile::Open("TrainedModels.root");
    if (!file) {
        std::cerr << "Error: Could not open file TrainedModels.root" << std::endl;
        return;
    }

    TTree* tree = (TTree*)file->Get("dataset/TestTree");
    if (!tree) {
        std::cerr << "Error: Could not find TestTree in file" << std::endl;
        return;
    }

    float BDTG, RF, DNN, weight, classID;
    tree->SetBranchAddress("BDTG", &BDTG);
    tree->SetBranchAddress("RF", &RF);
    tree->SetBranchAddress("DNN", &DNN);
    tree->SetBranchAddress("weight", &weight);
    tree->SetBranchAddress("classID", &classID);

    TH1F* hBDTG = new TH1F("hBDTG", "BDTG Score", 100, 0, 1);
    TH1F* hRF = new TH1F("hRF", "RF Score", 100, 0, 1);
    TH1F* hDNN = new TH1F("hDNN", "DNN Score", 100, 0, 1);

    int nEntries = tree->GetEntries();
    for (int i = 0; i < nEntries; ++i) {
        tree->GetEntry(i);
        if (classID == 1) {  // Signal
            hBDTG->Fill(BDTG, weight);
            hRF->Fill(RF, weight);
            hDNN->Fill(DNN, weight);
        }
    }

    TCanvas* c1 = new TCanvas("c1", "ROC Curves", 800, 600);
    TMultiGraph* mg = new TMultiGraph();

    TGraph* gBDTG = new TGraph();
    TGraph* gRF = new TGraph();
    TGraph* gDNN = new TGraph();

    for (int i = 1; i <= 100; ++i) {
        float cut = i / 100.0;
        float tpBDTG = hBDTG->Integral(hBDTG->FindBin(cut), 100) / hBDTG->Integral();
        float tpRF = hRF->Integral(hRF->FindBin(cut), 100) / hRF->Integral();
        float tpDNN = hDNN->Integral(hDNN->FindBin(cut), 100) / hDNN->Integral();

        float fpBDTG = hBDTG->Integral(0, hBDTG->FindBin(cut) - 1) / hBDTG->Integral();
        float fpRF = hRF->Integral(0, hRF->FindBin(cut) - 1) / hRF->Integral();
        float fpDNN = hDNN->Integral(0, hDNN->FindBin(cut) - 1) / hDNN->Integral();

        gBDTG->SetPoint(i - 1, fpBDTG, tpBDTG);
        gRF->SetPoint(i - 1, fpRF, tpRF);
        gDNN->SetPoint(i - 1, fpDNN, tpDNN);
    }

    gBDTG->SetLineColor(kRed);
    gRF->SetLineColor(kBlue);
    gDNN->SetLineColor(kGreen);

    mg->Add(gBDTG, "L");
    mg->Add(gRF, "L");
    mg->Add(gDNN, "L");

    mg->Draw("A");
    mg->SetTitle("ROC Curves;False Positive Rate;True Positive Rate");

    TLegend* legend = new TLegend(0.7, 0.2, 0.9, 0.4);
    legend->AddEntry(gBDTG, "BDTG", "L");
    legend->AddEntry(gRF, "RF", "L");
    legend->AddEntry(gDNN, "DNN", "L");
    legend->Draw();

    c1->SaveAs("ROC_Curves.png");

    delete hBDTG;
    delete hRF;
    delete hDNN;
    delete gBDTG;
    delete gRF;
    delete gDNN;
    delete mg;
    delete legend;
    delete c1;
    file->Close();
}