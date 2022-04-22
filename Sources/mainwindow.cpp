#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "FCFS.h"
#include "RoundRobin.h"
#include "Priority_NonPreemptive.h"
#include "Priority_Preemptive.h"
#include "SJF_NonPreemptive.h"
#include "SJF_Preemptive.h"
#include "processtray.h"
#include <QVector>
#include <QRegion>
#include <QTableWidget>
#include <QTableWidgetItem>
#include "qdebug.h"

int counter = 1;
vector<Process> memory;
float arrivalTime;
float burstTime;
int priority;
float QuantumTime;
int row = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Arrival->setDisabled(true);
    ui->Burst->setDisabled(true);
    ui->Priority->setDisabled(true);
    ui->Quantum->setEnabled(false);
    ui->AddProcess->setEnabled(false);
    ui->GanttChart->setDisabled(true);
    ui->label_5->setStyleSheet("background-color: white ; border: 1px solid");
    ui->label_7->setStyleSheet("background-color: white ; border: 1px solid");

    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setRowCount(0);
    QStringList hLabels;
    hLabels << "Process ID" << "Arrival Time" << "Burst Time" << "Priority";
    ui->tableWidget->setHorizontalHeaderLabels(hLabels);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setVisible(false);
    clearGranttTray();
}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{

    counter = 1;
    ui->AddProcess->setEnabled(false);
    ui->Arrival->setValue(0.00);
    ui->Burst->setValue(0.00);
    ui->Priority->setValue(0);
    ui->Quantum->setValue(0.00);
    ui->GanttChart->setEnabled(true);
    memory.clear();
    ui->label_5->clear();
    ui->label_7->clear();
    ui->tableWidget->clearContents();
    row = 0;
    ui->tableWidget->setRowCount(row);

    if(index == 0){
        ui->Arrival->setValue(0.00);
        ui->Burst->setValue(0.00);
        ui->Priority->setValue(0);
        ui->Quantum->setValue(0.00);
        ui->Arrival->setDisabled(true);
        ui->Burst->setDisabled(true);
        ui->Priority->setDisabled(true);
        ui->Quantum->setEnabled(false);
        ui->AddProcess->setEnabled(false);
        ui->GanttChart->setDisabled(true);

    }
    else if(index == 1 || index == 3 || index == 4){
        ui->Arrival->setDisabled(false);
        ui->Burst->setDisabled(false);
        ui->Priority->setDisabled(true);
        ui->Quantum->setEnabled(false);
    }

    else if(index == 2){
        ui->Arrival->setDisabled(false);
        ui->Burst->setDisabled(false);
        ui->Priority->setDisabled(true);
        ui->Quantum->setEnabled(true);
    }

    else if(index == 5 || index == 6){
        ui->Arrival->setDisabled(false);
        ui->Burst->setDisabled(false);
        ui->Priority->setDisabled(false);
        ui->Quantum->setEnabled(false);
    }
}




void MainWindow::on_Burst_valueChanged(double arg1)
{
    int i = ui->comboBox->currentIndex();
    if(arg1 == 0){
        ui->AddProcess->setEnabled(false);
    }
    else if((i  != 0 && i != 2) && arg1 > 0.0){
        ui->AddProcess->setEnabled(true);
    }
    else if(i == 2 && arg1 > 0.0 && ui->Quantum->value() > 0.0){
        ui->AddProcess->setEnabled(true);
    }
}




void MainWindow::on_Quantum_valueChanged(double arg1)
{
    int i = ui->comboBox->currentIndex();
    if(i == 2 && arg1 == 0){
        ui->AddProcess->setEnabled(false);
    }
    else if(i == 2 && arg1 > 0.0 && ui->Burst->value() > 0.0){
        ui->AddProcess->setEnabled(true);
    }
}



void MainWindow::on_AddProcess_clicked()
{
    arrivalTime = ui->Arrival->value();
    burstTime = ui->Burst->value();
    priority = ui->Priority->value();
    QuantumTime = ui->Quantum->value();

    Process item = Process(counter, arrivalTime, burstTime, priority);
    memory.push_back(item);
    ui->tableWidget->insertRow(row);
    QTableWidgetItem *tableItem;
    for(int i = 0; i < 4; i++){
        tableItem = new QTableWidgetItem;
        if(i == 0) tableItem->setText(QString::number(counter));
        else if(i == 1) tableItem->setText(QString::number(item.getArrival_time()));
        else if(i == 2) tableItem->setText(QString::number(item.getBurst_time()));
        else tableItem->setText(QString::number(item.getPriority()));

        tableItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
        tableItem->setTextAlignment(Qt::AlignHCenter);
        ui->tableWidget->setItem(row, i, tableItem);
    }
    row++;
    counter++;

    if(ui->comboBox->currentIndex() == 2) ui->Quantum->setEnabled(false);
    ui->AddProcess->setEnabled(false);
    ui->Arrival->setValue(0.00);
    ui->Burst->setValue(0.00);
    ui->Priority->setValue(0);
    ui->GanttChart->setEnabled(true);
}


void MainWindow::on_GanttChart_clicked()
{
    Algorithm *algo;
    TimeLine scheduler;
    int index = ui->comboBox->currentIndex();
    switch(index){
        case 1:
            algo = new FCFS();
            scheduler = algo->applyAlgorithm(memory);
            break;
        case 2:
            algo = new RoundRobin();
            scheduler = algo->applyAlgorithm(memory, QuantumTime);
            break;
        case 3:
            algo = new SJF_NonPreemptive();
            scheduler = algo->applyAlgorithm(memory);
            break;
        case 4:
            algo = new SJF_Preemptive();
            scheduler = algo->applyAlgorithm(memory);
            break;
        case 5:
            algo = new Priority_NonPreemptive();
            scheduler = algo->applyAlgorithm(memory);
            break;
        case 6:
            algo = new Priority_Preemptive();
            scheduler = algo->applyAlgorithm(memory);
            break;
        default:
            break;
    }
    ui->label_5->setText(QString::number((scheduler.calcWaiting())));
    ui->label_7->setText(QString::number((scheduler.calcTurnaround())));
    ProcessTray *tray = new ProcessTray();
    tray->drawTimeLine(scheduler);

    QLayoutItem* item = ui->ganttchart_layout->takeAt(0);
    if(item){
        delete item;
    }

    ui->ganttchart_layout->addLayout(tray);
}


void MainWindow::on_Reset_clicked()
{
    memory.clear();
    counter = 1;
    ui->Arrival->setValue(0.00);
    ui->Burst->setValue(0.00);
    ui->Priority->setValue(0);
    ui->Quantum->setValue(0.00);
    ui->GanttChart->setEnabled(false);
    ui->comboBox->setCurrentIndex(0);
    ui->label_5->clear();
    ui->label_7->clear();
    ui->tableWidget->clearContents();
    row = 0;
    ui->tableWidget->setRowCount(row);
    clearGranttTray();
}

void MainWindow::clearGranttTray(){
    QLayoutItem* item = ui->ganttchart_layout->takeAt(0);
    if(item){
        delete item;
    }
    ui->ganttchart_layout->update();
    ProcessWidget *holder = new ProcessWidget();
    ProcessTray *tray = new ProcessTray();
    tray->addLayout(holder);
    ui->ganttchart_layout->addLayout(tray);
}
