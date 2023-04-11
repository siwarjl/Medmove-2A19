#include "home.h"
#include "ui_home.h"
#include "mainwindow.h"

home::home(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::home)
{
    ui->setupUi(this);
}

home::~home()
{
    delete ui;
}

void home::on_pushButton_16_clicked()
{
    MainWindow *mainwindow = new MainWindow() ;
    hide();
    mainwindow->show();
}
