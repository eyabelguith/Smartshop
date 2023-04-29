#ifndef COMMANDE_H
#define COMMANDE_H
#include<QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Commande
{
public:
    Commande();
    Commande(int,int,QString,QString);
    int get_id_com();
    int get_num_l();
    QString get_nom_cl();
    QString get_nom_cat();
    void set_id_com(int);
    void set_num_l(int);
    void set_nom_cl(QString);
    void set_nom_cat(QString);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,int,QString,QString);
    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel * tri();
     QSqlQueryModel * affecter_Livraison();
     QSqlQueryModel * affecter_client();
     QSqlQueryModel * affecter_commande();
     QSqlQueryModel * affecter_categorie();



      int  calculerr(QString);
      int verifier_notifi(QString);

private:
    QString nom_cat,nom_cl;
    int id_com,num_l;
};
#endif // COMMANDE_H
