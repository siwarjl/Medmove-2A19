#include "donc.h"
#include <QSqlQuery>
#include<QtDebug>
#include <QObject>
#include <QDateTime>
#include <QSqlRecord>
#include <QSqlError>
#include <QPrinter>
#include <QTextDocument>
donc::donc()
{
id=0;
dispo=0;
type="";
donneur="";

}
donc::donc(int id ,int dispo,QString type,QString donneur, QString temps)
{
this->id=id;
this->dispo=dispo;
this->type=type;
this->donneur=donneur;
this->temps=temps;


}
bool donc::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO dons(id,type,dispo,donneur,temps) VALUES (:id,:type,:dispo,:donneur,:temps)");
    query.bindValue(":id",id);
    query.bindValue(":type",type);
    query.bindValue(":dispo",dispo);
    query.bindValue(":donneur",donneur);
    query.bindValue(":temps",temps);


    return query.exec();
}
QSqlQueryModel * donc::afficher()
{
    {
        QSqlQueryModel* model=new QSqlQueryModel();

              model->setQuery("SELECT * FROM dons");
              model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("donneur"));
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("dispo"));
              model->setHeaderData(4, Qt::Horizontal, QObject::tr("temps"));




        return model;
    }

}
bool donc::supprimer(int id){

    QSqlQuery query;
    query.prepare("Delete from dons where id=:id");
    query.bindValue(":id",id);


    return query.exec();
}
bool donc::modifier()
{


    QSqlQuery query;

    query.prepare("UPDATE dons SET id=:id,type=:type,dispo=:dispo,donneur=:donneur,temps=:temps WHERE id=:id");

     query.bindValue(":id",id);
     query.bindValue(":type",type);
     query.bindValue(":dispo",dispo);
     query.bindValue(":donneur",donneur);
     query.bindValue(":temps",temps);

    return query.exec();
}
QSqlQueryModel* donc::recherche(QString donneur )
{

        QSqlQueryModel * model= new QSqlQueryModel();   //creation instance de QSqlQueryModel
            QString qry="select * from DONS where donneur like '%"+donneur+"%' ";   //% rechercher toutes les occurrences de la variable "matricule"
            qDebug()<<qry;    //affiche des messages de débogage dans la console
            model->setQuery(qry);
            return model;



 }
QSqlQueryModel * donc::afficher_tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT* FROM DONS order by ID desc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));

    return model;
}

QString donc::apercupdf()
{

    QString text = "<html><head><style>"
                  "table { border-collapse: collapse; width: 100%; }"
                  "th, td { text-align: center; padding: 10px; }"
                  "th { background-color: #f5a623; color: white; font-weight: bold; font-size: 18px; font-family: 'Roboto', sans-serif; }"
                  "tr:nth-child(even) { background-color: #fcf3cf; }"
                  "tr:nth-child(odd) { background-color: #f7dc6f; }"
                  "tr:hover { background-color: #d35400; color: white; }"
                  "p { text-align: center; font-size: 14px; font-style: italic; }"
                  "</style>"
                  "<link href='https://fonts.googleapis.com/css?family=Roboto' rel='stylesheet'>"
                  "</head><body>"
                  "<table>"
                  "<tr><th>ID</th><th>Type</th><th>Disponibilité</th><th>Donneur</th></tr>";

    QSqlQuery query;
    QString a, b, c, d, e;
    QDateTime dateTime = QDateTime::currentDateTime(); // Récupérer la date et l'heure actuelles
    QString dateStr = dateTime.toString("dd/MM/yyyy hh:mm:ss"); // Formater la date et l'heure

    query.exec("SELECT * FROM DONS");
    int row = 1;
    while (query.next())
    {
        a = query.value(0).toString();
        b = query.value(1).toString();
        c = query.value(2).toString();
        d = query.value(3).toString();
        e = query.value(4).toString();


        if (row % 2 == 0) {
            text += "<tr style='background-color: #fcf3cf;'>";
        } else {
            text += "<tr style='background-color: #f7dc6f;'>";
        }
        text += "<td>" + a + "</td><td>" + b + "</td><td>" + c + "</td><td>" + d + "</td></tr>";
        row++;
    }

    text += "</table><p>Date et heure de génération du PDF: " + dateStr + "</p></body></html>"; // Ajouter la date et l'heure à la fin du texte

    return text;


}
QSqlQueryModel * donc::tricroissant_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select id, type, donneur, dispo ,temps from DONS ORDER BY donneur ASC");

    return model;

}

QSqlQueryModel * donc::tricroissant_dispo()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select id, type, donneur, dispo, temps from DONS ORDER BY dispo ASC");

    return model;

}


QSqlQueryModel * donc::tricroissant_type()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select id, type, donneur, dispo, temps from DONS ORDER BY type ASC");

    return model;

}
