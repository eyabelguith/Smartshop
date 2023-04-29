#include "categories.h"
#include <QDebug>

Categories::Categories()
{
nom="";
date_fabrication="";
prix=0;
}
Categories::Categories(QString nomc,QString date_fab,float prixx)
{
    nom=nomc;
    date_fabrication=date_fab;
    prix=prixx;
}


QString Categories::get_Nom(){return  nom;}
QString Categories::get_Datefab(){return date_fabrication;}
float Categories::get_Prix(){return prix;}
void Categories::set_Nom(QString nomc){nom=nomc;}
void Categories::set_Datefab(QString date_fab){date_fabrication=date_fab;}
void Categories::set_Prix(float prixx){prix=prixx;}


bool Categories::ajouter()
{
QSqlQuery query;
QString prixx= QString::number(prix);
query.prepare("INSERT INTO Categories (NOM_CATEGORIE, DATE_FAB, PRIX) "
                    "VALUES ('"+nom+"', '"+date_fabrication+"', "+prixx+")");
return    query.exec();
}


QSqlQueryModel * Categories::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from CATEGORIES ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM_CATEGORIE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_FAB"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX "));

        return model;
}

bool Categories::supprimer(QString nom_c)
{
    QSqlQuery query;
    query.prepare("Delete from CATEGORIES where NOM_CATEGORIE ='"+nom_c+"'");
    return    query.exec();
}


QSqlQueryModel *Categories::rechercher(QString rech)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from CATEGORIES where NOM_CATEGORIE LIKE '"+rech+"%' or PRIX LIKE '"+rech+"%'");
    return model;
}
bool Categories::modifier()
{
    QSqlQuery query;
    QString prixx= QString::number(prix);
    query.prepare("UPDATE CATEGORIES set PRIX= "+prixx+" , DATE_FAB='"+date_fabrication+"' where NOM_CATEGORIE like '"+nom+"' ");
    return    query.exec();
}

QSqlQueryModel * Categories::modifier_aff_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select nom_categorie from categories ");

        return model;
}
QSqlQuery Categories::recuperer_Modification(QString nom)
{
    QSqlQuery query;
    query.prepare("select * from categories where nom_categorie='"+nom+"'");
    return query;
}


QSqlQueryModel * Categories::tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from CATEGORIES ORDER BY PRIX DESC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM_CATEGORIE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_FAB"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX DESC"));

        return model;
}


