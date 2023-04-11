#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include "tache.h"
#include "auth.h"

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



void MainWindow::on_pushButton_17_clicked()
{ auth a ;
    hide ();
    a.exec ();

}
