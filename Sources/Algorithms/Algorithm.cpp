#include "Algorithm.h"

using namespace std;

TimeLine Algorithm::applyAlgorithm(vector<Process> processes, float quantumTime){
        sort(processes.begin(), processes.end(), 
        [](const Process& a, const Process& b) -> bool {
            return a.getArrival_time() < b.getArrival_time();}
        );
        return getTimeLine(processes, quantumTime);
}
