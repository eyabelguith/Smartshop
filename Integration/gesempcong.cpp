#include "gesempcong.h"
#include "ui_gesempcong.h"
#include "employes.h"
#include "conges.h"
#include "smtp.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QComboBox>
#include <QSpinBox>
#include<QIntValidator>
#include<QValidator>
#include<QMediaPlayer>
#include <QSystemTrayIcon>
#include "chat.h"
#include "excel.h"
#include "server.h"
#include "statemp.h"
#include "projeth.h"








gesempcong::gesempcong(QWidget *parent) :
    QDialog(parent),

    ui(new Ui::gesempcong)
{
    ui->setupUi(this);
    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));
    connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));



    setFixedSize(990,600);  //fixe la taille de la fenêtre

    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("../resources/button.wav"));
        player->setVolume(2000);
        player->play();

      ;
// arduino

        }








// arduino
void gesempcong::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );

}

void gesempcong::sendMail()
{

    smtp* Smtp = new smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toInt());
    connect(Smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        Smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        Smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void gesempcong::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}

gesempcong::~gesempcong()
{
    delete ui;
}

void gesempcong::on_ajoutemp_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("../resources/button.wav"));
        player->setVolume(2000);
        player->play();
          ui->matricule->setMaxLength(5);
    QString matemp=ui->matricule ->text();

    QString congeemp="";

    QString dateemb=ui->dateemb->text();
        ui->nom->setMaxLength(15);
    QString nom=ui->nom->text();
    ui->prenom->setMaxLength(15);
    QString prenom=ui->prenom->text();

    QString fonction=ui->fonction->text();


    QIntValidator *rolll=new QIntValidator(1,100);
        ui->age->setValidator(rolll);
    int age=ui->age->text().toInt();


      float salaire=ui->salaire->text().toFloat();

      srand (time(NULL));
                QDate d = QDate::currentDate() ;
                 QString datee =d.toString("dd / MM / yyyy ") ;
                 QString fn="ajout employes " ;
                QString nom1 = ui->ajoutemp->text();
              projeth pp(nom1,datee,fn) ;
              bool test1=pp.ajoutehis() ;

      if((nom!="")&&(prenom!="")&&(fonction!="")&&(age<70)&&(age>0)&&(salaire>0))

        {

    Employes E(matemp,congeemp,dateemb,nom,prenom,fonction,salaire,age);



    if(E.ajouter()) {



        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                notifyIcon->show();
                notifyIcon->setIcon(QIcon("stat.png"));

                notifyIcon->showMessage("GESTION employes  ","employé Ajouté",QSystemTrayIcon::Information,15000);

        QMessageBox::information(nullptr, QObject::tr("ajouté!!!"),
                    QObject::tr("Ajout effectuer avec succés.\n" ), QMessageBox::Cancel);

                ui->matricule->setText("");



                ui->nom->setText("");
                ui->prenom->setText("");
                ui->fonction->setText("");
                ui->salaire->setText("");
                ui->age->setText("");


}else{
        QMessageBox::information(nullptr, QObject::tr("Erreur!!!"),
                    QObject::tr("employé existe déja.\n"), QMessageBox::Cancel);
    }

      }else QMessageBox::information(nullptr, QObject::tr("controle de saisie!"),
                                        QObject::tr(" verifier la saisie.\n"), QMessageBox::Cancel);


     }



void gesempcong::on_tabWidget_employes_currentChanged(int index)
{
    ui->tableemp->setEnabled(true);
    ui->tableemp->setModel(insemployes.afficher());
    ui->mmatricule->setModel(insemployes.modifier_liste_employes());
    ui->comboBoxempsup->setModel(insemployes.modifier_liste_employes());
    ui->mmatricule_2->setModel(insemployes.modifier_liste_employes());
    ui->comboBoxconges_2->setModel(insemployes.affecter_conge());






}


void gesempcong::on_suppemp_clicked()
{  QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("../resources/button.wav"));
    player->setVolume(2000);
    player->play();
    Employes e1;
    e1.setmatemp(ui->comboBoxempsup->currentText());


    if(e1.supprimer(e1.getmatemp()))
    {
        srand (time(NULL));
                QDate d = QDate::currentDate() ;
                 QString datee =d.toString("dd / MM / yyyy ") ;
                 QString fn="suppression employes" ;
                QString nom1 = ui->suppemp->text();
              projeth pp(nom1,datee,fn) ;
              bool test1=pp.ajoutehis() ;

        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
        notifyIcon->show();
        notifyIcon->setIcon(QIcon("C:/Users/EYA/Desktop/4545.jpg"));
        notifyIcon->setVisible("C:/Users/EYA/Desktop/4545.jpg");

        notifyIcon->showMessage("GESTION employes  ","employé supprimé",QSystemTrayIcon::Information,15000);


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
{  QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("../resources/button.wav"));
    player->setVolume(2000);
    player->play();

    QString matemp=ui->mmatricule->currentText();
    QString congeemp=ui->mconge->text();
    QString dateemb=ui->mdateemb->text();
    QString nom=ui->mnom->text();
    QString prenom=ui->mprenom->text();
    QString fonction=ui->mfonction->text();

    int age=ui->mage->text().toInt();

     float salaire=ui->msalaire->text().toFloat();


     if((nom!="")&&(prenom!="")&&(fonction!="")&&(age<70)&&(age>0)&&(salaire>0))

         {

   Employes E(matemp,congeemp,dateemb,nom,prenom,fonction,salaire,age);

    if(E.modifier(matemp))
    {
        srand (time(NULL));
        QDate d = QDate::currentDate() ;
        QString datee =d.toString("dd / MM / yyyy ") ;
        QString fn="modification employes" ;
       QString nom1 = ui->modifemp->text();
     projeth pp(nom1,datee,fn) ;
     bool test1=pp.ajoutehis() ;




        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
        notifyIcon->show();
        notifyIcon->setIcon(QIcon("stat.png"));

        notifyIcon->showMessage("GESTION employes  ","employé modifié",QSystemTrayIcon::Information,15000);
              QMessageBox::information(nullptr, QObject::tr("Modifier un employé"),
                          QObject::tr("employé modifie.\n"), QMessageBox::Cancel);


              ui->matricule->setText("");
              ui->mnom->setText("");
              ui->mprenom->setText("");
              ui->mfonction->setText("");
              ui->msalaire->setText("");
              ui->mage->setText("");
              srand (time(NULL));


    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier un employé"),
                          QObject::tr("Erreur !\n"), QMessageBox::Cancel);
    }
}else QMessageBox::information(nullptr, QObject::tr("controle de saisie!"),
                                QObject::tr(" verifier la saisie.\n"), QMessageBox::Cancel);


}


void gesempcong::on_pushButton_rechercheemp_clicked()
{  QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("../resources/button.wav"));
    player->setVolume(2000);
    player->play();
       QString rech =ui->rechercheemp->text();
      ui->tableemp->setModel(insemployes.rechercher(rech));
}


void gesempcong::on_triemp_clicked()
{  QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("../resources/button.wav"));
    player->setVolume(2000);
    player->play();
      ui->tableemp->setModel(insemployes.tri());
}






void gesempcong::on_pushButton_ajouterconges_2_clicked()
{  QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("../resources/button.wav"));
    player->setVolume(2000);
    player->play();




   int duree=ui->duree_2->text().toInt();


 QString idc=ui->idc_2->text();
 QString type=ui->type_2->text();



 QString datedeb= ui->datedeb_2->date().toString("yyyy/MM/dd");
  QString datefin= ui->datefin_2->date().toString("yyyy/MM/dd");


  if((duree>0)&&(datefin>datedeb)&&(idc!="")&&(type!=""))

     {

       datedeb= ui->datedeb_2->text();
        datefin= ui->datefin_2->text();

    Conges c(duree,idc,type,datedeb,datefin);
    if(c.ajouter()) {
        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                notifyIcon->show();
                notifyIcon->setIcon(QIcon("stat.png"));

                notifyIcon->showMessage("GESTION employes  ","congé Ajouté",QSystemTrayIcon::Information,15000);
        QMessageBox::information(nullptr, QObject::tr("ajouté!!!"),
                    QObject::tr("Ajout effectuer avec succés.\n" ), QMessageBox::Cancel);

        ui->idc_2->setText("");
        ui->duree_2->setText("");
            ui->type_2->setText("");



}else{
        QMessageBox::information(nullptr, QObject::tr("erreur!!!"),
                    QObject::tr("congé existe déja.\n"), QMessageBox::Cancel);
    }

  }else QMessageBox::information(nullptr, QObject::tr("controle de saisie!"),
                                    QObject::tr("verifier la saisie"), QMessageBox::Cancel);


 }


void gesempcong::on_pushButton_modifierconges_clicked()
{QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("../resources/button.wav"));
    player->setVolume(2000);
    player->play();


    QString idc=ui->idcm->currentText();
    int duree=ui->dureem->text().toInt();
    QString type=ui->typem->text();

    QString datedeb= ui->datedebm->date().toString("yyyy/MM/dd");
     QString datefin= ui->datefinm->date().toString("yyyy/MM/dd");

     if((duree>0)&&(datefin>datedeb)&&(idc!="")&&(type!=""))

        {

          datedeb= ui->datedebm->text();
           datefin= ui->datefinm->text();


    Conges c(duree,idc,type,datedeb,datefin);
    if(c.modifier())
    {QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
        notifyIcon->show();
        notifyIcon->setIcon(QIcon("stat.png"));

        notifyIcon->showMessage("GESTION employes  ","congé modifié",QSystemTrayIcon::Information,15000);
              QMessageBox::information(nullptr, QObject::tr("Modifier un congé"),
                          QObject::tr("congé modifie.\n"), QMessageBox::Cancel);
              ui->idc_2->setText("");
              ui->dureem->setText("");
                  ui->typem->setText("");
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier un congé"),
                          QObject::tr("Erreur !\n"), QMessageBox::Cancel);
    }

     }else QMessageBox::information(nullptr, QObject::tr("controle de saisie!"),
                                       QObject::tr("verifier la saisie"), QMessageBox::Cancel);


    }


void gesempcong::on_pushButton_supprimerconges_clicked()
{QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("../resources/button.wav"));
    player->setVolume(2000);
    player->play();

    Conges c;
    c.setidc(ui->suppcong->currentText());
    if(c.supprimer(c.getidc()))
    {QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
        notifyIcon->show();
        notifyIcon->setIcon(QIcon("stat.png"));

        notifyIcon->showMessage("GESTION employes  ","congé supprimé",QSystemTrayIcon::Information,15000);
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
    ui->idcm->setModel(insconges.modifier_liste_conges());
    ui->suppcong->setModel(insconges.modifier_liste_conges());

}


void gesempcong::on_recherchecong_clicked()
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("../resources/button.wav"));
    player->setVolume(2000);
    player->play();

    QString rech =ui->edit_recherchecong->text();
    ui->tableViewconges->setModel(insconges.rechercher(rech));

}

void gesempcong::on_tricong_clicked()
{QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("../resources/button.wav"));
    player->setVolume(2000);
    player->play();

    ui->tableViewconges->setModel(insconges.tri());

}











void gesempcong::on_affecterbouton_clicked()
{QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("../resources/button.wav"));
    player->setVolume(2000);
    player->play();

    Employes e1;
    e1.setmatemp(ui->mmatricule_2->currentText());
    e1.setcongeemp(ui->comboBoxconges_2->currentText());
    if(e1.affecter(e1.getmatemp()))
    {srand (time(NULL));
        QDate d = QDate::currentDate() ;
         QString datee =d.toString("dd / MM / yyyy ") ;
         QString fn="affectation employes" ;
        QString nom1 = ui->affecterbouton->text();
      projeth pp(nom1,datee,fn) ;
      bool test1=pp.ajoutehis() ;
        QMessageBox::information(nullptr, QObject::tr("affecter un employé"),
                    QObject::tr("affectation avec succés.\n" ), QMessageBox::Cancel);

    }
    else
    { QMessageBox::critical(nullptr, QObject::tr("Erreur!"),
                    QObject::tr("non affecté.\n"
                                ), QMessageBox::Cancel);

    }


}

void gesempcong::on_mmatricule_currentIndexChanged(const QString &arg1)
{
    QString matemp=ui->mmatricule->currentText();
    QSqlQuery query=insemployes.recuperer(matemp);
    if(query.exec())
    {
        while(query.next())
        {


           ui->mdateemb->setDate(query.value(1).toDate());
           ui->mnom->setText(query.value(2).toString());
           ui->mprenom->setText(query.value(3).toString());
           ui->mfonction->setText(query.value(4).toString());
           ui->mconge->setText(query.value(5).toString());
           ui->msalaire->setText(query.value(6).toString());
           ui->mage->setText(query.value(7).toString());

        }
    }else{
        QMessageBox::information(nullptr, QObject::tr("Modifier un employé"),
                    QObject::tr("erreur requete.\n"), QMessageBox::Cancel);
    }
}

void gesempcong::on_idcm_currentIndexChanged(const QString &arg1)
{ QString idc=ui->idcm->currentText();
    QSqlQuery query=insconges.recupererc(idc);
    if(query.exec())
    {
        while(query.next())
        {
           ui->dureem->setText(query.value(1).toString());
           ui->typem->setText(query.value(2).toString());
          ui->datedebm->setDate(query.value(3).toDate());
          ui->datefinm->setDate(query.value(4).toDate());



        }
    }else{
        QMessageBox::information(nullptr, QObject::tr("Modifier un congé"),
                    QObject::tr("erreur requete.\n"), QMessageBox::Cancel);
    }

}


void gesempcong::on_statstemp_clicked()
{
    statemp *p = new statemp();
    p->setWindowModality(Qt::ApplicationModal);
    p->show();
}


void gesempcong::on_excel_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                           tr("Excel Files (*.xls)"));
           if (fileName.isEmpty())
               return;

           ExportExcelObject obj(fileName, "mydata", ui->tableemp);

           //colums to export
           obj.addField(0, "matemp", "char(20)");
           obj.addField(1, "dateemb", "char(20)");
           obj.addField(2, "nom", "char(20)");
           obj.addField(3, "prenom", "char(20)");
           obj.addField(4, "fonction", "char(20)");
           obj.addField(5, "congeemp", "char(20)");
           obj.addField(6, "salaire", "float");
           obj.addField(7, "age", "int");



           int retVal = obj.export2Excel();
           if( retVal > 0)
           {
               QMessageBox::information(this, tr("Done"),
                                        QString(tr("%1 records exported!")).arg(retVal)
                                        );
           }
}




void gesempcong::on_server_2_clicked()
{
    Server *p = new Server();
    p->setWindowModality(Qt::ApplicationModal);
    p->show();

}

void gesempcong::on_pushButton_clicked()
{
    ui->hist->setModel(tmph.afficherhis()) ;
        ui->hist->setModel(tmph.afficherhis());//refresh
}
