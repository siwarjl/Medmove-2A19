#ifndef ARDUINO_H
#define ARDUINO_H

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

#endif // ARDUINO_H
