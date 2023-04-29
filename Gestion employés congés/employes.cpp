#include "employes.h"

#include <QtDebug>



Employes::Employes()
{
   matemp=0;
   salaire=0;
   dateemb="";
   nom="";
   prenom="";
   fonction="";


}

Employes::Employes(int matemp,float salaire,QString dateemb,QString nom ,QString prenom ,QString fonction)
{
  this->matemp=matemp;
  this->salaire=salaire;
  this->dateemb=dateemb;
  this->nom=nom;
  this->prenom=prenom;
  this->fonction=fonction;
}


int Employes::getmatemp(){ return matemp;}
float Employes::getsalaire(){ return salaire;}
QString Employes::getdateemb(){ return dateemb;}
QString Employes::getnom(){ return nom;}
QString Employes::getprenom(){ return prenom;}
QString Employes::getfonction(){ return fonction;}


void Employes::setmatemp(int matemp){ this->matemp=matemp;}
void Employes::setsalaire(float salaire){ this->salaire=salaire;}
void Employes::setdateemb(QString dateemb){ this->dateemb=dateemb;}
void Employes::setnom(QString nom){ this->nom=nom;}
void Employes::setprenom(QString prenom){ this->prenom=prenom;}
void Employes::setfonction(QString fonction){ this->fonction=fonction;}

bool Employes::ajouter()
{

QSqlQuery query;
QString mat_string= QString::number(matemp);
QString salairee= QString::number(salaire);
query.prepare("INSERT INTO employes (matemp,salaire,dateemb,nom,prenom,fonction) "
              "VALUES (:matemp, :salaire, :dateemb, :nom ,:prenom ,:fonction)");
query.bindValue(":matemp", mat_string);
query.bindValue(":salaire", salairee);
query.bindValue(":dateemb", dateemb);
query.bindValue(":nom", nom);
query.bindValue(":prenom",prenom);
query.bindValue(":fonction",fonction);
 return query.exec();


}

QSqlQueryModel * Employes::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from employes ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("matemp"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("salaire"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("dateemb "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("nom "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("prenom "));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("fonction "));


        return model;
}

bool Employes::supprimer(int matemp)
{
    QSqlQuery query;
    query.prepare("Delete from employes where matemp=:matemp");
    query.bindValue(0,matemp);
    return    query.exec();
}

bool Employes::modifier()
{
    QSqlQuery query;
    QString mat_string= QString::number(matemp);
    QString salairee= QString::number(salaire);
    query.prepare("UPDATE employes set salaire='"+salairee+"',dateemb='"+dateemb+"',nom='"+nom+"',prenom='"+prenom+"',fonction='"+fonction+"' where matemp like '"+mat_string+"' ");
    return    query.exec();
}



QSqlQueryModel *Employes::rechercher(QString rech)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from employes where fonction LIKE '"+rech+"%' or dateemb LIKE '"+rech+"%'");
    return model;
}

QSqlQueryModel * Employes::tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from employes ORDER BY salaire DESC");


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("matemp"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("salaire"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("dateemb "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("nom "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("prenom "));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("fonction "));

        return model;
}






