#ifndef CURVATUREREGULARIZER_H
#define CURVATUREREGULARIZER_H

#include <TMatrixD.h>

class CurvatureRegularizer {
public:
    CurvatureRegularizer(const TMatrixD& curvatureMap);
    void ApplyRegularization(TMatrixD& features);

private:
    TMatrixD curvatureMap;
};

#endif // CURVATUREREGULARIZER_H
