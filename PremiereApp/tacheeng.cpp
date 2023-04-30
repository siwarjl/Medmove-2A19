#include "tacheeng.h"
#include "ui_tacheeng.h"
#include "home.h"
#include "produitang.h"
#include "tache.h"
#include<QMessageBox>
tacheeng::tacheeng(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tacheeng)
{
    ui->setupUi(this);
}

tacheeng::~tacheeng()
{
    delete ui;
}

void tacheeng::on_pushButton_5_clicked()
{
    home h ;
      hide();
      h.exec();
}

void tacheeng::on_pushButton_produit_2_clicked()
{
    produitang p ;
      hide();
      p.exec();
}

void tacheeng::on_pushButton_16_clicked()
{
    tache t ;
      hide();
      t.exec();
}

void tacheeng::on_pushButton_17_clicked()
{
    QMessageBox::warning(this, "traduction", "you are already in english  !");

}
