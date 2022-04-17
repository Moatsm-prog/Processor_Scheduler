#include "processwidget.h"

ProcessWidget::ProcessWidget(QWidget *parent, QString name, QString start, QString end, int width, QString color)
    : QGridLayout{parent}
{
    nameLabel = new QLabel();
    startLabel = new QLabel();
    endLabel = new QLabel();
    this->color = color;
    this->width = width;

    nameLabel->setText(name);
    startLabel->setText(start);
    endLabel->setText(end);
    nameLabel->setStyleSheet("QLabel { background-color : "+ color +";}");
    startLabel->setStyleSheet("QLabel { background-color : "+ color +";}");
    endLabel->setStyleSheet("QLabel { background-color : "+ color +";}");

    this->addWidget(nameLabel, 0, 0, 1, 2);
    this->addWidget(startLabel, 1, 0);
    this->addWidget(endLabel, 1, 1);
}
