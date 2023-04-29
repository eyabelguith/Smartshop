#ifndef RECLAMATIONBAR_H
#define RECLAMATIONBAR_H
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

namespace Ui {
class reclamationBar;
}

class reclamationBar : public QDialog
{
    Q_OBJECT

public:
    explicit reclamationBar(QWidget *parent = nullptr);
    ~reclamationBar();

private:
    Ui::reclamationBar *ui;
};

#endif // RECLAMATIONBAR_H
