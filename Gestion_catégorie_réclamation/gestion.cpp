#include "gestion.h"
#include "ui_gestion.h"
#include"gestion_categories_reclamations.h"

Gestion::Gestion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Gestion)
{
    ui->setupUi(this);
    son=new QSound("C:/Users/Mr/Desktop/2ème année/2 sem/projet C++/music.wav");
}

Gestion::~Gestion()
{
    delete ui;
}
void Gestion::on_pushButton_clicked()
{
Gestion_categories_reclamations fenetre;
fenetre.exec();
}

void Gestion::on_sonon_clicked()
{

    son->play();
}

void Gestion::on_sonoff_clicked()
{
    son->stop();
}
