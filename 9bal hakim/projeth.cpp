
#include "projeth.h"
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

projeth::projeth()
{
action="";
datee="";
fn="";
}
projeth::projeth(QString action,QString datee,QString fn)
{
    this->action=action;
    this->datee=datee;
    this->fn=fn ;
}
QString projeth::get_datee(){return  datee;}
QString projeth::get_fn(){return  fn;}
QString projeth::get_action(){return  action;}
bool projeth::ajoutehis()
{
    QSqlQuery query;
    query.prepare("INSERT INTO historique (action, DATEE, FN) "
                  "VALUES (:action, :datee, :fn)");
    query.bindValue(":action", action);
    query.bindValue(":datee", datee);
    query.bindValue(":fn", fn);
    return    query.exec();
}
bool projeth::modifierhis()
{
    QSqlQuery query;
    query.prepare("UPDATE historique SET datee='"+datee+"',fn='"+fn+"' where action='"+action+"'");
    query.bindValue(":action",action);
    query.bindValue(":datee", datee);
    query.bindValue(":fn", fn);
    return    query.exec();
}
QSqlQueryModel * projeth::afficherhis()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from historique");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("action"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("date "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("fonction "));
        return model;

}


