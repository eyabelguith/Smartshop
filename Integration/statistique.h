#ifndef STATISTIQUE_H
#define STATISTIQUE_H
#include<QtCharts>
#include<qchartview.h>
#include<qpieseries.h>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>


class statistique
{
public:
    statistique();
    QChart*  afficher_statistique();
};

#endif // STATISTIQUE_H
