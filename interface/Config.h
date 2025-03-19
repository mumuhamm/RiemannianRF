#ifndef CONFIG_H
#define CONFIG_H

#include <vector>
#include <TString.h>

class Config {
public:
    // File paths
    static std::vector<TString> INPUT_FILES;
    static TString SIGNAL_FILE;
    static TString OUTPUT_MODEL_PATH;

    // Model flags
    static bool USE_GBDT;
    static bool USE_DNN;
    static bool USE_RF;

    // Training parameters
    static bool USE_GPU;
    static int K_FOLDS;

    // Riemannian geometry parameters
    static double CURVATURE_SCALE;

    // Load configuration from a file (optional)
    static void Load(const TString& configFile);


    // Get the total PDF (model) from the workspace
    static RooAbsPdf* GetTotalPDF(RooWorkspace& ws) {
        return ws.pdf("totalPdf");
    }

    // Define and import the model into the workspace
    static void DefineModel(RooWorkspace& ws) {
        // Define variables
        RooRealVar invMass("invMass", "Invariant Mass", 0, 200);
        RooRealVar mean("mean", "Mean", 100, 0, 200);
        RooRealVar sigma("sigma", "Sigma", 10, 0, 50);
        RooRealVar bkgMean("bkgMean", "Background Mean", 50, 0, 200);
        RooRealVar bkgSigma("bkgSigma", "Background Sigma", 20, 0, 50);

        // Define PDFs
        RooGaussian signalPdf("signalPdf", "Signal PDF", invMass, mean, sigma);
        RooGaussian bkgPdf("bkgPdf", "Background PDF", invMass, bkgMean, bkgSigma);

        // Define yields
        RooRealVar nsig("nsig", "Number of Signal Events", 1000, 0, 1e6);
        RooRealVar nbkg("nbkg", "Number of Background Events", 1000, 0, 1e6);

        // Construct the total PDF
        RooAddPdf totalPdf("totalPdf", "Total PDF", RooArgList(signalPdf, bkgPdf), RooArgList(nsig, nbkg));

        // Import into the workspace
        ws.import(totalPdf);
    }
};

#endif // CONFIG_H