#ifndef GESTION_PRODUIT_FOURNISSEUR_H
#define GESTION_PRODUIT_FOURNISSEUR_H
#include "produit.h"
#include "fournisseur.h"
#include <QMainWindow>
#include <QMediaPlayer>
#include "smtphakim.h"
#include <QtWidgets/QMessageBox>
#include <QFileDialog>
#include <QDesktopServices>
#include <QUrl>
#include "stat_fournisseur.h"
#include "arduino.h"
#include "QrCode.hpp"
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class gestion_produit_fournisseur; }
QT_END_NAMESPACE

class gestion_produit_fournisseur : public QDialog
{
    Q_OBJECT

public:
    gestion_produit_fournisseur(QWidget *parent = nullptr);
    ~gestion_produit_fournisseur();

private slots:
    void enableButton();
    void selectDirectory();
    void generateQR();
    void exitApp();
    void sendMail();
    void mailSent(QString);
    void browse();
    void on_toolButton_clicked();

    void on_pushButton_clicked();

    void on_affficherp_clicked();

    void on_pushButton_3_clicked();


    void on_mofidifierp_clicked();

    void on_supprimerp_clicked();

    void on_pushButton_4_clicked();

    void on_ajouterp_2_clicked();

    void on_toolButton_3_clicked();

    void on_retourfromaf_clicked();

    void on_ajout_clicked();


    void on_produit_2_activated(const QModelIndex &index);

    void on_modif_clicked();

    void on_trie_clicked();

    void on_ajoutf_clicked();

    void on_toolButton_AF_clicked();

    void on_toolButton_2_clicked();

    void on_toolButton_fromajoutf_clicked();

    void on_toolButton_AFF_clicked();

    void on_toolButton_7_clicked();

    void on_toolButton_SF_clicked();

    void on_toolButton_8_clicked();

    void on_tableView_3_activated(const QModelIndex &index);

    void on_idmodif_currentIndexChanged(const QString &arg1);

    void on_tableView_activated(const QModelIndex &index);

    void on_toolButton_4_clicked();

    void on_toolButton_5_clicked();

    void on_rech_clicked();

    void on_cherchep_clicked();


    void on_pl_clicked();

    void on_pushButton_modf_clicked();

    void on_toolButton_MF_clicked();

    void on_comboBox_mat_currentIndexChanged(const QString &arg1);

    void on_fournisseurtable_activated(const QModelIndex &index);

    void on_frommod_clicked();

    void on_stop_clicked();

    void on_start_clicked();

    void on_horizontalSlider_sliderMoved(int position);

    void on_pushButton_2_clicked();

    void on_frommaling_clicked();


    void on_cherchp_cursorPositionChanged(int arg1, int arg2);

    void on_recherche_cursorPositionChanged(int arg1, int arg2);


    void on_toolButton_6_clicked();

    void on_toolButton_9_clicked();
    void update_label();


    void on_qrcode_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_tableView_4_activated(const QModelIndex &index);

    void on_pushButton_10_clicked();

private:
    Ui::gestion_produit_fournisseur *ui;
    produit tabproduit;
    fournisseur tabfour;
    QMediaPlayer* Player;
    stat_fournisseur *stat_four;
    QStringList files;
    Arduino ard;
    QByteArray data;
    // Default Qt ui class
    //Ui::QRplusplusClass ui;

    // Member data
    QString dir;
    std::string fileDirectory;

    // Getter
    std::string getColor();
    int getBorderSize();
    // Member functions
    void openWeb();
    void openGithub();
    void openFile() { QDesktopServices::openUrl(QUrl::fromLocalFile(dir)); }
    void doneDialog();
    void aboutQt() { QApplication::aboutQt(); }
    void nayukiDialog();
    void aboutDialog();

    // UI Initialization Functions
    void initMenuBar();
    void initFileDirectory();
    void initPushButton();
    void initColorComboBox();
    void initStatusBar();


};
#endif // GESTION_PRODUIT_FOURNISSEUR_H
