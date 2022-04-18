#ifndef PROCESSTRAY_H
#define PROCESSTRAY_H

#include <QHBoxLayout>
#include <QMap>

#include "TimeLine.h"

class ProcessTray : public QHBoxLayout
{
    Q_OBJECT

private:
    QMap<QString, QString> colorMap;
    QVector<QString> colors = {"#7EB3FF", "#117243", "#CEFF9D", "#FED876", "#F4EDB2", "#FE9E76", "#FC9A40"};
    int curColor = 0;

public:
    explicit ProcessTray(QWidget *parent = nullptr);

    void drawTimeLine(TimeLine timeline);
};

#endif // PROCESSTRAY_H
