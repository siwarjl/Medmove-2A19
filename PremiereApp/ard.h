#ifndef ARD_H
#define ARD_H

#include <QString>
#include <string.h>
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
class ard
{
    QString lum;
public:
 ard();
    ard(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
};

#endif // ARD_H
