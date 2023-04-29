/********************************************************************************
** Form generated from reading UI file 'statemp.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATEMP_H
#define UI_STATEMP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_statemp
{
public:

    void setupUi(QDialog *statemp)
    {
        if (statemp->objectName().isEmpty())
            statemp->setObjectName(QStringLiteral("statemp"));
        statemp->resize(815, 534);
        statemp->setStyleSheet(QStringLiteral("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 102, 125, 11), stop:0.423729 rgba(180, 47, 126, 13), stop:0.855932 rgba(255, 170, 255, 20), stop:1 rgba(255, 170, 255, 13));"));

        retranslateUi(statemp);

        QMetaObject::connectSlotsByName(statemp);
    } // setupUi

    void retranslateUi(QDialog *statemp)
    {
        statemp->setWindowTitle(QApplication::translate("statemp", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class statemp: public Ui_statemp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATEMP_H
