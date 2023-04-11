#ifndef PRODUITENG_H
#define PRODUITENG_H
#include"produitc.h"
#include <QDialog>

namespace Ui {
class produiteng;
}

class produiteng : public QDialog
{
    Q_OBJECT

public:
    explicit produiteng(QWidget *parent = nullptr);
    ~produiteng();

private slots:
    void on_pushButton_24_clicked();

    void on_ajout_clicked();

private:
    Ui::produiteng *ui;
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

#endif // PRODUITENG_H
