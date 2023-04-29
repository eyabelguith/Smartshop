#ifndef JEU_H
#define JEU_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
class jeu
{
public:
   jeu();
    jeu(QString,QString,QString,QString,QString,QString,QString);

    bool ajouterJeu();
 bool supprimerJeu(QString);
 QSqlQueryModel * afficherJeu();
QSqlQueryModel *rechercherJeu(const QString&);
QSqlQueryModel * triDESC();
QSqlQueryModel * afficherListeIdCadeau();
QSqlQueryModel *afficherListeMatriculeClient();
QSqlQueryModel *afficherListeIdJeu();
    bool modifierJeu(QString);
bool supprimerJeuAutomatique(QString );
private:
    QString idj,mat1,mat2,date_deb,idc,principe,date_fin;

};

#endif // JEU_H
