#include "tache.h"
#include "ui_tache.h"
#include "ambulance.h"
#include "mainwindow.h"
tache::tache(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tache)
{
    ui->setupUi(this);
}

tache::~tache()
{
    delete ui;
}

void tache::on_pushButton_employees_2_clicked()
{
    Ambulance A ;
    hide();
    A.exec();
}

void tache::on_pushButton_2_clicked()
{
    MainWindow *mainWindow = new MainWindow();
       hide();
          mainWindow->show();
}
