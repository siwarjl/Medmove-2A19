#ifndef PATIENTARDUINO_H
#define PATIENTARDUINO_H

#include <QDialog>
#include "arduino.h"
#include "patientarduinoc.h"

namespace Ui {
class patientarduino;
}

class patientarduino : public QDialog
{
    Q_OBJECT

public:
    explicit patientarduino(QWidget *parent = nullptr);
    ~patientarduino();

private slots:
    void on_pushButton_10_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::patientarduino *ui;
    patientarduinoc p;

    QByteArray data; // variable contenant les données reçues

    Arduino A; // objet temporaire
};

#endif // PATIENTARDUINO_H
