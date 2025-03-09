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