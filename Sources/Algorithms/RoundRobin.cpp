#include "RoundRobin.h"
#include "QuantumInvalidException.h"

#include <string>

TimeLine RoundRobin::getTimeLine(vector<Process> processes, float quantumTime){
    if(quantumTime <= 0){
        std::string msg = "Qunatum is Invalid" + std::to_string(quantumTime); 
        throw QuantumInvalidException(msg.c_str());
    }

    TimeLine schedule = *(new TimeLine());
    float len = processes.size();
    float remaining = len;
    float j = 0;
    float total_waiting_time = 0;
    float total_turnaround_time = 0;
    queue<pair<Process, float>> jobQueue;
    pair<Process, float> current;
    for(float time = 0; remaining > 0;){
        while(j < len && processes[j].getArrival_time() <= time){
            jobQueue.push({processes[j], processes[j++].getBurst_time()});
        }
        if(!jobQueue.empty()){
            current = jobQueue.front();
            jobQueue.pop();
            if(current.second <= quantumTime){
                current.first.setTurnaround_time(current.second + time - current.first.getArrival_time());
                current.first.setWaiting_time(current.first.getTurnaround_time() - current.first.getBurst_time());
                total_waiting_time += current.first.getWaiting_time();
                total_turnaround_time += current.first.getTurnaround_time();
                schedule.addProcess(current.first, time, time + current.second);
                time += current.second;
                remaining--;
            }
            else{
                schedule.addProcess(current.first, time, time + quantumTime);
                current.second -= quantumTime;
                time += quantumTime;
                while(j < len && processes[j].getArrival_time() <= time)
                    jobQueue.push({processes[j], processes[j++].getBurst_time()});
                jobQueue.push({current.first, current.second});
            }
        }
        else time += (processes[j].getArrival_time() - time);
    }
/*     schedule.setAvgTurnaround(total_turnaround_time / (float)len);
    schedule.setAvgWaiting(total_waiting_time / (float)len); */
    return schedule;
}
