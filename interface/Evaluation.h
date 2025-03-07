#ifndef EVALUATION_H
#define EVALUATION_H
#include <TGraph.h>
#include <TCanvas.h>

class Evaluation {
public:
    void ComputeROC();
    void PlotCurvatureVsAccuracy();
    void PlotOverfittingMetrics();
};

#endif // EVALUATION_H