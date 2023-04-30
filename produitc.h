#ifndef PRODUITC_H
#define PRODUITC_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>


class produitc
{ QString id;
    QString nom,marque,disponibilite,etat;
public:
    produitc();
    produitc(QString,QString,QString,QString,QString);
    //getters
  QString getid(){return id; }
    QString getnom(){return nom; }
    QString getmarque(){return marque; }
    QString getdisponibilite(){return disponibilite; }
    QString getetat(){return etat; }


    //setters
    void setid(QString id){this->id=id;}
    void setnom(QString nom){this->nom=nom;}
    void setmarque(QString marque){this->marque=marque;}
    void setpdisponibilite(QString disponibilite){this->disponibilite=disponibilite;}
    void setpetat(QString etat){this->etat=etat;}


    //fonctionalite de class revenue
    bool ajouter();
     QSqlQueryModel* afficher1(QString lettre);
     QSqlQueryModel* afficher();

         bool supprimer(QString);
       bool modifier();
       QSqlQueryModel* recherche(QString n);
       QSqlQueryModel * afficher_tri();
        int statistique_E(QString dispo);
        int statistique_ET();
QSqlQueryModel* afficher_tri1();
//QString apercupdf();
QSqlQueryModel *tricroissant_etat();
QSqlQueryModel *tricroissant_id();
QSqlQueryModel *tricroissant_disponibilite();
bool ajouter1();


};

#endif // PRODUITC_H
