#include "Algorithm.h"

using namespace std;

class FCFS : public Algorithm {
    TimeLine getTimeLine(vector<Process> processes, float quantumTime);
};
