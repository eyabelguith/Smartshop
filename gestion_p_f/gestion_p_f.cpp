#include "gestion_p_f.h"
#include "ui_produit.h"

Produit::Produit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Produit)
{
    ui->setupUi(this);
}

Produit::~Produit()
{
    delete ui;
}
