/********************************************************************************
** Form generated from reading UI file 'securite.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECURITE_H
#define UI_SECURITE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_securite
{
public:
    QLabel *label;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label_temperature;
    QLabel *label_temperature_2;
    QWidget *tab_2;
    QLabel *green;
    QLabel *red;
    QPushButton *resolution;
    QLabel *label_2;

    void setupUi(QDialog *securite)
    {
        if (securite->objectName().isEmpty())
            securite->setObjectName(QStringLiteral("securite"));
        securite->resize(820, 439);
        label = new QLabel(securite);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, -20, 871, 481));
        label->setPixmap(QPixmap(QString::fromUtf8("../../../../../i/sec.png")));
        tabWidget = new QTabWidget(securite);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 811, 601));
        tabWidget->setStyleSheet(QLatin1String("color: rgb(255, 0, 127);\n"
"font: 75 11pt \"MS Shell Dlg 2\";\n"
"font: 11pt \"MS Shell Dlg 2\";"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label_temperature = new QLabel(tab);
        label_temperature->setObjectName(QStringLiteral("label_temperature"));
        label_temperature->setGeometry(QRect(20, 30, 291, 91));
        label_temperature->setStyleSheet(QLatin1String("font: 75 16pt 'Script MT Bold';background-color: rgb(0, 0, 127);color: rgb(255, 0, 0);\n"
""));
        label_temperature_2 = new QLabel(tab);
        label_temperature_2->setObjectName(QStringLiteral("label_temperature_2"));
        label_temperature_2->setGeometry(QRect(500, 300, 291, 91));
        label_temperature_2->setStyleSheet(QLatin1String("font: 75 16pt 'Script MT Bold';background-color: rgb(0, 0, 127);color: rgb(255, 0, 0);\n"
""));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        green = new QLabel(tab_2);
        green->setObjectName(QStringLiteral("green"));
        green->setGeometry(QRect(30, 40, 471, 91));
        QFont font;
        font.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font.setPointSize(26);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        green->setFont(font);
        green->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 102, 125, 108), stop:0.55 rgba(235, 61, 165, 168), stop:0.98 rgba(255, 170, 255, 147), stop:1 rgba(0, 0, 0, 0));\n"
"color: rgb(0, 0, 0);\n"
"font: 75 26pt \"MS Shell Dlg 2\";"));
        red = new QLabel(tab_2);
        red->setObjectName(QStringLiteral("red"));
        red->setGeometry(QRect(310, 280, 481, 91));
        red->setFont(font);
        red->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 102, 125, 108), stop:0.55 rgba(235, 61, 165, 168), stop:0.98 rgba(255, 170, 255, 147), stop:1 rgba(0, 0, 0, 0));\n"
"color: rgb(0, 0, 0);\n"
"font: 75 26pt \"MS Shell Dlg 2\";"));
        resolution = new QPushButton(tab_2);
        resolution->setObjectName(QStringLiteral("resolution"));
        resolution->setGeometry(QRect(70, 290, 151, 51));
        QFont font1;
        font1.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(9);
        resolution->setFont(font1);
        resolution->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0.0635593 rgba(170, 0, 127, 164), stop:1 rgba(255, 214, 0, 82));\n"
"color: rgb(0, 0, 0);\n"
"font: 75 16pt \"MS Shell Dlg 2\";"));
        QIcon icon;
        icon.addFile(QStringLiteral("../../../../../images_projets/reg.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        resolution->setIcon(icon);
        resolution->setIconSize(QSize(45, 60));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, -150, 901, 721));
        label_2->setPixmap(QPixmap(QString::fromUtf8("../../../../../images_projets/gazF.jpg")));
        tabWidget->addTab(tab_2, QString());
        label_2->raise();
        green->raise();
        red->raise();
        resolution->raise();

        retranslateUi(securite);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(securite);
    } // setupUi

    void retranslateUi(QDialog *securite)
    {
        securite->setWindowTitle(QApplication::translate("securite", "Gestion de la s\303\251curit\303\251", Q_NULLPTR));
        label->setText(QString());
        label_temperature->setText(QApplication::translate("securite", "   Veuillez patientez un moment...", Q_NULLPTR));
        label_temperature_2->setText(QApplication::translate("securite", "   Veuillez patientez un moment...", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("securite", "Controle temp\303\251rature", Q_NULLPTR));
        green->setText(QString());
        red->setText(QString());
        resolution->setText(QApplication::translate("securite", "R\303\251solution", Q_NULLPTR));
        label_2->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("securite", "Controle fum\303\251e", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class securite: public Ui_securite {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECURITE_H
