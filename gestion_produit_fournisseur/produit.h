#ifndef PRODUIT_H
#define PRODUIT_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class produit
{
private :
    QString nom,ref,m_f;
    int stock,prix;

public:
    produit();
    produit(QString,QString,QString,int,int);
    produit(QString,QString,int,int);
    QString getref();
    QString getnom();
    QString getf();
    int getstock();
    int getprix();
    void setref(QString);
    void setstock(int);
    void setnom(QString);
    void setf(QString);
    void setprix(int);
    bool ajouterp();
    QSqlQueryModel * afficherp();
    bool supprmierp(int);
    bool modifierp(QString);
    QSqlQueryModel *recherchep(QString ref);
    QSqlQueryModel *triep();
    QSqlQueryModel * affecter_fournisseur();
    QSqlQueryModel * mailing();



};

#endif // PRODUIT_H
