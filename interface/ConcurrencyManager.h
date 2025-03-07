#ifndef CONCURRENCYMANAGER_H
#define CONCURRENCYMANAGER_H

#include <thread>
#include <vector>
#include <TMatrixD.h>

class ConcurrencyManager {
public:
    void ParallelizeSplits(std::vector<TMatrixD>& splits);
    void LaunchMetalTasks(const TMatrixD& data);
    void HandleOpenCLTasks(const TMatrixD& data);
};

#endif // CONCURRENCYMANAGER_H