#include "statistic.h"
#include "ui_statistic.h"
#include "produit.h"
#include "ui_produit.h"

statistic::statistic(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistic)
{
    ui->setupUi(this);
}

statistic::~statistic()
{
    delete ui;
}

void statistic::on_pb_statistique_2_clicked()
{

    int SA=0;
    int a =p1.statistique_E(ui->comboBoxStat->currentText());
     int t=p1.statistique_ET();
     SA=(a*100)/t;
     ui->progressBar->setValue(SA);
}
