#ifndef PRODUIT_H
#define PRODUIT_H
#include "connection.h"

class Produit
{
private :
    int matricule,stock,m_f;
    QString nom;
    float prix;
public:
    Produit();
    Produit(int,QString,int,int,float);
    int getmatricule()
    {
        return matricule;
    }
    int getstock()
    {
        return stock;
    }
    QString getnom()
    {
        return nom;
    }
    int getf()
    {
        return m_f;
    }
    float getprix()
    {
        return prix;
    }
    void setmatricule(int);
    void setstock(int);
    void setnom(QString);
    void setf(int);
    void setprix(float);
    void ajouter();
    QSqlQueryModel * afficher();


};

#endif // PRODUIT_H
