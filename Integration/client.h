#ifndef CLIENT_H
#define CLIENT_H
#include "jeu.h"
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
class Client
{
public:
    Client();
    Client(QString,QString,QString,QString,QString,int,QString);
     Client(QString,QString,QString,QString,QString,int);
     Client(QString);

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
bool mettre_a_jour_pts(QString,QString);
QString afficher_cadeauC(QString mat);
QSqlQueryModel * tri_ASC();
QSqlQueryModel * tri_DESC();
    bool modifier1(QString);
      bool modifier2(QString);
int tester_affectation(QString);
QSqlQueryModel *affecter_cadeau(QString);
int verifier_affJeuCl1(QString );
int verifier_affJeuCl2(QString );
QSqlQueryModel *rechercheFidele();
private:
    QString nom,prenom,adresse,tel,matricule,id_cadeau;
    int pts;
};

#endif // CLIENT_H
