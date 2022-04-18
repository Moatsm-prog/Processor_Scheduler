#ifndef ALGORITHM_H
#define ALGORITHM_H
#include "algorithm"
#include "TimeLine.h"

struct BurstCompare{
    bool operator()(const Process& a, const Process& b) const {
        return a.getBurst_time() > b.getBurst_time();
    }
};

struct PriorityCompare{
    bool operator()(const Process& a, const Process& b) const {
        return a.getPriority() > b.getPriority();
    }
};

class Algorithm {
protected:
    virtual TimeLine getTimeLine(vector<Process>, float) = 0;
public:
    TimeLine applyAlgorithm(vector<Process> processes, float quantumTime=0);
};

#endif


