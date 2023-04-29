/********************************************************************************
** Form generated from reading UI file 'reclamationbar.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECLAMATIONBAR_H
#define UI_RECLAMATIONBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_reclamationBar
{
public:

    void setupUi(QDialog *reclamationBar)
    {
        if (reclamationBar->objectName().isEmpty())
            reclamationBar->setObjectName(QStringLiteral("reclamationBar"));
        reclamationBar->resize(770, 429);

        retranslateUi(reclamationBar);

        QMetaObject::connectSlotsByName(reclamationBar);
    } // setupUi

    void retranslateUi(QDialog *reclamationBar)
    {
        reclamationBar->setWindowTitle(QApplication::translate("reclamationBar", "Calcul des r\303\251clamations selon l'\303\251tat", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class reclamationBar: public Ui_reclamationBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECLAMATIONBAR_H
