#include "TimeLine.h"
#include <stdio.h>

bool TimeLine::addProcess(Process p, float start_time, float end_time){
    if(end_time <= start_time) return 0;
    if(entries.size()){
        TimeEntry lastE = entries.back();
        if(start_time < lastE.getEnd_time()) return 0; 
    }

    entries.push_back(TimeEntry(p, start_time, end_time));
    return 1;
}

void TimeLine::print() {
    for(TimeEntry e : entries){
        Process p = e.getProcess();
        printf("Process:: ID: %i, arrival time: %0.3f, burst time: %0.3f, priority: %i\nstart time: %0.3f, end time: %0.3f"
        ", waiting time: %0.3f\n", 
        p.getProcess_id(), p.getArrival_time(), p.getBurst_time(), p.getPriority(), e.getStart_time(), e.getEnd_time(), p.getWaiting_time());
    }
}

float TimeLine::calcTurnaround(){
    float TotalTurnaround =0;
    int count = 0;
    for(TimeEntry i : entries){
        Process p = i.getProcess();
        if(p.getTurnaround_time() != -1){
            TotalTurnaround += p.getTurnaround_time();
            count++;
        }
    }

    return TotalTurnaround/count;


}

float TimeLine::calcWaiting(){
    float TotalWaiting =0;
    int count = 0;
    for(TimeEntry i : entries){
        Process p = i.getProcess();
        if(p.getWaiting_time() != -1){
            TotalWaiting += p.getWaiting_time();
            count++;
        }
    }

    return TotalWaiting/count;


}

bool TimeLine::equal(TimeLine tl){
    if(tl.entries.size() != entries.size()) return 0;
    for(int i = 0; i < entries.size(); i++){
        if(!entries[i].equal(tl.entries[i])) return 0;
    }
    return 1;
}