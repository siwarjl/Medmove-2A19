#include "employec.h"
#include <QSqlQuery>
#include<QtDebug>
#include <QObject>
#include <QDateTime>
#include <QPrinter>
#include <QPainter>
#include <QTableView>
#include <QHeaderView>




employec::employec()
{
    cin=0;
    numero=0;
    salaire=0;

    nom="";
    prenom="";
    tache="";

}
employec::employec(int cin ,QString nom,QString prenom,int numero,int salaire,QString tache)
{
        this->cin=cin;
     this->nom=nom;
     this->prenom=prenom;
    this->salaire=salaire;
    this->numero=numero;
    this->tache=tache;


}

bool employec::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO EMPLOYE (cin,nom,prenom,numero,tache,salaire) VALUES (:cin,:nom,:prenom,:numero,:tache,:salaire)");
    query.bindValue(":cin",cin);//liaison avec base de donnée
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":numero",numero);
    query.bindValue(":salaire",salaire);
    query.bindValue(":tache",tache);



    return query.exec();
}

QSqlQueryModel* employec::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM EMPLOYE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("numero"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("salaire"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("tache"));

    QTableView* tableView = new QTableView();
    tableView->setModel(model);

    // Mettre en forme le TableView
    tableView->setStyleSheet("QTableView {background-color: white; alternate-background-color: #FFB4B4; border: none; font-size: 12px;}"
                             "QTableView::item {padding: 5px;}"
                             "QHeaderView::section {background-color: #d8d8d8; color: #333; font-size: 12px;}"
                             "QTableView::horizontalHeader {border: none;}"
                             "QTableView::verticalHeader {border: none;}"
                             "QTableView::item:selected {background-color: #0078D7; color: white;}");

    return model;
}

bool employec::supprimer(int cin){

    QSqlQuery query;
    query.prepare("Delete from EMPLOYE where cin=:cin");
    query.bindValue(":cin",cin);


    return query.exec();
}

bool employec::modifier()
{

    QSqlQuery query;
        query.prepare("UPDATE EMPLOYE SET cin=:cin,nom=:nom,prenom=:prenom , numero=:numero ,salaire=:salaire, tache=:tache WHERE cin=:cin ");
        query.bindValue(":cin",cin);
        query.bindValue(":nom",nom);
        query.bindValue(":prenom",prenom);
        query.bindValue(":numero",numero);
        query.bindValue(":salaire",salaire);
        query.bindValue(":tache",tache);
        return query.exec();
}
QSqlQueryModel* employec::recherche(QString nom )
{



    QSqlQueryModel * model= new QSqlQueryModel();   //creation instance de QSqlQueryModel
        QString qry="select * from EMPLOYE where nom like '%"+nom+"%' ";   //% rechercher toutes les occurrences de la variable "matricule"
        qDebug()<<qry;    //affiche des messages de débogage dans la console
        model->setQuery(qry);
        return model;



}




QSqlQueryModel * employec::afficher_tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT* FROM employe order by CIN desc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));

    return model;
}

QSqlQueryModel * employec::afficher_tri_nom()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT* FROM employe order by NOM asc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));

    return model;
}
QSqlQueryModel * employec::afficher_tri_prenom()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT* FROM employe order by PRENOM asc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));

    return model;
}
QSqlQueryModel * employec::afficher_tri_salaire()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT* FROM employe order by salaire desc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));

    return model;
}
QString employec::apercupdf()
{
    QString text = "<br><br><br><br><h1 style='text-align: center;'>LA LISTE DES EMPLOYES</h1>";
    text += "<table style='border-collapse: collapse; width: 80%; margin: auto;'>";
    text += "<tr style='background-color: #FFB4B4; border: 1px solid #ddd;'>";
    text += "<th style='padding: 12px; text-align: left; border: 1px solid #ddd;'>CIN</th>";
    text += "<th style='padding: 12px; text-align: left; border: 1px solid #ddd;'>NOM</th>";
    text += "<th style='padding: 12px; text-align: left; border: 1px solid #ddd;'>PRENOM</th>";
    text += "<th style='padding: 12px; text-align: left; border: 1px solid #ddd;'>NUMERO</th>";
    text += "<th style='padding: 12px; text-align: left; border: 1px solid #ddd;'>SALAIRE</th>";
    text += "<th style='padding: 12px; text-align: left; border: 1px solid #ddd;'>TACHE</th>";

    text += "</tr>";

    QSqlQuery query;
    QString a, b, c, d, e, f;
    QDateTime dateTime = QDateTime::currentDateTime(); // Récupérer la date et l'heure actuelles
    QString dateStr = dateTime.toString("dd/MM/yyyy hh:mm:ss"); // Formater la date et l'heure

    query.exec("select * from EMPLOYE");
    while (query.next())
    {
        a = query.value(0).toString();
        b = query.value(1).toString();
        c = query.value(2).toString();
        d = query.value(3).toString();
        e = query.value(4).toString();
        f = query.value(5).toString();
        text += "<tr style='background-color: #fff; border: 1px solid #ddd;'>";
        text += "<td style='padding: 12px; text-align: left; border: 1px solid #F5421B;'>" + a + "</td>";
        text += "<td style='padding: 12px; text-align: left; border: 1px solid #F5421B;'>" + b + "</td>";
        text += "<td style='padding: 12px; text-align: left; border: 1px solid #F5421B;'>" + c + "</td>";
        text += "<td style='padding: 12px; text-align: left; border: 1px solid #F5421B;'>" + d + "</td>";
        text += "<td style='padding: 12px; text-align: left; border: 1px solid #F5421B;'>" + e + "</td>";
        text += "<td style='padding: 12px; text-align: left; border: 1px solid #F5421B;'>" + f + "</td>";
        text += "</tr>";
    }

    text += "</table><p>Date et heure de génération du PDF: " + dateStr + "</p>"; // Ajouter la date et l'heure à la fin du texte

    return text;

}
