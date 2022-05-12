#include "Process.h"
#include "ProcessInvalidException.h"

#include <string>

Process::Process(int process_id, float arrival_time, float burst_time, int priority):
            process_id(process_id), arrival_time(arrival_time), burst_time(burst_time), priority(priority) , total_burst_time(burst_time){
                if(arrival_time < 0){
                    std::string msg = "Arrival time is invalid" + std::to_string(arrival_time); 
                    throw ProcessInvalidException(msg.c_str());
                } else if(burst_time <= 0){
                    std::string msg = "Burst Time time is invalid" + std::to_string(burst_time); 
                    throw ProcessInvalidException(msg.c_str());
                } else if(priority < 0){
                    std::string msg = "Priority is invalid" + std::to_string(priority); 
                    throw ProcessInvalidException(msg.c_str());
                }
            }

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

