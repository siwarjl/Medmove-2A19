#ifndef DONC_H
#define DONC_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class donc
{ int id,dispo;
    QString donneur,type,temps;
public:
    donc();
     donc(int,int, QString, QString, QString);
     //getters
   int getid(){return id; }
   int getdispo(){return dispo; }

     QString getdonneur(){return donneur; }

     QString gettype(){return type; }

     QString gettemps(){return temps; }


     //setters
      void setid(int id){this->id=id;}
     void setdispo(int dispo){this->dispo=dispo;}
     void setdonneur(QString donneur){this->donneur=donneur;}
     void settype(QString type){this->type=type;}
     void settemps(QString temps){this->temps=temps;}


     //fonctionalite de class revenue
     bool ajouter();
     QSqlQueryModel* afficher();
     bool supprimer(int);
        bool modifier();
    QSqlQueryModel* recherche(QString );
    QSqlQueryModel*tricroissant_id();
        QSqlQueryModel *tricroissant_dispo();
        QSqlQueryModel *tricroissant_type();
        QSqlQueryModel* afficher_tri();

        QString   apercupdf();


};

#endif // DONC_H
