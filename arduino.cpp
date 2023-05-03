#include "arduino.h"
<<<<<<< HEAD

Arduino::Arduino()
{
    data="";



    arduino_port_name="";
    arduino_is_available=false;
    serial=new QSerialPort;
}

QString Arduino::getarduino_port_name()
{
    return arduino_port_name;
}

QSerialPort *Arduino::getserial()
{
   return serial;
}
int Arduino::connect_arduino()
{   // recherche du port sur lequel la carte arduino identifée par  arduino_uno_vendor_id
    // est connectée
    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()){
           if(serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier()){
               if(serial_port_info.vendorIdentifier() == arduino_uno_vendor_id && serial_port_info.productIdentifier()
                       == arduino_uno_producy_id) {
                   arduino_is_available = true;
                   arduino_port_name=serial_port_info.portName();
               } } }
        qDebug() << "arduino_port_name is :" << arduino_port_name;
        if(arduino_is_available){ // configuration de la communication ( débit...)
            serial->setPortName(arduino_port_name);
            if(serial->open(QSerialPort::ReadWrite)){
                serial->setBaudRate(QSerialPort::Baud9600); // débit : 9600 bits/s
                serial->setDataBits(QSerialPort::Data8); //Longueur des données : 8 bits,
                serial->setParity(QSerialPort::NoParity); //1 bit de parité optionnel
                serial->setStopBits(QSerialPort::OneStop); //Nombre de bits de stop : 1
                serial->setFlowControl(QSerialPort::NoFlowControl);
                return 0;
            }
            return 1;
        }
        return -1;
}

int Arduino::close_arduino()

{

    if(serial->isOpen()){
            serial->close();
            return 0;
        }
    return 1;


}


 QByteArray Arduino::read_from_arduino()
{
    if(serial->isReadable()){
         data=serial->readAll(); //récupérer les données reçues

         return data;
    }
 }


int Arduino::write_to_arduino( QByteArray d)
=======
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
>>>>>>> origin/gestionAmbulance

{

    if(serial->isWritable()){
        serial->write(d);  // envoyer des donnés vers Arduino
    }else{
        qDebug() << "Couldn't write to serial!";
    }


}
<<<<<<< HEAD
=======

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

>>>>>>> origin/gestionAmbulance
