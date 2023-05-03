#ifndef PRODUIT_H
#define PRODUIT_H

#include <QDialog>

#include"produitc.h"


namespace Ui {
class produit;
}

class produit : public QDialog
{
    Q_OBJECT

public:
    explicit produit(QWidget *parent = nullptr);
    ~produit();

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_ajout_clicked();

    void on_ajout_4_clicked();

    void on_ajout_3_clicked();

    void on_view_activated(const QModelIndex &index);

    void on_pushButton_20_clicked();

    void on_pushButton_15_clicked();

    void on_nomrecherche_textChanged(const QString &arg1);

    void on_pushButton_13_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_34_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_35_clicked();

    void on_nomrecherche_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_19_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_36_clicked();

    void on_pushButton_23_clicked();

private:
    Ui::produit *ui;
    produitc p1;
    int n0=0;
    int n1=1;
    int n2=2;
    int n3=3;
    int n4=4;
    int n5=5;
    int n6=6;
    int n7=7;
    int n8=8;
    int n9=9;




};

#endif // PRODUIT_H
