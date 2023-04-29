#ifndef CONNECTION_H
#define CONNECTION_H
#include <QDebug>
#include <QDialog>
#include <QMainWindow>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QString>

class Connection
{
public:
    QSqlDatabase db;
public:
    Connection();
    bool createconnect();
    void close();
};



#endif // CONNECTION_H
