#ifndef PRIORITY_NONPREM
#define PRIORITY_NONPREM

#include "NonPreemptive.h"

#include <queue>

class Priority_NonPreemprive : public NonPreemptive {
    priority_queue<Process, vector<Process>, PriorityCompare> pq;

    void addProcess(Process p);
    Process getTopProcess();
};

#endif // PRIORITY_NONPREM
