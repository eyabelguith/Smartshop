#include "securritefume.h"
#include "arduino.h"

#include "gesempcong.h"
#include "ui_securritefume.h"
#include "employes.h"
#include "conges.h"
#include "smtp.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QComboBox>
#include <QSpinBox>
#include<QIntValidator>
#include<QValidator>
#include<QMediaPlayer>
#include <QSystemTrayIcon>
#include "chat.h"
#include "excel.h"





securritefume::securritefume(QWidget *parent) :
    QDialog(parent),

    ui(new Ui::securritefume)
{
    ui->setupUi(this);



        int ret =A.connect_arduino();
        switch(ret){
        case(0):qDebug()<<"arduino is available and connect to : " <<A.getarduino_port_name();
                break;
        case(1):qDebug()<<"arduino is available but not connected to : "<<A.getarduino_port_name();
                break;
        case(-1):qDebug()<<"arduino in not available";
        }
        QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));
        }




void securritefume::update_label()
{

    data=A.read_from_arduino();
    if (data=="0"){

       ui->green->setText(" pas de danger");
       ui->red->setText("");}
    else if (data=="1")
     { ui->red->setText("  il y'a une fuite de gaz");
    ui->green->setText("");}

}




void securritefume::on_resolution_clicked()
{
     A.write_to_arduino("0");
}

securritefume::~securritefume()
{
    delete ui;
}
