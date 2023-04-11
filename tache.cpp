#include "tache.h"
#include "ui_tache.h"
#include "mainwindow.h"
#include"produit.h"
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

void tache::on_pushButton_5_clicked()
{
    MainWindow *mainwindow = new MainWindow() ;
    hide();
    mainwindow->show();
}

void tache::on_pushButton_produit_2_clicked()
{
   produit p ;
     hide();
     p.exec();
}
