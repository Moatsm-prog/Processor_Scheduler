#include "Priority_Preemptive.h"

void Priority_Preemptive::addProcess(Process p){
    jobQueue.push(p);
}

Process Priority_Preemptive::getTopProcess(){
    return jobQueue.top();;

}
int Priority_Preemptive::getSize() {return jobQueue.size();}

void Priority_Preemptive::popProcess(){
       jobQueue.pop();
}
