#include "processtray.h"

#include "qdebug.h"

#include "random"
#include <ctime>

ProcessTray::ProcessTray(QWidget *parent)
    : QHBoxLayout{parent}
{

}

ProcessTray::~ProcessTray()
{
    QLayoutItem *child;
    while ((child = this->takeAt(0)) != nullptr) {
        delete child->widget(); // delete the widget
        delete child;   // delete the layout item
    }
}

void ProcessTray::drawTimeLine(TimeLine timeline) {
    printf("dddddddddddddddddd\n");
    timeline.print();
    printf("dddddddddddddddddd\n");

    if(!timeline.entries.size()) return;

    if(timeline.entries[0].getStart_time()){
        this->addLayout(getIdleProcess(0, timeline.entries[0].getStart_time()));
    }
    this->addLayout(getProcessWidget(timeline.entries[0]));
    for(int i =1; i < (int) timeline.entries.size(); i++){
        if(timeline.entries[i].getStart_time() != timeline.entries[i-1].getEnd_time()){
            this->addLayout(getIdleProcess(
                                timeline.entries[i-1].getEnd_time(), timeline.entries[i].getStart_time()));
        }
        TimeEntry entry = timeline.entries[i];
        this->addLayout(getProcessWidget(entry));
    }
}

ProcessWidget* ProcessTray::getIdleProcess(float start, float end) {
    return new ProcessWidget(nullptr,
                             "idle", QString::number(start), QString::number(end), end-start, "#5BFF62");
}

ProcessWidget *ProcessTray::getProcessWidget(TimeEntry entry) {
    Process proc = entry.getProcess();
    QString name = "p" + QString::number(proc.getProcess_id());
    QString start = QString::number(entry.getStart_time());
    QString end = QString::number(entry.getEnd_time());
    float width = proc.getBurst_time();

    QString color;
    auto it = colorMap.find(name);
    if(it == colorMap.end()){
        colorMap[name] = colors[curColor++%colors.size()];
    }
    color = colorMap[name];

    ProcessWidget *procWidget = new ProcessWidget(nullptr,
                             name, start, end, width, color);
    return procWidget;
}
