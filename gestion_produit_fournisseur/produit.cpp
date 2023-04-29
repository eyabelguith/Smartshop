#include "produit.h"

produit::produit()
{
    ref="";
    stock=0;
    m_f="";
    nom ="";
    prix=0;
}
produit::produit(QString r,QString n,QString m,int s,int p)
{
    ref=r;
    stock=s;
    m_f=m;
    nom =n;
    prix=p;
}
produit::produit(QString r,QString n,int s,int p)
{
    ref=r;
    stock=s;
    nom =n;
    prix=p;
}
void produit::setref(QString v)
{
    ref=v;
}
void produit::setstock(int v)
{
    stock=v;
}
void produit::setnom(QString v)
{
    nom=v;
}
void produit::setf(QString v)
{
    m_f=v;
}
void produit::setprix(int v)
{
    prix=v;
}
QString produit::getref()
{
    return ref;
}
QString produit::getnom()
{
    return nom;
}
QString produit::getf()
{
    return m_f;
}
int produit::getstock()
{
    return stock;
}
int produit::getprix()
{
    return prix;
}
bool produit::ajouterp()
{
    QSqlQuery query;
    query.prepare("insert into produit (REF,NOM,STOCK,PRIX,M_F) "
                  "values(:ref,:nom,:stock,:prix,:m_f)");
    query.bindValue(":ref",ref);
    query.bindValue(":nom",nom);
    query.bindValue(":stock",stock);
    query.bindValue(":prix",prix);
    query.bindValue(":m_f",m_f);
    return  query.exec();

}
QSqlQueryModel * produit::afficherp()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from PRODUIT ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF   "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM   "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("STOCK "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIX  "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("matr_F"));
        return model;
}
QSqlQueryModel * produit::mailing()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select f.nom,p.nom,p.stock,f.email from fournisseur f join produit p on (p.m_f=f.matricule) where stock<20 ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr(" matricule   "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("produit   "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("STOCK "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("        E_mail          "));
    return model;

}


bool produit::supprmierp(int ref)
{
    QSqlQuery query;
    QString t= QString::number(ref);
    query.prepare("DELETE FROM PRODUIT WHERE REF = :ID");
    query.bindValue(":ID", t);
    return    query.exec();
}
bool produit::modifierp(QString ref)
{
    QSqlQuery query;  
    query.prepare("update PRODUIT set NOM=:nom,STOCK=:stock,PRIX=:prix where REF = :ref");
            query.bindValue(":nom",nom);
            query.bindValue(":stock",stock);
            query.bindValue(":prix",prix);
            query.bindValue(":ref",ref);
            return query.exec();
}
QSqlQueryModel *produit::recherchep(QString ref)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from PRODUIT where REF like '%"+ref+"%' OR NOM like '%"+ref+"%'OR m_f like '%"+ref+"%' OR STOCK like '%"+ref+"%' OR PRIX like '%"+ref+"%'  ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF  "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM  "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("STOCK "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIX  "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NOM_F "));
    return model;

}
int returnstock(QString ref)
{
    QSqlQuery query;
    query.prepare("select STOCK from PRODUIT where NOM like '%"+ref+"%  ");
    if(query.exec())
    {
        while(query.next())
        {

            return query.value(0).toInt();
        }
    }
}
QSqlQueryModel * produit::triep()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from PRODUIT order BY Prix  ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF  "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM  "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("STOCK "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIX  "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NOM_F "));
        return model;
}
QSqlQueryModel * produit::affecter_fournisseur()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select matricule from fournisseur");
    return model;
}








































