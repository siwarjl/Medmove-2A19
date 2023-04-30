#ifndef HISTORIQUE_H
#define HISTORIQUE_H
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>


class historique
{
public:

    historique();
    void enregistrer_txt(QString,QString,QString,QString,QString);
    QString imprimer_hist();
    void enregistrer_txt1(QString,QString,QString,QString,QString);
    void enregistrer_txt2(QString);
private:
    QString chaine;
};

#endif // HISTORIQUE_H
