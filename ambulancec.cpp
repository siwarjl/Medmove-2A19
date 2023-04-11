#include "ambulancec.h"
#include <QSqlQuery>
#include<QtDebug>
#include <QDebug>
#include <QObject>
#include<QString>
#include<QDateTime>
Ambulancec::Ambulancec()
{
    matricule="";
    marque="";
    //atec=";
    dispo=""; //disponible
    etat="";


}
Ambulancec::Ambulancec(QString matricule,QString marque,QString datec,QString dispo,QString etat,QPixmap img)
{
    this->matricule=matricule;
    this->marque=marque;
    this->datec=datec;
    this->dispo=dispo;
    this->etat=etat;
    this->img=img;



}

bool Ambulancec::ajouter()
{
    QSqlQuery query;
    //conversion image Qpixmap img lel byte to base 64
    QByteArray bytes;
    QBuffer buffer(&bytes);
    buffer.open(QIODevice::WriteOnly);
    QPixmap pixMap = getImg();
    pixMap.save(&buffer,"PNG");
    query.prepare("INSERT INTO AMBULANCE (matricule,marque,datec,dispo,etat,img) VALUES (:matricule,:marque,:datec,:dispo,:etat,:img)");
    query.bindValue(":matricule",matricule);
    query.bindValue(":marque",marque);
    query.bindValue(":datec",datec);
    query.bindValue(":dispo",dispo);
    query.bindValue(":etat",etat);
    query.bindValue(":img", QVariant(bytes.toBase64().data())); //blob



    return query.exec();   //pour l'execution
}
QSqlQueryModel * Ambulancec::afficher()
{
    {
        QSqlQueryModel* model=new QSqlQueryModel();

              model->setQuery("SELECT * FROM AMBULANCE");
           model->setHeaderData(0, Qt::Horizontal, QObject::tr("matricule"));  //le titre de chaque champs..
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("marque"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("datec"));
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("dispo"));
              model->setHeaderData(4, Qt::Horizontal, QObject::tr("etat"));



        return model;

    }}
bool Ambulancec::supprimer(QString matricule)
{
    QSqlQuery query;
    query.prepare("Delete from AMBULANCE where matricule=:matricule");
    query.bindValue(":matricule",matricule);
    return query.exec();
}
/*bool Ambulancec::modifier()
{
    QSqlQuery query;


        query.prepare("UPDATE AMBULANCE SET marque=:marque,datec=:datec,dispo=:dispo,etat=:etat WHERE matricule=:matricule");
        query.bindValue(":matricule",matricule);
        query.bindValue(":marque",marque);
        query.bindValue(":datec",datec);
        query.bindValue(":dispo",dispo);
        query.bindValue(":etat",etat);
 return query.exec();
}*/
bool Ambulancec::modifier()
{
    QSqlQuery query;
    QByteArray bytes;
    QBuffer buffer(&bytes);
    buffer.open(QIODevice::WriteOnly);
    QPixmap pixMap = getImg();
    pixMap.save(&buffer,"PNG");

        query.prepare("UPDATE AMBULANCE SET matricule=:matricule,marque=:marque,datec=:datec , dispo=:dispo ,etat=:etat, img =:img  WHERE matricule=:matricule");
        query.bindValue(":matricule",matricule);
        query.bindValue(":marque",marque);
        query.bindValue(":datec",datec);
        query.bindValue(":dispo",dispo);
        query.bindValue(":etat",etat);
        query.bindValue(":img", QVariant(bytes.toBase64().data()));

        return query.exec();
}
            //***LES METIERS****//
QSqlQueryModel* Ambulancec::recherche(QString matricule )
{


    QSqlQueryModel * model= new QSqlQueryModel();   //creation instance de QSqlQueryModel
        QString qry="select * from AMBULANCE where matricule like '%"+matricule+"%' ";   //% rechercher toutes les occurrences de la variable "matricule"
        qDebug()<<qry;    //affiche des messages de débogage dans la console
        model->setQuery(qry);
        return model;



}

QSqlQueryModel * Ambulancec::tricroissant_matricule()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select matricule, marque, datec, dispo,etat from AMBULANCE ORDER BY matricule ASC");

    return model;

}

QSqlQueryModel * Ambulancec::tricroissant_marque()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select matricule, marque, datec, dispo,etat from AMBULANCE ORDER BY marque ASC");

    return model;

}


QSqlQueryModel * Ambulancec::tricroissant_etat()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select matricule, marque, datec, dispo,etat from AMBULANCE ORDER BY etat ASC");

    return model;

}
QString Ambulancec::apercupdf()
{
    QString text = "                * LA LISTE DES AMBULANCES *       \n";
    text += "Date et heure d'impression : " + QDateTime::currentDateTime().toString() + "\n\n";

    QSqlQuery query;
    QString a, b, c, d, e;

    query.exec("select * from AMBULANCE");
    while (query.next())
    {
        a = query.value(0).toString();
        b = query.value(1).toString();
        c = query.value(2).toString();
        d = query.value(3).toString();
        e = query.value(4).toString();

        text += " - matricule : " + a + "\n"
              + " - marque : " + b + "\n"
              + " - datec : " + c + "\n"
              + " - dispo : " + d + "\n"
              + " - etat : " + e + "\n    __\n";
    }

    return text;
}

/*int Ambulancec :: statistique_E(QString dispo)
{
 int nbrEF=0;
  QSqlQuery requete("select  DISPO from AMBULANCE  where dispo like '"+dispo+"%' ;");

   while(requete.next())
    {
        nbrEF++;
        }
   return nbrEF;

}
int Ambulancec :: statistique_ET()
{
    int nbrET=0;
     QSqlQuery requete("select dispo from AMBULANCE ");
      while(requete.next())
       {
           nbrET++;
       }
           return nbrET;
}*/
