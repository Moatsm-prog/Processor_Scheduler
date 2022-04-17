#ifndef SJF_PREEMPTIVE_H
#define SJF_PREEMPTIVE_H
#include "Preemptive.h"
#include <queue>

struct BurstCompare{
bool operator()(const Process& a, const Process& b) const {
return a.getBurst_time() > b.getBurst_time();
}
};

class SJF_Preemptive : public Preemptive{
    priority_queue<Process, vector<Process>, BurstCompare> jobQueue;
    void addProcess(Process p);
    Process getTopProcess();
    int getSize();
    void popProcess();

};
#endif // SJF_PREEMPTIVE_H
