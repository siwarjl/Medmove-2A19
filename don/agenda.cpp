#include "agenda.h"
#include "ui_agenda.h"

agenda::agenda(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::agenda)
{
    ui->setupUi(this);
}

agenda::~agenda()
{
    delete ui;
}
