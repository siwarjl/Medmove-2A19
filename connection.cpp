#include "connection.h"
<<<<<<< HEAD

=======
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
>>>>>>> origin/gestionAmbulance
Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
<<<<<<< HEAD
db.setUserName("emna");//inserer nom de l'utilisateur
db.setPassword("emna");//inserer mot de passe de cet utilisateur
=======
db.setUserName("siwar");//inserer nom de l'utilisateur
db.setPassword("123");//inserer mot de passe de cet utilisateur
>>>>>>> origin/gestionAmbulance

if (db.open())
test=true;





    return  test;
}
