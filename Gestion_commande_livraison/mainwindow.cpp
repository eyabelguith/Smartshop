#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "CL.h"
#include<QMessageBox>
#include<QString>

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


        QString utilisateur=ui->username->text();
            QString mdp=ui->password->text();
        MainWindow w;
            if ((utilisateur=="eya")&&(mdp=="eya"))
            {

                gestionCl fenetre;
                      fenetre.exec();
            }

            else{ QMessageBox::critical(nullptr, QObject::tr("Problème de connexion"),
                                              QObject::tr("Veuillez revérifier vos informations"), QMessageBox::Cancel);

                hide();
            }

}
