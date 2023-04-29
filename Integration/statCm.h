#ifndef STATCM_H
#define STATCM_H
#include "commande.h"
#include <QDialog>
#include <QGridLayout>
#include <QWidget>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QChartView>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLegend>
#include <QtCharts/QLineSeries>
QT_CHARTS_USE_NAMESPACE


//class statistiques;

namespace Ui {
class statCl : public stat{};
}

class statCl : public QDialog
{
    Q_OBJECT

public:
    explicit statCl(QWidget *parent = nullptr);
  ~statCl();

private:
    Ui::statCl *ui;
    stat s;
    Commande y ;
};
#endif // STATCM_H
