#include "processtray.h"
#include "processwidget.h"

#include "qdebug.h"

#include "random"
#include <ctime>

ProcessTray::ProcessTray(QWidget *parent)
    : QHBoxLayout{parent}
{

}

void ProcessTray::drawTimeLine(TimeLine timeline) {
    printf("dddddddddddddddddd\n");
    timeline.print();
    printf("dddddddddddddddddd\n");
    for(TimeEntry entry : timeline.entries){
        Process proc = entry.getProcess();
        QString name = "p" + QString::number(proc.getProcess_id());
        QString start = QString::number(entry.getStart_time());
        QString end = QString::number(entry.getEnd_time());
        float width = proc.getBurst_time();

        QString color;
        auto it = colorMap.find(name);
        if(it == colorMap.end()){
            colorMap[name] = colors[curColor++];
        }
        color = colorMap[name];

        ProcessWidget *procWidget = new ProcessWidget(nullptr,
                                 name, start, end, width, color);

        this->addLayout(procWidget);
    }
}
