#include "arduinoambulance.h"
#include "ui_arduinoambulance.h"
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QMessageBox>
int nbr1=10;

arduinoambulance::arduinoambulance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::arduinoambulance)
{
    ui->setupUi(this);
    serial = new QSerialPort; //Inicializa la variable Serial
    arduino_available = false;
    serialData="";
    portname="";

    QSqlQuery query;
          query.prepare("DELETE FROM ARDUINO");
           query.exec();

    foreach (const QSerialPortInfo &serial_Info, QSerialPortInfo::availablePorts()) {//Lee la información de cada puerto serial
        qDebug()<<"Puerto: "<<serial_Info.portName();
        portname = serial_Info.portName();
        qDebug()<<"Vendor Id: "<<serial_Info.vendorIdentifier();
        vendorId = serial_Info.vendorIdentifier();
        qDebug()<<"Product Id: "<<serial_Info.productIdentifier();
        productId = serial_Info.productIdentifier();
        arduino_available = true;
    }
    if(arduino_available){
        arduino_init();

    }

        ui->lcdNumber_2->display(nbr1);

}

arduinoambulance::~arduinoambulance()
{
    delete ui;
}
void arduinoambulance::arduino_init()
{
    serial->setPortName(portname);
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->open(QIODevice::ReadWrite);
    connect(serial,SIGNAL(readyRead()),this,SLOT(serial_read()));
}
void arduinoambulance::on_ouvrir_clicked()
{
    if(serial->isWritable()){
        serial->write("2");  // envoyer des donnés vers Arduino
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
void arduinoambulance::serial_read()
{
    if((serial->isWritable())&&(arduino_available))
    {
     serialData = serial->readAll();
     serialBuffer +=QString::fromStdString(serialData.toStdString());
        qDebug()<<serialBuffer;
arduinoambulance::update_dist(serialBuffer);

    }
}
void arduinoambulance::update_dist(const QString sensor_reading)
{
     ui->lcdNumber->display(sensor_reading);
}
bool arduino1::ajouter()
{
    QString quantite_string=QString::number(nbr1);
    QSqlQuery query;
          query.prepare("INSERT INTO ARDUINO (nbr, DATE_AJOUT) "
                        "VALUES (:nbr, :DATE_AJOUT)");
          query.bindValue(0, quantite_string);
          query.bindValue(1, date_ajout);
          return  query.exec();

}
