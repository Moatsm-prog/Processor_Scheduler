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

bool TimeEntry::equal(TimeEntry t){
    if(this->process.equal(t.getProcess()) && this->start_time == t.getStart_time() && this->end_time == t.getEnd_time()){
        return true;
    } else {
        return false;
    }
}
