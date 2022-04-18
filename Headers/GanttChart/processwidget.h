#ifndef PROCESSWIDGET_H
#define PROCESSWIDGET_H

#include <QGridLayout>
#include <QLabel>

class ProcessWidget : public QGridLayout
{
    Q_OBJECT

private:
    QLabel *nameLabel;
    QLabel *startLabel;
    QLabel *endLabel;
    QString color;
    float width;

public:
    explicit ProcessWidget(QWidget *parent = nullptr, QString name="GanttChart", QString start="",
                           QString end="", float width=10, QString color="#fff");
    ~ProcessWidget();
};

#endif // PROCESSWIDGET_H
