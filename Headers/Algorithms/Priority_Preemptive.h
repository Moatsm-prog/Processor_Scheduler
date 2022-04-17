#ifndef PRIORITY_PREEMPTIVE_H
#define PRIORITY_PREEMPTIVE_H
#include "Preemptive.h"
#include <queue>

struct BurstCompare{
bool operator()(const Process& a, const Process& b) const {
return a.getPriority() > b.getPriority();
}
};
class Priority_Preemptive : public Preemptive{
    priority_queue<Process, vector<Process>, BurstCompare> jobQueue;
    void addProcess(Process p);
    Process getTopProcess();
    int getSize();
    void popProcess();

};

#endif // PRIORITY_PREEMPTIVE_H
