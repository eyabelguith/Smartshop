#include "statemp.h"
#include "ui_statemp.h"
#include "employes.h"
#include "conges.h"

#include <QMap>
#include <QVector>
#include <QString>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtWidgets/QGridLayout>
#include <QSqlQuery>
#include <QDebug>
QT_CHARTS_USE_NAMESPACE
statemp::statemp(QWidget *parent) :



    ui(new Ui::statemp)
{
    ui->setupUi(this);
    QVector <QPieSlice *> tab;
        QPieSeries *series = new QPieSeries();
        QSqlQuery qry;
        int tous=0;
        int plus40=0;
        int moins40=0;

        qry.prepare("select * from employes ");
        if (qry.exec())
        {

            while (qry.next())
            {

    tous++;
    if (qry.value(7)>40)
    {
        plus40++;
    }
    else if(qry.value(7)<40)
    {
        moins40++;
    }


            }
        }


        qDebug () << " plus 40 ans " << plus40;
            qDebug () << " moins 40 ans " << moins40;


float testing1 =(plus40*100)/tous;
QString pleasework = QString::number(testing1);
float testing2 =(moins40*100)/tous;
QString pleasework1 = QString::number(testing2);
    series ->append("plus de 40 ans "+pleasework+"%",(plus40));
        series ->append(" moins de 40 ans  "+pleasework1+"%",(moins40));


QPieSlice * slice0= series->slices().at(0);
slice0->setLabelVisible();
QPieSlice * slice1= series->slices().at(1);
slice1->setLabelVisible();

    if (plus40>moins40)
    {

       slice0->setExploded();
        slice0->setPen(QPen(Qt::darkCyan,2));
       slice0->setBrush(Qt::magenta);

    }
    else
    {

 slice1->setExploded();
  slice1->setPen(QPen(Qt::darkCyan,2));
 slice1->setBrush(Qt::magenta);
    }





    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("statistiques selon l'age : ");
    chart->legend()->hide();



                QChartView *chartview = new QChartView (chart);
        chartview->setRenderHint(QPainter::Antialiasing);
        QGridLayout *mainLayout = new QGridLayout;
            mainLayout->addWidget(chartview, 1, 1);
            setLayout(mainLayout);


}

statemp::~statemp()
{
    delete ui;
}
