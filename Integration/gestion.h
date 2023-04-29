#ifndef GESTION_H
#define GESTION_H
#include<QSound>
#include <QDialog>

namespace Ui {
class Gestion;
}

class Gestion : public QDialog
{
    Q_OBJECT

public:
    explicit Gestion(QWidget *parent = nullptr);
    ~Gestion();
private slots:
    void on_sonon_clicked();

    void on_sonoff_clicked();
    void on_CATGREC_clicked();

    void on_pushButton_5_clicked();



    void on_pushButton_BenAmor_clicked();


    void on_eyakh_clicked();

    void on_pushButton_6_clicked();


    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::Gestion *ui;
    QSound *son;

};

#endif // GESTION_H
