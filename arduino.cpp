#include "arduino.h"
#include "ui_arduino.h"
#include<arduino1.h>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QMessageBox>
int nbr1=10;

    //constructeur de la class arduino
arduino::arduino(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::arduino)
{
    ui->setupUi(this);
    serial = new QSerialPort; //Inicializa la variable Serial
    arduino_available = false; //qu'aucune carte compatible n'a été détectée pour le moment.
    serialData="";
    portname="";

    QSqlQuery query;
          query.prepare("DELETE FROM ARDUINO");
           query.exec();

    foreach (const QSerialPortInfo &serial_Info, QSerialPortInfo::availablePorts()) {//Lire les informations de chaque port série
        qDebug()<<"Puerto: "<<serial_Info.portName();
        portname = serial_Info.portName(); //stocke le nom du port série détecté dans la variable portname.
        qDebug()<<"Vendor Id: "<<serial_Info.vendorIdentifier();
        vendorId = serial_Info.vendorIdentifier();
        qDebug()<<"Product Id: "<<serial_Info.productIdentifier(); //de meme
        productId = serial_Info.productIdentifier(); //de meme
        arduino_available = true;
    }
    if(arduino_available){ //si une carte est detectée
        arduino_init();

    }
    if(serial->isReadable()&&(arduino_available)){
         serialData=serial->readAll(); //récupérer les données reçues
         nbr1 --;
         ui->lcdNumber_2->display(nbr1);
         QString d1 = QDateTime::currentDateTime().toString();
         arduino1 a1(nbr1,d1);
         a1.ajouter();
    }

        ui->lcdNumber_2->display(nbr1);

}


       //destructeur de la class arduino
arduino::~arduino()
{
    delete ui;
}

void arduino::arduino_init()
{
    serial->setPortName(portname); // Définit le nom du port série à utiliser
    serial->setBaudRate(QSerialPort::Baud9600);// Définit la vitesse de transmission en bauds
    serial->setDataBits(QSerialPort::Data8); // Définit le nombre de bits de données par trame
    serial->setParity(QSerialPort::NoParity); // Définit le type de parité utilisé
    serial->setStopBits(QSerialPort::OneStop); // Définit le nombre de bits d'arrêt par trame
    serial->setFlowControl(QSerialPort::NoFlowControl); // Définit le type de contrôle de flux utilisé
    serial->open(QIODevice::ReadWrite); // Ouvre le port série en lecture et écriture
    connect(serial,SIGNAL(readyRead()),this,SLOT(serial_read())); // Connecte le signal readyRead() du port série au slot serial_read() de la classe arduino

}


void arduino::on_ouvrir_clicked()
{
    if(serial->isWritable()){
        serial->write("2");  // envoyer des donnés vers Arduino le caractere "2"
            qDebug()<<"ouvrir";
           nbr1 --;
            ui->lcdNumber_2->display(nbr1);
            QString d1 = QDateTime::currentDateTime().toString();
            arduino1 a1(nbr1,d1);
            a1.ajouter();
            if(nbr1==0)
             QMessageBox::information(nullptr, QObject::tr("non dispo"),
                                       QObject::tr("parking complet.\n" "Click Cancel to exit."), QMessageBox::Cancel);


        }
        else {
            QMessageBox::information(nullptr, QObject::tr("non dispo"),
                        QObject::tr("parking complet.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }

}

void arduino::on_fermer_clicked()
{
    if(serial->isWritable()&&(nbr1>0)){
        serial->write("1");
        qDebug()<<"fermer";
        nbr1 --;
        ui->lcdNumber_2->display(nbr1);
        QString d1 = QDateTime::currentDateTime().toString();
        arduino1 a1(nbr1,d1);
        a1.ajouter();
    }
    else{nbr1=10;
        ui->lcdNumber_2->display(nbr1);}


}
    // lecture des données reçues sur le port série de la carte Arduino
void arduino::serial_read()
{
    // Vérifie si le port série est disponible pour la lecture
    if(serial->isWritable() && arduino_available)
    {
        // Lit toutes les données disponibles dans le port série
        serialData = serial->readAll();

        // Convertit les données en chaîne de caractères et les ajoute au tampon
        serialBuffer += QString::fromStdString(serialData.toStdString());

        // Affiche le contenu du tampon sur la console de débogage
        qDebug() << serialBuffer;

        // Traite les données dans la classe arduino en appelant la fonction update_dist() avec le contenu du tampon
        arduino::update_dist(serialBuffer);
    }
}


   //mettre à jour la distance mesurée par un capteur connecté à la carte Arduino.
void arduino::update_dist(const QString sensor_reading)
{
     ui->lcdNumber->display(sensor_reading); // Affiche la valeur de la variable sensor_reading sur un écran LCD
}

int arduino::write_to_arduino( QByteArray d)

{

    if(serial->isWritable()){
        serial->write(d);  // envoyer des donnés vers Arduino
    }else{
        qDebug() << "Couldn't write to serial!";
    }


}

bool arduino1::ajouter()
{
    QString quantite_string=QString::number(nbr1);  // Convertit la variable nbr1 en une chaîne de caractères
    QSqlQuery query; //recuperation de la base avec modifier
          query.prepare("INSERT INTO ARDUINO (nbr, DATE_AJOUT) "
                        "VALUES (:nbr, :DATE_AJOUT)");
          query.bindValue(0, quantite_string); //ajout a la colonne 1
          query.bindValue(1, date_ajout);  //ajout a la colonne 2
          return  query.exec(); // Exécute la requête SQL et renvoie true si l'insertion a réussi, false sinon

}

