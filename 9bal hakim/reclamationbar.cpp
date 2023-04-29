#include "reclamationbar.h"
#include "ui_reclamationbar.h"

reclamationBar::reclamationBar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reclamationBar)
{
    ui->setupUi(this);
    QBarSet *set1 = new QBarSet("Non traitées");
    QBarSet *set3 = new QBarSet("Traitées");
    QBarSet *set2 = new QBarSet("En cours");


    QSqlQuery query;
    query.prepare("select count(*) from reclamations where (etat like 'Non traitee') group by etat ");
    if(query.exec())
    {
    while(query.next())
    {
        *set1 << query.value(0).toInt() << 0 << 0 ;
    }
    }

    query.prepare("select count(*) from reclamations where (etat like 'En cours') group by etat ");
    if(query.exec())
    {
    while(query.next())
    {
        *set2 << 0 << query.value(0).toInt() << 0 ;
    }
    }
    query.prepare("select count(*) from reclamations where (etat like 'Traitee') group by etat ");
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
    chart->setTitle("Calcul des réclamations par état");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    categories << "Non traitées"
               << "En cours"
               << "Traitées";

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

reclamationBar::~reclamationBar()
{
    delete ui;
}
