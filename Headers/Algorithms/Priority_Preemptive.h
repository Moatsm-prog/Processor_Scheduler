#ifndef PRIORITY_PREEMPTIVE_H
#define PRIORITY_PREEMPTIVE_H
#include "Preemptive.h"
#include <queue>


class Priority_Preemptive : public Preemptive{
    priority_queue<Process, vector<Process>, PriorityCompare> jobQueue;
    void addProcess(Process p);
    Process getTopProcess();
    int getSize();
    void popProcess();

};

#endif // PRIORITY_PREEMPTIVE_H
