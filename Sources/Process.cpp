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

void Process::setWaiting_time(int time) { 
    waiting_time = time; 
}
