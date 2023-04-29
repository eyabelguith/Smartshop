#ifndef CADEAU_H
#define CADEAU_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
class Cadeau
{
public:
    Cadeau();
    Cadeau(QString,QString,int,int);
    QString get_id();
    QString get_categorie();

   int get_nb();
    int get_somme();
    void set_id(QString);
    void set_categorie(QString);

        void set_nb(int);
        void set_somme(int);
    bool ajouter2();
 bool supprimer2(QString);
 QSqlQueryModel * affiche2();

    QSqlQueryModel * recherche2(const QString&);
QSqlQueryModel * modifier_liste_id();

QSqlQueryModel * tri2();
    bool modifier2(QString);
    QVector<double> statistique();
private:
    QString categorie,id;
    int nb,somme;
};

#endif // CADEAU_H
