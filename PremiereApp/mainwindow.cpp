#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include "patient.h"
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




void MainWindow::on_pushButton_11_clicked()
{
   tache t;
    hide();
    t.exec();
}
