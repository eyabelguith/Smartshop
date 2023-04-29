#ifndef MAINTENANCES_H
#define MAINTENANCES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Maintenances
{
private:
    QString reference,description,date_panne;
    float prix;

public:
    Maintenances();
    Maintenances(QString,QString,float,QString);

    QString get_Reference();
    QString get_Description();
    QString get_Datepanne();
    float get_Prix();
    void set_Description(QString);
    void set_Datepanne(QString);
    void set_Reference(QString);
    void set_Prix(float);

    bool ajouter();
    QSqlQueryModel * afficher();

    QSqlQueryModel * affectation_liste_materiaux();
    QSqlQueryModel * liste_Maintenances();
    bool supprimer(QString);
    bool modifier();


    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel *tri();
};

#endif // MAINTENANCES_H
