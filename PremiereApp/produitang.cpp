#include "produitang.h"
#include "ui_produitang.h"
#include "blocnote.h"
#include "produit.h"
#include "tacheeng.h"
#include"home.h"
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

produitang::produitang(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::produitang)
{
    ui->setupUi(this);
    QString id = ui->id->text();
    QString nom = ui->nom->text();
    QString marque = ui->marque->text();
   QString disponibilite = ui-> disponibilite->text();
   QString etat = ui->etat->text();
    //QString prix = ui->prix->text();
     produitc p(id,nom,marque,disponibilite,etat);
      ui->view->setModel(p.afficher());
}

produitang::~produitang()
{
    delete ui;
}

void produitang::on_pushButton_27_clicked()
{
    blocnote b;
    b.exec();
}

void produitang::on_ajout_clicked()
{
    QString id = ui->id->text();
       QString nom = ui->nom->text();
       QString marque = ui->marque->text();
      QString disponibilite = ui-> disponibilite->text();
      QString etat = ui->etat->text();
       // QString prix = ui->prix->text();

      produitc p(id,nom,marque,disponibilite,etat);
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




}

void produitang::on_ajout_3_clicked()
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

void produitang::on_ajout_4_clicked()
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

void produitang::on_view_activated(const QModelIndex &index)
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

}
}



void produitang::on_pushButton_13_clicked()
{
    calculatrice ca;
    ca.exec();
}

void produitang::on_pushButton_17_clicked()
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
 "<div style='text-align:centre'><h1>PRODUCT LISTE</h1>"
                 "<div style='text-align:right'><img src='file:///C:/Users/nciby/Desktop/logo.png'></div>"

                 "<table>"
            "<thead>"
                 "<tr>"
                 "<th>ID</th>"
                  "<div style='text-align:right'><img src='file:///C:/Users/nciby/Downloads/bookmark.svg'></div>"

                 "<th>NAME</th>"
                  "<div style='text-align:right'><img src='file:///C:/Users/nciby/Downloads/edit-3.svg'></div>"

                 "<th>BRAND</th>"
                  "<div style='text-align:right'><img src='file:///C:/Users/nciby/Downloads/tag.svg'></div>"

                 "<th>DISPONIBILITY</th>"
                  "<div style='text-align:right'><img src='file:///C:/Users/nciby/Downloads/archive.svg'></div>"

                 "<th>STATUS</th>"

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



void produitang::on_pushButton_26_clicked()
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

void produitang::on_pushButton_24_clicked()
{
    produit pe ;
       hide();
       pe.exec();
}

void produitang::on_pushButton_25_clicked()
{
    QMessageBox::warning(this, "traduction", "you are already in english  !");
}

void produitang::on_pushButton_36_clicked()
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

void produitang::on_pushButton_35_clicked()
{
    camera c1;
         c1.exec();
}

void produitang::on_pushButton_6_clicked()
{
    tacheeng t;
            hide();
            t.exec();
}

void produitang::on_pushButton_5_clicked()
{
    home h;
            hide();
            h.exec();
}
