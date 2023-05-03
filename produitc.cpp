#include "produitc.h"
#include <QSqlQuery>
#include<QtDebug>
#include <QObject>
#include <QDateTime>
produitc::produitc()
{
id="";
nom="";
marque="";
disponibilite="";
etat="";
}
produitc::produitc(QString id ,QString nom,QString marque,QString disponibilite,QString etat)
{
    this->id=id;
this->nom=nom;
this->marque=marque;
this->disponibilite=disponibilite;
this->etat=etat;

}
bool produitc::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO PRODUIT1 (id,nom,marque,disponibilite,etat) VALUES (:id,:nom,:marque,:disponibilite,:etat)");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":marque",marque);
    query.bindValue(":disponibilite",disponibilite);
    query.bindValue(":etat",etat);


    return query.exec();
}
QSqlQueryModel * produitc::afficher()
{
    {
        QSqlQueryModel* model=new QSqlQueryModel();

              model->setQuery("SELECT * FROM PRODUIT1");
              model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("marque"));
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("disponibilite"));
              model->setHeaderData(4, Qt::Horizontal, QObject::tr("etat"));





        return model;
    }

}
QSqlQueryModel* produitc::afficher1(QString lettre)
{
    QSqlQueryModel* model = new QSqlQueryModel();

    QSqlQuery query;
    query.prepare("SELECT * FROM produit1 WHERE nom LIKE :lettre");
    query.bindValue(":lettre", lettre + "%"); // add % to search for any product starting with the letter
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Marque"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Disponibilite"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Etat"));

    return model;
}

bool produitc::supprimer(QString id){

    QSqlQuery query;
    query.prepare("Delete from produit1 where id=:id");
    query.bindValue(":id",id);


    return query.exec();
}
bool produitc::modifier()
{


    QSqlQuery query;

    query.prepare("UPDATE PRODUIT1 SET nom=:nom,marque=:marque,disponibilite=:disponibilite , etat=:etat  WHERE id = :id");
     query.bindValue(":id",id);
     query.bindValue(":nom",nom);
     query.bindValue(":marque",marque);
    query.bindValue(":disponibilite",disponibilite);
    query.bindValue(":etat",etat);

    return query.exec();
}
/*bool produitc::modifier()
{
    QSqlQuery query;
    QString id_string= QString::number(id);
 //   QString nom_string= QString::number(nom);

          query.prepare("UPDATE EQUIPEMENTS SET id=:id, nom=:nom, marque=:marque , disponibilite=:disponibilite, etat=:etat WHERE id=:id ");

          query.bindValue(":id",id_string);
          query.bindValue(":nom",nom);
          query.bindValue(":marque",marque);
          query.bindValue(":disponibilite",disponibilite);
          query.bindValue(":etat",etat);


            return query.exec();

}*/

QSqlQueryModel * produitc::recherche(QString n)
 {
    QSqlQueryModel* model = new QSqlQueryModel();
     QSqlQuery query;

     query.prepare("select * from produit1 where nom like '"+n+"%' or  etat like '"+n+"%'   or disponibilite like '"+n+"%'   ");
    query.addBindValue("%"+ n +"%");
    query.exec();
    model->setQuery(query);

    return (model);}


QSqlQueryModel * produitc::tricroissant_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from produit1 ORDER BY id ASC");

    return model;

}

QSqlQueryModel * produitc::tricroissant_disponibilite()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from produit1 ORDER BY disponibilite ASC");

    return model;

}


QSqlQueryModel * produitc::tricroissant_etat()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from produit1 ORDER BY etat ASC");

    return model;

}
