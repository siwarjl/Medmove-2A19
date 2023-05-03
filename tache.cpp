#include "tache.h"
#include "ui_tache.h"
<<<<<<< HEAD
<<<<<<< HEAD
#include "mainwindow.h"
#include "employe.h"
#include "auth.h"

=======
#include "ambulance.h"
#include "mainwindow.h"
>>>>>>> origin/gestionAmbulance
=======
#include "mainwindow.h"
#include"produit.h"
#include"employe.h"

>>>>>>> origin/produit
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

<<<<<<< HEAD
<<<<<<< HEAD
void tache::on_pushButton_clicked()
{
     MainWindow *mainWindow = new MainWindow();
        hide();
           mainWindow->show();


=======
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
>>>>>>> origin/produit
}

void tache::on_pushButton_employees_4_clicked()
{
<<<<<<< HEAD

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


=======
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
>>>>>>> origin/gestionAmbulance
=======
    employe e ;
    hide ();
    e.exec ();
}
>>>>>>> origin/produit
