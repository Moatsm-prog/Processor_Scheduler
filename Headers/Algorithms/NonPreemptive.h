#ifndef NON_PREM
#define NON_PREM

#include "Algorithm.h"

class NonPreemptive : public Algorithm {
protected:
    virtual void addProcess(Process p) = 0;
    virtual Process getTopProcess() = 0;
public:
    TimeLine getTimeLine(vector<Process>, float quantumTime);
};

#endif // NON_PREM
