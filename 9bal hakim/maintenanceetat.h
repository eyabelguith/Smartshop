#ifndef MAINTENANCEETAT_H
#define MAINTENANCEETAT_H

#include <QDialog>

namespace Ui {
class maintenanceEtat;
}

class maintenanceEtat : public QDialog
{
    Q_OBJECT

public:
    explicit maintenanceEtat(QWidget *parent = nullptr);
    ~maintenanceEtat();

private:
    Ui::maintenanceEtat *ui;
};

#endif // MAINTENANCEETAT_H
