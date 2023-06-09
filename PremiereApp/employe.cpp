#include "employe.h"
#include "ui_employe.h"
#include "mainwindow.h"
#include "stat_combo.h"
#include "localisation.h"
#include <QSettings>
#include <QPixmap>
#include <QDateTime>
#include <QMessageBox>
#include "employec.h"
#include "tache.h"
#include <QPrinter>
#include <QPainter>
#include <QLabel>
#include <QColor>
#include <QPrintDialog>
#include <QFileDialog>
#include<QDebug>
employe::employe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::employe)
{
    ui->setupUi(this);
    ui->cin->setValidator(new QIntValidator(0,99999999, this));
    ui->cin1->setValidator(new QIntValidator(0,99999999, this));
     ui->numero->setValidator(new QIntValidator(0,99999999, this));
     ui->numero1->setValidator(new QIntValidator(0,99999999, this));
     ui->salaire->setValidator(new QIntValidator(0,99999999, this));
     ui->salaire1->setValidator(new QIntValidator(0,99999999, this));




     QRegExp regExppp("^[A-Za-z]*"); // Autorise uniquement les majuscules et les chiffres
     ui->prenom->setValidator(new QRegExpValidator(regExppp, this));
     ui->prenom1->setValidator(new QRegExpValidator(regExppp, this));
     ui->nom->setValidator(new QRegExpValidator(regExppp, this));
     ui->nom1->setValidator(new QRegExpValidator(regExppp, this));

       //QRegExp regExppp("^[A-Za-z]*$"); // Autorise uniquement les majuscules et les chiffres
      //  ui->tache->setValidator(new QRegExpValidator(regExppp, this));
        //QRegExp regExpp("^[A-Z0-9]*$"); // Autorise uniquement les majuscules et les chiffres
      //  ui->MATRICULE->setValidator(new QRegExpValidator(regExpp, this));
        //QRegExp regExppp("^[A-Za-z]*$"); // Autorise uniquement les majuscules et les chiffres
      //ui->CATEGORIE->setValidator(new QRegExpValidator(regExppp, this));
        QRegExp regEx("^[A-Za-z]*"); // Autorise uniquement les majuscules et les chiffres
        ui->tache->setValidator(new QRegExpValidator(regEx, this));
        ui->tache1->setValidator(new QRegExpValidator(regEx, this));


    int  cin = ui->cin->text().toInt();
        QString nom = ui->nom->text();
        QString prenom = ui->prenom->text();
       int numero = ui->numero->text().toInt();
       int salaire = ui->salaire->text().toInt();
        QString tache = ui->tache->text();
          employec e ( cin ,nom, prenom, numero ,salaire,tache);
            ui->view->setModel( e.afficher());

}

employe::~employe()
{
    delete ui;
}

void employe::on_pushButton_9_clicked()
{
    MainWindow *mainWindow = new MainWindow();
       hide();
          mainWindow->show();
}



void employe::on_pushButton_45_clicked()
{
    MainWindow *mainWindow = new MainWindow();
        hide();
           mainWindow->show();

}

void employe::on_pushButton_46_clicked()
{
    MainWindow *mainWindow = new MainWindow();
        hide();
           mainWindow->show();

}



void employe::on_pushButton_8_clicked()
{
    int  cin = ui->cin->text().toInt();
        QString nom = ui->nom->text();
        QString prenom = ui->prenom->text();
       int numero = ui->numero->text().toInt();
       int salaire = ui->salaire->text().toInt();
        QString tache = ui->tache->text();


        employec e ( cin ,nom, prenom, numero ,salaire,tache);

        bool test = e.ajouter();
        if (test) {
            QMessageBox::information(this, "Ajout réussi", "Le nouvel enregistrement a été ajouté avec succès !");
        } else {
            QMessageBox::warning(this, "Erreur", "Une erreur est survenue lors de l'ajout de l'enregistrement !");
        }    ui->view->setModel( e.afficher());
        ui->cin->clear();
        ui->nom->clear();
        ui->prenom->clear();
        ui->salaire->clear();
        ui->tache->clear();
        ui->numero->clear();
}




void employe::on_pushButton_10_clicked()
{
    MainWindow *mainWindow = new MainWindow();
        hide();
           mainWindow->show();

}

void employe::on_pushButton_16_clicked()
{
    tache t ;
    hide ();
    t.exec ();
}



void employe::on_pushButton_28_clicked()
{
    int  cin = ui->cin_1->text().toInt();
             bool test=e.supprimer(cin);
             if (test) {
                 ui->view->setModel(e.afficher());

                 QMessageBox::information(this, "suppression réussi", "Le nouvel enregistrement a été supprimer avec succès !");
             } else {
                 QMessageBox::warning(this, "Erreur", "Une erreur est survenue lors de la supprition de l'enregistrement !");
             }  ui->view->setModel(e.afficher());
}







void employe::on_pushButton_29_clicked()
{

    int  cin = ui->cin1->text().toInt();
        QString nom = ui->nom1->text();
        QString prenom = ui->prenom1->text();
       int numero = ui->numero1->text().toInt();
       int salaire = ui->salaire1->text().toInt();
        QString tache = ui->tache1->text();
         employec e(cin ,nom, prenom, numero ,salaire,tache);
         bool test=e.modifier();
         if(test){
                    ui->view->setModel(e.afficher());

                }
                else
                        QMessageBox::warning(nullptr,"Error","employe non modifie");
         ui->cin1->clear();
         ui->nom1->clear();
         ui->prenom1->clear();
         ui->salaire1->clear();
         ui->tache1->clear();
         ui->numero1->clear();
}

void employe::on_view_activated(const QModelIndex &index)
{
    QString val=ui->view->model()->data(index).toString();
        QSqlQuery qry;
        qry.prepare("select * from EMPLOYE where nom='"+val+"'");
        if(qry.exec())
        {
            while(qry.next())
            {
                      ui->cin1->setText(qry.value(0).toString());
                      ui->nom1->setText(qry.value(1).toString());
                      ui->prenom1->setText(qry.value(2).toString());
                      ui->numero1->setText(qry.value(3).toString());
                      ui->salaire1->setText(qry.value(4).toString());
                      ui->tache1->setText(qry.value(5).toString());


            }
            qry.prepare("select * from EMPLOYE where cin='"+val+"'");
            if(qry.exec())
            {
                while(qry.next())
                {
                          ui->cin_1->setText(qry.value(0).toString());

        }

} }
        }


void employe::on_pushButton_11_clicked()
{     ui->view->setModel( e.afficher_tri_nom());


}

void employe::on_pushButton_31_clicked()
{
    QString type_tri = "Nom";
        //QString test_ordre ="croissant" ;
        type_tri = ui->comboBox->currentText();
        //test_ordre = ui->comboBox_ordre->currentText() ;

            if (type_tri == "Nom")

            ui->view->setModel(e.afficher_tri_nom());
            if (type_tri == "Prenom")

            ui->view->setModel(e.afficher_tri_prenom());
            if (type_tri == "Salaire")

            ui->view->setModel(e.afficher_tri_salaire());}


void employe::on_pushButton_13_clicked()
{

     QPainter painter;
                 QString text=e.apercupdf();
                 ui->textEdit->setText(text);
                 QPrinter printer;


                        printer.setPrinterName("imprimer");
                        printer.setOutputFormat(QPrinter::PdfFormat);
                        printer.setOutputFileName("C:/Users/emnaa/OneDrive/Bureau/employes.pdf");
                        //printer.setFullPage(true);

                        painter.begin(&printer);

                       painter.drawPixmap(QRect(700, 50, 75, 75), QPixmap("C:/Users/emnaa/OneDrive/Bureau/logo.png"));
                       painter.drawPixmap(QRect(200, 450, 75, 75), QPixmap("C:/Users/emnaa/OneDrive/Bureau/Signature_Ali_Baba_Mohamadou.png"));

                        // Draw the text on the page
                        QTextDocument doc;
                        doc.setHtml(text);
                        doc.setPageSize(printer.pageRect().size());
                        doc.drawContents(&painter);

                  painter.end();

}

void employe::on_pushButton_12_clicked()
{
    stat_combo *s = new stat_combo();

            s->setWindowTitle("Les Statistiques selon categorie");
            s->choix_pie();

            s->show();
            hide ();


}

void employe::on_recherche_cursorPositionChanged(int arg1, int arg2)
{
    //recuperation des donnees de l'interface ui
    int  cin = ui->cin->text().toInt();
        QString nom = ui->nom->text();
        QString prenom = ui->prenom->text();
       int numero = ui->numero->text().toInt();
       int salaire = ui->salaire->text().toInt();
        QString tache = ui->tache->text();

           employec e( cin ,nom, prenom, numero ,salaire,tache);
           ui->view->setModel( e.recherche(ui->recherche->text()));
}

void employe::on_pushButton_15_clicked()
{
    ui->view->setModel( e.afficher_tri_prenom());

}



void employe::on_local_clicked()
{
    l = new localisation();

    l->setWindowTitle("Map");
    l->map();
    l->show();
    hide();

}


