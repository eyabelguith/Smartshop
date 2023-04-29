#ifndef STATISTIQUERECLAMATIONS_H
#define STATISTIQUERECLAMATIONS_H
#include<QtCharts>
#include<qchartview.h>
#include<qpieseries.h>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include<QMessageBox>




class statistiqueReclamations
{
public:
    statistiqueReclamations();
    QChart*  afficher_piechart();

};

#endif // STATISTIQUERECLAMATIONS_H
