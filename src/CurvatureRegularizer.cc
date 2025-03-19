#include "CurvatureRegularizer.h"
#include <TDecompSVD.h>
#include <cmath>

CurvatureRegularizer::CurvatureRegularizer(double lambda) : lambda_(lambda) {}

void CurvatureRegularizer::ApplyRegularization(TMatrixD& features) {
    TMatrixD fisherMatrix = ComputeFisherMatrix(features);
    double penalty = ComputeRegularizationPenalty(fisherMatrix);
    if (ShouldPruneNode(fisherMatrix, penalty)) {
        // Apply regularization logic here
    }
}

TMatrixD CurvatureRegularizer::ProjectOntoStiefelManifold(const TMatrixD& data) {
    TDecompSVD svd(data);
    TMatrixD U = svd.GetU();
    TMatrixD V = svd.GetV();

    TMatrixD stiefel = U * V.T();
    return stiefel;
}

TMatrixD CurvatureRegularizer::ComputeFisherMatrix(const TMatrixD& data) {
    int nRows = data.GetNrows();
    int nCols = data.GetNcols();
    TMatrixD fisherMatrix(nCols, nCols);

    std::vector<double> mean(nCols, 0.0);
    for (int i = 0; i < nRows; ++i) {
        for (int j = 0; j < nCols; ++j) {
            mean[j] += data(i, j);
        }
    }
    for (double& m : mean) m /= nRows;

    for (int i = 0; i < nRows; ++i) {
        for (int j = 0; j < nCols; ++j) {
            for (int k = 0; k < nCols; ++k) {
                fisherMatrix(j, k) += (data(i, j) - mean[j]) * (data(i, k) - mean[k]);
            }
        }
    }
    fisherMatrix *= (1.0 / nRows);

    return fisherMatrix;
}

double CurvatureRegularizer::ComputeRegularizationPenalty(const TMatrixD& fisherMatrix) {
    double trace = 0.0;
    for (int i = 0; i < fisherMatrix.GetNrows(); ++i) {
        trace += fisherMatrix(i, i);
    }
    return lambda_ * trace;
}

bool CurvatureRegularizer::ShouldPruneNode(const TMatrixD& fisherMatrix, double threshold) {
    double trace = ComputeRegularizationPenalty(fisherMatrix);
    return trace > threshold;
}