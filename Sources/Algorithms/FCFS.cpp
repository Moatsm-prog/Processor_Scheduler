#include "FCFS.h"

TimeLine FCFS::getTimeLine(vector<Process> processes, float quantumTime){
    TimeLine schedule = *(new TimeLine());
    int len = processes.size();
    float start_time, end_time;
    for(int i = 0; i < len; i++) {
        if (i == 0){
            start_time = processes[i].getArrival_time();
        }
        else {
            start_time = max(end_time,processes[i].getArrival_time());
        }
        end_time = start_time + processes[i].getBurst_time();
        processes[i].setTurnaround_time( end_time - processes[i].getArrival_time() );
        processes[i].setWaiting_time( processes[i].getTurnaround_time() - processes[i].getBurst_time() );
        schedule.addProcess(processes[i], start_time, end_time);
    }
    return schedule;
}
