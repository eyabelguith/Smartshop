#include "stat.h"
#include "ui_stat.h"
#include <qvariant.h>
#include "cadeau.h"
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
#include <ui_stat.h>
#include <qwindow.h>
statistiques::statistiques(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistiques)
{
    //  ui->setupUi(this) ;

      QBarSet *set0 = new QBarSet("Chocolat");
      QBarSet *set1 = new QBarSet("Bon d'achat");
      QBarSet *set2 = new QBarSet("Accessoires cuisine");



      *set0 <<  c.calculer("Chocolat")<< 0 << 0;
      *set1 << 0 << c.calculer("Bon d'achat") << 0;
      *set2 << 0 << 0 << c.calculer("Accessoires cuisine");

      QBarSeries *series = new QBarSeries();
      series->append(set0);
      series->append(set1);
      series->append(set2);

      QChart *chart = new QChart();
      chart->addSeries(series);
      chart->setTitle("Statistique des cadeaux");
      chart->setAnimationOptions(QChart::SeriesAnimations);

      QStringList categories;
      categories << "Chocolat"
                 << "Bon d'achat"
                 << "Accessoires cuisine";

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
statistiques ::~statistiques()
{
delete ui;
}
