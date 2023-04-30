#include "stat.h"
#include "ui_stat.h"

stat::stat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stat)
{
    ui->setupUi(this);
}

stat::~stat()
{
    delete ui;
}

void stat::on_pb_statistique_2_clicked()
{
    int SA=0;
    int a =A.statistique_E(ui->comboBoxStat->currentText());
     int t=A.statistique_ET();
     SA=(a*100)/t;
     ui->progressBar->setValue(SA);
}
