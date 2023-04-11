#include "produit.h"
#include "blocnote.h"
#include "ui_produit.h"
#include "tache.h"
#include "statistique.h"
#include "produitang.h"
#include"mainwindow.h"
#include "produitc.h"
#include "camera.h"
#include "calculatrice.h"
#include <QFile>
#include <QMessageBox>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QDate>
#include <QIntValidator>
#include <QRegExpValidator>
#include <QDebug>
#include<QWidget>
#include <QTextDocument>
#include <QTextEdit>
#include <fstream>
#include <QTextStream>
#include <QRadioButton>
#include <QFileDialog>
#include <QPixmap>
#include <QPainter>
#include "qrcode.h"
#include <QFileDialog>
#include <QPixmap>
#include <QPainter>
#include <QPrinter>
#include <QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextDocument>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QtSvg/QSvgRenderer>
#include <QtSvg/QSvgGenerator>
#include <QDirModel>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QAbstractPrintDialog>
#include <QDirModel>
#include <QtPrintSupport/QPrintDialog>
#include <QPrinter>
#include <QPrintDialog>
#include <QErrorMessage>
#include <QFile>
#include <QDataStream>
#include <QTimer>
#include <QPixmap>
#include <QDateTime>
#include <QMessageBox>
produit::produit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::produit)
{
    ui->setupUi(this);

 //   ui->id->setValidator(new QIntValidator(0,99, this));
  // QRegExp regExp("[A-Z]*"); // Autorise uniquement les caractères numériques
   //   ui->nom->setValidator(new QRegExpValidator(regExp, this));
    //  ui->nom1->setValidator(new QRegExpValidator(regExp, this));

      QRegExp regExppp("^[A-Za-z]*$"); // Autorise uniquement les majuscules et les chiffres
        ui->etat->setValidator(new QRegExpValidator(regExppp, this));
       // ui->marque->setValidator(new QRegExpValidator(regExppp, this));
        ui->marque1->setValidator(new QRegExpValidator(regExppp, this));
        ui->etat1->setValidator(new QRegExpValidator(regExppp, this));


    QString id = ui->id->text();
    QString nom = ui->nom->text();
    QString marque = ui->marque->text();
   QString disponibilite = ui-> disponibilite->text();
   QString etat = ui->etat->text();
    //QString prix = ui->prix->text();
     produitc p(id,nom,marque,disponibilite,etat);
      ui->view->setModel(p.afficher());
}

produit::~produit()
{
    delete ui;
}

void produit::on_pushButton_6_clicked()
{
    tache t ;
     hide();
     t.exec();
}

void produit::on_pushButton_5_clicked()
{
    MainWindow *mainwindow = new MainWindow() ;
    hide();
    mainwindow->show();
}

void produit::on_ajout_clicked()
{     QString id = ui->id->text();
    QString nom = ui->nom->text();
    QString marque = ui->marque->text();
   QString disponibilite = ui-> disponibilite->text();
   QString etat = ui->etat->text();
    // QString prix = ui->prix->text();

   produitc p(id,nom,marque,disponibilite,etat);
     /*if (id!=n1||id!=n0||id!=n2||id!=n3||id!=n4||id!=n5||id!=n6||id!=n7||id!=n8||id!=n9){
         QMessageBox::warning(this, "Erreur", "Une erreur le nom contient des chiffre  !");


     }

     else {
*/


   bool test = p.ajouter();
   if (test) {
       // ui->listView->setModel(p.afficher());
       QMessageBox::information(this, "Ajout réussi", "Le nouvel enregistrement a été ajouté avec succès !");
   } else {
       QMessageBox::warning(this, "Erreur", "Une erreur est survenue lors de l'ajout de l'enregistrement !");
   }
   ui->view->setModel(p.afficher());
    ui->id->clear();
     ui->nom->clear();
      ui->marque->clear();
        ui->disponibilite->clear();

        ui->etat->clear();

        //  ui->prix->clear();

         }
      /* if (disponibilite!=n1||id!=n0){
           QMessageBox::warning(this, "Erreur", "Une erreur disponibilite doit etre soit 0 ou 1 !");


       }*/











/*/////////////////////////supp//////////////////////////////////*/

void produit::on_ajout_3_clicked()
{
        QString id = ui->id1->text();

 bool test=p1.supprimer(id);
 if (test) {
     ui->view->setModel(p1.afficher());
    // QMessageBox::information(this, "suppression réussi", "Le nouvel enregistrement a été supprimer avec succès !");
        }
 else


     QMessageBox::warning(this, "Erreur", "Une erreur est survenue lors de la supprition de l'enregistrement !");
 ui->id1->clear();


}



/*/////////////////////////mod//////////////////////////////////*/

void produit::on_ajout_4_clicked()
{
   QString id=ui->id1_3->text();
    QString nom=ui->nom1->text();
    QString marque=ui->marque1->text();
    QString disponibilite=ui->disponibilite1->text();
    QString etat=ui->etat1->text();
   // QString prix=ui->prix1->text();

   produitc p(id,nom,marque,disponibilite,etat);

    bool test=p.modifier();
    if(test){
        ui->view->setModel(p.afficher());

        QMessageBox::information(nullptr,"Modifier produit","produit modifié avec succés");
        ui->id1_3->clear();
        ui->nom1->clear();
        ui->marque1->clear();
        ui->disponibilite1->clear();
        ui->etat1->clear();
       // ui->prix1->clear();



    }
    else
            QMessageBox::warning(nullptr,"Error","produit non modifié");





   }


void produit::on_view_activated(const QModelIndex &index)
{
    QString val=ui->view->model()->data(index).toString();
        QSqlQuery qry;
        qry.prepare("select * from PRODUIT1 where marque='"+val+"'  ");
        if(qry.exec())
        {
            while(qry.next())
            {
             ui->id1_3->setText(qry.value(0).toString());
                      ui->nom1->setText(qry.value(1).toString());
                      ui->marque1->setText(qry.value(2).toString());
                     ui->disponibilite1->setText(qry.value(3).toString());
                      ui->etat1->setText(qry.value(4).toString());


            }

        }
        qry.prepare("select nom from PRODUIT1 where nom='"+val+"'  ");
        if(qry.exec())
        {
            while(qry.next())
            {
                ui->id1_3->setText(qry.value(0).toString());
                         ui->nom1->setText(qry.value(1).toString());
                         ui->marque1->setText(qry.value(2).toString());
                        ui->disponibilite1->setText(qry.value(3).toString());
                         ui->etat1->setText(qry.value(4).toString());

            }




            qry.prepare("select * from PRODUIT1 where id='"+val+"'  ");
            if(qry.exec())
            {
                while(qry.next())
                {
                 ui->id1->setText(qry.value(0).toString());


                }

        }

} }










void produit::on_pushButton_13_clicked()
{
    calculatrice ca;
    ca.exec();
}
/*/////////////////////////pdf//////////////////////////////////*/

void produit::on_pushButton_17_clicked()//pdf
{

    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A3);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    QSqlQuery q;
    q.prepare("SELECT * FROM PRODUIT1 ");
    q.exec();

    QString pdf = "<html><head>"
                 "<style>"
                 "table { border-collapse: collapse; width: 100%; margin: 0 auto; }"
                 "th, td { border: 1px solid black; text-align: center; padding: 10px; }"
                 "th { background-color: #CCCCCC; }"
                 "h1 { color: red; }"
                 "table { font-size: 15pt; }"
                 "</style>"
                 "</head><body>"
 "<div style='text-align:centre'><h1>LISTE DE PRODUIT</h1>"
                 "<div style='text-align:right'><img src='file:///C:/Users/nciby/Desktop/logo.png'></div>"

                 "<table>"
            "<thead>"
                 "<tr>"
                 "<th>ID</th>"
                  "<div style='text-align:right'><img src='file:///C:/Users/nciby/Downloads/bookmark.svg'></div>"

                 "<th>NOM</th>"
                  "<div style='text-align:right'><img src='file:///C:/Users/nciby/Downloads/edit-3.svg'></div>"

                 "<th>MARQUE</th>"
                  "<div style='text-align:right'><img src='file:///C:/Users/nciby/Downloads/tag.svg'></div>"

                 "<th>DISPONIBILITE</th>"
                  "<div style='text-align:right'><img src='file:///C:/Users/nciby/Downloads/archive.svg'></div>"

                 "<th>ETAT</th>"

                  "<div style='text-align:right'><img src='file:///C:/Users/nciby/Downloads/award.svg'></div>"
"</tr>"
                  "</thead>"

                               "<tbody>";

    while (q.next()) {
        pdf += "<tr>"
               "<td>" + q.value(0).toString() + "</td>"
               "<td>" + q.value(1).toString() + "</td>"
               "<td>" + q.value(2).toString() + "</td>"
               "<td>" + q.value(3).toString() + "</td>"
               "<td>" + q.value(4).toString() + "</td>"
               "</tr>";
    }

    pdf += "</table>"
           "<div style='text-align:right'>" + QDate::currentDate().toString(Qt::ISODate) + "</div>"
           "</body></html>";


    doc.setHtml(pdf);
    doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
    doc.print(&printer);



}


/*/////////////////////////qrcode//////////////////////////////////*/


void produit::on_pushButton_27_clicked()
{



    if(ui->view->currentIndex().row()==-1)
        QMessageBox::information(nullptr, QObject::tr("Suppression"),
                                 QObject::tr("Veuillez Choisir un employé du Tableau.\n"
                                             "Click Ok to exit."), QMessageBox::Ok);
    else
    {
         int  Code=ui->view->model()->data(ui->view->model()->index(ui->view->currentIndex().row(),0)).toInt();
        //const QrCode qr = QrCode::encodeText(std::to_string(Code).c_str(), QrCode::Ecc::LOW);
         const qrcodegen::QrCode qr = qrcodegen::QrCode::encodeText(std::to_string(Code).c_str(),qrcodegen::QrCode::Ecc::LOW);
         std::ofstream myfile;
         myfile.open ("qrcode.svg") ;
         myfile << qr.toSvgString(1);
         myfile.close();
         QSvgRenderer svgRenderer(QString("qrcode.svg"));
         QPixmap pix( QSize(90, 90) );
         QPainter pixPainter( &pix );
         svgRenderer.render(&pixPainter);
         ui->label1->setPixmap(pix);
    }

}





void produit::on_pushButton_22_clicked()
{

        // ui->listView->setModel(p.afficher());
        QMessageBox::information(this, "traductiion", "Il est deja en français !");

}



void produit::on_pushButton_35_clicked()
{ camera c1;
     c1.exec();
}





void produit::on_pushButton_19_clicked()
{
    statistique s;
    s.exec();
}

void produit::on_nomrecherche_cursorPositionChanged(int arg1, int arg2)   //recherche
{
    QString n=ui->nomrecherche->text();
        ui->view->setModel(p1.recherche(n));
}




void produit::on_pushButton_36_clicked()
{
    QString type_tri = "id";
    //QString test_ordre ="croissant" ;
    type_tri = ui->comboBox->currentText();
    //test_ordre = ui->comboBox_ordre->currentText() ;

        if (type_tri == "id")

        ui->view->setModel(p1.tricroissant_id());
        if (type_tri == "etat")

        ui->view->setModel(p1.tricroissant_etat());
        if (type_tri == "disponibilite")

        ui->view->setModel(p1.tricroissant_disponibilite());
}


void produit::on_pushButton_18_clicked()
{
    blocnote bl;
    bl.exec();
}

void produit::on_pushButton_23_clicked()
{
    produitang pe ;
       hide();
       pe.exec();
}
