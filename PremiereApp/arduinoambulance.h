#ifndef ARDUINOAMBULANCE_H
#define ARDUINOAMBULANCE_H
#include <QDialog>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include<QDate>
#include "arduino1.h"
namespace Ui {
class arduinoambulance;
}

class arduinoambulance : public QDialog
{
    Q_OBJECT

public:
    explicit arduinoambulance(QWidget *parent = nullptr);
    ~arduinoambulance();
private slots:
    void on_ouvrir_clicked();

    void on_fermer_clicked();
    void serial_read();
        void update_dist(const QString );
        int write_to_arduino( QByteArray ); // envoyer des données vers arduino


private:
        Ui::arduinoambulance *ui;
    QSerialPort *serial;
    QString portname;
    quint16 vendorId;
    quint16 productId;
    bool arduino_available;
    void arduino_init();
    QByteArray serialData;
    QString serialBuffer;

};

#endif // ARDUINOAMBULANCE_H
