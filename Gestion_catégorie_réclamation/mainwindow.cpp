#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include<QString>
#include"gestion.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString username=ui->lineEdit->text();
    QString password=ui->lineEdit_2->text();
    if((username=="admin")&&(password=="admin"))
    {
        Gestion gestion;
        gestion.setModal(true);
        gestion.exec();
    }else QMessageBox::critical(nullptr, QObject::tr("Erreur de connexion"),
                               QObject::tr("Veuillez vérifier vos coordonnées ."), QMessageBox::Cancel);
}
