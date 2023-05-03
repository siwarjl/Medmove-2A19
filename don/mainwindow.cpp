#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tache.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_12_clicked()
{
    tache t ;
    hide();
    t.exec();
}


