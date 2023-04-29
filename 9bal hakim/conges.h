#ifndef CONGES_H
#define CONGES_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>



class Conges
{
private:

    int duree;
    QString idc,type,datedeb,datefin;

public:

    Conges();
    Conges(int,QString,QString,QString,QString);



  int getduree();
    QString getidc();
    QString gettype();
    QString getdatebdeb();
    QString getdatefin();



    void setduree(int);

    void setidc(QString);
    void settype(QString);
    void setdatedeb(QString);
    void setdatefin(QString);


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool modifier();

    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel *tri();

    QSqlQueryModel * modifier_liste_conges();

    QSqlQuery recupererc(QString);











};

#endif // CONGES_H
