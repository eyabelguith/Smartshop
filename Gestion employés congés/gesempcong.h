#ifndef GESEMPCONG_H
#define GESEMPCONG_H

#include"employes.h"

#include"conges.h"
#include <QDialog>




namespace Ui {
class gesempcong;
}

class gesempcong : public QDialog
{
    Q_OBJECT

public:
    explicit gesempcong(QWidget *parent = nullptr);
    ~gesempcong();

private slots:
 void on_ajoutemp_clicked();
 void on_tabWidget_employes_currentChanged(int index);
 void on_suppemp_clicked();
 void on_modifemp_clicked();


 void on_pushButton_rechercheemp_clicked();
 void on_triemp_clicked();

 void on_pushButton_ajouterconges_clicked();

 void on_pushButton_modifierconges_clicked();

 void on_pushButton_supprimerconges_clicked();

 void on_tabWidget_conges_currentChanged(int index);



 void on_tricong_clicked();

 void on_recherchecong_clicked();

private:
    Ui::gesempcong *ui;
    Employes insemployes;
    Conges insconges;



};


#endif // GESEMPCONG_H
