#ifndef TIME_ENTRY
#define TIME_ENTRY

#include "Process.h"

class TimeEntry {
private:
    Process process;
    float start_time;
    float end_time;

public:
    TimeEntry(Process process, float start_time, float end_time);
    Process getProcess();
    float getStart_time();
    float getEnd_time();
    bool equal(TimeEntry);
};

#endif // TIME_ENTRY
