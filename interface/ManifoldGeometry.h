/*    Purpose: Handle Riemannian geometry computations.
    Responsibilities:
        Compute Riemannian metrics (e.g., geodesic distances, curvature tensors).
        Provide low-level geometry utilities for CurvatureRegularizer.
    Dependencies:
        None (standalone geometry computations).
*/

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