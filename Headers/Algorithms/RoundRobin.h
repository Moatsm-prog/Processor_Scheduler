#include "Algorithm.h"
#include <utility>
#include <queue>

using namespace std;

class RoundRobin : public Algorithm {
    TimeLine getTimeLine(vector<Process> processes, float quantumTime);
};
