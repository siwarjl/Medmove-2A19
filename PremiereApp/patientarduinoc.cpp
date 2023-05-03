#include "patientarduinoc.h"
#include <QSqlQuery>
#include<QtDebug>
#include <QObject>
patientarduinoc::patientarduinoc()
{
    coeur="";

}
patientarduinoc::patientarduinoc(QString coeur)
{
     this->coeur=coeur;
}
bool patientarduinoc::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO patientarduino (coeur) VALUES (:coeur)");

    query.bindValue(":coeur",coeur);

    return query.exec();
}
QSqlQueryModel* patientarduinoc::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();





          model->setQuery("SELECT * FROM patientarduino");

          model->setHeaderData(0, Qt::Horizontal, QObject::tr("coeur"));

    return model;
}
