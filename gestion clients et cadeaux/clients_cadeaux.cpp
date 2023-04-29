#include "clients_cadeaux.h"
#include "ui_clients_cadeaux.h"
#include"client.h"
#include"cadeau.h"

#include<QString>
#include<QMessageBox>
#include<QPixmap>
#include <QSqlQuery>
#include <QSqlQueryModel>
clients_cadeaux::clients_cadeaux(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::clients_cadeaux)
{
    ui->setupUi(this);

}

clients_cadeaux::~clients_cadeaux()
{
    delete ui;
}
void clients_cadeaux::on_pushButton_ajouterCl_2_clicked()
{
    QString nom= ui->lineEdit_nom_ajout_2->text();
    QString prenom= ui->lineEdit_prenom_ajout_2->text();
    QString adresse= ui->lineEdit_adresse_ajout_2->text();
    QString tel= ui->lineEdit_tel_ajout_2->text();

      int pts=0;
      QString matricule= ui->lineEdit_cin_ajout_2->text();
      QString id_cadeau="";
    Client a(matricule,nom,prenom,adresse,tel,pts,id_cadeau);
    bool test=a.ajouter1();
    if(test)
  {

  QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
  QObject::tr("Client ajouté.\nClick Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un client "),
                    QObject::tr("Erreur else !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);




}


void clients_cadeaux::on_pushButton_suppCl_2_clicked()
{
    QString matricule= ui->comboBox_suppCl_2->currentText();

       if(tmpclient.supprimer1(matricule))

           {

                   QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                               QObject::tr("client supprimé.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
                    ui->comboBox_suppCl_2->setModel(tmpclient.modifier_liste_matricule());

               }
               else
                   QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
                               QObject::tr("Erreur !.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
}







void clients_cadeaux::on_pushButton_modifCl_2_clicked()
{
    QString matricule= ui->comboBox_client_2->currentText();
       QString nom= ui->lineEdit_nom_modif_2->text();
       QString prenom= ui->lineEdit_prenom_modif_2->text();
       QString adresse= ui->lineEdit_adresse_modif_2->text();
      QString  tel=ui->lineEdit_tel_modif_2->text();
        int  pts=ui->spinBox_pt_fid_modif_2->text().toInt();
       QString  id_cadeau=ui->comboBox_affecCadeau_2->currentText();
       Client a(matricule,nom,prenom,adresse,tel,pts,id_cadeau);
       bool test=a.modifier1(matricule);
        if(test)
       {
                 QMessageBox::information(nullptr, QObject::tr("Modifier un client"),
                             QObject::tr("client modifié.\n"), QMessageBox::Cancel);

       }
       else
       {
           QMessageBox::critical(nullptr, QObject::tr("Modifier un client"),
                             QObject::tr("Erreur de modification !\n"), QMessageBox::Cancel);
       }
}







void clients_cadeaux::on_tabWidget_2_currentChanged(int index)
{
     ui->tableView_2->setModel(tmpclient.afficher1());
     ui->comboBox_suppCl_2->setModel(tmpclient.modifier_liste_matricule());
      ui->comboBox_client_2->setModel(tmpclient.modifier_liste_matricule());
     ui->comboBox_affecCadeau_2->setModel(tmpclient.affecter_cadeau());
}

void clients_cadeaux::on_pushButton_triCl_2_clicked()
{
     ui->tableView_2->setModel(tmpclient.tri());
}

void clients_cadeaux::on_pushButton_rechCl_3_clicked()
{
    QString nom_client =ui->lineEdit_rech_nom->text();
      ui->tableView_2->setModel(tmpclient.recherche1(nom_client));
}


void clients_cadeaux::on_pushButton_ajoutCa_2_clicked()
{
    QString categorie= ui->lineEdit_categ_ajout_3->text();

    QString id= ui->lineEdit_categ_ajout_2->text();
      int somme= ui->spinBox_exp_ajout_2->text().toInt();
      int nb= ui->spinBox_somme_ajout_2->text().toInt();
    Cadeau ca(id,categorie,somme,nb);
    bool test=ca.ajouter2();
    if(test)
  {

  QMessageBox::information(nullptr, QObject::tr("Ajouter un cadeau"),
  QObject::tr("Cadeau ajouté.\nClick Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un cadeau "),
                    QObject::tr("Erreur else !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



}

void clients_cadeaux::on_pushButton_suppCa_2_clicked()
{
   QString id= ui->comboBox->currentText();
       if(tmpcadeau.supprimer2(id))

           {

                   QMessageBox::information(nullptr, QObject::tr("Supprimer un cadeau"),
                               QObject::tr("cadeau supprimé.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
                    ui->comboBox->setModel(tmpcadeau.modifier_liste_id());

               }
               else
                   QMessageBox::critical(nullptr, QObject::tr("Supprimer un cadeau"),
                               QObject::tr("Erreur !.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
}

void clients_cadeaux::on_pushButton_triCa_2_clicked()
{
     ui->tableView->setModel(tmpcadeau.tri2());
}

void clients_cadeaux::on_pushButton_rechCa_2_clicked()
{
    QString categorie =ui->lineEdit->text();
      ui->tableView->setModel(tmpcadeau.recherche2(categorie));
}

void clients_cadeaux::on_tabWidget_4_currentChanged(int index)
{
    ui->tableView->setModel(tmpcadeau.affiche2());
    ui->comboBox->setModel(tmpcadeau.modifier_liste_id());
     ui->comboBox_Cadeau_2->setModel(tmpcadeau.modifier_liste_id());
}

void clients_cadeaux::on_pushButton_modifCa_2_clicked()
{
    QString id= ui->comboBox_Cadeau_2->currentText();
       QString categorie= ui->lineEdit_categ_modif_2->text();

      int  somme=ui->spinBox->text().toInt();
        int  nb=ui->spinBox_2->text().toInt();
       Cadeau ca(id,categorie,somme,nb);
       bool test=ca.modifier2(id);
        if(test)
       {
                 QMessageBox::information(nullptr, QObject::tr("Modifier un cadeau"),
                             QObject::tr("cadeau modifié.\n"), QMessageBox::Cancel);

       }
       else
       {
           QMessageBox::critical(nullptr, QObject::tr("Modifier un cadeau"),
                             QObject::tr("Erreur de modification !\n"), QMessageBox::Cancel);
       }
}
