#include "materiaux.h"
#include <QDebug>
Materiaux::Materiaux()
{
    reference="";
    nom="";
    type="";
    date_achat="";
    prix=0;
}
Materiaux::Materiaux(QString ch1,QString ch2,QString ch3,QString ch4,float n)
{
    reference=ch1;
    nom=ch2;
    type=ch3;
    date_achat=ch4;
    prix=n;
}

QString Materiaux::get_Reference()
{ return reference;}
QString Materiaux::get_Nom()
{return nom;}
QString Materiaux::get_Type()
{return type;}
QString Materiaux::get_Dateachat()
{return date_achat;}
float Materiaux::get_Prix()
{return prix;}
void Materiaux::set_Nom(QString ch)
{nom=ch;}
void Materiaux::set_Type(QString ch)
{type=ch;}
void Materiaux::set_Dateachat(QString ch)
{date_achat=ch;}
void Materiaux::set_Reference(QString ch)
{reference=ch;}
void Materiaux::set_Prix(float n)
{prix=n;}

bool Materiaux::ajouter()
{
QSqlQuery query;
QString prix_materiel= QString::number(prix);
query.prepare("INSERT INTO MATERIAUX (reference,nom,type,date_achat,prix) "
                    "VALUES ('"+reference+"','"+nom+"','"+type+"','"+date_achat+"',"+prix_materiel+")");
return    query.exec();
}


QSqlQueryModel * Materiaux::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from materiaux ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Reference"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date d'achat"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prix "));
    return model;
}

bool Materiaux::supprimer(QString refer)
{
    QSqlQuery query;
    query.prepare("Delete from Materiaux where reference ='"+refer+"'");
    return    query.exec();
}



bool Materiaux::modifier()
{
    QSqlQuery query;
    QString prix_materiel= QString::number(prix);
    query.prepare("UPDATE Materiaux set nom='"+nom+"' ,type='"+type+"' ,PRIX= "+prix_materiel +" , date_achat='"+date_achat+"' where reference like '"+reference+"' ");
    return    query.exec();
}

QSqlQueryModel * Materiaux::liste_materiaux()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select reference from Materiaux ");

    return model;
}
QSqlQuery Materiaux::recuperer_Modification(QString ref)
{
    QSqlQuery query;
    query.prepare("select * from Materiaux where reference ='"+ref+"'");
    return    query;
}

QSqlQueryModel * Materiaux::tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from Materiaux ORDER BY date_achat DESC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Reference"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date d'achat desc"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prix"));
    return model;
}
QSqlQueryModel *Materiaux::rechercher(QString ref)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from Materiaux where reference LIKE '"+ref+"%' ");
    return model;
}

