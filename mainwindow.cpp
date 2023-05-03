<<<<<<< HEAD
<<<<<<< HEAD
 #include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include "tache.h"
#include "auth.h"
#include "arduino.h"
#include "ard.h"

=======
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ambulance.h"
#include "tache.h"
>>>>>>> origin/gestionAmbulance
=======
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tache.h"
#include "home.h"
#include "dialog.h"
#include "auth.h"

#include "chatbox.h"
using namespace DuarteCorporation;

>>>>>>> origin/produit
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
<<<<<<< HEAD
<<<<<<< HEAD
    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).
        ard h();
      ui->tableView->setModel( temp.afficher());
}



=======
}

>>>>>>> origin/gestionAmbulance
=======
}

>>>>>>> origin/produit
MainWindow::~MainWindow()
{
    delete ui;
}


<<<<<<< HEAD


<<<<<<< HEAD
void MainWindow::on_pushButton_17_clicked()
{ auth a ;
    hide ();
    a.exec ();

}

void MainWindow::update_label()
{
   QString data=A.read_from_arduino();

        ui->lum->setText(data);
        QString lum = ui->lum->text();



        ard a ( lum);

        bool test = a.ajouter();
         ui->tableView->setModel( a.afficher());


}

void MainWindow::on_pushButton_22_clicked()
{
A.write_to_arduino("1");
}

void MainWindow::on_pushButton_23_clicked()
{
 A.write_to_arduino("2");
}


void MainWindow::on_pushButton_24_clicked()
{

        QString lum = ui->lum->text();



        ard a ( lum);

        bool test = a.ajouter();
        if (test) {
            QMessageBox::information(this, "Ajout réussi", "Le nouvel enregistrement a été ajouté avec succès !");
        } else {
            QMessageBox::warning(this, "Erreur", "Une erreur est survenue lors de l'ajout de l'enregistrement !");
        }   ui->tableView->setModel( a.afficher());

=======

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
>>>>>>> origin/gestionAmbulance
=======
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
>>>>>>> origin/produit
}
