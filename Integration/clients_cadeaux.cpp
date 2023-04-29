#include "clients_cadeaux.h"
#include "ui_clients_cadeaux.h"
#include"client.h"
#include"cadeau.h"
#include "stat.h"
#include "QDebug"
#include<QString>
#include<QMessageBox>
#include<QPixmap>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMediaPlayer>
#include <QSound>
#include <QPropertyAnimation>
#include<QIntValidator>
#include<QValidator>
#include <QTextDocument>
#include <QTextStream>
#include <QFile>
#include <QFileDialog>
#include <QPrintDialog>
#include <QPrinter>
#include"QPdfWriter"
#include<QSystemTrayIcon>
#include <QtGui>
#include<QMediaPlayer>
#include<QFileDialog>
clients_cadeaux::clients_cadeaux(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::clients_cadeaux)
{
    ui->setupUi(this);
    ui->comboBox_4->addItem("Chocolat");
    ui->comboBox_4->addItem("Bon d'achat");
    ui->comboBox_4->addItem("Accessoires cuisine");
    ui->comboBox_5->addItem("Chocolat");
    ui->comboBox_5->addItem("Bon d'achat");
    ui->comboBox_5->addItem("Accessoires cuisine");
    connect(ui->sendBtn_2, SIGNAL(clicked()),this, SLOT(sendMail()));
       connect(ui->exitBtn_2, SIGNAL(clicked()),this, SLOT(close()));
       mMediaPlayer = new QMediaPlayer(this);



}
clients_cadeaux::~clients_cadeaux()
{
    delete ui;
}
void clients_cadeaux::on_pushButton_ajouterCl_3_clicked()
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
    player->setVolume(2000);
    player->play();
   ui->pushButton_ajouterCl_3->setStyleSheet(QString::fromUtf8("background-color: #de1c58;"));

    QString nom= ui->lineEdit_nom_ajout_3->text();

    QString prenom= ui->lineEdit_prenom_ajout_3->text();

    QString adresse= ui->lineEdit_adresse_ajout_3->text();
     QString tel= ui->lineEdit_tel_ajout_3->text();
 ui->lineEdit_tel_ajout_3->setMaxLength(8);

      int pts=0;
      QString matricule= ui->lineEdit_cin_ajout_3->text();
      QString id_cadeau="";
    Client a(matricule,nom,prenom,adresse,tel,pts,id_cadeau);
    if((nom=="")&&(prenom=="")&&(adresse=="")&&(matricule=="")&&(tel==""))
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("Tous les champs sont vides"), QMessageBox::Ok);
     }
    else if(matricule =="")
       {
           QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                       QObject::tr("matricule vide"), QMessageBox::Ok);

       }
    else if(nom =="")
       {
           QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                       QObject::tr("nom vide"), QMessageBox::Ok);

       }
    else if(prenom =="")
       {
           QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                       QObject::tr("prenom vide"), QMessageBox::Ok);

       }
    else if(adresse =="")
       {
           QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                       QObject::tr("adresse vide"), QMessageBox::Ok);

       }

    else if(tel =="")
       {
           QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                       QObject::tr("Télephone vide"), QMessageBox::Ok);

       }

else if(nom.contains(QRegExp("^[A-Za-z]+$"))==false)
{
   QMessageBox::critical(nullptr, QObject::tr("WARNING"),
               QObject::tr("faux nom"), QMessageBox::Ok);

}
    else if(prenom.contains(QRegExp("^[A-Za-z]+$"))==false)
    {
       QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                   QObject::tr("faux prenom"), QMessageBox::Ok);

    }
    else if(tel.contains(QRegExp("^[0-9]+$"))==false)
    {
       QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                   QObject::tr("le numéro de téléphone doit se composer par des chiffres seulement"), QMessageBox::Ok);

    }
    else if (tel.size()!=8)
{
   QMessageBox::critical(nullptr, QObject::tr("WARNING"),
               QObject::tr("le numéro de téléphone doit se composer par 8 chiffres"), QMessageBox::Ok);

}
    else
    {
    bool test=a.ajouter1();
    if(test)
  {

  QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
  QObject::tr("Client ajouté.\nClick Cancel to exit."), QMessageBox::Cancel);
  ui->lineEdit_adresse_ajout_3->setText("");


                  ui->lineEdit_tel_ajout_3->setText("");
                  ui->lineEdit_cin_ajout_3->setText("");
                  ui->lineEdit_nom_ajout_3->setText("");
                  ui->lineEdit_prenom_ajout_3->setText("");

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un client "),
                    QObject::tr("client existe déjà !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
}


void clients_cadeaux::on_pushButton_suppCl_3_clicked()
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
    player->setVolume(2000);
    player->play();
  ui->pushButton_suppCl_3->setStyleSheet(QString::fromUtf8("background-color: #de1c58;"));
    QString matricule= ui->comboBox_suppCl_3->currentText();
int verif1=tmpclient.verifier_affJeuCl1(matricule);
int verif2=tmpclient.verifier_affJeuCl2(matricule);

  if(verif1==0&&verif2==0)
           {
           if(tmpclient.supprimer1(matricule))
           {

                   QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                               QObject::tr("client supprimé.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
                     ui->comboBox_suppCl_3->setModel(tmpclient.modifier_liste_matricule());
            }

        else
           {
               QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
                           QObject::tr("Erreur !.\n"
                                       "Suppression impossible "), QMessageBox::Cancel);
           }

               }
               else
      QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
                  QObject::tr("Erreur !.\n"
                              "Suppression impossible le client est en cours d'affectation"), QMessageBox::Cancel);


}







void clients_cadeaux::on_pushButton_modifCl_4_clicked()
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
    player->setVolume(2000);
    player->play();
   ui->pushButton_modifCl_4->setStyleSheet(QString::fromUtf8("background-color: #de1c58;"));
    QString matricule= ui->comboBox_client_3->currentText();
       QString nom= ui->lineEdit_nom_modif_3->text();
       QString prenom= ui->lineEdit_prenom_modif_3->text();
       QString adresse= ui->lineEdit_adresse_modif_3->text();
      QString  tel=ui->lineEdit_tel_modif_3->text();
        int  pts=ui->lineEdit_7->text().toInt();


       Client a(matricule,nom,prenom,adresse,tel,pts);
       if((nom=="")&&(prenom=="")&&(adresse=="")&&(tel==""))
       {
           QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                       QObject::tr("Tous les champs sont vides"), QMessageBox::Ok);
        }

       else if(nom =="")
          {
              QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                          QObject::tr("nom vide"), QMessageBox::Ok);

          }
       else if(prenom =="")
          {
              QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                          QObject::tr("prenom vide"), QMessageBox::Ok);

          }
       else if(adresse =="")
          {
              QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                          QObject::tr("adresse vide"), QMessageBox::Ok);

          }

       else if(tel =="")
          {
              QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                          QObject::tr("Télephone vide"), QMessageBox::Ok);

          }

   else if(nom.contains(QRegExp("^[A-Za-z]+$"))==false)
   {
      QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                  QObject::tr("faux nom"), QMessageBox::Ok);

   }
       else if(prenom.contains(QRegExp("^[A-Za-z]+$"))==false)
       {
          QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                      QObject::tr("faux prenom"), QMessageBox::Ok);

       }
       else if(tel.contains(QRegExp("^[0-9]+$"))==false)
       {
          QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                      QObject::tr("le numéro de téléphone doit se composer par des chiffres seulement"), QMessageBox::Ok);

       }
       else if (tel.size()!=8)
   {
      QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                  QObject::tr("le numéro de téléphone doit se composer par 8 chiffres"), QMessageBox::Ok);

   }
       else
       {
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



}









void clients_cadeaux::on_tabWidget_5_currentChanged(int index)
{ QMediaPlayer *player = new QMediaPlayer;

     ui->tableView_4->setModel(tmpclient.afficher1());
     ui->comboBox_suppCl_3->setModel(tmpclient.modifier_liste_matricule());
      ui->comboBox_client_3->setModel(tmpclient.modifier_liste_matricule());

 ui->comboBox_Matclient_2->setModel(tmpclient.modifier_liste_matricule());
 setStyleSheet(" QPushButton {"
               "border-radius: 5px; "
               "border: 1.5px solid rgb(91,231,255); "
               "background-color: red; }"
               "QPushButton:pressed {"
               "border: 1.4px solid rgb(73,186,205); }"
               "QPushButton:hover {"
               "font-size: 16px;"
               "transition: 0.9s; }");




}

void clients_cadeaux::on_pushButton_triCl_4_clicked()
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
    player->setVolume(2000);
    player->play();
   ui->pushButton_triCl_4->setStyleSheet(QString::fromUtf8("background-color: #de1c58;"));
     ui->tableView_4->setModel(tmpclient.tri_DESC());
}

void clients_cadeaux::on_pushButton_rechCl_5_clicked()
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
    player->setVolume(2000);
    player->play();
      ui->pushButton_rechCl_5->setStyleSheet(QString::fromUtf8("background-color: #de1c58;"));
    QString nom_client =ui->lineEdit_rech_nom_2->text();
      ui->tableView_4->setModel(tmpclient.recherche1(nom_client));
}




void clients_cadeaux::on_pushButton_suppCa_3_clicked()
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
    player->setVolume(2000);
    player->play();
       ui->pushButton_suppCa_3->setStyleSheet(QString::fromUtf8("background-color: #ffff00;"));
   QString id= ui->comboBox_6->currentText();
   int verif=tmpcadeau.verifier_affJeu(id);

if(verif==0)
           {
  if(tmpcadeau.supprimer2(id))
{
                   QMessageBox::information(nullptr, QObject::tr("Supprimer un cadeau"),
                               QObject::tr("cadeau supprimé.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
                    ui->comboBox_6->setModel(tmpcadeau.modifier_liste_id());
}
else
{QMessageBox::critical(nullptr, QObject::tr("Supprimer un cadeau"),
                       QObject::tr("Erreur !.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
 }
       }
               else

    QMessageBox::critical(nullptr, QObject::tr("Supprimer un cadeau"),
                QObject::tr("Erreur !.\n"
                            "suppression impossible le cadeau est en cours d'affectation."), QMessageBox::Cancel);

}

void clients_cadeaux::on_pushButton_triCa_3_clicked()
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
    player->setVolume(2000);
    player->play();
    ui->pushButton_triCa_3->setStyleSheet(QString::fromUtf8("background-color: #ffff00;"));
     ui->tableView_5->setModel(tmpcadeau.tri2());
}

void clients_cadeaux::on_pushButton_rechCa_3_clicked()
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
    player->setVolume(2000);
    player->play();
     ui->pushButton_rechCa_3->setStyleSheet(QString::fromUtf8("background-color: #ffff00;"));
    QString categorie =ui->lineEdit_10->text();
      ui->tableView_5->setModel(tmpcadeau.recherche2(categorie));
}

void clients_cadeaux::on_tabWidget_6_currentChanged(int index)
{QMediaPlayer *player = new QMediaPlayer;

    ui->tableView_5->setModel(tmpcadeau.affiche2());
    ui->comboBox_6->setModel(tmpcadeau.modifier_liste_id());
     ui->comboBox_Cadeau_3->setModel(tmpcadeau.modifier_liste_id());
 setStyleSheet(" QPushButton {"
                   "border-radius: 5px; "
                   "border: 1.5px solid rgb(91,231,255); "
                   "background-color: red; }"
                   "QPushButton:pressed {"
                   "border: 1.4px solid rgb(73,186,205); }"
                   "QPushButton:hover {"
                   "font-size: 16px;"
                   "transition: 0.9s; }");


}

void clients_cadeaux::on_pushButton_modifCa_3_clicked()
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
    player->setVolume(2000);
    player->play();
 ui->pushButton_modifCa_3->setStyleSheet(QString::fromUtf8("background-color: #ffff00;"));
    QString id= ui->comboBox_Cadeau_3->currentText();
       QString categorie= ui->comboBox_5->currentText();

      int  somme=ui->lineEdit_11->text().toInt();
        int  nb=ui->lineEdit_12->text().toInt();
       Cadeau ca(id,categorie,somme,nb);



             if(somme<20||somme>10000)
          {
              QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                          QObject::tr("La somme doit etre entre 20 et 10000 points"), QMessageBox::Ok);

          }
       else if(nb==0)
       {
           QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                       QObject::tr("le nombre d'exemplaires ne doit pas etre nul"), QMessageBox::Ok);
       }

       else
       {
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
}

void clients_cadeaux::on_pushButton_statCa_3_clicked()
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
    player->setVolume(2000);
    player->play();
    ui->pushButton_statCa_3->setStyleSheet(QString::fromUtf8("background-color: #ffff00;"));
    int res;
            statistiques w(this);
            w.setWindowTitle("Statistiques des cadeaux");

            res = w.exec();
            qDebug() << res;
            if (res == QDialog::Rejected)
              return;
}



void clients_cadeaux::on_comboBox_client_3_currentIndexChanged(const QString &arg1)
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
    player->setVolume(2000);
    player->play();
    QString mat=ui->comboBox_client_3->currentText();

    QSqlQuery q;
       q.prepare("select * from client where matricule LIKE '"+mat+"'" );

    if(q.exec())
    {
        while(q.next())
        {
            ui->lineEdit_nom_modif_3->setText(q.value(1).toString());
            ui->lineEdit_prenom_modif_3->setText(q.value(2).toString());
             ui->lineEdit_7->setText(q.value(5).toString());
           ui->lineEdit_adresse_modif_3->setText(q.value(3).toString());
             ui->lineEdit_tel_modif_3->setText(q.value(4).toString());







        }



}
}

void clients_cadeaux::on_comboBox_Matclient_2_currentIndexChanged(const QString &arg1)
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
    player->setVolume(2000);
    player->play();
    QString mat=ui->comboBox_Matclient_2->currentText();

    QSqlQuery q;
       q.prepare("select * from client where matricule LIKE '"+mat+"'" );

    if(q.exec())
    {
        while(q.next())
        {

                ui->comboBox_affecCadeau_3->setModel(tmpclient.affecter_cadeau(mat));




        }
}
}
void clients_cadeaux::on_pushButton_modifCl_5_clicked()
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
    player->setVolume(2000);
    player->play();
   ui->pushButton_modifCl_5->setStyleSheet(QString::fromUtf8("background-color: #de1c58;"));
   QString id= ui->comboBox_Matclient_2->currentText();
    QString  id_cadeau=ui->comboBox_affecCadeau_3->currentText();
int aff=tmpclient.tester_affectation(id);
   Client a(id_cadeau);
Cadeau ca;
Client ca2;
   if (aff==0)
        {
       bool test=a.modifier2(id);
        if(test)
       {
bool test_mis_a_jour_nb=ca.mettre_a_jour_nb_exp(id_cadeau);
bool test_mis_a_jour_pt=ca2.mettre_a_jour_pts(id,id_cadeau);
if(test_mis_a_jour_pt&&test_mis_a_jour_nb)
{QMessageBox::information(nullptr, QObject::tr("affecter cadeau "),
                          QObject::tr("cadeau affecté et mise à jour en cours.\n"), QMessageBox::Cancel);


        }

else
{ QMessageBox::critical(nullptr, QObject::tr("affecter un cadeau"),
                        QObject::tr("pas de mise à jour  !\n"), QMessageBox::Cancel);

        }
        }
       else
       {
           QMessageBox::critical(nullptr, QObject::tr("affecter un cadeau"),
                             QObject::tr("Erreur d'affectation !\n"), QMessageBox::Cancel);
       }
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("affecter un cadeau"),
                              QObject::tr("Le client sélectionné a déjà gangé un cadeau !\n"), QMessageBox::Cancel);
}




}
void clients_cadeaux::on_comboBox_Cadeau_3_currentIndexChanged(const QString &arg1)
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
    player->setVolume(2000);
    player->play();
    QString id=ui->comboBox_Cadeau_3->currentText();

    QSqlQuery q;
       q.prepare("select * from cadeau where id LIKE '"+id+"'" );

    if(q.exec())
    {
        while(q.next())
        {
            ui->lineEdit_11->setText(q.value(2).toString());
            ui->lineEdit_12->setText(q.value(3).toString());
            ui->comboBox_5->setCurrentText(q.value(1).toString());




        }



}

}

void clients_cadeaux::on_pushButton_triCl_5_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
        player->setVolume(2000);
        player->play();
       ui->pushButton_triCl_5->setStyleSheet(QString::fromUtf8("background-color: #de1c58;"));
         ui->tableView_4->setModel(tmpclient.tri_ASC());
}

void clients_cadeaux::on_pushButton_ajouterCa_4_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
        player->setVolume(2000);
        player->play();
       ui->pushButton_ajouterCa_4->setStyleSheet(QString::fromUtf8("background-color: #ffff00;"));
        QString categorie=ui->comboBox_4->currentText();
        QString id= ui->lineEdit_categ_ajout_3->text();
          int somme= ui->lineEdit_8->text().toInt();
          QIntValidator *roll=new QIntValidator(20,10000);




          int nb= ui->lineEdit_9->text().toInt();
        Cadeau ca(id,categorie,somme,nb);

       if(id=="")
        {
            QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                        QObject::tr("id vide"), QMessageBox::Ok);
        }

                else if(somme<20||somme>10000)
           {
               QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                           QObject::tr("La somme doit etre entre 20 et 10000 points"), QMessageBox::Ok);

           }
        else if(nb==0)
        {
            QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                        QObject::tr("le nombre d'exemplaires ne doit pas etre nul"), QMessageBox::Ok);
        }

        else
        {
        bool test=ca.ajouter2();
        if(test)
      {

      QMessageBox::information(nullptr, QObject::tr("Ajouter un cadeau"),
      QObject::tr("Cadeau ajouté.\nClick Cancel to exit."), QMessageBox::Cancel);
      ui->lineEdit_categ_ajout_3->setText("");


                      ui->lineEdit_8->setText("");
                      ui->lineEdit_9->setText("");


      }
        else
            QMessageBox::critical(nullptr, QObject::tr("Ajouter un cadeau "),
                        QObject::tr("Cadeau existe déjà !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


}
}

void clients_cadeaux::on_comboBox_affecCadeau_3_currentIndexChanged(const QString &arg1)
{

     QString id=ui->comboBox_affecCadeau_3->currentText();
 ui->comboBox_categorie_2->setModel(tmpcadeau.chercher_categ(id));
 QString categorie=ui->comboBox_categorie_2->currentText();

      QImage image(tr("C:/images_projets/choc.jpg"));
      QImage image1(tr("C:/images_projets/Cheques-Cadeaux.png"));
       QImage image2(tr("C:/images_projets/acc.jpg"));
     if(categorie=="Chocolat")
     {

         ui->label_14->setPixmap(QPixmap::fromImage(image));
     }
     else if (categorie=="Bon d'achat")
     {

         ui->label_14->setPixmap(QPixmap::fromImage(image1));
     }
     else if (categorie=="Accessoires cuisine")
     {

         ui->label_14->setPixmap(QPixmap::fromImage(image2));
   }
     else
     {
//rien
     }

}

void clients_cadeaux::on_pushButton_pdf_2_clicked()
{
    ui->tableView_4->setModel(tmpclient.rechercheFidele());
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
        player->setVolume(2000);
        player->play();
       ui->pushButton_pdf_2->setStyleSheet(QString::fromUtf8("background-color: #de1c58;"));
 QString system_date = QDateTime::currentDateTime().toString("yyyy/MM/dd");
             QString strStream;
                       QTextStream out(&strStream);
                       const int rowCount = ui->tableView_4->model()->rowCount();
                       const int columnCount = ui->tableView_4->model()->columnCount();

                       out <<  "<html>\n"
                       "<head>\n"

                                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                        <<  QString("<title %1 </title>\n").arg("strTitle")
                                        <<  "</head> \n"
                                        "<body bgcolor=#ff557f link=#5000A0 >\n"

                                        "<align='right'> " << system_date << "</align>"

                                        "<center> <img src='C:/images_projets/logo.png'></img></br><H1>E-pastry</H1></br><H2>Vous etes le client le plus fidele de ce mois </H2></br><table border=1 cellspacing=0 cellpadding=2>\n";

                       // headers
                       out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                       out<<"<cellspacing=10 cellpadding=3>";
                       for (int column = 0; column < columnCount; column++)
                           if (!ui->tableView_4->isColumnHidden(column))
                               out << QString("<th>%1</th>").arg(ui->tableView_4->model()->headerData(column, Qt::Horizontal).toString());
                       out << "</tr></thead>\n";

                       // data table
                       for (int row = 0; row < rowCount; row++) {
                           out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                           for (int column = 0; column < columnCount; column++) {
                               if (!ui->tableView_4->isColumnHidden(column)) {
                                   QString data = ui->tableView_4->model()->data(ui->tableView_4->model()->index(row, column)).toString().simplified();
                                   out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                               }
                           }
                           out << "</tr>\n";
                       }
                       out <<  "</table></br> <H1>Felicitaions</H1></br><H2>Vous avez -30% bonus sur votre prochaine commande</H2></br></center>\n"
                                       " <img src='C:/images_projets/bonus.png'></img>" "</body>\n"
                                        "</html>\n";
                                if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }


                               QPrinter printer (QPrinter::PrinterResolution);
                                printer.setOutputFormat(QPrinter::PdfFormat);
                               printer.setPaperSize(QPrinter::A4);
                              printer.setOutputFileName(fileName);

                               QTextDocument doc;
                                doc.setHtml(strStream);
                                doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                                doc.print(&printer);
                                  ui->tableView_4->setModel(tmpclient.afficher1());
}

void clients_cadeaux::on_pushButton_notif_2_clicked()
{   QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
    player->setVolume(2000);
    player->play();
   ui->pushButton_notif_2->setStyleSheet(QString::fromUtf8("background-color: #de1c58;"));

    int verif =tmpcadeau.verifier_notif("Chocolat");
   int verif1 =tmpcadeau.verifier_notif("Bon d'achat");
   int verif2 =tmpcadeau.verifier_notif("Accessoires cuisine");
    if(verif!=0)
     {
     QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
             notifyIcon->show();
             notifyIcon->setIcon(QIcon("C:/images_projets/notif.png"));

             notifyIcon->showMessage("Gestion cadeau ","Un des cadeaux de la catégorie chocolat est terminée",QSystemTrayIcon::Information,15000);
     }
    if(verif1!=0)
     {
     QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
             notifyIcon->show();
             notifyIcon->setIcon(QIcon("C:/images_projets/notif.png"));

             notifyIcon->showMessage("Gestion cadeau ","Un des cadeaux de la catégorie bon d'achat est terminée",QSystemTrayIcon::Information,15000);
     }
    if(verif2!=0)
     {
     QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
             notifyIcon->show();
             notifyIcon->setIcon(QIcon("C:/images_projets/notif.png"));

             notifyIcon->showMessage("Gestion cadeau ","Un des cadeaux de la  catégorie accessoires cuisine est terminée",QSystemTrayIcon::Information,15000);
     }
}



void clients_cadeaux::sendMail()
{
    Smtp* smtp = new Smtp(ui->uname_2->text(), ui->paswd_2->text());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
           smtp->sendMail(ui->uname_2->text(), ui->rcpt_2->text() , ui->subject_2->text(),ui->msg_2->toPlainText(), files );
       else

    smtp->sendMail(ui->uname_2->text(), ui->rcpt_2->text() , ui->subject_2->text(),ui->msg_2->toPlainText());
}

void clients_cadeaux::mailSent(QString status)
{
    if(status == "Message envoyé")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message envoyé!\n\n" ) );
}

void clients_cadeaux::on_browseBtn_2_clicked()
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

    ui->file_2->setText( fileListString );
}


void clients_cadeaux::on_pushButton_ajouterJeu_2_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
        player->setVolume(2000);
        player->play();
       ui->pushButton_ajouterJeu_2->setStyleSheet(QString::fromUtf8("background-color: #de1c58;"));
        QString fichier = "C:/images_projets/fichier.txt";
       QFile file(fichier);

        QString id= ui->lineEdit_idJeu_2->text();
        QString date_deb= ui->dateEdit_datedeb_2->date().toString("yyyy/MM/dd");
         QString mat1=ui->comboBox_client1_3->currentText();
         QString mat2=ui->comboBox_client2_3->currentText();
         QString idc=ui->comboBox_cadeau_3->currentText();
         QString type= ui->textEdit_3->toPlainText();;
           QString date_fin= ui->dateEdit_datefin_2->date().toString("yyyy/MM/dd");
           QString system_date = QDateTime::currentDateTime().toString("yyyy/MM/dd");
        jeu j(id,mat1,mat2,date_deb,date_fin,type,idc);
        if(date_deb>date_fin)
        {
            QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                        QObject::tr("la date debut ne doit pas etre supérieure à date fin"), QMessageBox::Ok);
         }
       else if(system_date>=date_fin)
        {
            QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                        QObject::tr("la date fin doit etre superieure à la date d'aujourd'hui"), QMessageBox::Ok);
         }
        else if(system_date>=date_deb)
         {
             QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                         QObject::tr("la date debut doit etre superieure à la date d'aujourd'hui"), QMessageBox::Ok);
          }

       else  if(mat1==mat2)
        {
            QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                        QObject::tr("Il ne faut pas sélectionner la meme personne"), QMessageBox::Ok);
         }
        else
        {
        bool test=j.ajouterJeu();
        if(test)
      {

      QMessageBox::information(nullptr, QObject::tr("Ajouter un jeu concours"),
      QObject::tr("Jeu concours ajouté.\nClick Cancel to exit."), QMessageBox::Cancel);



      if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {


          QTextStream out(&file);
          out <<"La regle de jeu " << id << " :\n" << type << "\n";



     file.close();
      }
      ui->lineEdit_idJeu_2->setText("");
      ui->textEdit_3->setText("");


      }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Ajouter un jeu concours "),
                        QObject::tr("Jeu concours existe déjà !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
    }
}

void clients_cadeaux::on_pushButton_suppjeu_2_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
        player->setVolume(2000);
        player->play();
           ui->pushButton_suppjeu_2->setStyleSheet(QString::fromUtf8("background-color: #ffff00;"));
       QString idj= ui->comboBox_suppjeu_2->currentText();
           if(tmpjeu.supprimerJeu(idj))

               {

                       QMessageBox::information(nullptr, QObject::tr("Supprimer un jeu concours"),
                                   QObject::tr("jeu concours supprimé.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
                        ui->comboBox_suppjeu_2->setModel(tmpjeu.afficherListeIdJeu());

                   }
                   else
                       QMessageBox::critical(nullptr, QObject::tr("Supprimer un jeu concours"),
                                   QObject::tr("Erreur !.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
}

void clients_cadeaux::on_tabWidget_7_currentChanged(int index)
{
    QMediaPlayer *player = new QMediaPlayer;

         ui->tableView_6->setModel(tmpjeu.afficherJeu());
         ui->comboBox_client1_3->setModel(tmpjeu.afficherListeMatriculeClient());
         ui->comboBox_client2_3->setModel(tmpjeu.afficherListeMatriculeClient());
         ui->comboBox_cadeau_3->setModel(tmpjeu.afficherListeIdCadeau());
        ui->comboBox_suppjeu_2->setModel(tmpjeu.afficherListeIdJeu());
     ui->comboBox_idjeu_2->setModel(tmpjeu.afficherListeIdJeu());
     ui->comboBox_client1_4->setModel(tmpjeu.afficherListeMatriculeClient());
     ui->comboBox_client2_4->setModel(tmpjeu.afficherListeMatriculeClient());
     ui->comboBox_cadeau_4->setModel(tmpjeu.afficherListeIdCadeau());
     QString id=ui->comboBox_idjeu_2->currentText();

     QSqlQuery q;
        q.prepare("select * from jeu where idj LIKE '"+id+"'" );

     if(q.exec())
     {
         while(q.next())
         {
             ui->dateEdit_datedeb2_2->setDate(q.value(3).toDate());

                          ui->dateEdit_datefin2_2->setDate(q.value(4).toDate());
                            ui->comboBox_client1_4->setCurrentText(q.value(1).toString());
                             ui->comboBox_client2_4->setCurrentText(q.value(2).toString());
                  ui->textEdit_4->setText(q.value(5).toString());
                 ui->comboBox_cadeau_4->setCurrentText(q.value(6).toString());



         }
     }
     setStyleSheet(" QPushButton {"
                   "border-radius: 5px; "
                   "border: 1.5px solid rgb(91,231,255); "
                   "background-color: red; }"
                   "QPushButton:pressed {"
                   "border: 1.4px solid rgb(73,186,205); }"
                   "QPushButton:hover {"
                   "font-size: 16px;"
                   "transition: 0.9s; }");

     QString system_date = QDateTime::currentDateTime().toString("yyyy/MM/dd");
     tmpjeu.supprimerJeuAutomatique(system_date);

}

void clients_cadeaux::on_pushButton_modifjeu_2_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
        player->setVolume(2000);
        player->play();
     ui->pushButton_modifjeu_2->setStyleSheet(QString::fromUtf8("background-color: #ffff00;"));
        QString idj=ui->comboBox_idjeu_2->currentText();
       QString fichier = "C:/images_projets/fichier.txt";
       QFile file(fichier);


        QString date_deb= ui->dateEdit_datedeb2_2->date().toString("yyyy/MM/dd");
         QString mat1=ui->comboBox_client1_4->currentText();
         QString mat2=ui->comboBox_client2_4->currentText();
         QString idc=ui->comboBox_cadeau_4->currentText();
         QString type= ui->textEdit_4->toPlainText();
           QString date_fin= ui->dateEdit_datefin2_2->date().toString("yyyy/MM/dd");
                  QString system_date = QDateTime::currentDateTime().toString("yyyy/MM/dd");
     jeu j(idj,mat1,mat2,date_deb,date_fin,type,idc);

     if(date_deb>date_fin)
     {
         QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                     QObject::tr("la date debut ne doit pas etre supérieure à date fin"), QMessageBox::Ok);
      }
    else if(system_date>=date_fin)
     {
         QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                     QObject::tr("la date fin doit etre superieure à la date d'aujourd'hui"), QMessageBox::Ok);
      }
     else if(system_date>=date_deb)
      {
          QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                      QObject::tr("la date debut doit etre superieure à la date d'aujourd'hui"), QMessageBox::Ok);
       }
    else  if(mat1==mat2)
     {
         QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                     QObject::tr("Il ne faut pas sélectionner la meme personne"), QMessageBox::Ok);
      }
     else
{
           bool test=j.modifierJeu(idj);
            if(test)
           {


                     QMessageBox::information(nullptr, QObject::tr("Modifier un jeu concours"),
                                 QObject::tr("jeu concours modifié.\n"), QMessageBox::Cancel);

                     if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {


                         QTextStream out(&file);
                               out <<"La regle de jeu " << idj << " :\n" << type << "\n";


                    file.close();

           }
            }
           else

               QMessageBox::critical(nullptr, QObject::tr("Modifier un jeu concours"),
                                 QObject::tr("Erreur de modification !\n"), QMessageBox::Cancel);

    }
}

void clients_cadeaux::on_comboBox_idjeu_2_currentIndexChanged(const QString &arg1)
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
        player->setVolume(2000);
        player->play();
        QString id=ui->comboBox_idjeu_2->currentText();

        QSqlQuery q;
           q.prepare("select * from jeu where idj LIKE '"+id+"'" );

        if(q.exec())
        {
            while(q.next())
            {  ui->dateEdit_datedeb2_2->setDate(q.value(3).toDate());

              ui->dateEdit_datefin2_2->setDate(q.value(4).toDate());
                ui->comboBox_client1_4->setCurrentText(q.value(1).toString());
                 ui->comboBox_client2_4->setCurrentText(q.value(2).toString());
      ui->textEdit_4->setText(q.value(5).toString());
     ui->comboBox_cadeau_4->setCurrentText(q.value(6).toString());


            }



    }
}

void clients_cadeaux::on_pushButton_rechCl_6_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
        player->setVolume(2000);
        player->play();
         ui->pushButton_rechCl_6->setStyleSheet(QString::fromUtf8("background-color: #ffff00;"));
        QString date =ui->lineEdit_rech_type_2->text();
          ui->tableView_6->setModel(tmpjeu.rechercherJeu(date));
}

void clients_cadeaux::on_pushButton_triJeu_2_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
        player->setVolume(2000);
        player->play();
       ui->pushButton_triJeu_2->setStyleSheet(QString::fromUtf8("background-color: #de1c58;"));
         ui->tableView_6->setModel(tmpjeu.triDESC());
}

void clients_cadeaux::loadImage()
{

    QSize size(ui->imageLabel_2->width(), ui->imageLabel_2->height());
    QImage image2 = image1.scaled(size, Qt::KeepAspectRatio);

    ui->imageLabel_2->setPixmap(QPixmap::fromImage(image2));


}
// ouvrir une  image
void clients_cadeaux::ouvrir()
{

    fileName = QFileDialog::getOpenFileName(this, "Ouvrir un fichier...", QString());

    if (!fileName.isEmpty()) {
        QImage image(fileName);
        image1=image;
        m_chemin=fileName;
        if (image1.isNull()) {
            QMessageBox::information(this, "MainWindow ",
                                     tr("ne peut pas etre charge").arg(fileName));
            return;
        }
        int fact=image1.depth()/8;
        im1=new TraiterImage(image1.height(),fact*image1.width());
        this->loadImage();
    }
}






void clients_cadeaux::on_pushButton_clicked()
{

    fileName = QFileDialog::getOpenFileName(this, "Ouvrir un fichier...", QString());

    if (!fileName.isEmpty()) {
        QImage image(fileName);
        image1=image;
        m_chemin=fileName;
        if (image1.isNull()) {
            QMessageBox::information(this, "MainWindow ",
                                     tr("ne peut pas etre charge.").arg(fileName));
            return;
        }
        int fact=image1.depth()/8;
        im1=new TraiterImage(image1.height(),fact*image1.width());
        this->loadImage();
    }
}

void clients_cadeaux::on_vtgradientAct_clicked()
{
    if (image1.isNull()) {
        QMessageBox::information(this, "MainWindow ",
                                 "Veuillez charger une image!!!,"
                                 "pour ouvrir une image, clicker sur le bouton ouvrir image,"
                                 "  selectionner une image");
        return;
    }

    int fact=image1.depth()/8;
    if(im1->isNULL())
    {
        im1=new TraiterImage(image1.height(),fact*image1.width());
    }

    this->show();
    this->image1=this->image1.copy();
    im1->transfert_to_exim(&(this->image1));
    im1->normex(fact);
    im1->transfertx();
    im1->transfert_to_qim(&(this->image1));
    this->loadImage();
    this->repaint();
}

void clients_cadeaux::on_hrgradientAct_clicked()
{
    if (image1.isNull()) {
        QMessageBox::information(this, "MainWindow ",
                                 "Veuillez charger une image!!!,"
                                 "pour ouvrir une image, clicker sur le bouton ouvrir image,"
                                 "  selectionner une image");
        return;
    }

    int fact=image1.depth()/8;
    if(im1->isNULL())
    {
        im1=new TraiterImage(image1.height(),fact*image1.width());
    }

    this->show();
    this->image1=this->image1.copy();
    im1->transfert_to_exim(&(this->image1));
    im1->normey(fact);
    im1->transferty();
    im1->transfert_to_qim(&(this->image1));
    this->loadImage();
    this->repaint();
}

void clients_cadeaux::on_initialiserAct_clicked()
{
    if (image1.isNull()) {
        QMessageBox::information(this, "MainWindow ",
                                 "Veuillez charger une image!!!,"
                                 "pour ouvrir une image, clicker sur le bouton ouvrir image,"
                                 "  selectionner une image");
        return;
    }

    QImage image(fileName);
    image1=image;
    m_chemin=fileName;

    this->loadImage();
}

void clients_cadeaux::on_inversionfilterAct_clicked()
{
    if (image1.isNull()) {
        QMessageBox::information(this, "MainWindow ",
                                 "Veuillez charger une image!!!,"
                                 "pour ouvrir une image, clicker sur le bouton ouvrir image,"
                                 "  selectionner une image");
        return;
    }
    meth=8;

    int fact=image1.depth()/8;
    if( im1->isNULL())
    {
        im1=new TraiterImage(image1.height(),fact*image1.width());
    }


    this->show();

    this->image1=this->image1.copy();
    im1->transfert_to_exim(&(this->image1));
    im1->inversion(fact);
    im1->transfert_to_qim(&(this->image1));

    this->loadImage();
    this->repaint();
}

void clients_cadeaux::on_rgbtolumAct_clicked()
{
    if (image1.isNull()) {
        QMessageBox::information(this, "MainWindow ",
                                 "Veuillez charger une image!!!,"
                                 "pour ouvrir une image, clicker sur le bouton ouvrir image,"
                                 "  selectionner une image");
        return;
    }
    meth=1;

    int fact=image1.depth()/8;
    if(im1->isNULL())
    {
        im1=new TraiterImage(image1.height(),fact*image1.width());
    }

    this->show();
    this->image1=this->image1.copy();
    im1->transfert_to_exim(&(this->image1));
    if(fact==4)
    { im1->rgb_to_lum(fact);}
    im1->transfert_to_qim(&(this->image1));
    this->loadImage();
    this->repaint();;
}

void clients_cadeaux::on_gaussianfilterAct_clicked()
{
    if (image1.isNull()) {
        QMessageBox::information(this, "MainWindow ",
                                 "Veuillez charger une image!!!,"
                                 "pour ouvrir une image, clicker sur le bouton ouvrir image,"
                                 "  selectionner une image");
        return;
    }

    meth=0;
    int fact=image1.depth()/8;
    if(im1->isNULL())
    {
        im1=new TraiterImage(image1.height(),fact*image1.width());
    }

    this->show();
    this->image1=this->image1.copy();
    im1->transfert_to_exim(&(this->image1));
    im1->gaussian(fact);
    im1->transfert_to_qim(&(this->image1));
    this->loadImage();
    this->repaint();
}

void clients_cadeaux::on_binarisationfilterAct_clicked()
{
    if (image1.isNull()) {
        QMessageBox::information(this, "MainWindow ",
                                 "Veuillez charger une image!!!,"
                                 "pour ouvrir une image, clicker sur le bouton ouvrir image,"
                                 "  selectionner une image");
        return;
    }
    if (aa>255 ||aa<0 )
    {
        aa=50;
    }
    if ( bb>255 ||bb<0)
    {
        bb=100;
    }
    meth=5;


    int fact=image1.depth()/8;

    if(im1->isNULL())
    {
        im1=new TraiterImage(image1.height(),fact*image1.width());
    }


    this->show();

    this->image1=this->image1.copy();
    this->image2=this->image1;

    im1->transfert_to_exim(&(this->image1));
    im1->binarisation(fact,aa,255);;
    im1->transfert_to_qim(&(this->image1));
    this->loadImage();
    this->repaint();
}

void clients_cadeaux::on_binaristionIntervallefilterAct_clicked()
{
    if (image1.isNull()) {
        QMessageBox::information(this, "MainWindow ",
                                 "Veuillez charger une image!!!,"
                                 "pour ouvrir une image, clicker sur le bouton ouvrir image,"
                                 "  selectionner une image");
        return;
    }
    if ( aa>255 ||aa<0 )
    {
        aa=50;
    }
    if (bb>255 ||bb<0)
    {
        bb=100;
    }
    meth=7;



    int fact=image1.depth()/8;

    if(im1->isNULL())
    {
        im1=new TraiterImage(image1.height(),fact*image1.width());
    }

    this->show();

    this->image1=this->image1.copy();
    this->image2=this->image1;

    im1->transfert_to_exim(&(this->image1));

    im1->mediane(fact,3);
    im1->transfert_to_qim(&(this->image1));
    this->loadImage();
    this->repaint();
}

void clients_cadeaux::on_seuilageIntervallefilterAct_clicked()
{
    if (image1.isNull()) {
        QMessageBox::information(this, "MainWindow ",
                                 "Veuillez charger une image!!!,"
                                 "pour ouvrir une image, clicker sur le bouton ouvrir image,"
                                 "  selectionner une image");
        return;
    }
    if ( aa>255 ||aa<0 )
    {
        aa=50;
    }
    if ( bb>255 ||bb<0)
    {
        bb=100;
    }
    meth=6;

    int fact=image1.depth()/8;

    if(im1->isNULL())
    {
        im1=new TraiterImage(image1.height(),fact*image1.width());
    }

    this->show();

    this->image1=this->image1.copy();
    im1->transfert_to_exim(&(this->image1));

    im1->moyenneur(fact);
    im1->transfert_to_qim(&(this->image1));
    this->loadImage();
    this->repaint();
}

void clients_cadeaux::on_fenetragefilterAct_clicked()
{
    if (image1.isNull()) {
        QMessageBox::information(this, "MainWindow ",
                                 "Veuillez charger une image!!!,"
                                 "pour ouvrir une image, clicker sur le bouton ouvrir image,"
                                 "  selectionner une image");
        return;
    }

    if ( aa>255 ||aa<0 )
    {
        aa=50;
    }
    if ( bb>255 ||bb<0)
    {
        bb=100;
    }

    meth=3;

    int fact=image1.depth()/8;

    if(im1->isNULL())
    {
        im1=new TraiterImage(image1.height(),fact*image1.width());
    }

    this->show();

    this->image1=this->image1.copy();
    this->image2=this->image1;

    im1->transfert_to_exim(&(this->image1));
    im1->fenetrage(fact,aa,bb,255,1);
    im1->transfert_to_qim(&(this->image1));
    this->loadImage();
    this->repaint();
}

void clients_cadeaux::on_seuillagefilterAct_clicked()
{
    if (image1.isNull()) {
        QMessageBox::information(this, "MainWindow ",
                                 "Veuillez charger une image!!!,"
                                 "pour ouvrir une image, clicker sur le bouton ouvrir image,"
                                 "  selectionner une image");
        return;
    }
    if ( aa>255 ||aa<0 )
    {
        aa=50;
    }
    if ( bb>255 ||bb<0)
    {
        bb=100;
    }
    meth=4;

    int fact=image1.depth()/8;

    if(im1->isNULL())
    {
        im1=new TraiterImage(image1.height(),fact*image1.width());
    }

    this->show();

    this->image1=this->image1.copy();
    this->image2=this->image1;


    im1->transfert_to_exim(&(this->image1));
    im1->seuillage(fact,aa,1);
    im1->transfert_to_qim(&(this->image1));
    this->loadImage();
    this->repaint();
}

void clients_cadeaux::on_borderdetectAct_clicked()
{
    if (image1.isNull()) {
        QMessageBox::information(this, "MainWindow ",
                                 "Veuillez charger une image!!!,"
                                 "pour ouvrir une image, clicker sur le bouton ouvrir image,"
                                 "  selectionner une image");
        return;
    }
    meth=2;

    int fact=image1.depth()/8;
    if(im1->isNULL())
    {
        im1=new TraiterImage(image1.height(),fact*image1.width());
    }

    this->show();
    this->image1=this->image1.copy();
    im1->transfert_to_exim(&(this->image1));
    im1->normex(fact);
    im1->normey(fact);
    im1->norme(fact);
    im1->transfert_to_qim(&(this->image1));
    this->loadImage();
    this->repaint();
}


void clients_cadeaux::on_pushButton_2_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,"ouvrir");
        if (filename.isEmpty())
        {return;}
        mMediaPlayer->setMedia(QUrl::fromLocalFile(filename));
        mMediaPlayer->setVolume(ui->volume->value());
        on_play_clicked();
}

void clients_cadeaux::on_play_clicked()
{
     mMediaPlayer->play();
}

void clients_cadeaux::on_pause_clicked()
{
      mMediaPlayer->pause();
}

void clients_cadeaux::on_stop_clicked()
{
      mMediaPlayer->stop();
}

void clients_cadeaux::on_mute_clicked()
{
    if(ui->mute->text()=="muet"){
       mMediaPlayer->setMuted(true);
       ui->mute->setText("normal");
       }else {mMediaPlayer->setMuted(false);
           ui->mute->setText("muet");
       }
}

void clients_cadeaux::on_volume_valueChanged(int value)
{
     mMediaPlayer->setVolume(value);
}

void clients_cadeaux::on_enregistrer_clicked()
{
    QString chemin = QFileDialog::getSaveFileName(this, "Enregistrer le fichier", m_chemin,"Image (*.jpeg)");
       QFile file(chemin);
       if(!file.open(QIODevice::WriteOnly))
           return;
       QImage im1=this->image1;
       QString extension=  QFileInfo(chemin).suffix();
       im1.save(chemin, extension. toLatin1());
}

void clients_cadeaux::on_Imprimer_clicked()
{
    Q_ASSERT(ui->imageLabel_2->pixmap());
    #ifndef QT_NO_PRINTER
        QPrintDialog dialog(&printer, this);

        if (dialog.exec()) {
            QPainter painter(&printer);
            QRect rect = painter.viewport();
            QSize size = ui->imageLabel_2->pixmap()->size();
            size.scale(rect.size(), Qt::KeepAspectRatio);
            painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
            painter.setWindow(ui->imageLabel_2->pixmap()->rect());
            painter.drawPixmap(0, 0, *ui->imageLabel_2->pixmap());
        }
    #endif
}

void clients_cadeaux::on_modifier_clicked()
{
    QSize size((ui->imageLabel_2->width())*3, (ui->imageLabel_2->height())*2);
    QImage image2 = image1.scaled(size, Qt::KeepAspectRatio);

    ui->label_40->setPixmap(QPixmap::fromImage(image2));
}

void clients_cadeaux::on_pushButton_pdf_cadeau_clicked()
{
    QString categorie =ui->lineEdit_10->text();
      ui->tableView_5->setModel(tmpcadeau.recherche2(categorie));
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
        player->setVolume(2000);
        player->play();
       ui->pushButton_pdf_2->setStyleSheet(QString::fromUtf8("background-color: #de1c58;"));
 QString system_date = QDateTime::currentDateTime().toString("yyyy/MM/dd");
             QString strStream;
                       QTextStream out(&strStream);
                       const int rowCount = ui->tableView_5->model()->rowCount();
                       const int columnCount = ui->tableView_5->model()->columnCount();

                       out <<  "<html>\n"
                       "<head>\n"

                                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                        <<  QString("<title %1 </title>\n").arg("strTitle")
                                        <<  "</head> \n"
                                        "<body bgcolor=#ffaa7f link=#5000A0 >\n"

                                        "<align='right'> " << system_date << "</align>"

                                        "<center> <img src='C:/images_projets/logo.png'></img></br><H1>E-pastry</H1></br><H2>Categorie cible</H2></br><table border=1 cellspacing=0 cellpadding=2>\n";

                       // headers
                       out << "<thead><tr bgcolor=#ca8963> <th>Numero</th>";
                       out<<"<cellspacing=10 cellpadding=3>";
                       for (int column = 0; column < columnCount; column++)
                           if (!ui->tableView_4->isColumnHidden(column))
                               out << QString("<th>%1</th>").arg(ui->tableView_5->model()->headerData(column, Qt::Horizontal).toString());
                       out << "</tr></thead>\n";

                       // data table
                       for (int row = 0; row < rowCount; row++) {
                           out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                           for (int column = 0; column < columnCount; column++) {
                               if (!ui->tableView_5->isColumnHidden(column)) {
                                   QString data = ui->tableView_5->model()->data(ui->tableView_5->model()->index(row, column)).toString().simplified();
                                   out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                               }
                           }
                           out << "</tr>\n";
                       }
                    "</body>\n"
                                        "</html>\n";
                                if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }


                               QPrinter printer (QPrinter::PrinterResolution);
                                printer.setOutputFormat(QPrinter::PdfFormat);
                               printer.setPaperSize(QPrinter::A4);
                              printer.setOutputFileName(fileName);

                               QTextDocument doc;
                                doc.setHtml(strStream);
                                doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                                doc.print(&printer);
                               }
