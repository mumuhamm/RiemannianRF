/*    Purpose: Compute and apply Riemannian curvature regularization during model training.
    Responsibilities:
        Compute curvature metrics from the input curvature map.
        Apply curvature regularization to the loss function during training.
        Provide curvature-related utilities (e.g., curvature-aware distance metrics).
    Dependencies:
        ManifoldGeometry (for Riemannian geometry computations).*/
        
#ifndef CURVATUREREGULARIZER_H
#define CURVATUREREGULARIZER_H

#include <TMatrixD.h>
#include <vector>

class CurvatureRegularizer {
public:
    CurvatureRegularizer(double lambda);
    void ApplyRegularization(TMatrixD& features);
    TMatrixD ProjectOntoStiefelManifold(const TMatrixD& data);
    TMatrixD ComputeFisherMatrix(const TMatrixD& data);
    double ComputeRegularizationPenalty(const TMatrixD& fisherMatrix);
    bool ShouldPruneNode(const TMatrixD& fisherMatrix, double threshold);

private:
    double lambda_;
};

#endif // CURVATUREREGULARIZER_H