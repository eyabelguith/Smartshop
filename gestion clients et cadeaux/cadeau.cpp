#include "cadeau.h"
#include <QString>
#include <QDebug>
Cadeau::Cadeau()
{
id="";
categorie="";
nb=0;
somme=0;
}
Cadeau::Cadeau(QString id,QString categorie,int somme,int nb)
{
    this->id=id;
    this->categorie=categorie;
    this->somme=somme;
    this->nb=nb;

}
QString Cadeau::get_id(){return id;}
QString Cadeau::get_categorie(){return categorie;}

int Cadeau::get_somme(){return somme;}
int Cadeau::get_nb(){return nb;}

void Cadeau::set_categorie(QString cat){categorie=cat;}

void Cadeau::set_somme(int s){somme=s;}
void Cadeau::set_nb(int nb2){nb=nb2;}



bool Cadeau::supprimer2(QString id)
{
QSqlQuery query;

query.prepare("Delete from cadeau where id = :id ");
query.bindValue(":id", id);
return    query.exec();
}
bool Cadeau::ajouter2()
{
QSqlQuery query;

QString s= QString::number(somme);
QString nb2= QString::number(nb);
query.prepare("INSERT INTO cadeau ( id, categorie, somme, nb) "
                    "VALUES (:id, :categorie, :somme, :nb)");
query.bindValue(":id", id);
query.bindValue(":categorie", categorie);
query.bindValue(":somme", s);
query.bindValue(":nb", nb2);

return    query.exec();
}
QSqlQueryModel * Cadeau::affiche2()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from cadeau");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("CATEGORIE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("SOMME"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("NB"));

    return model;
}
QSqlQueryModel * Cadeau::modifier_liste_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select id from cadeau ");

    return model;
}
bool Cadeau::modifier2(QString id)
{
    QSqlQuery query;

    QString s= QString::number(somme);
    QString nb2= QString::number(nb);
    query.prepare("UPDATE cadeau SET ID=:id,CATEGORIE=:categorie,SOMME=:somme,NB=:nb WHERE id=:id");

    query.bindValue(":categorie",categorie);
    query.bindValue(":id",id);
    query.bindValue(":somme",s);
    query.bindValue(":nb",nb2);

    return    query.exec();
}
QSqlQueryModel * Cadeau::recherche2(const QString& categorie)
{

    QSqlQueryModel * model= new QSqlQueryModel();
       model->setQuery("select * from cadeau where categorie LIKE '"+categorie+"%'" );
       return model;
}
QSqlQueryModel * Cadeau::tri2()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from cadeau ORDER BY somme DESC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("CATEGORIE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("SOMME"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NB"));

        return model;
}

