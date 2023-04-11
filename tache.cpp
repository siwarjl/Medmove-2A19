#include "tache.h"
#include "ui_tache.h"
#include "mainwindow.h"
#include "employe.h"
#include "auth.h"

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

void tache::on_pushButton_clicked()
{
     MainWindow *mainWindow = new MainWindow();
        hide();
           mainWindow->show();


}

void tache::on_pushButton_employees_4_clicked()
{

        employe e ;
        hide ();
        e.exec ();

}

void tache::on_pushButton_8_clicked()
{
    auth a ;
    hide ();
    a.exec ();
}


