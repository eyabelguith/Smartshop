#include "gestion.h"
#include "ui_gestion.h"
#include"gestion_categories_reclamations.h"
#include "clients_cadeaux.h"
#include "gesempcong.h"
#include"gestion_materiaux_maintenances.h"
#include"gestion_produit_fournisseur.h"
#include"CL.h"
#include"securite.h"
#include<QMediaPlayer>
Gestion::Gestion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Gestion)
{
    ui->setupUi(this);
    son=new QSound("C:/i/music.wav");
    son->play();
}

Gestion::~Gestion()
{
    delete ui;
}
void Gestion::on_CATGREC_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/i/button.mp3"));
        player->setVolume(2000);
        player->play();

        Gestion_categories_reclamations fenetre;
        fenetre.exec();
}

void Gestion::on_sonon_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/i/button.mp3"));
        player->setVolume(2000);
        player->play();

        son->play();
}

void Gestion::on_sonoff_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/i/button.mp3"));
        player->setVolume(2000);
        player->play();

        son->stop();
}



void Gestion::on_pushButton_5_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/i/button.mp3"));
        player->setVolume(2000);
        player->play();

        securite fenetre;
        fenetre.exec();
}



void Gestion::on_pushButton_BenAmor_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
        player->setVolume(2000);
        player->play();

        clients_cadeaux fenetre;
        fenetre.exec();


}


void Gestion::on_eyakh_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
        player->setVolume(2000);
        player->play();

        gesempcong fenetre;
        fenetre.exec();
}
void Gestion::on_pushButton_6_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
        player->setVolume(2000);
        player->play();

        Gestion_materiaux_maintenances fenetre;
        fenetre.exec();

}

void Gestion::on_pushButton_4_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
        player->setVolume(2000);
        player->play();

        gestionCl fenetre;
        fenetre.exec();
}

void Gestion::on_pushButton_7_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
        player->setVolume(2000);
        player->play();

        gestion_produit_fournisseur fenetre;
        fenetre.exec();
}
