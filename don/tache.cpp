#include "tache.h"
#include "ui_tache.h"
#include"dons.h"
tache::tache(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tache)
{
    ui->setupUi(this);
}

tache::~tache()
{
    delete ui;
}

void tache::on_pushButton_dons_3_clicked()
{
     Dons d ;
    hide();
    d.exec();
}


