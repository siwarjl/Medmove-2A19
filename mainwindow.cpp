#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ambulance.h"
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
    tache T ;
    hide();
    T.exec();
}


void MainWindow::on_pushButton_2_clicked()
{
    MainWindow *mainWindow = new MainWindow();
       hide();
          mainWindow->show();
}
