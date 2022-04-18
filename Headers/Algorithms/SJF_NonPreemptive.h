#ifndef SJF_NONPREM
#define SJF_NONPREM

#include "NonPreemptive.h"

#include <queue>

class SJF_NonPreemptive : public NonPreemptive {
    priority_queue<Process, vector<Process>, BurstCompare> pq;

    void addProcess(Process p);
    Process getTopProcess();
};

#endif // SJF_NONPREM
