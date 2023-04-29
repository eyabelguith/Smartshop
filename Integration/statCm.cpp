#include "statCm.h"
#include "ui_statCm.h"
#include <qvariant.h>
#include "commande.h"
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
#include <ui_statCm.h>
#include <qwindow.h>
statCl::statCl(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statCl)
{


      QBarSet *set0 = new QBarSet("popola");
      QBarSet *set1 = new QBarSet("bibi");
      QBarSet *set2 = new QBarSet("polapopo");



      *set0 << y.calculerr("popola")<< 0 << 0;
      *set1 << 0 << y.calculerr("bibi") << 0;
      *set2 << 0 << 0 << y.calculerr("polapopo");

      QBarSeries *series = new QBarSeries();
      series->append(set0);
      series->append(set1);
      series->append(set2);

      QChart *chart = new QChart();
      chart->addSeries(series);
      chart->setTitle("Statistique des commandes");
      chart->setAnimationOptions(QChart::SeriesAnimations);

      QStringList categories;
      categories << "popola"
                 << "bibi"
                 << "polapopo";

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
statCl ::~statCl()
{
delete ui;
}
