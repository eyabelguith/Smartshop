#include "stat_fournisseur.h"
#include "ui_stat_fournisseur.h"
#include <QSqlQuery>
#include <iostream>
using namespace std;
stat_fournisseur::stat_fournisseur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stat_fournisseur)
{
    ui->setupUi(this);
    QPieSeries *series =new QPieSeries ;

    QList<qreal> list= stat_fournisseurs();
    QString s=st();

    QList<QString> list2=stat_fournisseur_nom();

    for(int i=0 ;i<list.size();i++)
    {
         series->append(list2[i],list[i]);

    }

        QChart *chart =new QChart;
        chart->addSeries(series);
        chart->setTitle("STATS des fournisseurs");
         QChartView *chartview= new QChartView(chart);
         chartview->setParent(ui->horizontalFrame);
}

stat_fournisseur::~stat_fournisseur()
{
    delete ui;
}

QList<qreal> stat_fournisseur::stat_fournisseurs()
{  QList<qreal> list ;
    QSqlQuery query;
    query.prepare("select m_f,count(m_f) from produit group by m_f");
    query.exec();
    while(query.next())
    {list.append(query.value(1).toInt());}
    return list ;
}
QList<QString> stat_fournisseur::stat_fournisseur_nom()
{
    QList<QString>  list ;
        QSqlQuery query;
        query.prepare("select m_f,count(m_f) from produit group by m_f");
        query.exec();
        while(query.next())
        {list.append(query.value(0).toString());}
        return list ;

}

QString stat_fournisseur::st()
{   QString st;
    QSqlQuery query;
    query.prepare("select m_f,count(m_f) from produit group by m_f");
    query.exec();
    while(query.next())
    {st =query.value(1).toString();}
    return st ;
}
