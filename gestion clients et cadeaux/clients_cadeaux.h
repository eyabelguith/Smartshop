#ifndef CLIENTS_CADEAUX_H
#define CLIENTS_CADEAUX_H
#include"client.h"
#include"cadeau.h"
#include <QDialog>

namespace Ui {
class clients_cadeaux;
}

class clients_cadeaux : public QDialog
{
    Q_OBJECT

public:
    explicit clients_cadeaux(QWidget *parent = nullptr);
    ~clients_cadeaux();
private slots:
void on_pushButton_ajouterCl_2_clicked();

void on_pushButton_suppCl_2_clicked();

void on_pushButton_modifCl_2_clicked();

void on_tabWidget_2_currentChanged(int index);

void on_pushButton_triCl_2_clicked();

void on_pushButton_rechCl_3_clicked();



void on_pushButton_ajoutCa_2_clicked();

void on_pushButton_suppCa_2_clicked();

void on_pushButton_triCa_2_clicked();

void on_pushButton_rechCa_2_clicked();

void on_tabWidget_4_currentChanged(int index);

void on_pushButton_modifCa_2_clicked();

private:
    Ui::clients_cadeaux *ui;

       Client tmpclient;
       Cadeau tmpcadeau;
};

#endif // CLIENTS_CADEAUX_H
