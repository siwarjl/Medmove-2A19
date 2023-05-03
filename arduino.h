#ifndef ARDUINO_H
#define ARDUINO_H
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> origin/produit
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>


class Arduino
{
public:     //méthodes de la classe Arduino
    Arduino();
    int connect_arduino(); // permet de connecter le PC à Arduino
    int close_arduino(); // permet de femer la connexion
    int write_to_arduino( QByteArray ); // envoyer des données vers arduino
    QByteArray read_from_arduino();  //recevoir des données de la carte Arduino
    QSerialPort* getserial();   // accesseur
    QString getarduino_port_name();
<<<<<<< HEAD
=======
    bool ajouter1();

>>>>>>> origin/produit
private:
QSerialPort * serial; //Cet objet rassemble des informations (vitesse, bits de données, etc.)
//et des fonctions (envoi, lecture de réception,…) sur ce qu’est une voie série pour Arduino.
static const quint16 arduino_uno_vendor_id=9025;
static const quint16 arduino_uno_producy_id=67;
QString arduino_port_name;
bool arduino_is_available;
QByteArray data;  // contenant les données lues à partir d'Arduino
<<<<<<< HEAD
QByteArray data1;
QByteArray data2;

};


=======

#include <QDialog>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include<QDate>
namespace Ui {
class arduino;
}

class arduino : public QDialog
{
    Q_OBJECT

public:
    explicit arduino(QWidget *parent = nullptr);
    ~arduino();



private slots:
    void on_ouvrir_clicked();

    void on_fermer_clicked();
    void serial_read();
        void update_dist(const QString );
        int write_to_arduino( QByteArray ); // envoyer des données vers arduino


private:
    Ui::arduino *ui;
    QSerialPort *serial; //configurer et gérer la communication série avec carte uno
    QString portname; //nom du port série connecté
    quint16 vendorId; // l'ID du vendeur
    quint16 productId;  // l'ID du produit
    bool arduino_available;
    void arduino_init();  //initialise la communication série
    QByteArray serialData; //tableau de bytes qui stocke les données reçues depuis la carte
    QString serialBuffer; //stocke les données reçues depuis la carte et qui sont en train d'être traitées par l'application.
    };
>>>>>>> origin/gestionAmbulance

=======
};

>>>>>>> origin/produit
#endif // ARDUINO_H
