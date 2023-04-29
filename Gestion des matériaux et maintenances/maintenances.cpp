#include "maintenances.h"
#include <QDebug>
Maintenances::Maintenances()
{
    reference="";
    description="";
    date_panne="";
    prix=0;
}
Maintenances::Maintenances(QString ch1,QString ch2,float n,QString ch3)
{
    reference=ch1;
    date_panne=ch2;
    prix=n;
    description=ch3;
}


QString Maintenances::get_Reference()
{ return reference;}
QString Maintenances::get_Description()
{return description;}
QString Maintenances::get_Datepanne()
{return date_panne;}
float Maintenances::get_Prix()
{return prix;}

void Maintenances::set_Description(QString ch)
{description=ch;}
void Maintenances::set_Datepanne(QString ch)
{date_panne=ch;}
void Maintenances::set_Reference(QString ch)
{reference=ch;}
void Maintenances::set_Prix(float n)
{prix=n;}

bool Maintenances::ajouter()
{
QSqlQuery query;
QString prix_reparation= QString::number(prix);
query.prepare("INSERT INTO Maintenances (reference,description,date_panne,prix) "
                    "VALUES (:reference,:description,:date_panne,:prix)");

query.bindValue(":reference", reference);
query.bindValue(":prix", prix_reparation);
query.bindValue(":description", description);
query.bindValue(":date_panne", date_panne);
return    query.exec();
}


QSqlQueryModel * Maintenances::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from Maintenances ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Reference"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date d'panne"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("description "));
    return model;
}

bool Maintenances::supprimer(QString refer)
{
    QSqlQuery query;
    query.prepare("Delete from Maintenances where reference ='"+refer+"'");
    return    query.exec();
}



bool Maintenances::modifier()
{
    QSqlQuery query;
    QString prix_reparation= QString::number(prix);
    query.prepare("UPDATE Maintenances set description='"+description+"' ,PRIX= "+prix_reparation +" , date_panne='"+date_panne+"' where reference like '"+reference+"' ");
    return    query.exec();
}
QSqlQueryModel * Maintenances::affectation_liste_materiaux()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select reference from Materiaux ");

    return model;
}

QSqlQueryModel * Maintenances::liste_Maintenances()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select reference from Maintenances ");

    return model;
}

QSqlQueryModel * Maintenances::tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from Maintenances ORDER BY date_panne DESC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Reference"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date de panne desc"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Description "));

    return model;
}
QSqlQueryModel *Maintenances::rechercher(QString ref)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from Maintenances where reference LIKE '"+ref+"%' ");
    return model;
}


