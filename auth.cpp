#include "auth.h"
#include "ui_auth.h"
#include "tache.h"
#include "mainwindow.h"

auth::auth(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::auth)
{
    ui->setupUi(this);
}

auth::~auth()
{
    delete ui;
}







void auth::on_pushButton_30_clicked()
{
    QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this,"Emna","Are you sure you wanna close the application?",QMessageBox::Yes |QMessageBox::No)
     ;
        if(reply==QMessageBox::Yes)
        {QApplication::quit();
      }

}

void auth::on_pushButton_31_clicked()
{ QString username =ui->username->text();
    QString password =ui->password->text();
    if(username=="emna"&& password=="123*")
    {QMessageBox::information(this,"Emna","Login successful");
        tache t ;
        hide ();
        t.exec ();

}else
    { QMessageBox::warning(this,"Emna","please enter valid username or password");}


}

void auth::on_pushButton_11_clicked()
{  MainWindow *mainWindow = new MainWindow();
    hide();
       mainWindow->show();


}
