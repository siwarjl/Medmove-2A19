#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tache.h"
#include "home.h"
#include "dialog.h"
#include "auth.h"

#include "chatbox.h"
using namespace DuarteCorporation;

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
  /* tache t ;
    hide();
    t.exec();*/
    auth a ;
    hide ();
    a.exec ();
}

void MainWindow::on_pushButton_17_clicked()
{
    home h;
    hide();
    h.exec();
}

void MainWindow::on_chatbox_clicked()
{
  chatbox ch;
  ch.exec();
}

void MainWindow::on_pushButton_clicked()
{
   Dialog d;
   d.exec();
}
