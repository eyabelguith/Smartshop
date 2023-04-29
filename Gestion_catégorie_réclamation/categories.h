#ifndef CATEGORIES_H
#define CATEGORIES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Categories
{
private:
    QString nom,date_fabrication;
    float prix;

public:
    Categories();
    Categories(QString,QString,float);

    QString get_Nom();
    QString get_Datefab();
    float get_Prix();
    void set_Nom(QString);
    void set_Datefab(QString);
    void set_Prix(float);

    bool ajouter();
    QSqlQueryModel * afficher();

    bool supprimer(QString);
    bool modifier();
    QSqlQueryModel * modifier_aff_id();
    QSqlQuery recuperer_Modification(QString);


    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel *tri();

    Categories get_Categorie(QString);

};

#endif // CATEGORIES_H
