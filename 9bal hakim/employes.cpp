#include "employes.h"
#include "conges.h"



#include <QtDebug>




Employes::Employes()
{
   matemp="";
   congeemp="";
   dateemb="";
   nom="";
   prenom="";
   fonction="";
    salaire=0;
    age=0;






}

Employes::Employes(QString matemp,QString congeemp,QString dateemb,QString nom ,QString prenom ,QString fonction,float salaire,int age)
{
  this->matemp=matemp;
  this->congeemp=congeemp;
  this->dateemb=dateemb;
  this->nom=nom;
  this->prenom=prenom;
  this->fonction=fonction;
  this->salaire=salaire;
    this->age=age;
}


QString Employes::getmatemp(){ return matemp;}
QString Employes::getcongeemp(){ return congeemp;}
QString Employes::getdateemb(){ return dateemb;}
QString Employes::getnom(){ return nom;}
QString Employes::getprenom(){ return prenom;}
QString Employes::getfonction(){ return fonction;}
float Employes::getsalaire(){ return salaire;}
int Employes::getage(){return age;}


void Employes::setmatemp(QString matemp){this->matemp=matemp;}
void Employes::setcongeemp(QString congeemp){ this->congeemp=congeemp;}
void Employes::setdateemb(QString dateemb){ this->dateemb=dateemb;}
void Employes::setnom(QString nom){ this->nom=nom;}
void Employes::setprenom(QString prenom){ this->prenom=prenom;}
void Employes::setfonction(QString fonction){ this->fonction=fonction;}
void Employes::setsalaire(float salaire){ this->salaire=salaire;}
void Employes::setage(int age){this->age=age;}

bool Employes::ajouter()
{

QSqlQuery query;
;
QString salairee= QString::number(salaire);
QString agee= QString::number(age);
query.prepare("INSERT INTO employes (matemp,congeemp,dateemb,nom,prenom,fonction,salaire,age) "
              "VALUES (:matemp,:congeemp,:dateemb, :nom ,:prenom ,:fonction,:salaire,:age)");
query.bindValue(":matemp", matemp);
query.bindValue(":congeemp", congeemp);
query.bindValue(":dateemb", dateemb);
query.bindValue(":nom", nom);
query.bindValue(":prenom",prenom);
query.bindValue(":fonction",fonction);
query.bindValue(":salaire", salairee);
query.bindValue(":age", agee);
 return query.exec();


}

QSqlQueryModel * Employes::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from employes ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("matemp"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("dateemb"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("fonction "));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("congeemp "));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("salaire"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("age"));


        return model;
}

bool Employes::supprimer(QString matemp)
{
    QSqlQuery query;
    query.prepare("Delete from employes where matemp=:matemp");
    query.bindValue(0,matemp);
    return    query.exec();
}

bool Employes::modifier(QString  mat)
{
    QSqlQuery query;


    QString salairee= QString::number(salaire);
    QString agee= QString::number(age);
    query.prepare("UPDATE employes set  congeemp='"+congeemp+"',dateemb='"+dateemb+"',nom='"+nom+"',prenom='"+prenom+"',fonction='"+fonction+"',salaire='"+salairee+"',age='"+agee+"' where matemp like '"+matemp+"' ");

    query.bindValue(":matemp", matemp);
    query.bindValue(":congeemp", congeemp);
    query.bindValue(":dateemb", dateemb);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":fonction",fonction);
    query.bindValue(":salaire", salairee);
     query.bindValue(":age", agee);
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
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("dateemb"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("fonction "));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("congeemp "));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("salaire"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("age"));


        return model;
}


QSqlQueryModel * Employes::affecter_conge()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select idc from conges ");

        return model;
}

QSqlQueryModel * Employes::modifier_liste_employes()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select matemp from employes ");

        return model;
}



bool Employes::affecter(QString)
{
    QSqlQuery query;


    query.prepare("UPDATE employes set  congeemp='"+congeemp+"' where matemp like '"+matemp+"' ");


    query.bindValue(":congeemp", congeemp);

    return    query.exec();
}

QSqlQuery Employes::recuperer(QString matemp)
{
    QSqlQuery query;
    query.prepare("select * from employes where matemp='"+matemp+"'");
    return query;
}


