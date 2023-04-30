#ifndef AMBULANCE_H
#define AMBULANCE_H
#include"ambulancec.h"
#include <QDialog>
#include "image.h"
#include <QStandardPaths>
#include"statistique.h"
#include "historique.h"
#include "arduinoambulance.h"
namespace Ui {
class Ambulance;
}

class Ambulance : public QDialog
{
    Q_OBJECT

public:
    explicit Ambulance(QWidget *parent = nullptr);
    ~Ambulance();

private slots:
    void on_pushButton_21_clicked();

    void on_Quitter_clicked();

    void on_pushButton_39_clicked();

    void on_pushButton_28_clicked();

    void on_nomrecherche_cursorPositionChanged(int arg1, int arg2);

    void on_view_activated(const QModelIndex &index);

    void on_pushButton_26_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_23_clicked();

    void on_load_modifier_clicked();

    void on_consulter_clicked();

    void on_statistique_clicked();

    void on_arduino_2_clicked();

private:
    Ui::Ambulance *ui;
    Ambulancec A;

};

#endif // AMBULANCE_H
