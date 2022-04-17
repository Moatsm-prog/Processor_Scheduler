#ifndef SJF_NONPREM
#define SJF_NONPREM

#include "NonPreemptive.h"

#include <queue>

struct BurstCompare{
    bool operator()(const Process& a, const Process& b) const {
        return a.getBurst_time() > b.getBurst_time();
    }
};

class SJF_NonPreemptive : public NonPreemptive {
    priority_queue<Process, vector<Process>, BurstCompare> pq;

    void addProcess(Process p);
    Process getTopProcess();
};

#endif // SJF_NONPREM
