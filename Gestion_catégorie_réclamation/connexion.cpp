#include "connexion.h"

Connexion::Connexion()
{

}

bool Connexion::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("source_projet_2A");//inserer le nom de la source de données ODBC
db.setUserName("marwa");//inserer nom de l'utilisateur
db.setPassword("marwa");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
    return  test;
}
