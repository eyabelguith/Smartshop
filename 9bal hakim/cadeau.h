#ifndef CADEAU_H
#define CADEAU_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include "jeu.h"
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
bool mettre_a_jour_nb_exp(QString);
        void set_nb(int);
        void set_somme(int);
    bool ajouter2();
 bool supprimer2(QString);
 QSqlQueryModel * affiche2();
QSqlQueryModel *  chercher_categ(QString);
    QSqlQueryModel * recherche2(const QString&);
QSqlQueryModel * modifier_liste_id();

QSqlQueryModel * tri2();
    bool modifier2(QString);
 int  calculer(QString);
int verifier_notif(QString);
int verifier_affJeu(QString );
private:
    QString categorie,id;
    int nb,somme;
};

#endif // CADEAU_H
