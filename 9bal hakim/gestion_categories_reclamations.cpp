#include "gestion_categories_reclamations.h"
#include "ui_gestion_categories_reclamations.h"
#include <QDateTime>
#include "categories.h"
#include"reclamations.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QMediaPlayer>
#include<QIntValidator>
#include<QValidator>
#include <QPrinter>
#include <QPrintDialog>
#include"reclamationbar.h"
#include <QSystemTrayIcon>

Gestion_categories_reclamations::Gestion_categories_reclamations(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Gestion_categories_reclamations)
{
    ui->setupUi(this);
    ui->status->setVisible(0);
}

Gestion_categories_reclamations::~Gestion_categories_reclamations()
{
    delete ui;
}

void Gestion_categories_reclamations::on_pushButton_categorie_4_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/i/button.mp3"));
        player->setVolume(2000);
        player->play();

    QString nom= ui->lineEdit_categorie_12->text();
    QString date_fab= ui->dateEdit_categorie_7->date().toString("yyyy/MM/dd");
    float prix=ui->lineEdit_categorie_13->text().toFloat();
    QString date_per= ui->dateEdit_categorie_8->date().toString("yyyy/MM/dd");
    QString nbr= ui->lineEdit_categorie_14->text();
    QString system_date = QDateTime::currentDateTime().toString("yyyy/MM/dd");

    if((prix>0)&&(system_date>=date_fab)&&(nom!="")&&(nbr!="")&&(nbr!="0")&&(date_fab<date_per))
    {
        date_fab= ui->dateEdit_categorie_7->text();
        date_fab= ui->dateEdit_categorie_8->text();
        Categories catg(nom,date_fab,prix,date_per,nbr);
        if(catg.ajouter()) {
            QMessageBox::information(nullptr, QObject::tr("BRAVO!!!"),
                        QObject::tr("Ajout effectuer avec succés.\n" ), QMessageBox::Cancel);

            QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                    notifyIcon->show();
                    notifyIcon->setIcon(QIcon(" "));
                    notifyIcon->setVisible(" ");

                    notifyIcon->showMessage("Nouvelle réclamation ajoutée","Veuillez traiter cette réclamation",QSystemTrayIcon::Information,15000);


            ui->lineEdit_categorie_12->setText("");
            ui->lineEdit_categorie_13->setText("");

    }else{
            QMessageBox::information(nullptr, QObject::tr("ECHEC!!!"),
                        QObject::tr("Cette catégorie existe déja.\n"), QMessageBox::Cancel);
        }

    }else QMessageBox::information(nullptr, QObject::tr("Problème de saisie!"),
                                   QObject::tr("le nom doit pas etre vide.\nle prix doit etre supérieure à 0.\nla date ne doit pas dépasser la date d'aujourd'hui .\n"), QMessageBox::Cancel);


}


void Gestion_categories_reclamations::on_pushButton_categorie_6_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/i/button.mp3"));
        player->setVolume(2000);
        player->play();

    QString nom= ui->comboBox_categorie_sup->currentText();
    if(tmpcategorie.supprimer(nom))
    {
        QMessageBox::information(nullptr, QObject::tr("Supprimer une categorie"),
                    QObject::tr("Suppression avec succés.\n" ), QMessageBox::Cancel);
        ui->comboBox_categorie_sup->setModel(tmpcategorie.modifier_aff_id());
    }
    else
    { QMessageBox::critical(nullptr, QObject::tr("Erreur!"),
                    QObject::tr("Cette catégorie est affectée à une ou plusieurs réclamations,\n Veuillez supprimer les réclamations qui la concerne avant.\n"
                                ), QMessageBox::Cancel);

    }
}

void Gestion_categories_reclamations::on_tabWidget_categorie_4_currentChanged(int index)
{
    ui->tab_categorie->setEnabled(true);
    ui->tab_categorie->setModel(tmpcategorie.afficher());
    ui->comboBox_categorie_modifi->setModel(tmpcategorie.modifier_aff_id());
    ui->comboBox_categorie_sup->setModel(tmpcategorie.modifier_aff_id());
    ui->status->setVisible(0);
}


void Gestion_categories_reclamations::on_pushButton_categorie_14_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/i/button.mp3"));
        player->setVolume(2000);
        player->play();

    ui->tab_categorie->setModel(tmpcategorie.tri());
}
void Gestion_categories_reclamations::on_comboBox_categorie_modifi_currentIndexChanged(const QString &arg1)
{
    QString nom=ui->comboBox_categorie_modifi->currentText();
    QSqlQuery query=tmpcategorie.recuperer_Modification(nom);
    if(query.exec())
    {
        while(query.next())
        {
            ui->lineEdit_categorie_5->setText(query.value(2).toString());
            ui->dateEdit_categorie_2->setDate(query.value(1).toDate());
        }
    }else{
        QMessageBox::information(nullptr, QObject::tr("Modifier une catégorie"),
                    QObject::tr("erreur requete.\n"), QMessageBox::Cancel);
    }

}

void Gestion_categories_reclamations::on_pushButton_categorie_7_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/i/button.mp3"));
        player->setVolume(2000);
        player->play();

    QString nom= ui->comboBox_categorie_modifi->currentText();
    QString date_fab= ui->dateEdit_categorie_2->date().toString("yyyy/MM/dd");
    float prix=ui->lineEdit_categorie_5->text().toFloat();
    QString date_per= ui->dateEdit_categorie_9->date().toString("yyyy/MM/dd");
    QString nbr= ui->lineEdit_categorie_15->text();
    QString system_date = QDateTime::currentDateTime().toString("yyyy/MM/dd");
    if((prix>0)&&(system_date>=date_fab)&&(nbr!="")&&(nbr!="0")&&(date_fab<date_per))
    {
    date_fab= ui->dateEdit_categorie_2->text();
    date_per= ui->dateEdit_categorie_9->text();

    Categories catg(nom,date_fab,prix,date_per,nbr);

    if(catg.modifier())
    {
              QMessageBox::information(nullptr, QObject::tr("Modifier une catégorie"),
                          QObject::tr("Catégorie modifiée.\n"), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier une catégorie"),
                          QObject::tr("Erreur !\n"), QMessageBox::Cancel);
    }

    }else QMessageBox::information(nullptr, QObject::tr("ECHEC!!!"),
                                   QObject::tr("le prix doit etre supérieure à 0.\nla date ne doit pas dépasser la date d'aujourd'hui .\n"), QMessageBox::Cancel);


}

void Gestion_categories_reclamations::on_bouton_ajout_reclamation_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/i/button.mp3"));
        player->setVolume(2000);
        player->play();

    QString nom_categ= ui->comboBox_reclamation_1->currentText();
    QString id= ui->comboBox_reclamation_2->currentText();
    QString avis_c= ui->avis_reclamation->text();
    QString etat= ui->comboBox_reclamation_etat1->currentText();
    QString date_rec= ui->date_reclamation->date().toString("yyyy/MM/dd");
    QString system_date = QDateTime::currentDateTime().toString("yyyy/MM/dd");

    if((system_date>=date_rec)&&(avis_c!=""))
    {
        date_rec= ui->date_reclamation->text();
    reclamations rec(nom_categ,id,date_rec,avis_c,etat);
    if(rec.ajouter()) {
        QMessageBox::information(nullptr, QObject::tr("BRAVO!!!"),
                    QObject::tr("Ajout effectuer avec succés.\n"), QMessageBox::Cancel);
        ui->avis_reclamation->setText("");


        //Notification pour la reclamation
        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                notifyIcon->show();
                notifyIcon->setIcon(QIcon(" "));
                notifyIcon->setVisible(" ");

                notifyIcon->showMessage("Nouvelle réclamation ajoutée","Veuillez traiter cette réclamation",QSystemTrayIcon::Information,15000);

                //fin notification


    } else
    {
        QMessageBox::information(nullptr, QObject::tr("ECHEC!!!"),
                    QObject::tr("Cette réclamation existe déja.\n"), QMessageBox::Cancel);
    }
    }else QMessageBox::information(nullptr, QObject::tr("ECHEC!!!"),
                                   QObject::tr("la date ne doit pas dépasser la date d'aujourd'hui .\n"), QMessageBox::Cancel);

}

void Gestion_categories_reclamations::on_pushButton_3_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/i/button.mp3"));
        player->setVolume(2000);
        player->play();

    QString nom= ui->comboBox_reclamation_5->currentText();
    QString id=ui->comboBox_reclamation_6->currentText();
    if(tmpreclamation.supprimer(nom,id))
    {
        QMessageBox::information(nullptr, QObject::tr("Supprimer une réclamation"),
                    QObject::tr("Suppression avec succés.\n"), QMessageBox::Cancel);
    }
    else
    { QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                    QObject::tr("Cette réclamation n'existe pas ou plus.\n"), QMessageBox::Cancel);

    }
}

void Gestion_categories_reclamations::on_pushButton_12_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/i/button.mp3"));
        player->setVolume(2000);
        player->play();

    ui->tab_reclamation->setModel(tmpreclamation.tri());
}

void Gestion_categories_reclamations::on_comboBox_reclamation_3_currentIndexChanged(const QString &arg1)
{
    QString nom=ui->comboBox_reclamation_3->currentText();
    QString id=ui->comboBox_reclamation_4->currentText();
    QSqlQuery query=tmpreclamation.recuperer_Modification(nom,id);
    if(query.exec())
    {
        while(query.next())
        {
            ui->LineEdit_reclamation_3->setText(query.value(3).toString());
            ui->dateEdit_reclamation_2->setDate(query.value(2).toDate());
        }
    }else{
        QMessageBox::information(nullptr, QObject::tr("Modifier une réclamation"),
                    QObject::tr("erreur requete.\n"), QMessageBox::Cancel);
    }

}

void Gestion_categories_reclamations::on_pushButton_2_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/i/button.mp3"));
        player->setVolume(2000);
        player->play();

    QString nom= ui->comboBox_reclamation_3->currentText();
    QString id_client= ui->comboBox_reclamation_4->currentText();
    QString avis= ui->LineEdit_reclamation_3->text();
    QString etat= ui->comboBox_reclamation_etat2->currentText();
    QString date_rec= ui->dateEdit_reclamation_2->date().toString("yyyy/MM/dd");
    QString system_date = QDateTime::currentDateTime().toString("yyyy/MM/dd");

    if((system_date>=date_rec)&&(avis!=""))
    {

    date_rec= ui->dateEdit_reclamation_2->text();
    reclamations rec(nom,id_client,date_rec,avis,etat);
    if(rec.modifier())
    {
              QMessageBox::information(nullptr, QObject::tr("Modifier une réclamation"),
                          QObject::tr("Réclamtion modifié.\n"), QMessageBox::Cancel);

    }
else
    {
        QMessageBox::critical(nullptr, QObject::tr("Erreur !"),
                          QObject::tr("Cette réclamation n'existe pas.\nVeuillez vérifier le nom de catégorie et le id client."), QMessageBox::Cancel);
    }
    }else QMessageBox::information(nullptr, QObject::tr("ECHEC!!!"),
                                   QObject::tr("la date ne doit pas dépasser la date d'aujourd'hui .\n"), QMessageBox::Cancel);

}

void Gestion_categories_reclamations::on_tabWidget_categorie_reclamation_2_currentChanged(int index)
{
    ui->comboBox_reclamation_1->setModel(tmpreclamation.affecter_Categorie());
    ui->comboBox_reclamation_2->setModel(tmpreclamation.affecter_Client());
}

void Gestion_categories_reclamations::on_tabWidget_reclamation_3_currentChanged(int index)
{
    ui->tab_reclamation->setEnabled(true);
    ui->tab_reclamation->setModel(tmpreclamation.afficher());
    ui->comboBox_reclamation_1->setModel(tmpreclamation.affecter_Categorie());
    ui->comboBox_reclamation_2->setModel(tmpreclamation.affecter_Client());
    ui->comboBox_reclamation_3->setModel(tmpreclamation.affecter_Categorie());
    ui->comboBox_reclamation_4->setModel(tmpreclamation.affecter_Client());
    ui->comboBox_reclamation_5->setModel(tmpreclamation.affecter_Categorie());
    ui->comboBox_reclamation_6->setModel(tmpreclamation.affecter_Client());
    QChartView *chartview = new QChartView(tmpstatreclamation.afficher_piechart());
        chartview->setParent(ui->frame_reclamations);

}

void Gestion_categories_reclamations::on_lineEdit_categorie_17_cursorPositionChanged(int arg1, int arg2)
{
    QString rech =ui->lineEdit_categorie_17->text();
    ui->tab_categorie->setModel(tmpcategorie.rechercher(rech));
}

void Gestion_categories_reclamations::on_rech_reclamation_cursorPositionChanged(int arg1, int arg2)
{
    QString rech =ui->rech_reclamation->text();
    ui->tab_reclamation->setModel(tmpreclamation.rechercher(rech));
}


void Gestion_categories_reclamations::on_pushButton_13_clicked()
{
    QString strStream;
            QTextStream out(&strStream);
            const int rowCount = ui->tab_reclamation->model()->rowCount();
            const int columnCount =ui->tab_reclamation->model()->columnCount();

            out <<  "<html>\n"
                    "<head>\n"
                    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                    <<  QString("<title>%1</title>\n").arg("Reclamations")
                    <<  "</head>\n"
                    "<body background='C:/i/mac.jpeg'>\n"
                        "<center><img src='C:/i/capture.png' width='300' height='300' ></center>\n"
                        "<center><h2>Liste des reclamations</h2></center>"

                        "<table border=1 align='center' width='70%' cellspacing=0 cellpadding=2 bgcolor=#FED5FF>\n";


            // headers
                out << "<thead><tr bgcolor=#F4B2F6>";
                for (int column = 0; column < columnCount; column++)
                    if (!ui->tab_reclamation->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->tab_reclamation->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";
                // data table
                   for (int row = 0; row < rowCount; row++) {
                       out << "<tr>";
                       for (int column = 0; column < columnCount; column++) {
                           if (!ui->tab_reclamation->isColumnHidden(column)) {
                               QString data = ui->tab_reclamation->model()->data(ui->tab_reclamation->model()->index(row, column)).toString().simplified();
                               out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                           }
                       }
                       out << "</tr>\n";
                   }
                   out <<  "</table>\n"

                      "<h5>Adresse mail : pastry.shop2A18@gmail.com</h5>"
                       "<h5>Numero fixe : 71255369</h5>"
                       "<center></center>"
                       "</body>\n"
                       "</html>\n";

                   QTextDocument *document = new QTextDocument();
                   document->setHtml(strStream);

                   QPrinter printer;

                   QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                   if (dialog->exec() == QDialog::Accepted) {
                       document->print(&printer);
                }
}

void Gestion_categories_reclamations::on_pushButton_14_clicked()
{
    reclamationBar bar;
    bar.setModal(true);
    bar.exec();
}

void Gestion_categories_reclamations::on_tab_categorie_doubleClicked(const QModelIndex &index)
{
    int ligne=ui->tab_categorie->currentIndex().row();

    QString date_fab =ui->tab_categorie->model()->data(ui->tab_categorie->model()->index(ligne,1)).toString();
    QString date_per =ui->tab_categorie->model()->data(ui->tab_categorie->model()->index(ligne,3)).toString();
    ui->status->setVisible(1);

    QDate date_f(date_fab.mid(6,4).toInt(),date_fab.mid(3,2).toInt(),date_fab.mid(0,2).toInt());


    QDate date_p(date_per.mid(6,4).toInt(),date_per.mid(3,2).toInt(),date_per.mid(0,2).toInt());


    QDate sys = QDate::currentDate();


    if(sys.daysTo(date_p)<=0) ui->status->setValue(0);
    else {
        //ui->status->colorCount();
        int value=((sys.daysTo(date_p))*100/(date_f.daysTo(date_p)));
        ui->status->setValue(value);
    }


}

void Gestion_categories_reclamations::on_pushButton_4_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/i/button.mp3"));
        player->setVolume(2000);
        player->play();

    if(tmpreclamation.supprimertaitee())
    {
        QMessageBox::information(nullptr, QObject::tr("Supprimer les réclamations Taitées"),
                    QObject::tr("Suppression avec succés.\n"), QMessageBox::Cancel);
    }
    else
    { QMessageBox::critical(nullptr, QObject::tr("Pas de réclamations traitées"),
                    QObject::tr("erreur.\n"), QMessageBox::Cancel);

    }
}
