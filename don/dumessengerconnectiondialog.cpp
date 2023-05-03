#include "dumessengerconnectiondialog.h"
#include "ui_dumessengerconnectiondialog.h"
namespace DuarteCorporation {

DUMessengerConnectionDialog::DUMessengerConnectionDialog(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::DUMessengerConnectionDialog)
{
    ui->setupUi(this);
}

DUMessengerConnectionDialog::~DUMessengerConnectionDialog()
{
    delete ui;
}

void DUMessengerConnectionDialog::on_ok_clicked()
{
    mHostname = ui->hostname->text();
    mPort = ui->puerto->value();
    accept();
}

void DUMessengerConnectionDialog::on_cancel_clicked()
{
    reject();
}
}
