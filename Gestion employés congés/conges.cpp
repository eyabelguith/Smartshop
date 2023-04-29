#include "conges.h"

#include <QtDebug>



Conges::Conges()
{
   idc=0;
   duree=0;
   matem=0;
   type="";
   datedeb="";
   datefin="";



}

Conges::Conges(int idc,int duree,int matemp,QString type ,QString datedeb ,QString datefin)
{
  this->idc=idc;
  this->duree=duree;
  this->matem=matemp;
  this->type=type;
  this->datedeb=datedeb;
  this->datefin=datefin;
}





int Conges:: getidc(){ return idc;}
int Conges::getduree(){ return duree;}
int Conges::getmatem(){ return matem;}
QString Conges::gettype(){ return type;}
QString Conges::getdatebdeb(){ return datedeb;}
QString Conges::getdatefin(){ return datefin;}


void Conges::setidc(int idc){ this->idc=idc;}
void Conges::setduree(int duree){ this->duree=duree;}
void Conges::setmatem(int matemp){ this->matem=matemp;}
void Conges::settype(QString type){ this->type=type;}
void Conges::setdatedeb(QString datedeb){ this->datedeb=datedeb;}
void Conges::setdatefin(QString datefin){ this->datefin=datefin;}

bool Conges::ajouter()
{

QSqlQuery query;
QString idc_string= QString::number(idc);
QString duree_string= QString::number(duree);
QString matt_string= QString::number(matem);

query.prepare("INSERT INTO conges (idc,duree,matem,type,datedeb,datefin) "
              "VALUES (:idc, :duree, :matem, :type ,:datedeb ,:datefin)");
query.bindValue(":idc", idc_string);
query.bindValue(":duree", duree_string);
query.bindValue(":matem", matt_string);
query.bindValue(":type", type);
query.bindValue(":datedeb",datedeb);
query.bindValue(":datefin",datefin);

 return query.exec();


}

QSqlQueryModel * Conges::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from conges ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idc"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("duree"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("matem "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("datedeb "));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("datefin "));


        return model;
}

bool Conges::supprimer(int idc)
{
    QSqlQuery query;
    query.prepare("Delete from conges where idc=:idc");
    query.bindValue(0,idc);
    return    query.exec();
}

bool Conges::modifier()
{
    QSqlQuery query;
    QString idc_string= QString::number(idc);
    QString duree_string= QString::number(duree);
    QString matt_string= QString::number(matem);

    query.prepare("UPDATE conges set duree='"+duree_string+"',matem='"+ matt_string+"',type='"+type+"',datedeb='"+datedeb+"',datefin='"+datefin+"' where idc like '"+idc_string+"' ");
    return    query.exec();
}


QSqlQueryModel *Conges::rechercher(QString rech)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from conges where type LIKE '"+rech+"%'");
    return model;
}

QSqlQueryModel * Conges::tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from conges ORDER BY duree DESC");


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idc"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("duree"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("matem "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("datedeb "));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("datefin "));

        return model;
}






