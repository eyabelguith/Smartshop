#ifndef STAT_FOURNISSEUR_H
#define STAT_FOURNISSEUR_H

#include <QDialog>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QWidget>
#include <QList>

namespace Ui {
class stat_fournisseur;
}

class stat_fournisseur : public QDialog
{
    Q_OBJECT

public:
    explicit stat_fournisseur(QWidget *parent = nullptr);
    ~stat_fournisseur();
    QList<qreal> stat_fournisseurs();
    QList<QString> stat_fournisseur_nom();
    QString st();

private:
    Ui::stat_fournisseur *ui;
};

#endif // STAT_FOURNISSEUR_H
