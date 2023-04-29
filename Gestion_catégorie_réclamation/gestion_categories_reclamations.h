#ifndef GESTION_CATEGORIES_RECLAMATIONS_H
#define GESTION_CATEGORIES_RECLAMATIONS_H
#include"categories.h"
#include"reclamations.h"
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
    void on_pushButton_categorie_4_clicked();

    void on_pushButton_categorie_6_clicked();

    void on_tabWidget_categorie_4_currentChanged(int index);

    void on_pushButton_categorie_13_clicked();

    void on_pushButton_categorie_14_clicked();

    void on_pushButton_categorie_7_clicked();

    void on_bouton_ajout_reclamation_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_comboBox_categorie_modifi_currentIndexChanged(const QString &arg1);

    void on_comboBox_reclamation_3_currentIndexChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_tabWidget_categorie_reclamation_2_currentChanged(int index);

    void on_tabWidget_reclamation_3_currentChanged(int index);

private:
    Ui::Gestion_categories_reclamations *ui;
    Categories tmpcategorie;
    reclamations tmpreclamation;
};

#endif // GESTION_CATEGORIES_RECLAMATIONS_H
