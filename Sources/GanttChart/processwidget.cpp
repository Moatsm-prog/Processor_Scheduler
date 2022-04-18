#include "processwidget.h"

ProcessWidget::ProcessWidget(QWidget *parent, QString name, QString start, QString end, float width, QString color)
    : QGridLayout{parent}
{
    nameLabel = new QLabel();
    startLabel = new QLabel();
    endLabel = new QLabel();
    this->color = color;
    this->width = width;
    nameLabel->setMinimumHeight(60);
    startLabel->setMinimumHeight(60);
    endLabel->setMinimumHeight(60);

    nameLabel->setText(name);
    startLabel->setText(start);
    endLabel->setText(end);
    nameLabel->setStyleSheet("QLabel { background-color : "+ color +";font-weight: bold; font-size:15pt;}");
    startLabel->setStyleSheet("QLabel {font-size:12pt;}");
    endLabel->setStyleSheet("QLabel {font-size:12pt;}");

    this->addWidget(nameLabel, 0, 0, 1, 2);
    this->addWidget(startLabel, 1, 0);
    this->addWidget(endLabel, 1, 1);

    //Allignment
    nameLabel->setAlignment(Qt::AlignCenter);
    startLabel->setAlignment(Qt::AlignLeft);
    endLabel->setAlignment(Qt::AlignRight);
    setSpacing(0);
}

ProcessWidget::~ProcessWidget() {
    delete nameLabel;
    delete startLabel;
    delete endLabel;
}
