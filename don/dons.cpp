#include "dons.h"
#include "donc.h"

#include "ui_dons.h"
#include "mainwindow.h"
#include "tache.h"
#include "stat_combo.h"
#include "agenda.h"
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
Dons::Dons(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dons)
{
    ui->setupUi(this);
    ui->dispo->setValidator(new QIntValidator(0,1, this));
    ui->dispo_2->setValidator(new QIntValidator(0,1, this));

        QRegExp regExp("[A-Z]*$");
        ui->type->setValidator(new QRegExpValidator(regExp, this));
        ui->type_2->setValidator(new QRegExpValidator(regExp, this));



        QRegExp regExppp("^[A-Za-z]*$");
        ui->donneur->setValidator(new QRegExpValidator(regExppp, this));
        ui->donneur_2->setValidator(new QRegExpValidator(regExppp, this));

        ui->id->setValidator(new QIntValidator(0,99, this));
        ui->id_2->setValidator(new QIntValidator(0,99, this));

        int id = ui->id->text().toInt();


    int dispo = ui->dispo->text().toInt();
       QString type = ui->type->text();
       QString donneur = ui->donneur->text();
       QDate temps=ui->temps->date();
       QString temps_v=temps.toString("yyyy-MM-dd");

       donc d(id,dispo,type,donneur,temps_v);
       ui->view->setModel(d.afficher());
}

Dons::~Dons()
{
    delete ui;
}







void Dons::on_pushButton_31_clicked()
{
    MainWindow *mainwindow = new MainWindow() ;
    hide();
    mainwindow->show();
}

void Dons::on_pushButton_33_clicked()
{
    tache t ;
     hide();
     t.exec();
}

void Dons::on_ajout_clicked()
{
    int id = ui->id->text().toInt();

    int dispo = ui->dispo->text().toInt();
       QString type = ui->type->text();
       QString donneur = ui->donneur->text();
       QDate temps=ui->temps->date();
       QString temps_v=temps.toString("yyyy-MM-dd");
       donc d(id,dispo,type,donneur,temps_v);
       bool test = d.ajouter();
       if (test) {
           // ui->listView->setModel(p.afficher());
           QMessageBox::information(this, "Ajout réussi", "Le nouvel enregistrement a été ajouté avec succès !");
       } else {
           QMessageBox::warning(this, "Erreur", "Une erreur est survenue lors de l'ajout de l'enregistrement !");
       }
       ui->view->setModel(d.afficher());
       ui->id->clear();
       ui->type->clear();
       ui->dispo->clear();
       ui->donneur->clear();
       ui->temps->clear();




    }


void Dons::on_pushButton_27_clicked()//supprimer
{
    int id = ui->id_2->text().toInt();

    int dispo = ui->dispo_2->text().toInt();
       QString type = ui->type_2->text();
       QString donneur = ui->donneur_2->text();
       QDate temps=ui->temps_2->date();
       QString temps_v=temps.toString("yyyy-MM-dd");
       donc d(id,dispo,type,donneur,temps_v);

     bool test=d.supprimer(d.getid());
     if (test) {

         QMessageBox::information(this, "suppression réussi", "Le nouvel enregistrement a été supprimer avec succès !");
     } else {
         QMessageBox::warning(this, "Erreur", "Une erreur est survenue lors de la supprition de l'enregistrement !");
     }  ui->view->setModel(d.afficher());
}

void Dons::on_pushButton_28_clicked()//modifier
{
    int id = ui->id_2->text().toInt();

    int dispo = ui->dispo_2->text().toInt();
       QString type = ui->type_2->text();
       QString donneur = ui->donneur_2->text();
       QDate temps=ui->temps_2->date();
       QString temps_v=temps.toString("yyyy-MM-dd");
       donc d(id,dispo,type,donneur,temps_v);
       bool test=d.modifier();
       if(test){
           ui->view->setModel(d.afficher());

       }
       else
               QMessageBox::warning(nullptr,"Error","produit non modifie");

       ui->id_2->clear();
       ui->type_2->clear();
       ui->dispo_2->clear();
       ui->donneur_2->clear();
       ui->temps_2->clear();


}

void Dons::on_view_activated(const QModelIndex &index)// affichage du don selectionné
{QString val=ui->view->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from DONS where id='"+val+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->id_2->setText(qry.value(0).toString());

                  ui->type_2->setText(qry.value(1).toString());
                  ui->donneur_2->setText(qry.value(2).toString());
                  ui->dispo_2->setText(qry.value(3).toString());
                  ui->temps_2->setDate(qry.value(4).toDate());

        }

    }


}

void Dons::on_pushButton_8_clicked()
{
    int id = ui->id->text().toInt();
    int dispo = ui->dispo->text().toInt();
            QString donneur = ui->donneur->text();
            QString type = ui->type->text();
            QDate temps=ui->temps->date();
            QString temps_v=temps.toString("yyyy-MM-dd");

            donc d(id,dispo,type,donneur,temps_v);
            ui->view->setModel( d.recherche(ui->recherche->text()));
}

void Dons::on_pushButton_9_clicked()
{
    ui->view->setModel( d.afficher_tri());
    QString type_tri = "Donneur";
        //QString test_ordre ="croissant" ;
        type_tri = ui->comboBox->currentText();
        //test_ordre = ui->comboBox_ordre->currentText() ;

            if (type_tri == "Donneur")

            ui->view->setModel(d.tricroissant_id());
            if (type_tri == "Dispo")

            ui->view->setModel(d.tricroissant_dispo());
            if (type_tri == "Type")

            ui->view->setModel(d.tricroissant_type());}

void Dons::on_pushButton_10_clicked()
{
    QPainter painter;
                     QString text=d.apercupdf();
                     ui->textEdit->setText(text);

                                       QPrinter printer ;
                                       printer.setPrinterName("imprimer");
                                       QImage logo("C:/Users/Amine/Desktop/projet/img/logo.png");
                                      QPoint logo_cordinates(100, 100);
                                          painter.drawImage(logo_cordinates, logo);
                                       QPrintDialog dialog (&printer,this);
                                       if(dialog.exec()==QDialog::Rejected) return ;
                                       ui->textEdit->print(&printer);
}



void Dons::on_pushButton_12_clicked()
{
    stat_combo *s = new stat_combo();

                s->setWindowTitle("Les Statistiques selon Disponiblité");
                s->choix_pie();
                hide ();

                s->show();
}

void Dons::on_pushButton_29_clicked()
{
    QPrinter rd;
                QPrintDialog d(&rd,this);
                d.setWindowTitle("Print Liste Dons");
                d.addEnabledOption(QAbstractPrintDialog::PrintSelection);
                if (d.exec() != QDialog::Accepted)
                    return ;
}

void Dons::on_pushButton_13_clicked()
{
    agenda ag ;
     hide();
     ag.exec();
}



void Dons::on_recherche_cursorPositionChanged(int arg1, int arg2)
{
        //recuperation des donnees de l'interface ui

    int id = ui->id_2->text().toInt();
    int dispo = ui->dispo_2->text().toInt();
            QString donneur = ui->donneur_2->text();
            QString type = ui->type_2->text();
            QDate temps=ui->temps_2->date();
            QString temps_v=temps.toString("yyyy-MM-dd");

            donc d(id,dispo,donneur,type,temps_v);
           ui->view->setModel( d.recherche(ui->recherche->text()));

    }


void Dons::on_calendarWidget_clicked(const QDate &date)
{
    QString val=date.toString("yyyy-MM-dd");
    QSqlQuery qry2;
    qry2.prepare(("select * from dons where temps='"+val+"'"));

        ui->id_5->setText("");
        ui->dispo_5->setText("");
        ui->type_5->setText("");
        ui->donneur_5->setText("");



        if(qry2.exec())
        {
            while (qry2.next()) {

                ui->id_5->setText(qry2.value(0).toString());
                ui->dispo_5->setText(qry2.value(3).toString());
                ui->type_5->setText(qry2.value(1).toString());
                ui->donneur_5->setText(qry2.value(2).toString());

            }

    }
}
