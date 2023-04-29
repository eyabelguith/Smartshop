#ifndef PROJETH_H
#define PROJETH_H


#include"employes.h"
#include "chat.h"
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
#include "server.h"

class projeth
{
public:
       projeth() ;
       projeth(QString,QString,QString) ;
       QString get_action();
       QString get_datee();
       QString get_fn();
       QSqlQueryModel * afficherhis() ;
       bool ajoutehis();
       bool modifierhis() ;
private:

    QString action,datee,fn ;
};


#endif // PROJETH_H
