#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tache.h"
#include "home.h"

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

void MainWindow::on_pushButton_17_clicked()
{
    home h;
    hide();
    h.exec();
}
