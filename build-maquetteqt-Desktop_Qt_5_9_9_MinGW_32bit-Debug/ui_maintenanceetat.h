/********************************************************************************
** Form generated from reading UI file 'maintenanceetat.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINTENANCEETAT_H
#define UI_MAINTENANCEETAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_maintenanceEtat
{
public:

    void setupUi(QDialog *maintenanceEtat)
    {
        if (maintenanceEtat->objectName().isEmpty())
            maintenanceEtat->setObjectName(QStringLiteral("maintenanceEtat"));
        maintenanceEtat->resize(935, 569);

        retranslateUi(maintenanceEtat);

        QMetaObject::connectSlotsByName(maintenanceEtat);
    } // setupUi

    void retranslateUi(QDialog *maintenanceEtat)
    {
        maintenanceEtat->setWindowTitle(QApplication::translate("maintenanceEtat", "calcul", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class maintenanceEtat: public Ui_maintenanceEtat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINTENANCEETAT_H
