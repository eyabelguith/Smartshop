#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class fournisseur
{
private:
    QString matricule,nom,adresse,email;
    int tel;

public:
    fournisseur();
    fournisseur(QString,QString,QString,QString,int);
    QString getnom();
    QString getmatricule();
    QString getadresse();
    QString getemail();
    int gettel();
    void setmatricule(QString);
    void setnom(QString);
    void setadresse(QString);
    void setemail(QString);
    void settel(int);
    bool ajouterf();
    QSqlQueryModel * afficherf();
    QSqlQueryModel * affichercf();
    bool supprimerf(QString);
    bool modifierf(QString);
    QSqlQueryModel * trief();
    QSqlQueryModel * cherchef(QString);


};

#endif // FOURNISSEUR_H
