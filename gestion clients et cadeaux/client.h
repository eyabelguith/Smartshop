#ifndef CLIENT_H
#define CLIENT_H

#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
class Client
{
public:
    Client();
    Client(QString,QString,QString,QString,QString,int,QString);
   QString get_matricule();
    QString get_nom();
    QString get_prenom();
    QString get_adresse();
   QString get_tel();
   QString get_id_cadeau();
    int get_pts();
    void set_matricule(QString);
    void set_nom(QString);
        void set_prenom(QString);
        void set_adresse(QString);
        void set_tel(QString);
        void set_id_cadeau(QString);
        void set_pts(int);
    bool ajouter1();
 bool supprimer1(QString);
 QSqlQueryModel * afficher1();
    QSqlQueryModel * afficherorder1();
    QSqlQueryModel * recherche1(const QString&);
QSqlQueryModel * modifier_liste_matricule();

QSqlQueryModel * tri();
    bool modifier1(QString);
QSqlQueryModel *affecter_cadeau();
private:
    QString nom,prenom,adresse,tel,matricule,id_cadeau;
    int pts;
};

#endif // CLIENT_H
