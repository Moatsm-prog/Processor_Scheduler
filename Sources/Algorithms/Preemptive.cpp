#include"Algorithm.h"
#include<vector>
#include<QtGlobal>


TimeLine Preemptive::getTimeLine(vector<Process> processes, float quantumTime = 0) {
    TimeLine schedule = *(new TimeLine());
    int len = processes.size();
    int remaining = len;
    int j = 0;
    float start;
    float end;
    float nextTime, startTime, last_end;
    float total_waiting = 0;
    float total_turnAround = 0;
    Process current, lastProc;
    int flag = 0;
    while (j < len && processes[j].getArrival_time() == 0) {
        addProcess(processes[j++]);
    }
    if (j > 0){
        current = getTopProcess();
    }
    int last_id = -1, cur_id;
    for (float time = 0; remaining > 0;time = nextTime) {

        if (getSize()!=0) {
            if(flag != current.getProcess_id()){
                flag = current.getProcess_id();
                end = nextTime;
            }
            else{
                end = nextTime;
            }
            current = getTopProcess();
            
            
            popProcess();
            flag = current.getProcess_id();
            float x;
            if (j >= len) x = INT64_MAX;
            else x = processes[j].getArrival_time();
            float y = time + (current).getBurst_time();
            nextTime = min(x, y);
            int burst = (current).getBurst_time();
            (current).setBurst_time(burst - nextTime + time);
            if (burst - nextTime + time > 0)
            {
                addProcess(current);
                cur_id = current.getProcess_id();
                if(last_id == -1){
                    startTime = time;
                }
                else if(last_id != cur_id){
                    schedule.addProcess(lastProc, startTime, last_end);
                    last_id = -1;
                    startTime = time;
                }
                lastProc = current;
                last_id = cur_id;
                last_end = nextTime;
            }
            else {
                (current).setTurnaround_time(nextTime - current.getArrival_time());
                total_turnAround += current.getTurnaround_time();
                (current).setWaiting_time((current).getTurnaround_time() - current.getTotal_Burst_time());
                total_waiting += current.getWaiting_time();

                cur_id = current.getProcess_id();
                if(last_id == -1){
                    startTime = time;
                }
                else if(last_id != cur_id){
                    schedule.addProcess(lastProc, startTime, last_end);
                    last_id = -1;
                    startTime = time;
                }
                lastProc = current;
                last_id = cur_id;
                last_end = nextTime;
                remaining--;
            }



        }
        else {
            nextTime = processes[j].getArrival_time();
            schedule.addProcess(*(new Process(-1, 0, 0, 0)), time, nextTime);

        }

        if (nextTime == processes[j].getArrival_time()) addProcess(processes[j++]);
    }
    schedule.addProcess(lastProc, startTime, last_end);
    schedule.print();
    //schedule.setAvgTurnaround(total_turnAround / len);
    //schedule.setAvgWaiting(total_waiting / len);
    //cout << "Average TurnAround:" + to_string(total_turnAround / len) << "\n";
    //cout << "Average Waiting:" + to_string(total_waiting / len) << "\n";
    return schedule;
}

