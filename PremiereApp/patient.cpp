#include "patient.h"
#include <QDebug>
#include <QDateTime>
#include "dialog.h"
patient::patient()
{
cin=0;
nom="";
prenom="";
age=0;
adresse="";
num=0;
mail="";
etat="";


}
patient::patient(int cin, QString nom, QString prenom,int age,QString adresse,int num, QString mail, QString etat)
{
        this->cin=cin;
        this->nom=nom;
        this->prenom=prenom;
         this->age=age;
         this->adresse=adresse;
         this->num=num;
     this->mail=mail;
     this->etat=etat;
}

bool patient::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO PATIENTC (cin,nom,prenom,age,adresse,numero,mail,etat) VALUES (:cin,:nom,:prenom,:age,:adresse,:numero,:mail,:etat)");
    query.bindValue(":cin",cin);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
     query.bindValue(":age",age);
      query.bindValue(":adresse",adresse);
 query.bindValue(":numero",num);
  query.bindValue(":mail",mail);
   query.bindValue(":etat",etat);
    return query.exec();
}

QSqlQueryModel * patient::afficher()
{
    {
        QSqlQueryModel* model=new QSqlQueryModel();

              model->setQuery("SELECT * FROM PATIENTC");
               model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
               model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
                model->setHeaderData(5, Qt::Horizontal, QObject::tr("numero"));
                 model->setHeaderData(6, Qt::Horizontal, QObject::tr("mail"));
                  model->setHeaderData(7, Qt::Horizontal, QObject::tr("etat"));



        return model;
    }}
bool patient::modifier()
{


    QSqlQuery query;

    query.prepare("UPDATE PATIENTC SET nom=:nom,prenom=:prenom , age=:age, adresse=:adresse,numero=:numero,mail=:mail,etat=:etat WHERE cin= :cin");
query.bindValue(":cin",cin);
     query.bindValue(":nom",nom);
     query.bindValue(":prenom",prenom);
    query.bindValue(":age",age);
     query.bindValue(":adresse",adresse);
     query.bindValue(":numero",num);
     query.bindValue(":mail",mail);
query.bindValue(":etat",etat);
    return query.exec();
}
bool patient::supprimer(int cin){

    QSqlQuery query;
    query.prepare("Delete from PATIENTC where cin=:cin");
    query.bindValue(":cin",cin);


    return query.exec();
}

QSqlQueryModel* patient::recherche(QString nom )
{


    QSqlQueryModel * model= new QSqlQueryModel();   //creation instance de QSqlQueryModel
            QString qry="select * from PATIENTC where nom like '%"+nom+"%' ";   //% rechercher toutes les occurrences de la variable "matricule"
            qDebug()<<qry;    //affiche des messages de débogage dans la console
            model->setQuery(qry);
            return model;



}


QSqlQueryModel * patient::afficher_tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT* FROM PATIENTC order by CIN desc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));

    return model;
}
QSqlQueryModel * patient::tricroissant_cin()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select cin, nom, prenom, age,adresse,numero,mail,etat from PATIENTC ORDER BY cin ASC");

    return model;

}

QSqlQueryModel * patient::tricroissant_nom()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select cin, nom, prenom, age,adresse,numero,mail,etat from PATIENTC ORDER BY nom ASC");

    return model;

}


QSqlQueryModel * patient::tricroissant_age()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select cin, nom, prenom, age,adresse,numero,mail,etat from PATIENTC ORDER BY age ASC");

    return model;

}
QString patient::apercupdf()
{
    QString text = "<br><br><br><br><br><br><br>";
        text += "<\n\n>";
          text += "<table class=centrer; style=border: 45px; width: 100%;'>";


          text += "<tr style='background-color: #696969; border: 10px solid #ddd;'>&emsp;&emsp;";
          text += "<th style='padding: 45px; text-align: center; border: 45px solid #ddd;'>CIN</th>";
          text += "<th style='padding: 45px; text-align: center; border: 45px solid #ddd;'>NOM</th>";
          text += "<th style='padding: 45px; text-align: center; border: 45px solid #ddd;'>PRENOM</th>";
          text += "<th style='padding: 45px; text-align: center; border: 45px solid #ddd;'>AGE</th>";
          text += "<th style='padding: 45px; text-align: center; border: 45px solid #ddd;'>ADRESSE</th>";
          text += "<th style='padding: 45px; text-align: center; border: 45px solid #ddd;'>NUMERO</th>";
          text += "<th style='padding: 45px; text-align: center; border: 45px solid #ddd;'>MAIL</th>";
          text += "<th style='padding: 45px; text-align: center; border: 45px solid #ddd;'>ETAT</th>";

          text += "</tr>";

          QSqlQuery query;
          QString a, b, c, d, e,f,g,h;
          QDateTime dateTime = QDateTime::currentDateTime(); // Récupérer la date et l'heure actuelles
          QString dateStr = dateTime.toString("dd/MM/yyyy hh:mm:ss"); // Formater la date et l'heure

          query.exec("select * from PATIENTC");
          while (query.next())
          {
              a = query.value(0).toString();
              b = query.value(1).toString();
              c = query.value(2).toString();
              d = query.value(3).toString();
              e = query.value(4).toString();
              f = query.value(5).toString();
              g = query.value(6).toString();
              h = query.value(7).toString();

              text += "<tr style='background-color: #fff; border: 1px solid #ddd;'>";
              text += "<td style='padding: 45px; text-align: left; border: 45px solid #F5421B;'>" + a + "</td>";
              text += "<td style='padding: 45px; text-align: left; border: 45px solid #F5421B;'>" + b + "</td>";
              text += "<td style='padding: 45px; text-align: left; border: 45px solid #F5421B;'>" + c + "</td>";
              text += "<td style='padding: 45px; text-align: left; border: 45px solid #F5421B;'>" + d + "</td>";
              text += "<td style='padding: 45px; text-align: left; border: 45px solid #F5421B;'>" + e + "</td>";
               text += "<td style='padding: 45px; text-align: left; border: 45px solid #F5421B;'>" + f+ "</td>";
                text += "<td style='padding: 45px; text-align: left; border: 45px solid #F5421B;'>" + g + "</td>";
                 text += "<td style='padding: 45px; text-align: left; border: 45px solid #F5421B;'>" + h + "</td>";

              text += "</tr>";
          }

          text += "<br></table><p  style='text-align: left';>Date et heure de génération du PDF: " + dateStr + "</p>"; // Ajouter la date et l'heure à la fin du texte

          return text;

}
int patient :: statistique_ET()
{
    int nbrET=0;
     QSqlQuery requete("select etat from PATIENTC ");
      while(requete.next())
       {
           nbrET++;
       }
           return nbrET;
}

QSqlQueryModel* patient::Find_Activite()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT CIN,NOM,PRENOM,AGE,ADRESSE,NUMERO,MAIL,ETAT FROM PATIENTC");

    query.exec();
    model->setQuery(query);
    return model;
}
