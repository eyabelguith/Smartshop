#ifndef SECURRITEFUME_H
#define SECURRITEFUME_H


#include"gesempcong.h"
#include"employes.h"

#include <QPropertyAnimation>
#include"conges.h"
#include <QDialog>
#include<QSound>
#include <QPropertyAnimation>
#include "smtp.h"
#include <QtWidgets/QMessageBox>
#include <QFileDialog>
#include "arduino.h"
#include"statemp.h"

namespace Ui {
class securritefume;
}

class securritefume : public QDialog
{
    Q_OBJECT

public:
    explicit securritefume(QWidget *parent = nullptr);
    ~securritefume();

private slots:


  void update_label();

  void on_resolution_clicked();





private:
    Ui::securritefume *ui;
    Employes insemployes;
    Conges insconges;
    QStringList files;
    QSound *son;
    QPropertyAnimation *animation;
    QByteArray data;
    arduino A ;


    };


#endif // SECURRITEFUME_H
