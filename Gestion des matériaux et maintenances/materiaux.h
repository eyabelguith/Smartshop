#ifndef MATERIAUX_H
#define MATERIAUX_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Materiaux
{
private:
    QString reference,nom,type,date_achat;
    float prix;

public:
    Materiaux();
    Materiaux(QString,QString,QString,QString,float);

    QString get_Reference();
    QString get_Nom();
    QString get_Type();
    QString get_Dateachat();
    float get_Prix();
    void set_Nom(QString);
    void set_Type(QString);
    void set_Dateachat(QString);
    void set_Reference(QString);
    void set_Prix(float);

    bool ajouter();
    QSqlQueryModel * afficher();

    QSqlQueryModel * liste_materiaux();
    bool supprimer(QString);
    bool modifier();


    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel *tri();

};

#endif // MATERIAUX_H
