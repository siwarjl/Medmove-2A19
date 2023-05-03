#include "produite.h"
#include "ui_produite.h"

produite::produite(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::produite)
{
    ui->setupUi(this);
}

produite::~produite()
{
    delete ui;
}
