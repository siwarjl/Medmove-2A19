#include "tache.h"
#include "ui_tache.h"
<<<<<<< HEAD
#include "mainwindow.h"
#include "employe.h"
#include "auth.h"

=======
#include "ambulance.h"
#include "mainwindow.h"
>>>>>>> origin/gestionAmbulance
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
