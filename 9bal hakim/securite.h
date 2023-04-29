#ifndef SECURITE_H
#define SECURITE_H
#include"arduino.h"
#include <QDialog>

namespace Ui {
class securite;
}

class securite : public QDialog
{
    Q_OBJECT

public:
    explicit securite(QWidget *parent = nullptr);
    ~securite();
private slots:
    void update_temperature();
    void update_label();
    void on_resolution_clicked();

private:
    Ui::securite *ui;
    //arduino
          QByteArray data;
          QString DataAsString;
          arduino Arduino;
};

#endif // SECURITE_H
