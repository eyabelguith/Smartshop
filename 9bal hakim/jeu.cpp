#include "jeu.h"
#include "cadeau.h"
#include "client.h"
#include <QString>
#include <QDebug>
jeu::jeu()
{
idj="";
mat1="";
mat2="";
date_deb="";
date_fin="";
principe="";
idc="";
}
jeu::jeu(QString idj,QString mat1,QString mat2, QString date_deb,QString date_fin,QString principe,QString idc)
{
    this->idj=idj;
    this->mat1=mat1;
    this->mat2=mat2;
    this->date_deb=date_deb;
    this->date_fin=date_fin;
    this->principe=principe;
    this->idc=idc;


}


bool jeu::supprimerJeu(QString id)
{
QSqlQuery query;

query.prepare("Delete from jeu where idj = :id ");
query.bindValue(":id", id);
return    query.exec();
}

bool jeu::supprimerJeuAutomatique(QString datesys)
{
QSqlQuery query;

query.prepare("Delete from jeu where date_fin = :datesys ");
query.bindValue(":datesys", datesys);
return    query.exec();
}
bool jeu::ajouterJeu()
{
QSqlQuery query;


query.prepare("INSERT INTO jeu ( idj, mat1, mat2, date_deb, date_fin, principe, idc) "
                    "VALUES (:idj, :mat1, :mat2, :date_deb, :date_fin, :principe, :idc)");
query.bindValue(":idj", idj);
query.bindValue(":mat1", mat1);
query.bindValue(":mat2", mat2);
query.bindValue(":date_deb", date_deb);
query.bindValue(":date_fin",date_fin);
query.bindValue(":principe", principe);
query.bindValue(":idc", idc);


return    query.exec();
}
QSqlQueryModel * jeu::afficherJeu()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from jeu");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id Jeu Concours"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Matricule client1"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Matricule client2"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date début"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date fin"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Règle de jeu"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("Cadeau"));

    return model;
}
QSqlQueryModel * jeu::afficherListeIdCadeau()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select id from cadeau where nb!=0 ");

    return model;
}
QSqlQueryModel * jeu::afficherListeMatriculeClient()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select matricule from client where pts>0 ");

    return model;
}
QSqlQueryModel * jeu::afficherListeIdJeu()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select idj from jeu ");

    return model;
}
bool jeu::modifierJeu(QString idj)
{
    QSqlQuery query;



    query.prepare("UPDATE jeu SET IDJ ='"+idj+"' , MAT1 ='"+mat1+"',MAT2 ='"+mat2+"', DATE_DEB  ='"+date_deb+"', DATE_FIN  ='"+date_fin+"', PRINCIPE  ='"+principe+"', IDC  ='"+idc+"' WHERE IDJ ='"+idj+"'");


    return    query.exec();
}
QSqlQueryModel * jeu::rechercherJeu(const QString& date)
{

    QSqlQueryModel * model= new QSqlQueryModel();
       model->setQuery("select * from jeu where (date_deb LIKE '"+date+"%' OR date_fin LIKE '"+date+"%' )" );
       return model;
}
QSqlQueryModel * jeu::triDESC()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from jeu ORDER BY date_deb ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id Jeu Concours"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Matricule client1"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Matricule client2"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date début"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date fin"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Règle de jeu"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Cadeau"));

        return model;
}
