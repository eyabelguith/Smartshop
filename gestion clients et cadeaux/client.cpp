#include "client.h"
#include <QString>
#include <QDebug>
Client::Client()
{
matricule="";
nom="";
prenom="";
adresse="";
tel="";
pts=0;
id_cadeau="";
}
Client::Client(QString matricule,QString nom,QString prenom,QString adresse,QString tel,int pts,QString id_cadeau)
{
    this->matricule=matricule;
    this->nom=nom;
    this->prenom=prenom;
    this->adresse=adresse;
    this->tel=tel;
    this->pts=pts;
    this->id_cadeau=id_cadeau;
}
QString Client::get_nom(){return  nom;}
QString Client::get_prenom(){return prenom;}
QString Client::get_adresse(){return adresse;}
QString Client::get_tel(){return tel;}
int Client::get_pts(){return pts;}
QString Client::get_matricule(){return matricule;}
void Client::set_nom(QString n){nom=n;}
void Client::set_prenom(QString p){prenom=p;}
void Client::set_adresse(QString ad){adresse=ad;}
void Client::set_tel(QString t){tel=t;}
void Client::set_pts(int pt){pts=pt;}
void Client::set_matricule(QString mat){matricule=mat;}
QString Client::get_id_cadeau(){return id_cadeau;}
void Client::set_id_cadeau(QString idc){id_cadeau=idc;}
bool Client::supprimer1(QString mat)
{
QSqlQuery query;

query.prepare("Delete from client where matricule = :matricule ");
query.bindValue(":matricule", mat);
return    query.exec();
}
bool Client::ajouter1()
{
QSqlQuery query;



QString p= QString::number(pts);

query.prepare("INSERT INTO client ( matricule, nom, prenom, adresse, tel, pts, id_cadeau) "
                    "VALUES (:matricule, :nom, :prenom, :adresse, :tel, :pts, :id_cadeau)");
query.bindValue(":matricule", matricule);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":adresse", adresse);
query.bindValue(":tel", tel);
query.bindValue(":pts", p);
query.bindValue(":id_cadeau", id_cadeau);

return    query.exec();
}
QSqlQueryModel * Client::afficher1()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from client");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("MATRICULE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("TEL"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("PTS"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("id_cadeau"));
    return model;
}
QSqlQueryModel * Client::modifier_liste_matricule()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select matricule from client ");

    return model;
}
bool Client::modifier1(QString mat)
{
    QSqlQuery query;

      QString pt= QString::number(pts);


    query.prepare("UPDATE client SET MATRICULE=:matricule,NOM=:nom,PRENOM=:prenom,ADRESSE=:adresse,TEL=:tel,PTS=:pts,id_cadeau=:id_cadeau WHERE matricule=:matricule");

    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":adresse",adresse);
    query.bindValue(":tel",tel);
     query.bindValue(":pts",pt);
      query.bindValue(":matricule",mat);
       query.bindValue(":id_cadeau",id_cadeau);

    return    query.exec();
}
QSqlQueryModel * Client::recherche1(const QString& nom)
{

    QSqlQueryModel * model= new QSqlQueryModel();
       model->setQuery("select * from client where nom LIKE '"+nom+"%'" );
       return model;
}
QSqlQueryModel * Client::tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from client ORDER BY pts DESC");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("MATRICULE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TEL"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("PTS"));
 model->setHeaderData(6, Qt::Horizontal, QObject::tr("id_cadeau"));

        return model;
}

QSqlQueryModel * Client::affecter_cadeau()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select id from cadeau ");

        return model;
}
