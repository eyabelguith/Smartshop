#include "reclamations.h"
#include <QDebug>
#include<QMessageBox>
reclamations::reclamations()
{
nom_categorie="";
date_rec="";
id_client="";
avis="";
etat="";
}
reclamations::reclamations(QString catg,QString client,QString dat,QString aviss,QString etatt)
{
    nom_categorie=catg;
    date_rec=dat;
    id_client=client;
    avis=aviss;
    etat=etatt;
}
QString reclamations::get_Nomcatg(){return nom_categorie;}
QString reclamations::get_Idclient(){return id_client;}
QString reclamations::get_Daterec(){return date_rec;}
QString reclamations::get_avis(){return avis;}
void reclamations::set_Nomcatg(QString ch){nom_categorie=ch;}
void reclamations::set_Idclient(QString ch){id_client=ch;}
void reclamations::set_Daterec(QString ch){avis=ch;}
void reclamations::set_avis(QString ch){avis=ch;}

bool reclamations::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO Reclamations (NOM_CATEGORIE, ID_CLIENT, DATE_REC, AVIS, ETAT) "
                        "VALUES (:nom_categorie, :id_client, :date_rec, :avis, :etat)");
    query.bindValue(":nom_categorie", nom_categorie);
    query.bindValue(":id_client", id_client);
    query.bindValue(":date_rec", date_rec);
    query.bindValue(":avis", avis);
    query.bindValue(":etat", etat);
    return    query.exec();

}
QSqlQueryModel * reclamations::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from RECLAMATIONS ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CLIENT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_CATEGORIE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_REC"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("AVIS"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ETAT"));

        return model;
}

bool reclamations::supprimer(QString nom,QString id)
{
    QSqlQuery query,test;
    int  fama=0;
    test.prepare("select count(*) from reclamations where(id_client like '"+id+"' and nom_categorie like '"+nom+"')");
    if(test.exec())
    {
    while(test.next())
    {
      fama=test.value(0).toInt();
      if(fama!=0)
      {
          query.prepare("Delete from RECLAMATIONS where ((NOM_CATEGORIE like '"+nom+"')AND (id_client like '"+id+"'))  ");

          return    query.exec();

      }
    }
}
 return false;
}
bool reclamations::supprimertaitee()
{
    QSqlQuery query;
    query.prepare("Delete from RECLAMATIONS where (Etat like 'Traitee')  ");
    return query.exec();

}
bool reclamations::modifier()
{
    QSqlQuery query,test;
    int  fama=0;
    test.prepare("select count(*) from reclamations where(id_client like '"+id_client+"' and nom_categorie like '"+nom_categorie+"')");
    if(test.exec())
    {
    while(test.next())
    {
      fama=test.value(0).toInt();
      if(fama!=0)
      {
          query.prepare("UPDATE RECLAMATIONS set DATE_REC='"+date_rec+"' , AVIS='"+avis+"' where (id_client like '"+id_client+"' and nom_categorie like '"+nom_categorie+"')");

          return    query.exec();

      }
    }
}
 return false;
}
QSqlQuery reclamations::recuperer_Modification(QString nom,QString id)
{
    QSqlQuery query;
    query.prepare("select * from reclamations where (nom_categorie='"+nom+"' and id_client='"+id+"') ");
    return query;
}
QSqlQueryModel * reclamations::rechercher(QString rech)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from RECLAMATIONS where NOM_CATEGORIE LIKE '"+rech+"%' or DATE_REC LIKE '"+rech+"%' or ID_CLIENT like '"+rech+"%' ");
    return model;
}
QSqlQueryModel *reclamations::tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from RECLAMATIONS ORDER BY DATE_REC DESC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CLIENT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_CATEGORIE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_REC"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("AVIS"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ETAT"));

        return model;
}
QSqlQueryModel * reclamations::affecter_Categorie()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select nom_categorie from categories ");

        return model;
}
QSqlQueryModel * reclamations::affecter_Client()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select matricule from client ");

        return model;
}

