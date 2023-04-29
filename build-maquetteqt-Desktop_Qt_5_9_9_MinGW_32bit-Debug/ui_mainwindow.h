/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_3;
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(562, 438);
        QFont font;
        font.setPointSize(10);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QStringLiteral(""));
        MainWindow->setIconSize(QSize(24, 24));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, -90, 881, 601));
        label_3->setPixmap(QPixmap(QString::fromUtf8("../../../../../../../../../../i/arc en ciel.jpg")));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(30, 30, 511, 171));
        QFont font1;
        font1.setFamily(QStringLiteral("Script MT Bold"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        groupBox->setFont(font1);
        groupBox->setStyleSheet(QLatin1String("\n"
"color: rgb(255, 0, 127);"));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(380, 70, 111, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Script MT Bold"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        pushButton->setFont(font2);
        pushButton->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0.0100503 rgba(252, 222, 204, 255), stop:0.0502513 rgba(254, 223, 175, 255), stop:0.211055 rgba(246, 189, 237, 255), stop:0.487437 rgba(249, 162, 183, 255), stop:0.753769 rgba(206, 122, 218, 255), stop:1 rgba(170, 128, 185, 255));"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 40, 111, 21));
        QFont font3;
        font3.setFamily(QStringLiteral("Script MT Bold"));
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        label->setFont(font3);
        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(200, 120, 113, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 120, 111, 21));
        label_2->setFont(font3);
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(200, 40, 113, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 562, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Se connecter", Q_NULLPTR));
        label_3->setText(QString());
        groupBox->setTitle(QApplication::translate("MainWindow", "Connexion", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Se Connecter", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Nom d'utilisateur", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Mot de passe", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
