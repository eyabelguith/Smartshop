#include "maintenanceetat.h"
#include "ui_maintenanceetat.h"
#include <QGridLayout>
#include <QWidget>
#include <QtCore>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QChartView>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLegend>
#include <QtCharts/QLineSeries>
#include <qwindow.h>
#include <QDialog>
#include<QtCharts>
#include<qchartview.h>
#include<qpieseries.h>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include<QMessageBox>

maintenanceEtat::maintenanceEtat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::maintenanceEtat)
{
    ui->setupUi(this);

        QBarSet *set1 = new QBarSet("Non réparés");
        QBarSet *set2 = new QBarSet("Réparés");
        QBarSet *set3 = new QBarSet("En cours");


        QSqlQuery query;
        query.prepare("select count(*) from maintenances where (etat like 'non repare') group by etat ");
        if(query.exec())
        {
        while(query.next())
        {
            *set1 << query.value(0).toInt() << 0 << 0 ;
        }
        }

        query.prepare("select count(*) from maintenances where (etat like 'repare') group by etat ");
        if(query.exec())
        {
        while(query.next())
        {
            *set2 << 0 << query.value(0).toInt() << 0 ;
        }
        }

        query.prepare("select count(*) from maintenances where (etat like 'en cours') group by etat ");
        if(query.exec())
        {
        while(query.next())
        {
            *set3 << 0 << 0 << query.value(0).toInt() ;
        }
        }


        QBarSeries *series = new QBarSeries();
        series->append(set1);
        series->append(set2);
        series->append(set3);

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Calcul des maintenances par état");
        chart->setAnimationOptions(QChart::SeriesAnimations);

        QStringList categories;
        categories << "Non réparés"
                   << "Réparés"
                   << "En cours";

        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(categories);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);

        QValueAxis *axisY = new QValueAxis();
        axisY->setRange(0,8);
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);

        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);

        QChartView *chartview = new QChartView(chart);
        chartview->setRenderHint(QPainter::Antialiasing);

        QGridLayout *mainLayout = new QGridLayout;
        mainLayout->addWidget(chartview, 1, 1);
        setLayout(mainLayout);
        setMinimumSize(800, 600);
}

maintenanceEtat::~maintenanceEtat()
{
    delete ui;
}
