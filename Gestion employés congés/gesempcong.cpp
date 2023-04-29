#include "gesempcong.h"
#include "ui_gesempcong.h"
#include "employes.h"
#include "conges.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include<QIntValidator>
#include<QValidator>

gesempcong::gesempcong(QWidget *parent) :
    QDialog(parent),

    ui(new Ui::gesempcong)
{
    ui->setupUi(this);
}

gesempcong::~gesempcong()
{
    delete ui;
}

void gesempcong::on_ajoutemp_clicked()
{
    int matemp=ui->matricule ->text().toInt();
    float salaire=ui->salaire->text().toFloat();
    QString dateemb=ui->dateemb->text();
    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    QString fonction=ui->fonction->text();

    Employes E(matemp,salaire,dateemb,nom,prenom,fonction);
    if(E.ajouter()) {
        QMessageBox::information(nullptr, QObject::tr("BRAVO!!!"),
                    QObject::tr("Ajout effectuer avec succés.\n" ), QMessageBox::Cancel);

        ui->matricule->setText("");
        ui->salaire->setText("");
        ui->dateemb->setText("");
                ui->nom->setText("");
                ui->prenom->setText("");
                ui->fonction->setText("");


}else{
        QMessageBox::information(nullptr, QObject::tr("ECHEC!!!"),
                    QObject::tr("employé existe déja.\n"), QMessageBox::Cancel);
    }

}



void gesempcong::on_tabWidget_employes_currentChanged(int index)
{
    ui->tableemp->setEnabled(true);
    ui->tableemp->setModel(insemployes.afficher());


}


void gesempcong::on_suppemp_clicked()
{
    Employes e1;
    e1.setmatemp(ui->comboBox_employes_sup->text().toInt());
    if(e1.supprimer(e1.getmatemp()))
    {
        QMessageBox::information(nullptr, QObject::tr("Supprimer un employé"),
                    QObject::tr("Suppression avec succés.\n" ), QMessageBox::Cancel);

    }
    else
    { QMessageBox::critical(nullptr, QObject::tr("Erreur!"),
                    QObject::tr("non supprimé.\n"
                                ), QMessageBox::Cancel);

    }



}

void gesempcong::on_modifemp_clicked()
{

    int matemp=ui->mmatricule ->text().toInt();
    float salaire=ui->msalaire->text().toFloat();
    QString dateemb=ui->mdateemb->text();
    QString nom=ui->mnom->text();
    QString prenom=ui->mprenom->text();
    QString fonction=ui->mfonction->text();
   Employes E(matemp,salaire,dateemb,nom,prenom,fonction);
    if(E.modifier())
    {
              QMessageBox::information(nullptr, QObject::tr("Modifier un employé"),
                          QObject::tr("employé modifie.\n"), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier un employé"),
                          QObject::tr("Erreur !\n"), QMessageBox::Cancel);
    }
}

void gesempcong::on_pushButton_rechercheemp_clicked()
{
       QString rech =ui->rechercheemp->text();
      ui->tableemp->setModel(insemployes.rechercher(rech));
}


void gesempcong::on_triemp_clicked()
{
      ui->tableemp->setModel(insemployes.tri());
}






void gesempcong::on_pushButton_ajouterconges_clicked()
{
int idc=ui->idc->text().toInt();
int duree=ui->duree->text().toInt();
int matem=ui->matemp->text().toInt();

    QString type=ui->type->text();
    QString datedeb=ui->datedeb->text();
    QString datefin=ui->datefin->text();


    Conges c(idc,duree,matem,type,datedeb,datefin);
    if(c.ajouter()) {
        QMessageBox::information(nullptr, QObject::tr("BRAVO!!!"),
                    QObject::tr("Ajout effectuer avec succés.\n" ), QMessageBox::Cancel);

        ui->idc->setText("");
        ui->duree->setText("");
        ui->matemp->setText("");
            ui->type->setText("");
                ui->datedeb->setText("");
                ui->datefin->setText("");


}else{
        QMessageBox::information(nullptr, QObject::tr("ECHEC!!!"),
                    QObject::tr("congé existe déja.\n"), QMessageBox::Cancel);
    }

}

void gesempcong::on_pushButton_modifierconges_clicked()
{
    int idc=ui->idcm->text().toInt();
    int duree=ui->dureem->text().toInt();
    int matem=ui->matempm->text().toInt();
    QString type=ui->typem->text();
    QString datedeb=ui->datedebm->text();
    QString datefin=ui->datefinm->text();


    Conges c(idc,duree,matem,type,datedeb,datefin);
    if(c.modifier())
    {
              QMessageBox::information(nullptr, QObject::tr("Modifier un congé"),
                          QObject::tr("congé modifie.\n"), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier un congé"),
                          QObject::tr("Erreur !\n"), QMessageBox::Cancel);
    }

}

void gesempcong::on_pushButton_supprimerconges_clicked()
{

    Conges c;
    c.setidc(ui->suppcong->text().toInt());
    if(c.supprimer(c.getidc()))
    {
        QMessageBox::information(nullptr, QObject::tr("Supprimer un congé"),
                    QObject::tr("Suppression avec succés.\n" ), QMessageBox::Cancel);

    }
    else
    { QMessageBox::critical(nullptr, QObject::tr("Erreur!"),
                    QObject::tr("non supprimé.\n"
                                ), QMessageBox::Cancel);

    }



}


void gesempcong::on_tabWidget_conges_currentChanged(int index)
{
    ui->tableViewconges->setEnabled(true);

    ui->tableViewconges->setModel(insconges.afficher());

}


void gesempcong::on_recherchecong_clicked()
{  QString rech =ui->edit_recherchecong->text();
    ui->tableViewconges->setModel(insconges.rechercher(rech));

}

void gesempcong::on_tricong_clicked()
{ ui->tableViewconges->setModel(insconges.tri());

}









