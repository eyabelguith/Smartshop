#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>


class Connection
{
private:
    QSqlDatabase db;
public:
    Connection();
    bool ouvrirConnection();
    void fermerConnection();

};
#endif // CONNEXION_H
