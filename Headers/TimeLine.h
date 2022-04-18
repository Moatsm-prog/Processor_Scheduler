#ifndef TIMELINE_H
#define TIMELINE_H

#include "Process.h"
#include "TimeEntry.h"

#include <vector>

using namespace std;

class TimeLine {
private:
    vector<TimeEntry> entries;
public:
    bool addProcess(Process p, float start_time, float end_time);

    void print();

    float calcTurnaround();

    float calcWaiting();

    friend class ProcessTray;
};

#endif
