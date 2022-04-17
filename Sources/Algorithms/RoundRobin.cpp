#include "RoundRobin.h"

TimeLine RoundRobin::getTimeLine(vector<Process> processes, float quantumTime){
    TimeLine schedule = *(new TimeLine());
    int len = processes.size();
    int remaining = len;
    int j = 0;
    float total_waiting_time = 0;
    float total_turnaround_time = 0;
    queue<pair<Process, int>> jobQueue;
    pair<Process, int> current;
    for(float time = 0; remaining > 0;){
        while(j < len && processes[j].getArrival_time() <= time){
            jobQueue.push({processes[j], processes[j++].getBurst_time()});
        }
        if(!jobQueue.empty()){
            current = jobQueue.front();
            jobQueue.pop();
            if(current.second <= quantumTime){
                current.first.setTurnaround_time(current.first.getBurst_time() + time - current.first.getArrival_time());
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
                while(j < len && processes[j].getArrival_time() < time)
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