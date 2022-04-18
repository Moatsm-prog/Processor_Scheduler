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
    explicit ProcessWidget(QWidget *parent = nullptr, QString name="---", QString start="0",
                           QString end="0", float width=10, QString color="#fff");

};

#endif // PROCESSWIDGET_H
