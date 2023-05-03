
#include "ambulance.h"
#include "ui_ambulance.h"
#include "mainwindow.h"
#include"ambulancec.h"
#include<QPixmap>
#include<QDateTime>
#include<QMessageBox>
#include "historique.h"
#include <QPrinter>
#include <QPainter>
#include <QLabel>
#include <QColor>
#include <QPrintDialog>
#include <QFileDialog>
#include<QDebug>
#include <QGraphicsPixmapItem>
#include <iostream>
#include <QPdfWriter>
#include <QDesktopServices>
#include "arduino.h"
Ambulance::Ambulance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ambulance)
{
    ui->setupUi(this);
    //QRegExp fournit une correspondance de modèle à l'aide d'expressions régulières.
    QRegExp regExpp("^[0-9]{3}[tT][uU][0-9]{4}$"); // Autorise uniquement les majuscules et les chiffres
    ui->lineEdit_matricule->setValidator(new QRegExpValidator(regExpp, this));

    ui->dispo->setValidator(new QIntValidator(0,1,this));
    QRegExp regExppp("^[A-Za-z]*$"); // Autorise uniquement les majuscules et les chiffres

   ui->marque->setValidator(new QRegExpValidator(regExppp, this));
   ui->etat->setValidator(new QRegExpValidator(regExppp, this));

   QString matricule = ui->lineEdit_matricule->text();
        QString marque = ui->marque->text();
       QString datec = ui->date->text();
        QString dispo= ui->dispo->currentText();
        QString etat = ui->etat->text();
        QPixmap img= ui->img1->grab();

        Ambulancec a(matricule,marque,datec,dispo,etat,img);
        ui->view->setModel( a.afficher());
        historique h;


}


Ambulance::~Ambulance()
{
    delete ui;
}



void Ambulance::on_Quitter_clicked()
{
    MainWindow *mainWindow = new MainWindow();
       hide();
          mainWindow->show();
}

void Ambulance::on_pushButton_clicked()
{
    MainWindow *mainWindow = new MainWindow();
       hide();
          mainWindow->show();
}

void Ambulance::on_pushButton_13_clicked()
{
    QString matricule = ui->lineEdit_matricule->text();
        QString marque = ui->marque->text();
       QString datec = ui->date->text();
        QString dispo= ui->dispo->currentText();
        QString etat = ui->etat->text();
       QPixmap img=this->ui->img1->grab();
        Ambulancec a(matricule,marque,datec,dispo,etat,img);

        bool test = a.ajouter();
        if (test) {

            QMessageBox::information(this, "Ajout réussi", "Le nouvel enregistrement a été ajouté avec succès !");
            QString nomFile ="hist";
                                     QFile file("C:/Users/siwar/Desktop"+nomFile+".txt");
                                     QString finalmsg="fichier modifie avec succes";
                                      if(!file.exists()){
                                      finalmsg="fichier cree avec succes";
                                      }
                      //mode ecriture seulem.|ecriture a la fin du file|ouvre le file en mode txt
                                      // "|" pour combiner ces modes
                                     file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);



                                     QTextStream txt(&file); //pour pouvoir ecrire dans le file
                                       QString d_info = QDateTime::currentDateTime().toString();

                                     QString message2=d_info+" - Une ambulance a été ajoutée avec la matricule "+ matricule +"\n";
                                     txt << message2;
                        historique h;
                        h.enregistrer_txt(ui->lineEdit_matricule->text(),marque,datec,ui->dispo->currentText(),etat);
                   ui->historique->setText(h.imprimer_hist()); //afficher sur l'interface
        } else {
            QMessageBox::warning(this, "Erreur", "Une erreur est survenue lors de l'ajout de l'enregistrement !");
        }
        ui->view->setModel( a.afficher());

}

void Ambulance::on_pushButton_39_clicked()
{

QString matricule = ui->lineEdit_matricule_3->text();
         bool test=A.supprimer(matricule);
         if (test) {
 ui->view->setModel( A.afficher());
 QMessageBox::information(this, "suppression réussi", "Le nouvel enregistrement a été supprimer avec succès !");


         QString nomFile ="hist";
                                  QFile file("C:/Users/siwar/Desktop"+nomFile+".txt");
                                  QString finalmsg="fichier modifie avec succes";
                                   if(!file.exists()){
                                   finalmsg="fichier cree avec succes";
                                   }
                                  file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);



                                  QTextStream txt(&file);
                                    QString d_info = QDateTime::currentDateTime().toString();

                                  QString message2=d_info+" - Une ambulance  a été supprimée avec la matricule "+ matricule +"\n";
                                  txt << message2;
                     historique h;
                    h.enregistrer_txt2(ui->lineEdit_matricule_3->text());
                ui->historique->setText(h.imprimer_hist());  //afficher sur l'interface
                ui->lineEdit_matricule_3->clear();

         }
         else
             QMessageBox::warning(this, "Erreur", "Une erreur est survenue lors de la supprition de l'enregistrement !");


}




void Ambulance::on_pushButton_23_clicked()
{

    QString matricule = ui->lineEdit_matricule_2->text();

    QString marque = ui->marque_2->text();
    QString datec = ui->date_2->text();
    QString dispo= ui->dispo_2->text();
    QString etat = ui->etat_2->text();
    QPixmap img=this->ui->img2->grab();


    Ambulancec a(matricule,marque,datec,dispo,etat,img);

                    bool test=a.modifier();
                    if(test)

                        {
                        QMessageBox::information(nullptr,QObject::tr("Ok"),
                                             QObject::tr("Modification effectuée\n"
                                                           "Click cancel to exit."),QMessageBox::Cancel);
                        QString nomFile ="hist";
                                                 QFile file("C:/Users/siwar/Desktop"+nomFile+".txt");
                                                 QString finalmsg="fichier modifie avec succes";
                                                  if(!file.exists()){
                                                  finalmsg="fichier cree avec succes";
                                                  }
                                                 file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);



                                                 QTextStream txt(&file);
                                                   QString d_info = QDateTime::currentDateTime().toString();

                                                 QString message2=d_info+" - Une ambulance a été ajoutée avec la matricule "+ matricule +"\n";
                                                 txt << message2;
                                    historique h;
                                    h.enregistrer_txt1(ui->lineEdit_matricule_2->text(),marque,datec,ui->dispo->currentText(),etat);
                               ui->historique->setText(h.imprimer_hist()); //afficher sur l'interface
                        ui->view->setModel( a.afficher());
                        ui->lineEdit_matricule_2->clear();
                        ui->marque_2->clear();
                        ui->date_2->clear();
                        ui->dispo_2->clear();
                        ui->etat_2->clear();

                        }
                    else
                        {
                        QMessageBox::critical(nullptr,QObject::tr("Not ok"),
                                             QObject::tr("Modification non effectuée\n"
                                                           "Click cancel to exit."),QMessageBox::Cancel);
                        }
}


void Ambulance::on_view_activated(const QModelIndex &index)
{
    QString val=ui->view->model()->data(index).toString();
        QSqlQuery qry;
        qry.prepare("select * from AMBULANCE where  marque='"+val+"' or datec='"+val+"' or dispo='"+val+"' or etat='"+val+"'" );
        if(qry.exec())
        {
            while(qry.next())
            {
             ui->lineEdit_matricule_2->setText(qry.value(0).toString());
                      ui->marque_2->setText(qry.value(1).toString());
                      ui->date_2->setText(qry.value(2).toString());
                      ui->dispo_2->setText(qry.value(3).toString());
                      ui->etat_2->setText(qry.value(4).toString());
                      image::showImage(ui->img2, qry.value(5).toByteArray() );

            }
            qry.prepare("select * from AMBULANCE where matricule='"+val+"'" );
            if(qry.exec())
            {
                while(qry.next())
                {
                 ui->lineEdit_matricule_3->setText(qry.value(0).toString());


                }

        }

} }

                //recherche
void Ambulance::on_nomrecherche_cursorPositionChanged(int arg1, int arg2)
{
    //recuperation des donnees de l'interface ui
    QString  matricule=ui->lineEdit_matricule_2->text();
        QString marque=ui->marque_2->text();
        QString datec=ui->date_2->text();
        QString dispo=ui->dispo_2->text();
        QString etat=ui->etat_2->text();
        QPixmap img= ui->img2->grab(); //grab():pour capturer l'image de ce widget et la stocker dans un objet QPixmap nommé img.

       Ambulancec a(matricule,marque,datec,dispo,etat,img);
        ui->view->setModel(a.recherche(ui->nomrecherche->text()));

}

    //bouton pour tri
void Ambulance::on_pushButton_19_clicked()
{
    QString type_tri = "matricule";
    type_tri = ui->comboBox_tri->currentText();

        if (type_tri == "matricule")

        ui->view->setModel(A.tricroissant_matricule());

        if (type_tri == "marque")

        ui->view->setModel(A.tricroissant_marque());

        if (type_tri == "etat")

        ui->view->setModel(A.tricroissant_etat());
}

        //PDF
void Ambulance::on_pushButton_16_clicked()
{
    Ambulancec s;
        QString text = s.apercupdf();
        ui->textEdit->setText(text);

        QPrinter printer;
        printer.setPrinterName("imprimer");  //nom de l'imprimante
        printer.setOutputFormat(QPrinter::PdfFormat);   //format de sortie
        printer.setOutputFileName("C:/Users/siwar/Desktop/ambulances.pdf");  //nom du fichier
        printer.setFullPage(true); // occuper toute la surface disponible sur la feuille ou non.

        QTextDocument doc;
        doc.setHtml(text); // text contient le code HTML qui sera converti en document par la méthode setHtml().

        QPainter painter; //dessiner sur l'imprimante
        painter.begin(&printer);

        // Dessiner le logo
        painter.drawPixmap(QRect(0, -45, 200, 200), QPixmap("C:/Users/siwar/Desktop/logo.png"));

        // Centrer le titre horizontalement
        QString title = "LA LISTE DES AMBULANCES";
        QFont titleFont("Arial", 20, QFont::Bold); //forme du texte+taille ::Bold =gras
        QFontMetrics titleMetrics(titleFont); //calculer les mesures de la police de caractères "titleFont"
        int titleWidth = titleMetrics.width(title); //largeur du titre
        int titleX = (printer.pageRect().width() - titleWidth) / 2;
        painter.setFont(titleFont);
        painter.drawText(titleX, 70, title); //70:hauteur

        //Calcule la position du tableau pour le centrer horizontalement
        int tableWidth = doc.size().width() * 1.2; //calculer largeur du tab
        int tableX = ((printer.pageRect().width() - tableWidth) / 2) + 74; //calcule la position horizontale où la table sera dessinée

        // dessiner le texte et le tab sur la page
        painter.translate(tableX, 0);
        doc.setPageSize(QSize(tableWidth, INT_MAX));//(INT_MAX) pour que le document puisse s'étendre sur plusieurs pages si nécessaire.
        doc.drawContents(&painter);

        painter.end(); //liberation
}
        //IMAGE


        //retourner l'emplacement par défaut où sont stockées les images
        //cette fct retourne l'emplacement de travail actuel si elle ne trouve aucun emplacement

static inline QString picturesLocation()
{
    return QStandardPaths::standardLocations(QStandardPaths::PicturesLocation).value(0, QDir::currentPath());
}

void Ambulance::on_pushButton_22_clicked()
{
    //to do
    QString m_currentPath;
    //choix du fichier
    QFileDialog fileDialog(this);
    //définir le mode de sélection de fichier à ouverture
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    //type de fichier autorisé
    fileDialog.setMimeTypeFilters(QStringList() << "image/png"); //<< "image/png"
    fileDialog.setWindowTitle(tr("Open PNG File"));
    if (m_currentPath.isEmpty())
        fileDialog.setDirectory(picturesLocation());

  while (fileDialog.exec() != QDialog::Accepted )
        ;

    m_currentPath=fileDialog.selectedFiles().constFirst() ; //récupérer le chemin complet du fichier sélectionné.
    //nouvelle scène graphique de taille 680x520
    QGraphicsScene * scene=new QGraphicsScene(QRect(10, 10, 680, 520));

    //nouvel objet QGraphicsPixmapItem à partir de l'image PNG chargée.
    QGraphicsItem * image=new QGraphicsPixmapItem(QPixmap(m_currentPath));
    scene ->addItem(image);  //najoutih lel scene

    ui->img1->setScene(scene); //definir la scene
    ui->img1->fitInView(scene->sceneRect(), Qt::KeepAspectRatio); //regler la vue
    ui->img1->show(); //afficher


}





void Ambulance::on_consulter_clicked()
{
    QString matricule= ui->id_consulter->text() ;

    QSqlQuery qry;
    qry.prepare("select * from AMBULANCE where matricule = :matricule") ;
    qry.bindValue(":matricule", matricule); //lier la val de matricule au matricule de la bd
    if(qry.exec())
    {
        while(qry.next())
        {
         ui->mat_consulter->setText(qry.value(0).toString());
                 ui->marque_consulter->setText(qry.value(1).toString());
                 ui->date_consulter->setText(qry.value(2).toString());
                 ui->dispo_consulter->setText(qry.value(3).toString());
                 ui->etat_consulter->setText(qry.value(4).toString());

         //afficher image
         image::showImage(ui->img_consulter, qry.value(5).toByteArray() );
 } }

}


void Ambulance::on_load_modifier_clicked()
{
    //to do
    QString m_currentPath;
    //récupérer file name
    QFileDialog fileDialog(this);
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog.setMimeTypeFilters(QStringList() << "image/png");
    fileDialog.setWindowTitle(tr("Open PNG File"));

    if (m_currentPath.isEmpty())
        fileDialog.setDirectory(picturesLocation());

  while (fileDialog.exec() != QDialog::Accepted )
        ;

    m_currentPath=fileDialog.selectedFiles().constFirst() ;

    QGraphicsScene * scene=new QGraphicsScene(QRect(10, 10, 680, 520));


    QGraphicsItem * image=new QGraphicsPixmapItem(QPixmap(m_currentPath));
    scene ->addItem(image);

    ui->img2->setScene(scene);
    ui->img2->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    ui->img2->show();
}

    //STAT
void Ambulance::on_statistique_clicked()
{
    statistique stat ;
    stat.exec();
}



void Ambulance::on_arduino_2_clicked()
{
    arduino ar;
    ar.setModal(true);
    ar.exec();
}
