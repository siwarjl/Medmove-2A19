ifndef CLIENTC_H
#define CLIENTC_H
#include<QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class clientc
{
    int cin ,age;
        QString nom,prenom;
    public:
        clientc();
         clientc(int,int, QString, QString);
         //getters
         QString getnom(){return nom; }
         int getcin(){return cin; }
         QString getprenom(){return prenom; }
         int getc(){return cin; }

         //setters
         void setprenom(QString prenom){this->prenom=prenom;}
         void setage(int age){this->age=age;}
         void setc(int cin){this->cin=cin;}
         void setnom(QString nom){this->nom=nom;}
         //fonctionalite de class revenue
         bool ajouter();
         QSqlQueryModel* afficher();
};

#endif // CLIENTC_H
