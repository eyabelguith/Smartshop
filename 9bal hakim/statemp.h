#ifndef STATEMP_H
#define STATEMP_H


#include <QDialog>

namespace Ui {
class statemp;
}

class statemp : public QDialog
{

    Q_OBJECT

public:
    explicit statemp(QWidget *parent = nullptr);
    ~statemp();

private:
    Ui::statemp *ui;
};

#endif // STATEMP_H
