#include "mainwindow.h"
#include "ui_mainwindow.h"
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
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if(index == 1 || index == 3 || index == 4){
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
    if(arg1 == 0){
        ui->AddProcess->setEnabled(false);
    }
    else if(i == 2 && arg1 > 0.0 && ui->Burst->value() > 0.0){
        ui->AddProcess->setEnabled(true);
    }
}



void MainWindow::on_AddProcess_clicked()
{

    ui->AddProcess->setEnabled(false);
    ui->Arrival->setValue(0.00);
    ui->Burst->setValue(0.00);
    ui->Priority->setValue(0);
    ui->Quantum->setValue(0.00);
    ui->GanttChart->setEnabled(true);


}


void MainWindow::on_GanttChart_clicked()
{
    ui->AddProcess->setEnabled(false);
    ui->Arrival->setValue(0.00);
    ui->Burst->setValue(0.00);
    ui->Priority->setValue(0);
    ui->Quantum->setValue(0.00);
    ui->GanttChart->setEnabled(false);
    ui->comboBox->setCurrentIndex(0);
}

