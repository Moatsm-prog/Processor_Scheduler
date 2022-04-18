#include "Priority_NonPreemptive.h"

void Priority_NonPreemptive::addProcess(Process process) {
    pq.push(process);
}

Process Priority_NonPreemptive::getTopProcess() {
    Process p = pq.top();
    pq.pop();
    return p;
}

