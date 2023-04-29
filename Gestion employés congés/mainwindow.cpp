#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employes.h"
#include"gesempcong.h"



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

gesempcong fenetre;
fenetre.exec();
}







