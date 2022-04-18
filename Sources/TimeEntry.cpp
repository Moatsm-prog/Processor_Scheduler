#include "TimeEntry.h"

TimeEntry::TimeEntry(Process process, float start_time, float end_time): process(process), 
                    start_time(start_time), end_time(end_time){}

Process TimeEntry::getProcess() {
    return process;
}

float TimeEntry::getStart_time(){
    return start_time;
}

float TimeEntry::getEnd_time(){
    return end_time;
}
