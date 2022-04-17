#include "NonPreemptive.h"

TimeLine NonPreemptive::getTimeLine(vector<Process> processes) {
    TimeLine tl;
    int i = 0;
    int readyPr = 0;
    float lEnd = processes[0].getArrival_time(), end_time, start_time;
    while(i < processes.size() || readyPr != 0) {
        while(readyPr == 0 || (i < processes.size() && processes[i].getArrival_time() <= lEnd)){
               addProcess(processes[i]);
               readyPr++;
               i++;
        }

        Process proc = getTopProcess();
        readyPr--;
        start_time = max(lEnd, proc.getArrival_time());
        end_time = start_time + proc.getBurst_time();
        proc.setWaiting_time(start_time - proc.getArrival_time());
        lEnd = end_time;
        tl.addProcess(proc, start_time, end_time);
    }

    return tl;
}
