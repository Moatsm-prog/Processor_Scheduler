#include "SJF_NonPreemptive.h"

void SJF_NonPreemptive::addProcess(Process process) {
    pq.push(process);
}

Process SJF_NonPreemptive::getTopProcess() {
    Process p = pq.top();
    pq.pop();
    return p;
}
