#include "SJF_Preemptive.h"

void SJF_Preemptive::addProcess(Process p){
    jobQueue.push(p);
}
Process SJF_Preemptive::getTopProcess(){
    return jobQueue.top();

}
int SJF_Preemptive::getSize() {return jobQueue.size();}
void SJF_Preemptive::popProcess(){
       jobQueue.pop();
}
