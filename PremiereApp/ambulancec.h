#ifndef AMBULANCEC_H
#define AMBULANCEC_H
#include<QString>
#include<QDate>
#include<QSqlQuery> //modif
#include<QSqlQueryModel>
#include <QPixmap>
#include <QBuffer>

class Ambulancec
{
    QString matricule,marque,etat,datec;

    QString dispo;
    QPixmap img;


public:
    Ambulancec();
    Ambulancec(QString,QString,QString,QString,QString,QPixmap);
    //getters
    QString getmatricule(){return matricule; }
    QString getmarque(){return marque; }
    QString getdate(){return datec; }
    QString getdispo(){return dispo; }
    QString getetat(){return etat; }
     QPixmap getImg(){return img;}
    //setters
    void setmatricule(QString matricule){this->matricule=matricule;}
    void setmarque(QString marque){this->marque=marque;}
    void setdate( QString datec){this->datec=datec;}
    void setdispo(QString dispo){this->dispo=dispo;}
    void setetat(QString etat){this->etat=etat;}
    void setImg (QPixmap img){this->img=img;}
    //fonctionalite de class revenue
    bool ajouter();
    QSqlQueryModel* afficher();    //QSqlQueryModel recu sans modif
    bool supprimer(QString);
    bool modifier();
    QSqlQueryModel* recherche(QString);
    QSqlQueryModel*tricroissant_matricule();
    QSqlQueryModel*tricroissant_marque();
    QSqlQueryModel*tricroissant_etat();

    QString apercupdf();
    int statistique_E(QString dispo);
    int statistique_ET();



};

#endif // AMBULANCEC_H
