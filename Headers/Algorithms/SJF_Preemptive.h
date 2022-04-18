#ifndef SJF_PREEMPTIVE_H
#define SJF_PREEMPTIVE_H
#include "Preemptive.h"
#include <queue>

class SJF_Preemptive : public Preemptive{
    priority_queue<Process, vector<Process>, BurstCompare> jobQueue;
    void addProcess(Process p);
    Process getTopProcess();
    int getSize();
    void popProcess();

};
#endif // SJF_PREEMPTIVE_H
