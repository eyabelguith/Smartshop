#ifndef EMPLOYES_H
#define EMPLOYES_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Employes
{
private:

    int matemp;
    float salaire;
    QString dateemb,nom,prenom,fonction;

public:

    Employes();
    Employes(int,float,QString,QString,QString,QString);




    int getmatemp();
    float getsalaire();
    QString getdateemb();
    QString getnom();
    QString getprenom();
    QString getfonction();


    void setmatemp(int);
    void setsalaire(float);
    void setdateemb(QString);
    void setnom(QString);
    void setprenom(QString);
    void setfonction(QString);

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();

    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel *tri();









};

#endif // EMPLOYES_H
