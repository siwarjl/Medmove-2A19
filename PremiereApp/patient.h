#ifndef PATIENT_H
#define PATIENT_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>


class patient
{
    int cin ,age,num;
        QString nom,prenom,adresse,mail,etat;
public:
    patient();
    patient(int, QString, QString, int, QString, int, QString, QString);
    int getcin(){return cin; }
    QString getnom(){return nom;}
     QString getprenom(){return prenom;}
     int getage(){return age;}
      QString getadresse(){return adresse;}
      int getnumero(){return num;}
       QString getmail(){return mail;}
        QString getetat(){return etat;}

        void setcin(int cin){this->cin=cin;}
        void setnom(QString nom){this->nom=nom;}
         void setprenom(QString prenom){this->prenom=prenom;}
         void setage(int age){this->age=age;}
         void setadresse(QString adresse){this->adresse=adresse;}
         void setnumero(int num){this->num=num;}
          void setmail(QString mail){this->mail=mail;}
           void setetat(QString etat){this->etat=etat;}

        //fonctionalite de class revenue
        bool ajouter();
        QSqlQueryModel* afficher();
        bool supprimer(int);
               bool modifier();
QSqlQueryModel* recherche(QString);
QSqlQueryModel * afficher_tri();
QSqlQueryModel*tricroissant_cin();
    QSqlQueryModel *tricroissant_nom();
    QSqlQueryModel *tricroissant_age();
QString apercupdf();
int statistique_E(QString etat);
int statistique_ET();
QSqlQueryModel *Find_Activite();


};

#endif // PATIENT_H
