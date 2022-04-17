#include "Process.h"

Process::Process(int process_id, int arrival_time, int burst_time, int priority):
            process_id(process_id), burst_time(burst_time), arrival_time(arrival_time), priority(priority){}

int Process::getProcess_id() const { 
    return process_id; 
}
float Process::getArrival_time() const { 
    return arrival_time; 
}
float Process::getBurst_time() const { 
    return burst_time; 
}
int Process::getPriority() const { 
    return priority; 
}
float Process::getWaiting_time() const { 
    return waiting_time; 
}

float Process::getTurnaround_time() const { 
    return turnaround_time; 
}

void Process::setWaiting_time(int time) { 
    waiting_time = time; 
}

void Process::setTurnaround_time(float time) { 
    turnaround_time = time; 
}

float Process::getTotal_Burst_time() const {
     return total_burst_time;
}

void Process::setBurst_time(float time) {
    burst_time = time;
}

