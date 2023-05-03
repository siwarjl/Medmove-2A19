#include "client.h"
#include "ui_client.h"
#include "mainwindow.h"
#include "patient.h"
#include <QPixmap>
#include <QDateTime>
#include <QMessageBox>
#include <QPrinter>
#include <QPainter>
#include <QLabel>
#include <QColor>
#include <QPrintDialog>
#include <QFileDialog>
#include<QDebug>
#include "connection.h"
#include "tache.h"
#include "stat_combop.h"
#include "smtp.h"
client::client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::client)
{
    ui->setupUi(this);
    ui->cinc->setValidator(new QIntValidator(0,99999999, this));
    ui->cinc_3->setValidator(new QIntValidator(0,99999999, this));
    ui->numc->setValidator(new QIntValidator(0,99999999, this));
    ui->numc_3->setValidator(new QIntValidator(0,99999999, this));
        QRegExp regExppp("^[A-Za-z]*$"); // Autorise uniquement les majuscules et les chiffres
        ui->nomc->setValidator(new QRegExpValidator(regExppp, this));
        ui->prenomc->setValidator(new QRegExpValidator(regExppp, this));
        ui->etatc->setValidator(new QRegExpValidator(regExppp, this));
        ui->nomc_3->setValidator(new QRegExpValidator(regExppp, this));
        ui->prenomc_3->setValidator(new QRegExpValidator(regExppp, this));
        ui->etatc_3->setValidator(new QRegExpValidator(regExppp, this));

        connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
        connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));
}

client::~client()
{
    delete ui;
}



void client::on_pushButton_33_clicked()
{
    int cin = ui->cinc->text().toInt();
        QString nom = ui->nomc->text();
        QString prenom = ui->prenomc->text();
        int age = ui->agec->text().toInt();
         QString adresse = ui->adressec->text();
         int num = ui->numc->text().toInt();
         QString mail = ui->mailc->text();
         QString etat = ui->etatc->currentText();

        patient p (cin, nom, prenom,age,adresse,num,mail,etat);

        bool test = p.ajouter();
        if (test) {
            ui->liste->setModel(p.afficher());
            QMessageBox::information(this, "Ajout réussi", "Le nouvel enregistrement a été ajouté avec succès !");
        } else {
            QMessageBox::warning(this, "Erreur", "Une erreur est survenue lors de l'ajout de l'enregistrement !");
        }
}

void client::on_pushButton_2_clicked()
{
    MainWindow *mainWindow = new MainWindow();
       hide();
          mainWindow->show();
}

void client::on_pushButton_4_clicked()
{
    tache t;
     hide();
     t.exec();
}

void client::on_pushButton_40_clicked()
{
    int cin = ui->cinc_3->text().toInt();
        QString nom = ui->nomc_3->text();
        QString prenom = ui->prenomc_3->text();
        int age = ui->agec_3->text().toInt();
         QString adresse = ui->adressec_3->text();
         int num = ui->numc_3->text().toInt();
         QString mail = ui->mailc_3->text();
         QString etat = ui->etatc_3->text();
         patient p (cin, nom, prenom,age,adresse,num,mail,etat);

        bool test=p.modifier();
        if(test){
            ui->liste->setModel(p.afficher());
}
}

void client::on_pushButton_41_clicked()
{
    int cin = ui->cinc_4->text().toInt();

   bool test=p1.supprimer(cin);
   if (test) {
       ui->liste->setModel(p1.afficher());
      // QMessageBox::information(this, "suppression réussi", "Le nouvel enregistrement a été supprimer avec succès !");
          }
   else


       QMessageBox::warning(this, "Erreur", "Une erreur est survenue lors de la supprition de l'enregistrement !");
     }

void client::on_liste_activated(const QModelIndex &index)
{
    QString val=ui->liste->model()->data(index).toString();
        QSqlQuery qry;
        qry.prepare("select * from PATIENTC where nom='"+val+"'");
        if(qry.exec())
        {
            while(qry.next())
            {
             ui->cinc_3->setText(qry.value(0).toString());
                      ui->nomc_3->setText(qry.value(1).toString());
                      ui->prenomc_3->setText(qry.value(2).toString());
                      ui->agec_3->setText(qry.value(3).toString());
                       ui->adressec_3->setText(qry.value(4).toString());
                        ui->numc_3->setText(qry.value(5).toString());
                         ui->mailc_3->setText(qry.value(6).toString());
                          ui->etatc_3->setText(qry.value(7).toString());

            }

        }

        else
        {
            QMessageBox::critical(this,tr("error::"),qry.lastError().text());
        }
        qry.prepare("select * from PATIENTC where cin='"+val+"'");
        if(qry.exec())
        {
            while(qry.next())
            {
             ui->cinc_4->setText(qry.value(0).toString());
}}}

void client::on_recherche_cursorPositionChanged(int arg1, int arg2)
{
    int cin=ui->cinc_3->text().toInt();
        QString nom=ui->nomc_3->text();
        QString prenom=ui->prenomc_3->text();
         int age=ui->agec_3->text().toInt();
        QString adresse=ui->adressec_3->text();
         int num=ui->num_3->text().toInt();
          QString mail=ui->mailc_3->text();
        QString etat=ui->etatc_3->text();

       patient p(cin,nom,prenom,age,adresse,num,mail,etat);
        ui->liste->setModel( p.recherche(ui->recherche->text()));
}

void client::on_tri_clicked()
{
     ui->liste->setModel( p1.afficher_tri());
     QString type_tri = "cin";
         //QString test_ordre ="croissant" ;
         type_tri = ui->comboBox->currentText();
         //test_ordre = ui->comboBox_ordre->currentText() ;

             if (type_tri == "cin")

             ui->liste->setModel(p1.tricroissant_cin());
             if (type_tri == "nom")

             ui->liste->setModel(p1.tricroissant_nom());
             if (type_tri == "age")

             ui->liste->setModel(p1.tricroissant_age());}






void client::on_pushButton_37_clicked()
{
    patient s;
            QString text = s.apercupdf();
            ui->textEdit->setText(text);

            QPrinter printer;
            printer.setPrinterName("imprimer");
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setOutputFileName("C:/Users/abeja/Documents/patient.pdf");
            printer.setFullPage(true);

            QTextDocument doc;
            doc.setHtml(text);

            QPainter painter;
            painter.begin(&printer);

            // Draw the logo at the top right of the page
            painter.drawPixmap(QRect(800, -45, 200, 200), QPixmap("C:/Users/abeja/Documents/logo.png"));

            // Center the title horizontally
            QString title = "LA LISTE DES PATIENTS";
            QFont titleFont("Arial", 20, QFont::Bold);
            QFontMetrics titleMetrics(titleFont);
            int titleWidth = titleMetrics.width(title);
            int titleX = (printer.pageRect().width() - titleWidth) / 2;
            painter.setFont(titleFont);
            painter.drawText(titleX, 70, title);

            // Calculate the position of the table to center it horizontally
            int tableWidth = doc.size().width() * 1.2;
            int tableX = ((printer.pageRect().width() - tableWidth) / 2) + 74;

            // Draw the text (including the table) on the page
            painter.translate(tableX, 0);
            doc.setPageSize(QSize(tableWidth, INT_MAX));
            doc.drawContents(&painter);

            painter.end();
}

/*void client::on_pushButton_39_clicked()
{
    ui->progressBar->setValue(0);
}*/






void client::on_pushButton_38_clicked()
{
    patient p;
                   QSqlQueryModel * model=new QSqlQueryModel();
                     model=p.Find_Activite();

                   QString textData= "cin ; nom ; prenom ; age ; adresse; numero ; mail ; etat \n";
                   int rows=model->rowCount();
                   int columns=model->columnCount();
                   for (int i = 0; i < rows; i++)
                   {
                       for (int j = 0; j < columns; j++)
                       {
                           textData += model->data(model->index(i,j)).toString();
                           textData +=" ; ";
                       }
                       textData += "\n";
                   }
                   QString fileName = QFileDialog::getSaveFileName(this, "Export Excel", QString(), "*.csv");
                   if (!fileName.isEmpty())
                       if (QFileInfo(fileName).suffix().isEmpty())
                           fileName.append(".csv");
                   QFile csvfile(fileName);
                   if(csvfile.open(QIODevice::WriteOnly|QIODevice::Truncate))
                   {
                       QTextStream out(&csvfile);
                       out<<textData;
                   }
                   csvfile.close();
}







void client::on_pushButton_42_clicked()
{
    stat_combop *s = new stat_combop();

            s->setWindowTitle("Les Statistiques selon l'etat");
            s->choix_pie();
            s->show();
}




void  client::browse()
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
void   client::sendMail()
{
    Smtp* smtp = new Smtp("bejaoui.ahmed@esprit.tn",ui->mail_pass->text(), "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail("bejaoui.ahmed@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail("bejaoui.ahmed@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}
void   client::mailSent(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
    ui->rcpt->clear();
    ui->subject->clear();
    ui->file->clear();
    ui->msg->clear();
    ui->mail_pass->clear();
}
