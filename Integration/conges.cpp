#include "conges.h"

#include <QtDebug>




Conges::Conges()
{
   idc="";
   duree=0;
   type="";
   datedeb="";
   datefin="";




}

Conges::Conges(int duree,QString idc,QString type ,QString datedeb ,QString datefin)
{this->duree=duree;
  this->idc=idc;
  this->type=type;
  this->datedeb=datedeb;
  this->datefin=datefin;
}






int Conges::getduree(){ return duree;}
QString Conges:: getidc(){ return idc;}
QString Conges::gettype(){ return type;}
QString Conges::getdatebdeb(){ return datedeb;}
QString Conges::getdatefin(){ return datefin;}



void Conges::setduree(int duree){ this->duree=duree;}
void Conges::setidc(QString idc){ this->idc=idc;}
void Conges::settype(QString type){ this->type=type;}
void Conges::setdatedeb(QString datedeb){ this->datedeb=datedeb;}
void Conges::setdatefin(QString datefin){ this->datefin=datefin;}

bool Conges::ajouter()
{

QSqlQuery query;

QString duree_string= QString::number(duree);


query.prepare("INSERT INTO conges (idc,duree,type,datedeb,datefin) "
              "VALUES (:idc, :duree, :type ,:datedeb ,:datefin)");
query.bindValue(":duree", duree_string);
query.bindValue(":idc", idc);
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
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("datedeb "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("datefin "));


        return model;
}

bool Conges::supprimer(QString idc)
{
    QSqlQuery query;
    query.prepare("Delete from conges where idc=:idc");
    query.bindValue(0,idc);
    return    query.exec();
}

bool Conges::modifier()
{
    QSqlQuery query;

    QString duree_string= QString::number(duree);


    query.prepare("UPDATE conges set duree='"+duree_string+"',type='"+type+"',datedeb='"+datedeb+"',datefin='"+datefin+"' where idc like '"+idc+"' ");
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
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("datedeb "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("datefin "));

        return model;
}


QSqlQueryModel * Conges::modifier_liste_conges()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select idc from conges ");

    return model;
}

QSqlQuery Conges::recupererc(QString idc)
{
    QSqlQuery query;
    query.prepare("select * from conges where idc='"+idc+"'");
    return query;
}




