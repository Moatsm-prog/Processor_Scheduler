#include "Priority_NonPreemprive.h"

void Priority_NonPreemprive::addProcess(Process process) {
    pq.push(process);
}

Process Priority_NonPreemprive::getTopProcess() {
    Process p = pq.top();
    pq.pop();
    return p;
}

