#ifndef CONGES_H
#define CONGES_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Conges
{
private:

    int idc,duree,matem;
    QString type,datedeb,datefin;

public:

    Conges();
    Conges(int,int,int,QString,QString,QString);




    int getidc();
    int getduree();
    int getmatem();
    QString gettype();
    QString getdatebdeb();
    QString getdatefin();



    void setidc(int);
    void setduree(int);
    void setmatem(int);
    void settype(QString);
    void setdatedeb(QString);
    void setdatefin(QString);


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();

    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel *tri();











};

#endif // CONGES_H
