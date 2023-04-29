/********************************************************************************
** Form generated from reading UI file 'gestion.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GESTION_H
#define UI_GESTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Gestion
{
public:
    QPushButton *sonon;
    QPushButton *CATGREC;
    QPushButton *sonoff;
    QLabel *label;
    QPushButton *eyakh;
    QPushButton *pushButton_BenAmor;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;

    void setupUi(QDialog *Gestion)
    {
        if (Gestion->objectName().isEmpty())
            Gestion->setObjectName(QStringLiteral("Gestion"));
        Gestion->resize(609, 408);
        sonon = new QPushButton(Gestion);
        sonon->setObjectName(QStringLiteral("sonon"));
        sonon->setGeometry(QRect(540, 310, 61, 41));
        sonon->setStyleSheet(QLatin1String("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));\n"
"border-top-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));\n"
"border-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));"));
        QIcon icon;
        icon.addFile(QStringLiteral("../../../../../i/on.png"), QSize(), QIcon::Normal, QIcon::Off);
        sonon->setIcon(icon);
        sonon->setIconSize(QSize(60, 60));
        CATGREC = new QPushButton(Gestion);
        CATGREC->setObjectName(QStringLiteral("CATGREC"));
        CATGREC->setGeometry(QRect(330, 190, 191, 51));
        CATGREC->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0, stop:0 rgba(255, 170, 127, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(235, 148, 61, 255));\n"
"font: 75 13pt \"Script MT Bold\";\n"
""));
        sonoff = new QPushButton(Gestion);
        sonoff->setObjectName(QStringLiteral("sonoff"));
        sonoff->setGeometry(QRect(540, 360, 61, 41));
        sonoff->setStyleSheet(QStringLiteral("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("../../../../../i/off.png"), QSize(), QIcon::Normal, QIcon::Off);
        sonoff->setIcon(icon1);
        sonoff->setIconSize(QSize(60, 60));
        label = new QLabel(Gestion);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, -40, 981, 501));
        label->setPixmap(QPixmap(QString::fromUtf8("../../../../../../../../../../i/mac.jpeg")));
        eyakh = new QPushButton(Gestion);
        eyakh->setObjectName(QStringLiteral("eyakh"));
        eyakh->setGeometry(QRect(330, 130, 191, 51));
        eyakh->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0, stop:0 rgba(255, 170, 127, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(235, 148, 61, 255));\n"
"font: 75 13pt \"Script MT Bold\";\n"
""));
        pushButton_BenAmor = new QPushButton(Gestion);
        pushButton_BenAmor->setObjectName(QStringLiteral("pushButton_BenAmor"));
        pushButton_BenAmor->setGeometry(QRect(80, 130, 191, 51));
        pushButton_BenAmor->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0, stop:0 rgba(255, 170, 127, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(235, 148, 61, 255));\n"
"font: 75 13pt \"Script MT Bold\";\n"
""));
        pushButton_4 = new QPushButton(Gestion);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(80, 70, 191, 51));
        pushButton_4->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0, stop:0 rgba(255, 170, 127, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(235, 148, 61, 255));\n"
"font: 75 13pt \"Script MT Bold\";\n"
""));
        pushButton_5 = new QPushButton(Gestion);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(260, 270, 81, 51));
        pushButton_5->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0, stop:0 rgba(255, 170, 127, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(235, 148, 61, 255));\n"
"font: 75 13pt \"Script MT Bold\";\n"
""));
        pushButton_6 = new QPushButton(Gestion);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(80, 190, 191, 51));
        pushButton_6->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0, stop:0 rgba(255, 170, 127, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(235, 148, 61, 255));\n"
"font: 75 13pt \"Script MT Bold\";\n"
""));
        pushButton_7 = new QPushButton(Gestion);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(330, 70, 191, 51));
        pushButton_7->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0, stop:0 rgba(255, 170, 127, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(235, 148, 61, 255));\n"
"font: 75 13pt \"Script MT Bold\";\n"
""));
        label->raise();
        sonon->raise();
        CATGREC->raise();
        sonoff->raise();
        eyakh->raise();
        pushButton_BenAmor->raise();
        pushButton_4->raise();
        pushButton_5->raise();
        pushButton_6->raise();
        pushButton_7->raise();

        retranslateUi(Gestion);

        QMetaObject::connectSlotsByName(Gestion);
    } // setupUi

    void retranslateUi(QDialog *Gestion)
    {
        Gestion->setWindowTitle(QApplication::translate("Gestion", "Modules", Q_NULLPTR));
        sonon->setText(QString());
        CATGREC->setText(QApplication::translate("Gestion", "Cat\303\251gories et R\303\251clamations", Q_NULLPTR));
        sonoff->setText(QString());
        label->setText(QString());
        eyakh->setText(QApplication::translate("Gestion", "Employ\303\251s et Cong\303\251s", Q_NULLPTR));
        pushButton_BenAmor->setText(QApplication::translate("Gestion", "Clients, Cadeaux et Jeux", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("Gestion", "Commandes et Livraisons", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("Gestion", "S\303\251curit\303\251", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("Gestion", "Mat\303\251riaux et Maintenances", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("Gestion", "Produits et Fournisseurs", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Gestion: public Ui_Gestion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTION_H
