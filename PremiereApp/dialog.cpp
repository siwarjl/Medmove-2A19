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

void Dialog::sendMail()
{
    Smtp* smtp = new Smtp("bejaoui.ahmed@esprit.tn", "211JMT6409", "smtp.gmail.com", 465);


    smtp->sendMail("bejaoui.ahmed@esprit.tn", "bejaoui.ahmed@esprit.tn" ," esm el message li hachtek bih","w el message li teb tektbou");
}



void Dialog::on_browse_clicked()
{

}

void Dialog::on_envoyer_clicked()
{

}
