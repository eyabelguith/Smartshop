#include "produit.h"

Produit::Produit()
{
    matricule=0;
    stock=0;
    m_f=0;
    nom ="";
    prix=0;
}
Produit::Produit(int m,QString n,int f,int s,float p)
{
   matricule=m;
   nom=n;
   m_f=f;
   stock=s;
   prix=p;
}
void Produit::setmatricule(int v)
{
    matricule=v;
}
void Produit::setstock(int v)
{
    stock=v;
}
void Produit::setnom(QString v)
{
    nom=v;
}
void Produit::setf(int v)
{
    m_f=v;
}
void Produit::setprix(float v)
{
    prix=v;
}
void Produit::ajouter()
{   Connection c;
    bool test=c.createconnect();
    if(test)
    {
    QSqlQuery q;
    q.prepare("insert into PRODUIT (NOM,ID,STOCK,NOM_F,prix) values ('"+nom+"','"+matricule+"','"+stock+"','"+m_f+"','"+prix+"')");
    if(q.exec())
    {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("database is save.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    c.close();
    }
}
QSqlQueryModel * Produit::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from Produit ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("STOCK "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOM_F "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRIX "));
        return model;
}
