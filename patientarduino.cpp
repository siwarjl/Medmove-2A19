#include "patientarduino.h"
#include "ui_patientarduino.h"
#include "arduino.h"
#include "patientarduinoc.h"

patientarduino::patientarduino(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::patientarduino)
{
    ui->setupUi(this);
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
    /*********/


    QString datee = ui->datee->text();
    QString nom = ui->nom->text();
    QString coeur = ui->coeur->text();

    //QString prix = ui->prix->text();
    patientarduinoc p(datee,nom,coeur);
      ui->view->setModel(p.afficher());
}

patientarduino::~patientarduino()
{
    delete ui;
}

void patientarduino::on_pushButton_10_clicked()
{
    QString nom = ui->nom->text();
       QString datee = ui->datee->text();
       QString coeur = ui->coeur->text();


      patientarduinoc p(nom,datee,coeur);


      bool test = p.ajouter();
      if (test) {
          // ui->listView->setModel(p.afficher());

      ui->view->setModel(p.afficher());
       ui->nom->clear();
        ui->datee->clear();
         ui->coeur->clear();   }
}








void patientarduino::on_pushButton_clicked()
{
     A.write_to_arduino("1");
}

void patientarduino::on_pushButton_2_clicked()
{
  A.write_to_arduino("0");
}
