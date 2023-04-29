#include "commande.h"
#include <QDebug>
#include<QSqlDatabase>
#include<QSqlQuery>
#include "connexion.h"
Commande::Commande()
{
    id_com=0;
    num_l=0;
    nom_cl="";
    nom_cat="";

}
Commande:: Commande(int id_com,int num_l,QString nom_cl, QString nom_cat)
{
  this->id_com=id_com;
  this->num_l=num_l;
  this->nom_cl=nom_cl;
  this->nom_cat=nom_cat;

}
void Commande::set_nom_cl(QString client){ nom_cl=client; }
void Commande::set_nom_cat(QString categorie){ nom_cat=categorie; }
void Commande::set_num_l(int numero){ num_l=numero; }
void Commande::set_id_com(int id){ id_com=id; }


bool Commande::ajouter()
{
QSqlQuery query;
QString res= QString::number(id_com);
query.prepare("INSERT INTO COMMANDES (ID_COM, NOM_CAT, NUM_L, NOM_CL) "
                    "VALUES (:id_com, :nom_cat, :num_l ,:nom_cl )");
query.bindValue(":id_com", res);
query.bindValue(":nom_cat", nom_cat);
query.bindValue(":num_l", num_l);

query.bindValue(":nom_cl", nom_cl);

return    query.exec();
}

QSqlQueryModel * Commande::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from COMMANDES");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_COM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Numéro "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom Client"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom Catégorie"));


    return model;
}

bool Commande::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from COMMANDES where ID_COM = :id_com ");
query.bindValue(":id_com", res);
return    query.exec();
}
bool Commande::modifier (int id_com,int num_l,QString nom_cat,QString nom_cl)
{
    QSqlQuery query;
    query.prepare("UPDATE COMMANDES SET id_com= :id_com,num_l= :num_l,nom_cat= :nom_cat,nom_cl = :nom_cl  WHERE id_com= :id_com ");
    query.bindValue(":id_com",id_com);
    query.bindValue(":num_l",num_l);
    query.bindValue(":nom_cat",nom_cat);
    query.bindValue(":nom_cl",nom_cl);
    return    query.exec();
}
QSqlQueryModel * Commande::tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from COMMANDES ORDER BY num_l ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_COM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Numéro "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom Client"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom Catégorie"));
        return model;
}

QSqlQueryModel *Commande::rechercher(QString rech)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from COMMANDES where nom_cl LIKE '"+rech+"%' or nom_cat LIKE '"+rech+"%'");
    return model;
}


QSqlQueryModel * Commande::affecter_Livraison()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select num_l from livraisons ");

        return model;
}


QSqlQueryModel * Commande::affecter_client()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select matricule from client");

        return model;
}

QSqlQueryModel * Commande::affecter_commande()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select id_com from commandes");

        return model;
}



QSqlQueryModel * Commande::affecter_categorie()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select NOM_CATEGORIE from categories");

        return model;
}



int Commande::calculerr(QString typeCom) {
      QSqlQuery query;

      query.prepare("select * from COMMANDES where (NOM_CAT = :typeCom)");
      query.bindValue(":typeCom", typeCom);

   query.exec();
      int total = 0;
      while (query.next()) {
        total++;
      }
return total;}



