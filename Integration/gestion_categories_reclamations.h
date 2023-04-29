#ifndef GESTION_CATEGORIES_RECLAMATIONS_H
#define GESTION_CATEGORIES_RECLAMATIONS_H
#include"categories.h"
#include"reclamations.h"
#include"statistiquereclamations.h"
#include <QDialog>

namespace Ui {
class Gestion_categories_reclamations;
}

class Gestion_categories_reclamations : public QDialog
{
    Q_OBJECT

public:
    explicit Gestion_categories_reclamations(QWidget *parent = nullptr);
    ~Gestion_categories_reclamations();

private slots:
    void sendMail();
    void mailSent(QString);
    void browse();
    void on_pushButton_categorie_4_clicked();

    void on_pushButton_categorie_6_clicked();

    void on_tabWidget_categorie_4_currentChanged(int index);

    void on_pushButton_categorie_14_clicked();

    void on_pushButton_categorie_7_clicked();

    void on_bouton_ajout_reclamation_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_12_clicked();

    void on_comboBox_categorie_modifi_currentIndexChanged(const QString &arg1);

    void on_comboBox_reclamation_3_currentIndexChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_tabWidget_categorie_reclamation_2_currentChanged(int index);

    void on_tabWidget_reclamation_3_currentChanged(int index);

    void on_lineEdit_categorie_17_cursorPositionChanged(int arg1, int arg2);

    void on_rech_reclamation_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_tab_categorie_doubleClicked(const QModelIndex &index);

    void on_pushButton_4_clicked();

private:
    Ui::Gestion_categories_reclamations *ui;
    QStringList files;

    Categories tmpcategorie;
    reclamations tmpreclamation;
    statistiqueReclamations tmpstatreclamation;
};

#endif // GESTION_CATEGORIES_RECLAMATIONS_H
