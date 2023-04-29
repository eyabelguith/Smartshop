#ifndef RECLAMATIONS_H
#define RECLAMATIONS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class reclamations
{
private:
    QString nom_categorie,date_rec,id_client,avis,etat;


public:
    reclamations();
    reclamations(QString,QString,QString,QString,QString);
    QString get_Nomcatg();
    QString get_Idclient();
    QString get_Daterec();
    QString get_avis();
    void set_Nomcatg(QString);
    void set_Idclient(QString);
    void set_Daterec(QString);
    void set_avis(QString);

    bool ajouter();
    QSqlQueryModel * afficher();

    bool supprimer(QString,QString);
    bool supprimertaitee();
    bool modifier();
    QSqlQuery recuperer_Modification(QString,QString);


    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel *tri();
    QSqlQueryModel * affecter_Categorie();
    QSqlQueryModel * affecter_Client();
};

#endif // RECLAMATIONS_H
