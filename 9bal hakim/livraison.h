#ifndef LIVRAISON_H
#define LIVRAISON_H
#include<QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class Livraison
{
public:
    Livraison();
    Livraison(int,int,QString,QString);

    int get_num_l();
    QString get_adr_c();
    int get_prix_l();
    QString get_datel();
    void set_num_l(int);
    void set_adr_c(QString);
    void set_prix_l(int);
    void set_datel(QString);
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int);
    bool modifier(int,int,QString,QString);
    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel * tri();
private:
    int num_l,prix_l ;
    QString datel,adr_c;


};
#endif // LIVRAISON_H
