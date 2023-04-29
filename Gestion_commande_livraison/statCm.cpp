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


      QBarSet *set0 = new QBarSet("salee");
      QBarSet *set1 = new QBarSet("gateaux");
      QBarSet *set2 = new QBarSet("croissant");



      *set0 << y.calculerr("salee")<< 0 << 0;
      *set1 << 0 << y.calculerr("gateaux") << 0;
      *set2 << 0 << 0 << y.calculerr("croissant");

      QBarSeries *series = new QBarSeries();
      series->append(set0);
      series->append(set1);
      series->append(set2);

      QChart *chart = new QChart();
      chart->addSeries(series);
      chart->setTitle("Statistique des commandes");
      chart->setAnimationOptions(QChart::SeriesAnimations);

      QStringList categories;
      categories << "salee"
                 << "gateaux"
                 << "croissant";

      QBarCategoryAxis *axis = new QBarCategoryAxis();
      axis->append(categories);
      chart->createDefaultAxes();
      chart->setAxisX(axis, series);

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
