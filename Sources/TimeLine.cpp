#include "TimeLine.h"
#include <stdio.h>

bool TimeLine::addProcess(Process p, float start_time, float end_time){
    if(entries.size()){
        Entry lastE = entries.back();
        if(start_time < lastE.end_time || end_time <= start_time) return 0; 
    }
    entries.push_back({p, start_time, end_time});
    return 1;
}

void TimeLine::print() {
    for(Entry e : entries){
        Process p = e.process;
        printf("Process:: ID: %i, arrival time: %0.3f, burst time: %0.3f, priority: %i\nstart time: %0.3f, end time: %0.3f"
        ", waiting time: %0.3f\n", 
        p.getProcess_id(), p.getArrival_time(), p.getBurst_time(), p.getPriority(), e.start_time, e.end_time, p.getWaiting_time());
    }
}