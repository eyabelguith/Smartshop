#ifndef GESTION_MATERIAUX_MAINTENANCES_H
#define GESTION_MATERIAUX_MAINTENANCES_H
#include"materiaux.h"
#include"maintenances.h"
#include"statistique.h"

#include <QDialog>

namespace Ui {
class Gestion_materiaux_maintenances;
}

class Gestion_materiaux_maintenances : public QDialog
{
    Q_OBJECT

public:
    explicit Gestion_materiaux_maintenances(QWidget *parent = nullptr);
    ~Gestion_materiaux_maintenances();

private slots:
    void on_pushButton_materiel_16_clicked();

    void on_tabWidget_4_currentChanged(int index);

    void on_pushButton_materiel_17_clicked();

    void on_pushButton_materiel_13_clicked();

    void on_pushButton_materiel_8_clicked();

    void on_pushButton_materiel_5_clicked();

    void on_tabWidget_materiel_maintenance_2_currentChanged(int index);

    void on_pushButton_maintenance_clicked();

    void on_tabWidget_maintenance_3_currentChanged(int index);

    void on_pushButton_maintenance_15_clicked();

    void on_pushButton_maintenance_11_clicked();

    void on_pushButton_maintenance_2_clicked();

    void on_pushButton_maintenance_7_clicked();

private:
    Ui::Gestion_materiaux_maintenances *ui;
    Materiaux tmpmateriel;
    Maintenances tmpmaintenance;
    statistique tmpstat;
};

#endif // GESTION_MATERIAUX_MAINTENANCES_H
