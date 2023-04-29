#include "gestion_produit_fournisseur.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    gestion_produit_fournisseur w;
    w.show();
    return a.exec();
}
