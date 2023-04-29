#ifndef CL_H
#define CL_H
#include <QtGui>
#include <QFile>
#include <QDialog>
#include "QDebug"
#include<QString>
#include "commande.h"
#include "livraison.h"
#include "mailCl.h"
#include "statCm.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QComboBox>
#include <QSpinBox>
#include<QIntValidator>
#include<QValidator>
#include<QFileDialog>
#include<QtPrintSupport/QPrinter>
#include<QPixmap>
#include <QPropertyAnimation>
#include <QTextDocument>
#include <QTextStream>
#include <QPrintDialog>
#include <QPrinter>
#include<QSystemTrayIcon>
#include<QMediaPlayer>
#include<QSound>





using namespace std;
namespace Ui {
class gestionCl;
}

class gestionCl : public QDialog
{
    Q_OBJECT

public:
    explicit gestionCl(QWidget *parent = nullptr);
    /* virtual */~gestionCl();
private slots:
    void on_pushButton_4_clicked();

     void on_pushButton_6_clicked();

     void on_pushButton_7_clicked();

     void on_pushButton_clicked();

     void on_pushButton_2_clicked();

     void on_pushButton_3_clicked();

     void on_pushButton_14_clicked();

     void on_pushButton_12_clicked();

     void on_lineEdit_10_cursorPositionChanged(int arg1, int arg2);

     void on_lineEdit_20_cursorPositionChanged(int arg1, int arg2);





     void sendMail();
     void mailSent(QString);
     void browse();
     void on_pushButton_5_clicked();

     void on_pushButton_8_clicked();








     void on_lineEdit_3_cursorPositionChanged(int arg1, int arg2);

     void on_pushButton_9_clicked();

     void on_label_4_linkActivated(const QString &link);

private:
    Ui::gestionCl *ui;
    Commande tmpcommande;
    Livraison tmplivraison;
    QStringList files;
    QMediaPlayer musicAdd;

};

#endif // CL_H
