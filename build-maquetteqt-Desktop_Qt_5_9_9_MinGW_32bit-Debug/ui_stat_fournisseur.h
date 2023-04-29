/********************************************************************************
** Form generated from reading UI file 'stat_fournisseur.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STAT_FOURNISSEUR_H
#define UI_STAT_FOURNISSEUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_stat_fournisseur
{
public:
    QFrame *horizontalFrame;
    QHBoxLayout *horizontalLayout;

    void setupUi(QDialog *stat_fournisseur)
    {
        if (stat_fournisseur->objectName().isEmpty())
            stat_fournisseur->setObjectName(QStringLiteral("stat_fournisseur"));
        stat_fournisseur->resize(807, 587);
        horizontalFrame = new QFrame(stat_fournisseur);
        horizontalFrame->setObjectName(QStringLiteral("horizontalFrame"));
        horizontalFrame->setGeometry(QRect(0, 20, 811, 561));
        horizontalLayout = new QHBoxLayout(horizontalFrame);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));

        retranslateUi(stat_fournisseur);

        QMetaObject::connectSlotsByName(stat_fournisseur);
    } // setupUi

    void retranslateUi(QDialog *stat_fournisseur)
    {
        stat_fournisseur->setWindowTitle(QApplication::translate("stat_fournisseur", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class stat_fournisseur: public Ui_stat_fournisseur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STAT_FOURNISSEUR_H
