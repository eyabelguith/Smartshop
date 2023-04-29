#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"gestion_materiaux_maintenances.h"
#include<QString>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    son=new QSound("");
    son->play();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_seconnecter_clicked()
{
    QString username=ui->username->text();
    QString password=ui->password->text();
    if((username=="admin")&&(password=="admin"))
    {
        Gestion_materiaux_maintenances gestion;
        gestion.setModal(true);
        gestion.exec();

    }else QMessageBox::critical(nullptr, QObject::tr("Problèmd de sécurité"),
                                QObject::tr("Vérifiez vos coordonnées."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_clicked()
{
    son->play();
}

void MainWindow::on_pushButton_2_clicked()
{
    son->stop();
}
