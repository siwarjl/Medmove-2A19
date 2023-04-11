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
              //ui->pushButton_18->setText(h.imprimer_hist());


}


Ambulance::~Ambulance()
{
    delete ui;
}







/*void Ambulance::on_pushButton_8_clicked()
{
    MainWindow *mainWindow = new MainWindow();
       hide();
          mainWindow->show();
}*/



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
                                     file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);



                                     QTextStream txt(&file);
                                       QString d_info = QDateTime::currentDateTime().toString();

                                     QString message2=d_info+" - Un Equipement a été ajouté avec la matricule "+ matricule +"\n";
                                     txt << message2;
                        historique h;
                        h.enregistrer_txt(ui->lineEdit_matricule->text(),marque,datec,ui->dispo->currentText(),etat);
                   ui->historique->setText(h.imprimer_hist());
        } else {
            QMessageBox::warning(this, "Erreur", "Une erreur est survenue lors de l'ajout de l'enregistrement !");
        }
        ui->view->setModel( a.afficher());

}

void Ambulance::on_pushButton_39_clicked()
{
    /*QString matricule = ui->lineEdit_matricule->text();
    QString marque = ui->marque->text();
    QString datec = ui->date->text();
    int dispo= ui->dispo->text().toInt();
    QString etat = ui->etat->text();
    Ambulancec a(matricule,marque,datec,dispo,etat);
    a.setmatricule(ui->lineEdit_matricule->text());
    bool test=a.supprimer(a.getmatricule());
    if (test) {

        QMessageBox::information(this, "suppression réussi", "Le nouvel enregistrement a été supprimer avec succès !");
    } else {
        QMessageBox::warning(this, "Erreur", "Une erreur est survenue lors de la supprition de l'enregistrement !");
    }          ui->view->setModel( a.afficher());*/
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
                ui->historique->setText(h.imprimer_hist());
                ui->lineEdit_matricule_3->clear();

         }
         else
             QMessageBox::warning(this, "Erreur", "Une erreur est survenue lors de la supprition de l'enregistrement !");


}


/*void Ambulance::on_pushButton_23_clicked()
{
    QString matricule = ui->lineEdit_matricule->text();
    QString marque = ui->marque->text();
    QString datec = ui->date->text();
    int dispo= ui->dispo->text().toInt();
    QString etat = ui->etat->text();
    Ambulancec a(matricule,marque,datec,dispo,etat);
    a.setmatricule(ui->lineEdit_matricule->text());
    bool test=a.modifier();
    if (test)

        ui->view->setModel( a.afficher());

    else
        QMessageBox::warning(nullptr,"Error","Ambulance non modifiee");
}*/

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
                        QString nomFile ="histo";
                                                 QFile file("C:/Users/siwar/Desktop"+nomFile+".txt");
                                                 QString finalmsg="fichier modifie avec succes";
                                                  if(!file.exists()){
                                                  finalmsg="fichier cree avec succes";
                                                  }
                                                 file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);



                                                 QTextStream txt(&file);
                                                   QString d_info = QDateTime::currentDateTime().toString();

                                                 QString message2=d_info+" - Un Equipement a été ajouté avec la matricule "+ matricule +"\n";
                                                 txt << message2;
                                    historique h;
                                    h.enregistrer_txt1(ui->lineEdit_matricule_2->text(),marque,datec,ui->dispo->currentText(),etat);
                               ui->historique->setText(h.imprimer_hist());
                        ui->view->setModel( a.afficher());
                        ui->lineEdit_matricule_2->clear();
                        ui->marque_2->clear();
                        ui->date_2->clear();
                        ui->dispo_2->clear();
                        ui->etat_2->clear();
                        //ui->salle_graphicsView_2->grab->clear();

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


void Ambulance::on_nomrecherche_cursorPositionChanged(int arg1, int arg2)
{
    //recuperation des donnees de l'interface ui
    QString  matricule=ui->lineEdit_matricule_2->text();
        QString marque=ui->marque_2->text();
        QString datec=ui->date_2->text();
        QString dispo=ui->dispo_2->text();
        QString etat=ui->etat_2->text();
        QPixmap img= ui->img2->grab();

       Ambulancec a(matricule,marque,datec,dispo,etat,img);
        ui->view->setModel( a.recherche(ui->nomrecherche->text()));

}
    //bouton pour tri
void Ambulance::on_pushButton_19_clicked()
{
    QString type_tri = "matricule";
    //QString test_ordre ="croissant" ;
    type_tri = ui->comboBox_tri->currentText();
    //test_ordre = ui->comboBox_ordre->currentText() ;

        if (type_tri == "matricule")

        ui->view->setModel(A.tricroissant_matricule());
        if (type_tri == "marque")

        ui->view->setModel(A.tricroissant_marque());
        if (type_tri == "etat")

        ui->view->setModel(A.tricroissant_etat());}

void Ambulance::on_pushButton_16_clicked()
{
                   QString text=A.apercupdf();
                   ui->textEdit->setText(text);

                                         QPdfWriter pdf("C:/Users/siwar/Desktop/Liste.pdf");

                                               QPainter painter(&pdf);

                                               int i = 4000;
                                               painter.setPen(Qt::black);
                                               painter.setFont(QFont("Konztante", 20));
                                               painter.drawPixmap(QRect(0,200,2000,2000),QPixmap("C:/Users/siwar/Desktop/logo.png"));
                                               painter.drawText(3000,1500,"LISTE DES AMBULANCES");
                                               painter.setPen(Qt::black);
                                               painter.setFont(QFont("Konztante", 50));
                                               painter.setPen(Qt::black);
                                               painter.setFont(QFont("Konztante", 9));
                                               painter.drawText(200,3200,"MATRICULE");
                                               painter.drawText(1500,3200,"MARQUE");
                                               painter.drawText(3000,3200,"DATEC");
                                               painter.drawText(4500,3200,"ETAT");
                                               painter.drawText(6000,3200,"DISPONIBILITE");

                                               QSqlQuery query;
                                               query.prepare("select * from AMBULANCE");
                                               query.exec();
                                               while (query.next())
                                               {
                                                   painter.drawText(200,i,query.value(0).toString());
                                                   painter.drawText(1500,i,query.value(1).toString());
                                                   painter.drawText(3000,i,query.value(2).toString());
                                                   painter.drawText(4500,i,query.value(3).toString());
                                                   painter.drawText(6000,i,query.value(4).toString());

                                                   i = i +500;
                                               }

                                               int reponse = QMessageBox ::question(this, "PDF généré", "Afficher le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                                               if (reponse == QMessageBox::Yes)
                                               {
                                                   QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/siwar/Desktop/Liste.pdf"));

                                                   painter.end();
                                               }
                                               if (reponse == QMessageBox::No)
                                               {
                                                   painter.end();
                                               }
}

/*void Ambulance::on_pushButton_17_clicked()
{
    //ui->groupBox;
    ui->progressBar->setValue(0);
}*/

/*void Ambulance::on_pb_statistique_2_clicked()
{
    int SA=0;
    int a =A.statistique_E(ui->comboBoxStat->currentText());
     int t=A.statistique_ET();
     SA=(a*100)/t;
     ui->progressBar->setValue(SA);
}*/

/*void Ambulance::on_image_linkActivated(const QString &link)
{
    QString dir = QFileDialog::getOpenFileName(this,tr("Select Picture"),"C:/Users/Admin/Desktop/capture.png");
            QPixmap pic(dir);
            int x = ui->image->width();
            int y = ui->image->height();
            ui->image->setPixmap(pic.scaled(x,y,Qt::KeepAspectRatio));
}*/

/*void Ambulance::on_pushButton_14_clicked()
{
    QString dir = QFileDialog::getOpenFileName(this,tr("Select Picture"),"C:/Users/Admin/Desktop/capture.png");
            QPixmap pic(dir);
            int x = ui->image->width();
            int y = ui->image->height();
            ui->image->setPixmap(pic.scaled(x,y,Qt::KeepAspectRatio));
}*/


static inline QString picturesLocation()
{
    return QStandardPaths::standardLocations(QStandardPaths::PicturesLocation).value(0, QDir::currentPath());
}


void Ambulance::on_pushButton_22_clicked()
{
    //to do
    QString m_currentPath;
    //récupérer file name
    QFileDialog fileDialog(this);
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog.setMimeTypeFilters(QStringList() << "image/png"); //<< "image/png"
    fileDialog.setWindowTitle(tr("Open PNG File"));
    if (m_currentPath.isEmpty())
        fileDialog.setDirectory(picturesLocation());

  while (fileDialog.exec() != QDialog::Accepted )
        ;

    m_currentPath=fileDialog.selectedFiles().constFirst() ; //charger image

    QGraphicsScene * scene=new QGraphicsScene(QRect(10, 10, 680, 520));


    QGraphicsItem * image=new QGraphicsPixmapItem(QPixmap(m_currentPath));
    scene ->addItem(image);

    ui->img1->setScene(scene);
    ui->img1->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    ui->img1->show();


}

/*void Ambulance::on_statistique_clicked()
{
    statistique stat ;
    stat.exec();
}*/



void Ambulance::on_consulter_clicked()
{
    QString matricule= ui->id_consulter->text() ;

    QSqlQuery qry;
    qry.prepare("select * from AMBULANCE where matricule = :matricule") ;
    qry.bindValue(":matricule", matricule);
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

    m_currentPath=fileDialog.selectedFiles().constFirst() ; //charger image

    QGraphicsScene * scene=new QGraphicsScene(QRect(10, 10, 680, 520));


    QGraphicsItem * image=new QGraphicsPixmapItem(QPixmap(m_currentPath));
    scene ->addItem(image);

    ui->img2->setScene(scene);
    ui->img2->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    ui->img2->show();
}

void Ambulance::on_statistique_clicked()
{
    statistique stat ;
    stat.exec();
}


