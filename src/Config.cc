#include "Config.h"

// File paths
std::vector<TString> Config::INPUT_FILES = {
    "/Users/am/Documents/06.Tracking/4mu/GluGluHToZZTo4L.root",
    "/Users/am/Documents/06.Tracking/4mu/VBF_HToZZTo4L.root",
    "/Users/am/Documents/06.Tracking/4mu/WH_HToZZTo4L.root",
    "/Users/am/Documents/06.Tracking/4mu/ZZTo4L.root",
    "/Users/am/Documents/06.Tracking/4mu/ttH_HToZZ_4L.root"
};
TString Config::SIGNAL_FILE = "/Users/am/Documents/06.Tracking/4mu/WH_HToZZTo4L.root";
TString Config::OUTPUT_MODEL_PATH = "TrainedModels";

// Model flags
bool Config::USE_GBDT = true;
bool Config::USE_DNN = true;
bool Config::USE_RF = true;

// Training parameters
bool Config::USE_GPU = true;
int Config::K_FOLDS = 5;

// Riemannian geometry parameters
double Config::CURVATURE_SCALE = 1.0;

// Load configuration from a file (optional)
void Config::Load(const TString& configFile) {
    // Implement loading from a file if needed
}