#include "algorithm"
#include "TimeLine.h"

class Algorithm {
protected:
    virtual TimeLine getTimeLine(vector<Process>, float) = 0;
public:
    TimeLine applyAlgorithm(vector<Process> processes, float quantumTime=0);
};

class RoundRobin : public Algorithm {
    TimeLine getTimeLine(vector<Process> processes, float quantumTime);
};

class Preemptive : public Algorithm {
    TimeLine getTimeLine(vector<Process> processes, float quantumTime);
    virtual void addProcess(Process p) = 0;
    virtual Process getTopProcess() = 0;
    virtual int getSize() = 0;
    virtual void popProcess() = 0;
};

