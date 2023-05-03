#include "connection.h"
<<<<<<< HEAD
<<<<<<< HEAD

=======
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
>>>>>>> origin/gestionAmbulance
=======

>>>>>>> origin/produit
Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
<<<<<<< HEAD
db.setDatabaseName("Source_Projet2A");
<<<<<<< HEAD
db.setUserName("emna");//inserer nom de l'utilisateur
db.setPassword("emna");//inserer mot de passe de cet utilisateur
=======
db.setUserName("siwar");//inserer nom de l'utilisateur
db.setPassword("123");//inserer mot de passe de cet utilisateur
>>>>>>> origin/gestionAmbulance
=======
db.setDatabaseName("Source_projet2A");
db.setUserName("yasmine");//inserer nom de l'utilisateur
db.setPassword("200225");//inserer mot de passe de cet utilisateur
>>>>>>> origin/produit

if (db.open())
test=true;





    return  test;
}
