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
Client::Client(QString matricule,QString nom,QString prenom,QString adresse,QString tel,int pts)
{
    this->matricule=matricule;
    this->nom=nom;
    this->prenom=prenom;
    this->adresse=adresse;
    this->tel=tel;
    this->pts=pts;

}
Client::Client(QString id_cadeau)
{

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
                    "VALUES (:matricule, :nom, :prenom, :adresse, :tel, :pts, :id_cadeau) ");
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
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Matricule"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Téléphone"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Points fidelité"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("Cadeau affecté"));
    return model;
}
QString Client::afficher_cadeauC(QString mat)
{
    QSqlQuery query;

    query.prepare("select id_cadeau from client where matricule=:matricule");
query.bindValue(":matricule", mat);
return    id_cadeau;

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


    query.prepare("UPDATE client SET MATRICULE=:matricule,NOM=:nom,PRENOM=:prenom,ADRESSE=:adresse,TEL=:tel,PTS=:pts WHERE matricule=:matricule");

    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":adresse",adresse);
    query.bindValue(":tel",tel);
     query.bindValue(":pts",pt);
      query.bindValue(":matricule",mat);


    return    query.exec();
}
bool Client::modifier2(QString mat)
{
    QSqlQuery query;



    query.prepare("UPDATE client SET id_cadeau=:id_cadeau WHERE matricule=:matricule");


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
QSqlQueryModel * Client::tri_DESC()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from client ORDER BY pts DESC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Matricule"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Téléphone"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Points fidelité"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Cadeau affecté"));
        return model;
}
QSqlQueryModel * Client::tri_ASC()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from client ORDER BY pts ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Matricule"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Téléphone"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Points fidelité"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Cadeau affecté"));
        return model;
}
QSqlQueryModel * Client::affecter_cadeau(QString mat)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select id from cadeau ca NATURAL JOIN client cl where cl.PTS>=ca.SOMME and cl.matricule  LIKE '"+mat+"'and ca.nb!=0 ");


        return model;
}

int Client::tester_affectation(QString mat)
{
    QSqlQuery query;
    query.prepare("select * from client cl  join cadeau ca on(ca.ID=cl.id_cadeau) where(cl.matricule = :matricule )");
    query.bindValue(":matricule", mat);
    query.exec();
       int total = 0;
       while (query.next()) {
         total++;
       }
 return total;

}
bool Client::mettre_a_jour_pts(QString matricule,QString id)
{
    QSqlQuery query;
    query.prepare("UPDATE client SET pts=(select (pts-(select somme from cadeau WHERE id = :id)) from client WHERE matricule = :matricule) WHERE matricule=:matricule");


      query.bindValue(":matricule",matricule);
query.bindValue(":id",id);

    return    query.exec();
}
int Client::verifier_affJeuCl1(QString matricule )
{   QSqlQuery query;
    query.prepare("select *  from client cl join jeu j on(cl.matricule = j.mat1) where (cl.matricule=:matricule)");
    query.bindValue(":matricule", matricule);

 query.exec();
    int total = 0;
    while (query.next()) {
      total++;
    }
return total;

}
int Client::verifier_affJeuCl2(QString matricule )
{   QSqlQuery query;
    query.prepare("select *  from client cl join jeu j on(cl.matricule = j.mat2) where (cl.matricule=:matricule)");
    query.bindValue(":matricule", matricule);

 query.exec();
    int total = 0;
    while (query.next()) {
      total++;
    }
return total;

}
QSqlQueryModel * Client::rechercheFidele()
{

    QSqlQueryModel * model= new QSqlQueryModel();
       model->setQuery("select * from client where pts=(select Max(pts) from client) " );
       return model;
}
