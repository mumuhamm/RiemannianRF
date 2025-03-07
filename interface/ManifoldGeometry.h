#ifndef MANIFOLDGEOMETRY_H
#define MANIFOLDGEOMETRY_H
#include <TMatrixD.h>
#include <TVectorD.h>
class ManifoldGeometry {
public:
    ManifoldGeometry(const TMatrixD& data);
    TMatrixD ComputeFisherMetric();
    double GeodesicDistance(const TVectorD& x, const TVectorD& y);
    TMatrixD ComputeCurvatureMap();
private:
    TMatrixD data;
    TMatrixD fisherMetric;
    TMatrixD features;
};
#endif //MANIFOLDGEOMETRY_H