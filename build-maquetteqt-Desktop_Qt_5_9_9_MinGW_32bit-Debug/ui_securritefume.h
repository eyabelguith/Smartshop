/********************************************************************************
** Form generated from reading UI file 'securritefume.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECURRITEFUME_H
#define UI_SECURRITEFUME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_securritefume
{
public:
    QLabel *label_photo_12;
    QLabel *label_39;
    QLabel *green;
    QPushButton *resolution;
    QLabel *red;
    QLabel *label_36;

    void setupUi(QDialog *securritefume)
    {
        if (securritefume->objectName().isEmpty())
            securritefume->setObjectName(QStringLiteral("securritefume"));
        securritefume->resize(926, 558);
        label_photo_12 = new QLabel(securritefume);
        label_photo_12->setObjectName(QStringLiteral("label_photo_12"));
        label_photo_12->setGeometry(QRect(-50, 0, 1281, 571));
        QFont font;
        font.setPointSize(1);
        label_photo_12->setFont(font);
        label_photo_12->setPixmap(QPixmap(QString::fromUtf8("../resources/food-party-cake-bakery-chocolate-black-cupcakes-cup-sweet-de.jpg")));
        label_39 = new QLabel(securritefume);
        label_39->setObjectName(QStringLiteral("label_39"));
        label_39->setGeometry(QRect(80, 180, 201, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("Lucida Calligraphy"));
        font1.setPointSize(20);
        label_39->setFont(font1);
        label_39->setAutoFillBackground(false);
        label_39->setStyleSheet(QLatin1String("color:rgb(225, 150, 225);\n"
"color: rgb(152, 76, 0);"));
        green = new QLabel(securritefume);
        green->setObjectName(QStringLiteral("green"));
        green->setGeometry(QRect(310, 40, 471, 91));
        QFont font2;
        font2.setPointSize(15);
        green->setFont(font2);
        green->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 102, 125, 108), stop:0.55 rgba(235, 61, 165, 168), stop:0.98 rgba(255, 170, 255, 147), stop:1 rgba(0, 0, 0, 0));\n"
"color: rgb(170, 0, 127);"));
        resolution = new QPushButton(securritefume);
        resolution->setObjectName(QStringLiteral("resolution"));
        resolution->setGeometry(QRect(530, 270, 191, 61));
        QFont font3;
        font3.setPointSize(21);
        resolution->setFont(font3);
        resolution->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0.0635593 rgba(170, 0, 127, 164), stop:1 rgba(255, 214, 0, 82));\n"
"color: rgb(255, 85, 255);"));
        red = new QLabel(securritefume);
        red->setObjectName(QStringLiteral("red"));
        red->setGeometry(QRect(310, 150, 481, 91));
        red->setFont(font2);
        red->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 102, 125, 108), stop:0.55 rgba(235, 61, 165, 168), stop:0.98 rgba(255, 170, 255, 147), stop:1 rgba(0, 0, 0, 0));\n"
"color: rgb(170, 0, 127);"));
        label_36 = new QLabel(securritefume);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setGeometry(QRect(60, 70, 221, 41));
        label_36->setFont(font1);
        label_36->setAutoFillBackground(false);
        label_36->setStyleSheet(QLatin1String("color:rgb(225, 150, 225);\n"
"color: rgb(152, 76, 0);"));

        retranslateUi(securritefume);

        QMetaObject::connectSlotsByName(securritefume);
    } // setupUi

    void retranslateUi(QDialog *securritefume)
    {
        securritefume->setWindowTitle(QApplication::translate("securritefume", "Dialog", Q_NULLPTR));
        label_photo_12->setText(QString());
        label_39->setText(QApplication::translate("securritefume", "ALERTE!!!", Q_NULLPTR));
        green->setText(QString());
        resolution->setText(QApplication::translate("securritefume", "resolution", Q_NULLPTR));
        red->setText(QString());
        label_36->setText(QApplication::translate("securritefume", "\303\251tat normal", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class securritefume: public Ui_securritefume {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECURRITEFUME_H
