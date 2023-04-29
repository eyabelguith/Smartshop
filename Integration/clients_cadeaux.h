#ifndef CLIENTS_CADEAUX_H
#define CLIENTS_CADEAUX_H
#include"client.h"
#include"cadeau.h"
#include"jeu.h"
#include <QFile>
#include <QDialog>
#include <QPropertyAnimation>
#include "mail.h"
#include <QFileDialog>
#include <QPrintDialog>
#include <QPrinter>
#include "traiterimage.h"
namespace Ui {
class clients_cadeaux;
}
class QMediaPlayer;
class clients_cadeaux : public QDialog
{
    Q_OBJECT

public:
    explicit clients_cadeaux(QWidget *parent = nullptr);
    ~clients_cadeaux();
private slots:
void on_pushButton_ajouterCl_3_clicked();

void on_pushButton_suppCl_3_clicked();

void on_pushButton_modifCl_4_clicked();

void on_tabWidget_5_currentChanged(int index);

void on_pushButton_triCl_4_clicked();

void on_pushButton_rechCl_5_clicked();



void on_pushButton_suppCa_3_clicked();

void on_pushButton_triCa_3_clicked();

void on_pushButton_rechCa_3_clicked();

void on_tabWidget_6_currentChanged(int index);

void on_pushButton_modifCa_3_clicked();

void on_pushButton_statCa_3_clicked();



void on_comboBox_client_3_currentIndexChanged(const QString &arg1);

void on_comboBox_Matclient_2_currentIndexChanged(const QString &arg1);

void on_pushButton_modifCl_5_clicked();

void on_comboBox_Cadeau_3_currentIndexChanged(const QString &arg1);

void on_pushButton_triCl_5_clicked();

void on_pushButton_ajouterCa_4_clicked();

void on_comboBox_affecCadeau_3_currentIndexChanged(const QString &arg1);

void on_pushButton_pdf_2_clicked();

void on_pushButton_notif_2_clicked();

void sendMail();
   void mailSent(QString);

   void on_browseBtn_2_clicked();

   void on_pushButton_ajouterJeu_2_clicked();

   void on_pushButton_suppjeu_2_clicked();

   void on_tabWidget_7_currentChanged(int index);

   void on_pushButton_modifjeu_2_clicked();

   void on_comboBox_idjeu_2_currentIndexChanged(const QString &arg1);

   void on_pushButton_rechCl_6_clicked();

   void on_pushButton_triJeu_2_clicked();
   void ouvrir();  // pour  ouvrir  une  image
   void on_pushButton_clicked();

   void on_vtgradientAct_clicked();
   void on_hrgradientAct_clicked();

   void on_initialiserAct_clicked();

   void on_inversionfilterAct_clicked();

   void on_rgbtolumAct_clicked();

   void on_gaussianfilterAct_clicked();

   void on_binarisationfilterAct_clicked();

   void on_binaristionIntervallefilterAct_clicked();

   void on_seuilageIntervallefilterAct_clicked();

   void on_fenetragefilterAct_clicked();

   void on_seuillagefilterAct_clicked();

   void on_borderdetectAct_clicked();

   void on_pushButton_2_clicked();

   void on_play_clicked();

   void on_pause_clicked();

   void on_stop_clicked();

   void on_mute_clicked();

   void on_volume_valueChanged(int value);

   void on_enregistrer_clicked();

   void on_Imprimer_clicked();

   void on_modifier_clicked();

   void on_pushButton_pdf_cadeau_clicked();

protected:
       int meth; // pour designer  la methode

private:
    Ui::clients_cadeaux *ui;
 QPixmap originalPixmap;
       Client tmpclient;
       Cadeau tmpcadeau;
        jeu tmpjeu;
       QPropertyAnimation *animation;
        QStringList files;

 QMediaPlayer *mMediaPlayer;
        void loadImage();           //methode pour  charger l'image

        int aa ;
        int bb;

        TraiterImage* im1; // classe TraiterImage
        QImage image1;
        QImage image2;
        QString m_chemin;
        QString fileName;

    #ifndef QT_NO_PRINTER
        QPrinter printer;
    #endif
};


#endif // CLIENTS_CADEAUX_H
