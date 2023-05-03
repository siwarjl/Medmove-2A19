#ifndef AMBULANCE_H
#define AMBULANCE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QDialog>
#include "ambulancec.h"
#include "image.h"
#include <QStandardPaths>
#include <iostream>
#include "statistique.h"
#include "ui_statistique.h"
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
    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_Quitter_clicked();

    void on_pushButton_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_39_clicked();

    void on_pushButton_23_clicked();

    void on_view_activated(const QModelIndex &index);

    void on_pushButton_15_clicked();

    void on_lineEdit_6_cursorPositionChanged(int arg1, int arg2);

    void on_nomrecherche_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_19_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pb_statistique_2_clicked();

    void on_image_linkActivated(const QString &link);

    void on_pushButton_14_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_18_clicked();

    void on_consulter_clicked();

    void on_load_modifier_clicked();

    void on_statistique_clicked();

    void on_tabWidget_currentChanged(int index);

private:
    Ui::Ambulance *ui;
    Ambulancec A;


};

#endif // AMBULANCE_H
