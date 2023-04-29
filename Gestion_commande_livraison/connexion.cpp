#include "connexion.h"

Connection::Connection()
{}

bool Connection::ouvrirConnection()
{
bool test=false;
    db=QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet_2A");
db.setUserName("eya");//inserer nom de l'utilisateur
db.setPassword("eya");//inserer mot de passe de cet utilisateur


if (db.open()) test = true;


return test;

}
void Connection::fermerConnection()
{db.close();}
