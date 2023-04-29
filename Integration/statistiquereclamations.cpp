#include "statistiquereclamations.h"

statistiqueReclamations::statistiqueReclamations()
{

}
QChart*  statistiqueReclamations::afficher_piechart()
{

    QPieSeries *series = new QPieSeries();
    QSqlQuery query;
    query.prepare("select count(*),nom_categorie from reclamations group by nom_categorie");
    if(query.exec())
    {
    while(query.next())
    {
        series->append(query.value(1).toString(),query.value(0).toInt());

    }
    series->setPieSize(0.6);

    }else QMessageBox::information(nullptr, QObject::tr("Echec"),
                                  QObject::tr("erreur de calcul.\n"), QMessageBox::Cancel);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistique des réclamations par nom de catégorie");
    return chart;

}

