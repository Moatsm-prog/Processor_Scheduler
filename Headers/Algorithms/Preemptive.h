#ifndef PREEMPTIVE_H
#define PREEMPTIVE_H
#include "Algorithm.h"

class Preemptive : public Algorithm {
protected:
    virtual void addProcess(Process p) = 0;
    virtual Process getTopProcess() = 0;
    virtual int getSize() = 0;
    virtual void popProcess() = 0;
public:
    TimeLine getTimeLine(vector<Process> processes, float quantumTime);
};

#endif // PREEMPTIVE_H

