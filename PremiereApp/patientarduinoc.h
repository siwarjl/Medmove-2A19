#ifndef PATIENTARDUINOC_H
#define PATIENTARDUINOC_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class patientarduinoc
{
    QString coeur;
public:
    patientarduinoc();
     patientarduinoc(QString);

     QString getcoeur(){return coeur; }

     void setcoeur(QString coeur){this->coeur=coeur;}
     bool ajouter();
     QSqlQueryModel* afficher();
};

#endif // PATIENTARDUINOC_H
