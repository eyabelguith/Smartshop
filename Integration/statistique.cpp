#include "statistique.h"
#include<QMessageBox>
statistique::statistique()
{

}
QChart* statistique::afficher_statistique()
{
   QPieSeries *series = new QPieSeries();
   QSqlQuery query;
   query.prepare("select count(*),materiaux.type from maintenances inner join materiaux on(materiaux.reference=maintenances.reference)group by materiaux.type");
   if(query.exec())
   {
   while(query.next())
   {
       series->append(query.value(1).toString(),query.value(0).toInt());

   }
   }else QMessageBox::information(nullptr, QObject::tr("stat erreur"),
                                 QObject::tr("stat error.\n"), QMessageBox::Cancel);
   series->setPieSize(0.5);
   QChart *chart = new QChart();
   chart->addSeries(series);
   chart->setTitle("Statistique des maintenances par type de matériaux");
   return chart;

}
