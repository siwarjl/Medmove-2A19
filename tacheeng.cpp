#include "tacheeng.h"
#include "ui_tacheeng.h"

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
