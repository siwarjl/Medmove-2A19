#include "dialog.h"
#include "ui_dialog.h"
#include "smtp.h"
#include <QFileDialog>
#include <QErrorMessage>
#include <QMessageBox>
#include <QDirModel>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->envoyer, SIGNAL(clicked()),this, SLOT(sendMail()));  // Ajouter Boutton
    connect(ui->browse, SIGNAL(clicked()), this, SLOT(browse())); // Ajouter Boutton

}

Dialog::~Dialog()
{
    delete ui;
}

void  Dialog::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );

}

void   Dialog::sendMail()
{
  /*  Smtp* smtp = new Smtp("labesni1@gmail.com", ui->pass->text(), "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail("labesni1@gmail.com", ui->adresseMail->text() , ui->objet->text(),ui->message->toPlainText(), files );
    else
        smtp->sendMail("labesni1@gmail.com", ui->adresseMail->text() , ui->objet->text(),ui->message->toPlainText());*/
    Smtp* smtp = new Smtp("ncib.yasmine@esprit.tn", "ugbwzfbhcymsomdb", "smtp.gmail.com", 465);


    smtp->sendMail("ncib.yasmine@esprit.tn", "ncib.yasmine@esprit.tn" ,"ui->objet->text() ","ui->message->toPlainText()");


}

void   Dialog::mailSent(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
    ui->adresseMail->clear();
    ui->objet->clear();
    ui->file->clear();
    ui->message->clear();
    ui->pass->clear();
}





void Dialog::on_browse_clicked()
{

}

void Dialog::on_envoyer_clicked()
{

}

