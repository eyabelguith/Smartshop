#ifndef GESEMPCONG_H
#define GESEMPCONG_H

#include"employes.h"
#include "chat.h"
#include <QPropertyAnimation>
#include"conges.h"
#include <QDialog>

#include<QSound>
#include <QPropertyAnimation>
#include "smtp.h"
#include <QtWidgets/QMessageBox>
#include <QFileDialog>
#include "arduino.h"
#include"statemp.h"
#include "server.h"
#include "projeth.h"


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

 void on_pushButton_ajouterconges_2_clicked();
 void on_pushButton_modifierconges_clicked();

 void on_pushButton_supprimerconges_clicked();

 void on_tabWidget_conges_currentChanged(int index);



 void on_tricong_clicked();

 void on_recherchecong_clicked();



 void on_affecterbouton_clicked();

 void on_mmatricule_currentIndexChanged(const QString &arg1);

 void on_idcm_currentIndexChanged(const QString &arg1);


private slots:
    void sendMail();
    void mailSent(QString);
    void browse();








  void on_excel_clicked();

  void on_statstemp_clicked();

  void on_server_2_clicked();
   void on_pushButton_clicked();

private:
    Ui::gesempcong *ui;
    Employes insemployes;
    Conges insconges;
    QStringList files;
    QSound *son;
    QPropertyAnimation *animation;
    QByteArray data;
    arduino A;
    projeth tmph;





};


#endif // GESEMPCONG_H
