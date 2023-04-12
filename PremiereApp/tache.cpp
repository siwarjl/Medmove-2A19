#include "tache.h"
#include "ui_tache.h"
#include "mainwindow.h"
#include "client.h"
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

void tache::on_pushButton_clicked()
{
    MainWindow *mainWindow = new MainWindow();
       hide();
          mainWindow->show();
}

void tache::on_pushButton_client_2_clicked()
{
    client c;
     hide();
     c.exec();
}
