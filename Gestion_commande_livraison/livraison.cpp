#include "livraison.h"
#include<QString>
#include<QSqlQuery>
#include <QDebug>
#include<QSqlDatabase>


Livraison::Livraison()
{
num_l=0;
datel="";
prix_l=0;
adr_c="";
}
Livraison::Livraison(int num_l,int prix_l,QString datel,QString adr_c)
{
    this->num_l=num_l;
    this->prix_l=prix_l;
    this->datel=datel;
    this->adr_c=adr_c;
}

void Livraison::set_num_l(int numero){num_l=numero;}
void Livraison::set_prix_l(int px){prix_l=px;}
void Livraison::set_adr_c(QString adr){adr_c=adr;}
void Livraison::set_datel(QString date){datel=date;}

bool Livraison::ajouter()
{
QSqlQuery query;
QString res= QString::number(num_l);
query.prepare("INSERT INTO LIVRAISONS (NUM_L, PRIX_L, DATEL ,ADR_C) "
                    "VALUES (:num_l, :prix_l, :datel ,:adr_c )");


query.bindValue(":num_l", res);
query.bindValue(":prix_l", prix_l);
query.bindValue(":datel", datel);
query.bindValue(":adr_c", adr_c);

return    query.exec();
}

QSqlQueryModel * Livraison::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from LIVRAISONS");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Numéro De Livraison"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prix "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date De Livraison"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse Client"));


    return model;
}
bool Livraison::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from LIVRAISONS where num_l = :num_l ");
query.bindValue(":num_l", res);
return    query.exec();
}
bool Livraison::modifier (int num_l,int prix_l,QString datel,QString adr_c)
{
    QSqlQuery query;
    query.prepare("UPDATE LIVRAISONS SET num_l= :num_l,prix_l= :prix_l,datel= :datel,adr_c = :adr_c  WHERE num_l= :num_l ");

    query.bindValue(":num_l",num_l);
    query.bindValue(":prix_l",prix_l);
    query.bindValue(":datel",datel);
    query.bindValue(":adr_c",adr_c);
    return    query.exec();
}
QSqlQueryModel * Livraison::tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();

       model->setQuery("select * from LIVRAISONS ORDER BY prix_l  ");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Numéro De Livraison"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prix "));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date De Livraison"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse Client"));

           return model;
}

QSqlQueryModel *Livraison::rechercher(QString rech)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from LIVRAISONS where num_l LIKE '"+rech+"%' or datel LIKE '"+rech+"%'");
    return model;
}
