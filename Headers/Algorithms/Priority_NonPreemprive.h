#ifndef PRIORITY_NONPREM
#define PRIORITY_NONPREM

#include "NonPreemptive.h"

#include <queue>

struct PriorityCompare{
    bool operator()(const Process& a, const Process& b) const {
        return a.getPriority() > b.getPriority();
    }
};

class Priority_NonPreemprive : public NonPreemptive {
    priority_queue<Process, vector<Process>, PriorityCompare> pq;

    void addProcess(Process p);
    Process getTopProcess();
};

#endif // PRIORITY_NONPREM
