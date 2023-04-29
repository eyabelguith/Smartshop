#ifndef GESTION_PRODUIT_FOURNISSEUR_H
#define GESTION_PRODUIT_FOURNISSEUR_H

#include <QDialog>
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
    void update_label();

    void on_tabWidget_2_currentChanged(int index);

    void on_tabWidget_3_currentChanged(int index);

    void on_ajout_clicked();

    void on_modif_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_produit_2_activated(const QModelIndex &index);

    void on_trie_clicked();

    void on_cherchp_cursorPositionChanged(int arg1, int arg2);

    void on_cherchep_clicked();

    void on_pushButton_2_clicked();

    void on_ajoutf_clicked();

    void on_fournisseurtable_activated(const QModelIndex &index);

    void on_pushButton_3_clicked();

    void on_recherche_cursorPositionChanged(int arg1, int arg2);

    void on_rech_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_modf_clicked();

    void on_tableView_3_activated(const QModelIndex &index);

    void on_toolButton_6_clicked();

    void on_toolButton_9_clicked();

    void on_tableView_4_activated(const QModelIndex &index);

    void on_comboBox_mat_currentIndexChanged(const QString &arg1);

    void on_idmodif_currentIndexChanged(const QString &arg1);
    void on_stop_clicked();

    void on_start_clicked();

    void on_horizontalSlider_sliderMoved(int position);

    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

private:
    Ui::gestion_produit_fournisseur *ui;
    produit tabproduit;
    fournisseur tabfour;
    QMediaPlayer* Player;
    stat_fournisseur *stat_four;
    QStringList files;
    arduino ard;
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
