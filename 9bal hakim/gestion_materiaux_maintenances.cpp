#include "gestion_materiaux_maintenances.h"
#include "ui_gestion_materiaux_maintenances.h"
#include"materiaux.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include<QIntValidator>
#include<QValidator>
#include <QPrinter>
#include <QPrintDialog>
#include <QMediaPlayer>
#include <QSystemTrayIcon>
#include"maintenanceetat.h"
#include <QProgressBar>

Gestion_materiaux_maintenances::Gestion_materiaux_maintenances(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Gestion_materiaux_maintenances)
{
    ui->setupUi(this);
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
            notifyIcon->show();
            notifyIcon->setIcon(QIcon("E:\arcmaher.png"));
            notifyIcon->setVisible("E:\arcmaher.png");
            notifyIcon->showMessage("Ajout nouvelle Maintenance  ","maintenance ajoutée",QSystemTrayIcon::Information,15000);

            ui->status->setVisible(0);

}

Gestion_materiaux_maintenances::~Gestion_materiaux_maintenances()
{
    delete ui;
}

void Gestion_materiaux_maintenances::on_pushButton_materiel_16_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/Users/dell/Desktop/2eme année/2eme semestre/Projet C++/button.mp3"));
        player->setVolume(2000);
        player->play();

    QString reference= ui->lineEdit_materiel_12->text();
    QString nom= ui->lineEdit_materiel_13->text();
    QString type= ui->lineEdit_materiel_15->text();
    QString date_achat= ui->dateEdit_materiel_7->text();
    float prix=ui->lineEdit_materiel_17->text().toFloat();
    Materiaux materiel(reference,nom,type,date_achat,prix);
    if(prix>0)
    {
    if(materiel.ajouter()) {
        QMessageBox::information(nullptr, QObject::tr("Ajouter matériel"),
                    QObject::tr("Ajout Bien effectué." ), QMessageBox::Cancel);
        ui->lineEdit_materiel_12->setText("");
        ui->lineEdit_materiel_13->setText("");
        ui->lineEdit_materiel_15->setText("");
        ui->lineEdit_materiel_17->setText("");

        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                notifyIcon->show();
                notifyIcon->setIcon(QIcon("E:\arcmaher.png"));
                notifyIcon->setVisible("E:\arcmaher.png");
                notifyIcon->showMessage("Ajout nouvelle Maintenance  ","maintenance ajoutée",QSystemTrayIcon::Information,15000);

}else{
        QMessageBox::information(nullptr, QObject::tr("Ajout matériel"),
                    QObject::tr("Echec de l'ajout . Ce matériel existe déja."), QMessageBox::Cancel);
    }
    }
    else QMessageBox::information(nullptr, QObject::tr("Ajout matériel"),
                                  QObject::tr("Vérifiez les champs de saisie."), QMessageBox::Cancel);
}

void Gestion_materiaux_maintenances::on_tabWidget_4_currentChanged(int index)
{
    ui->tableView_materiel_2->setEnabled(true);
    ui->tableView_materiel_2->setModel(tmpmateriel.afficher());
    ui->comboBox_materiel_1->setModel(tmpmateriel.liste_materiaux());
    ui->comboBox_materiel_2->setModel(tmpmateriel.liste_materiaux());

}


void Gestion_materiaux_maintenances::on_pushButton_materiel_17_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/Users/dell/Desktop/2eme année/2eme semestre/Projet C++/button.mp3"));
        player->setVolume(2000);
        player->play();

    ui->tableView_materiel_2->setModel(tmpmateriel.tri());
}

void Gestion_materiaux_maintenances::on_pushButton_materiel_13_clicked()
{

}

void Gestion_materiaux_maintenances::on_pushButton_materiel_8_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/Users/dell/Desktop/2eme année/2eme semestre/Projet C++/button.mp3"));
        player->setVolume(2000);
        player->play();

    QString refer= ui->comboBox_materiel_2->currentText();
    if(tmpmateriel.supprimer(refer))
    {
        QMessageBox::information(nullptr, QObject::tr("Supprimer un matériel"),
                    QObject::tr("Suppression avec succés.\n" ), QMessageBox::Cancel);
        ui->comboBox_materiel_2->setModel(tmpmateriel.liste_materiaux());
    }
    else
    { QMessageBox::critical(nullptr, QObject::tr("Suppression matériel!"),
                    QObject::tr("Vous ne pouvez pas supprimer ce matériel car il est en maintenance.\n"
                                ), QMessageBox::Cancel);

    }
}
void Gestion_materiaux_maintenances::on_comboBox_materiel_1_currentIndexChanged(const QString &arg1)
{
    QString reference= ui->comboBox_materiel_1->currentText();
    QSqlQuery query=tmpmateriel.recuperer_Modification(reference);
    if(query.exec())
    {
        while(query.next())
        {
            ui->lineEdit_materiel_18->setText(query.value(1).toString());
            ui->lineEdit_materiel_19->setText(query.value(2).toString());
            ui->lineEdit_materiel_20->setText(query.value(4).toString());
        }
    }else  QMessageBox::critical(nullptr, QObject::tr("Modification matériel!"),
                                 QObject::tr("erreur!"
                                             ), QMessageBox::Cancel);

}
void Gestion_materiaux_maintenances::on_pushButton_materiel_5_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/Users/dell/Desktop/2eme année/2eme semestre/Projet C++/button.mp3"));
        player->setVolume(2000);
        player->play();

    QString reference= ui->comboBox_materiel_1->currentText();
    QString nom= ui->lineEdit_materiel_18->text();
    QString type= ui->lineEdit_materiel_19->text();
    QString date_achat= ui->dateEdit_materiel_8->text();
    float prix=ui->lineEdit_materiel_20->text().toFloat();
    Materiaux materiel(reference,nom,type,date_achat,prix);
    if(prix>0)
    {
    if(materiel.modifier())
    {
              QMessageBox::information(nullptr, QObject::tr("Modifier un matériel"),
                          QObject::tr("Modification effectuée avec succées.\n"), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier un matériel"),
                          QObject::tr("Echec ,les champs ne sont pas bien remplis!\n"), QMessageBox::Cancel);
    }
    }
    else QMessageBox::information(nullptr, QObject::tr("Modification matériel"),
                                  QObject::tr("Vérifiez les champs de saisie."), QMessageBox::Cancel);
}

void Gestion_materiaux_maintenances::on_tabWidget_materiel_maintenance_2_currentChanged(int index)
{
    ui->comboBox_maintenance_1->setModel(tmpmaintenance.affectation_liste_materiaux());

}

void Gestion_materiaux_maintenances::on_pushButton_maintenance_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/Users/dell/Desktop/2eme année/2eme semestre/Projet C++/button.mp3"));
        player->setVolume(2000);
        player->play();

    QString reference= ui->comboBox_maintenance_1->currentText();
    QString description= ui->lineEdit_maintenance_6->text();
    QString date_panne= ui->dateEdit_maintenance->text();
    float prix=ui->lineEdit_maintenance->text().toFloat();
    QString etat=ui->comboBox_maintenance_4->currentText();
    Maintenances maintenance(reference,date_panne,prix,description,etat);
    if(prix>0)
    {
    if(maintenance.ajouter()) {
        QMessageBox::information(nullptr, QObject::tr("Ajouter maintenance"),
                    QObject::tr("Ajout Bien effectué." ), QMessageBox::Cancel);
        ui->lineEdit_maintenance_6->setText("");
        ui->lineEdit_maintenance->setText("");

        //Notification pour la reclamation
        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                notifyIcon->show();
                notifyIcon->setIcon(QIcon("1"));
                notifyIcon->setVisible("1");
                notifyIcon->showMessage("Ajout nouvelle Maintenance  ","maintenance ajoutée",QSystemTrayIcon::Information,15000);

}
    else{
        QMessageBox::information(nullptr, QObject::tr("Ajout maintenance"),
                    QObject::tr("Echec de l'ajout . Cette maintenance existe déja."), QMessageBox::Cancel);
    }
    }
    else QMessageBox::information(nullptr, QObject::tr("Ajout maintenance"),
                                  QObject::tr("Vérifiez les champs de saisie."), QMessageBox::Cancel);
}

void Gestion_materiaux_maintenances::on_tabWidget_maintenance_3_currentChanged(int index)
{
    ui->tableView_maintenance->setModel(tmpmaintenance.afficher());
    ui->comboBox_maintenance_2->setModel(tmpmaintenance.liste_Maintenances());
    ui->comboBox_maintenance_3->setModel(tmpmaintenance.liste_Maintenances());
    ui->status->setVisible(0);
    QChartView *chartview = new QChartView(tmpstat.afficher_statistique());
    chartview->setParent(ui->statistique_frame);

}

void Gestion_materiaux_maintenances::on_pushButton_maintenance_15_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/Users/dell/Desktop/2eme année/2eme semestre/Projet C++/button.mp3"));
        player->setVolume(2000);
        player->play();

    ui->tableView_maintenance->setModel(tmpmaintenance.tri());

}

void Gestion_materiaux_maintenances::on_pushButton_maintenance_11_clicked()
{

}

void Gestion_materiaux_maintenances::on_pushButton_maintenance_2_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/Users/dell/Desktop/2eme année/2eme semestre/Projet C++/button.mp3"));
        player->setVolume(2000);
        player->play();

    QString reference= ui->comboBox_maintenance_2->currentText();
    QString description= ui->lineEdit_maintenance_7->text();
    QString date_panne= ui->dateEdit_maintenance_2->text();
    float prix=ui->lineEdit_maintenance_3->text().toFloat();
    QString etat=ui->comboBox_maintenance_5->currentText();
    Maintenances maintenance(reference,date_panne,prix,description,etat);
    if(prix>0)
    {
    if(maintenance.modifier())
    {
              QMessageBox::information(nullptr, QObject::tr("Modifier une maintenance"),
                          QObject::tr("Modification effectuée avec succées.\n"), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier une maintenance"),
                          QObject::tr("Echec ,les champs ne sont pas bien remplis!\n"), QMessageBox::Cancel);
    }
    }
    else QMessageBox::information(nullptr, QObject::tr("Modification maintenance"),
                                  QObject::tr("Vérifiez les champs de saisie."), QMessageBox::Cancel);
}
void Gestion_materiaux_maintenances::on_comboBox_maintenance_2_currentTextChanged(const QString &arg1)
{
    QString reference= ui->comboBox_maintenance_2->currentText();
    QSqlQuery query=tmpmaintenance.recuperer_Modification(reference);
    if(query.exec())
    {
        while(query.next())
        {
            ui->lineEdit_maintenance_3->setText(query.value(2).toString());
            ui->lineEdit_maintenance_7->setText(query.value(3).toString());
        }
    }else  QMessageBox::critical(nullptr, QObject::tr("Modification maintenance"),
                                 QObject::tr("erreur!"
                                             ), QMessageBox::Cancel);

}
void Gestion_materiaux_maintenances::on_pushButton_maintenance_7_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/Users/dell/Desktop/2eme année/2eme semestre/Projet C++/button.mp3"));
        player->setVolume(2000);
        player->play();

    QString refer= ui->comboBox_maintenance_3->currentText();
    if(tmpmaintenance.supprimer(refer))
    {
        QMessageBox::information(nullptr, QObject::tr("Supprimer une maintenance"),
                    QObject::tr("Suppression avec succés.\n" ), QMessageBox::Cancel);
        ui->comboBox_maintenance_3->setModel(tmpmaintenance.liste_Maintenances());

    }
    else
    { QMessageBox::critical(nullptr, QObject::tr("Suppression d'une maintenance!"),
                    QObject::tr("echec.\n"
                                ), QMessageBox::Cancel);

    }
}





void Gestion_materiaux_maintenances::on_pushButton_maintenance_16_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/Users/dell/Desktop/2eme année/2eme semestre/Projet C++/button.mp3"));
        player->setVolume(2000);
        player->play();

    QString strStream;
                QTextStream out(&strStream);
                const int rowCount = ui->tableView_maintenance->model()->rowCount();
                const int columnCount =ui->tableView_maintenance->model()->columnCount();

                out <<  "<html>\n"
                        "<head>\n"
                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                        <<  QString("<title>%1</title>\n").arg("Maintenances")
                        <<  "</head>\n"
                        "<body background='C:/0.png'>\n"
                            "<center><img src='C:/i/arc.png' width='300' height='300' ></center>"
                            "<center><h2>Liste des Maintenances</h2></center>"
                            "<table border=1 align='center' width='65%'bgcolor=#33DFFF>\n";


                // headers
                    out << "<thead><tr bgcolor=#F7BE81>";
                    for (int column = 0; column < columnCount; column++)
                        if (!ui->tableView_maintenance->isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(ui->tableView_maintenance->model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";
                    // data table
                       for (int row = 0; row < rowCount; row++) {
                           out << "<tr>";
                           for (int column = 0; column < columnCount; column++) {
                               if (!ui->tableView_maintenance->isColumnHidden(column)) {
                                   QString data = ui->tableView_maintenance->model()->data(ui->tableView_maintenance->model()->index(row, column)).toString().simplified();
                                   out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                               }
                           }
                           out << "</tr>\n";
                       }
                       out <<  "</table>\n"

                      "<h5>Adresse mail : pastry.shop2A18@gmail.com</h5>"
                       "<h5>Numero fixe : 71255369</h5>"
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

void Gestion_materiaux_maintenances::on_lineEdit_materiel_cursorPositionChanged(int arg1, int arg2)
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/Users/dell/Desktop/2eme année/2eme semestre/Projet C++/button.mp3"));
        player->setVolume(2000);
        player->play();

    QString recherche =ui->lineEdit_materiel->text();
    ui->tableView_materiel_2->setModel(tmpmateriel.rechercher(recherche));
}

void Gestion_materiaux_maintenances::on_lineEdit_maintenance_5_cursorPositionChanged(int arg1, int arg2)
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/Users/dell/Desktop/2eme année/2eme semestre/Projet C++/button.mp3"));
        player->setVolume(2000);
        player->play();

    QString recherche =ui->lineEdit_maintenance_5->text();
    ui->tableView_maintenance->setModel(tmpmaintenance.rechercher(recherche));
}

void Gestion_materiaux_maintenances::on_pushButton_maintenance_17_clicked()
{
    maintenanceEtat fen;
    fen.setModal(true);
    fen.exec();
}

void Gestion_materiaux_maintenances::on_tableView_maintenance_doubleClicked(const QModelIndex &index)
{

     int ligne=ui->tableView_maintenance->currentIndex().row();
    /* QString reference =ui->tableView_maintenance->model()->data(ui->tableView_maintenance->model()->index(ligne,0)).toString();
     qDebug()<< reference;
     QString date_panne =ui->tableView_maintenance->model()->data(ui->tableView_maintenance->model()->index(ligne,1)).toString();
     qDebug()<< date_panne;*/
     QString etat =ui->tableView_maintenance->model()->data(ui->tableView_maintenance->model()->index(ligne,4)).toString();
     qDebug()<< etat;
   /*  QString date_recuperation =ui->tableView_maintenance->model()->data(ui->tableView_maintenance->model()->index(ligne,5)).toString();
     qDebug()<< date_recuperation;*/

     ui->status->setVisible(1);

     if(etat=="repare")
     {
         //barsatus kolha 5adhra
         ui->status->setValue(100);

     }
     else if(etat=="non repare"){
         //mise a jour status bar
ui->status->setValue(0);

     }else ui->status->setValue(50);

     }

