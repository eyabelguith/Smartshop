#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"clients_cadeaux.h"

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
    clients_cadeaux fenetre;
    fenetre.exec();
}
