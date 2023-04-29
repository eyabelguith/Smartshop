#include "fournisseur.h"

fournisseur::fournisseur()
{
    matricule="";
    nom="";
    adresse="";
    email="";
    tel=0;
}

fournisseur::fournisseur(QString m,QString n,QString a,QString e,int t)
{
    matricule=m;
    nom=n;
    adresse=a;
    email=e;
    tel=t;
}
bool fournisseur::ajouterf()
{
    QSqlQuery q;
    //q.prepare("inset into fournisseur (MATRICULE,NOM,ADRESSE,EMAIL,TEL) values (:matricule,:nom,:adresse,:email,:tel)");
    q.prepare("insert into fournisseur (MATRICULE,NOM,ADRESSE,EMAIL,TEL) "
                  "values(:matricule,:nom,:adresse,:email,:tel)");
    q.bindValue(":matricule",matricule);
    q.bindValue(":nom",nom);
    q.bindValue(":adresse",adresse);
    q.bindValue(":email",email);
    q.bindValue(":tel",tel);
    return q.exec();

}
bool fournisseur::modifierf(QString m)
{
    QSqlQuery q;
    q.prepare("update fournisseur set  NOM=:nom,ADRESSE=:adresse,email=:email,tel=:tel where MATRICULE like '"+m+"' ");
    q.bindValue(":nom",nom);
    q.bindValue(":adresse",adresse);
    q.bindValue(":email",email);
    q.bindValue(":tel",tel);
    return q.exec();
}
QSqlQueryModel * fournisseur::afficherf()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from fournisseur");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("MAtricule"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("email"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("n°tel"));
    return model;
}
QSqlQueryModel * fournisseur::affichercf()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select MATRICULE from fournisseur");
    return model;
}

bool fournisseur::supprimerf(QString m)
{
    QSqlQuery query;
    query.prepare("DELETE FROM fournisseur WHERE MATRICULE = :m");
    query.bindValue(":m", m);
    return    query.exec();
}
QSqlQueryModel * fournisseur::trief()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from fournisseur order by NOM");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Matricule "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM       "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse   "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("email     "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("n°tel     "));
    return model;
}
QSqlQueryModel * fournisseur::cherchef(QString m)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from fournisseur where MATRICULE like '%"+m+"%' OR NOM like '%"+m+"%' OR ADRESSE like '%"+m+"%' OR EMAIL like '%"+m+"%'  ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Matricule "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM       "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse   "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("email     "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("n°tel     "));
    return model;
}

