#ifndef CONCURRENCYMANAGER_H
#define CONCURRENCYMANAGER_H

#include <thread>
#include <vector>
#include <TMatrixD.h>

class ConcurrencyManager {
public:
    void ParallelizeTrees(std::vector<TMatrixD>& trees);
    void ParallelizeNodes(std::vector<TMatrixD>& nodes);
    void LaunchMetalTasks(const TMatrixD& data);
    void HandleOpenCLTasks(const TMatrixD& data);

private:
    void ProcessTree(TMatrixD& tree);
    void ProcessNode(TMatrixD& node);
    void MetalTask(const TMatrixD& data);
    void OpenCLTask(const TMatrixD& data);
};

#endif // CONCURRENCYMANAGER_H