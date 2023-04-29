#ifndef GESTION_P_F_H
#define GESTION_P_F_H

#include <QDialog>

namespace Ui {
class Produit;
}

class Produit : public QDialog
{
    Q_OBJECT

public:
    explicit Produit(QWidget *parent = nullptr);
    ~Produit();

private:
    Ui::Produit *ui;
};

#endif // GESTION_P_F_H
