#ifndef EMPLOYEC_H
#define EMPLOYEC_H

#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
class employec
{int cin ,salaire,numero;
    QString nom,prenom,tache;
public:
    employec();
    employec(int cin ,QString nom,QString prenom,int numero,int salaire,QString tache);
     //getters
    int getcin(){return cin; }
     QString getnom(){return nom; }

     QString getprenom(){return prenom; }
      int getnumero(){return numero; }


     int getsalaire(){return salaire; }

     QString gettache(){return tache; }




     //setters
     void setcin(int cin){this->cin=cin;}
      void setnom(QString nom){this->nom=nom;}
     void setprenom(QString prenom){this->prenom=prenom;}
     void setnumero(int numero){this->numero=numero;}


     void setsalaire(int salaire){this->salaire=salaire;}
       void settache(QString tache){this->tache=tache;}


     //fonctionalite de class revenue
     bool ajouter();
     QSqlQueryModel* afficher();
     bool supprimer(int);
     bool modifier();
QSqlQueryModel* recherche(QString );
QSqlQueryModel * afficher_tri();
QSqlQueryModel * afficher_tri_nom();
QSqlQueryModel * afficher_tri_salaire();
QString   apercupdf();
QSqlQueryModel * afficher_tri_prenom();



};


#endif // CLIENT_H
