/********************************************************************************
** Form generated from reading UI file 'server.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_H
#define UI_SERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Server
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *serverGroupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *portLabel;
    QSpinBox *portSpinBox;
    QSpacerItem *horizontalSpacer;
    QPushButton *startStopButton;
    QGroupBox *sslFilesGroupBox;
    QGridLayout *gridLayout;
    QLabel *keyLabel;
    QLabel *certificateLabel;
    QLineEdit *keyLineEdit;
    QLineEdit *certificateLineEdit;
    QToolButton *keyButton;
    QToolButton *certificateButton;
    QTextEdit *logTextEdit;
    QPushButton *allerchat;

    void setupUi(QMainWindow *Server)
    {
        if (Server->objectName().isEmpty())
            Server->setObjectName(QStringLiteral("Server"));
        Server->resize(773, 531);
        Server->setStyleSheet(QLatin1String("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 102, 125, 11), stop:0.423729 rgba(180, 47, 126, 13), stop:0.855932 rgba(255, 170, 255, 20), stop:1 rgba(255, 170, 255, 13));\n"
"color: rgb(255, 255, 255);"));
        centralWidget = new QWidget(Server);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        serverGroupBox = new QGroupBox(centralWidget);
        serverGroupBox->setObjectName(QStringLiteral("serverGroupBox"));
        horizontalLayout = new QHBoxLayout(serverGroupBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(4, 4, 4, 4);
        portLabel = new QLabel(serverGroupBox);
        portLabel->setObjectName(QStringLiteral("portLabel"));

        horizontalLayout->addWidget(portLabel);

        portSpinBox = new QSpinBox(serverGroupBox);
        portSpinBox->setObjectName(QStringLiteral("portSpinBox"));
        portSpinBox->setMinimum(1024);
        portSpinBox->setMaximum(65535);
        portSpinBox->setValue(32767);

        horizontalLayout->addWidget(portSpinBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        startStopButton = new QPushButton(serverGroupBox);
        startStopButton->setObjectName(QStringLiteral("startStopButton"));
        startStopButton->setEnabled(false);

        horizontalLayout->addWidget(startStopButton);


        verticalLayout->addWidget(serverGroupBox);

        sslFilesGroupBox = new QGroupBox(centralWidget);
        sslFilesGroupBox->setObjectName(QStringLiteral("sslFilesGroupBox"));
        sslFilesGroupBox->setEnabled(false);
        sslFilesGroupBox->setFlat(false);
        gridLayout = new QGridLayout(sslFilesGroupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(4, 4, 4, 4);
        keyLabel = new QLabel(sslFilesGroupBox);
        keyLabel->setObjectName(QStringLiteral("keyLabel"));

        gridLayout->addWidget(keyLabel, 0, 0, 1, 1);

        certificateLabel = new QLabel(sslFilesGroupBox);
        certificateLabel->setObjectName(QStringLiteral("certificateLabel"));

        gridLayout->addWidget(certificateLabel, 1, 0, 1, 1);

        keyLineEdit = new QLineEdit(sslFilesGroupBox);
        keyLineEdit->setObjectName(QStringLiteral("keyLineEdit"));

        gridLayout->addWidget(keyLineEdit, 0, 1, 1, 1);

        certificateLineEdit = new QLineEdit(sslFilesGroupBox);
        certificateLineEdit->setObjectName(QStringLiteral("certificateLineEdit"));

        gridLayout->addWidget(certificateLineEdit, 1, 1, 1, 1);

        keyButton = new QToolButton(sslFilesGroupBox);
        keyButton->setObjectName(QStringLiteral("keyButton"));

        gridLayout->addWidget(keyButton, 0, 2, 1, 1);

        certificateButton = new QToolButton(sslFilesGroupBox);
        certificateButton->setObjectName(QStringLiteral("certificateButton"));

        gridLayout->addWidget(certificateButton, 1, 2, 1, 1);


        verticalLayout->addWidget(sslFilesGroupBox);

        logTextEdit = new QTextEdit(centralWidget);
        logTextEdit->setObjectName(QStringLiteral("logTextEdit"));
        logTextEdit->setReadOnly(true);

        verticalLayout->addWidget(logTextEdit);

        allerchat = new QPushButton(centralWidget);
        allerchat->setObjectName(QStringLiteral("allerchat"));

        verticalLayout->addWidget(allerchat);

        Server->setCentralWidget(centralWidget);

        retranslateUi(Server);
        QObject::connect(startStopButton, SIGNAL(clicked()), Server, SLOT(startStopButtonClicked()));
        QObject::connect(keyButton, SIGNAL(clicked()), Server, SLOT(keyButtonClicked()));
        QObject::connect(certificateButton, SIGNAL(clicked()), Server, SLOT(certificateButtonClicked()));
        QObject::connect(keyLineEdit, SIGNAL(textChanged(QString)), Server, SLOT(keyFileChanged(QString)));
        QObject::connect(certificateLineEdit, SIGNAL(textChanged(QString)), Server, SLOT(certificateFileChanged(QString)));

        QMetaObject::connectSlotsByName(Server);
    } // setupUi

    void retranslateUi(QMainWindow *Server)
    {
        Server->setWindowTitle(QApplication::translate("Server", "QSsl Chat Server", Q_NULLPTR));
        portLabel->setText(QApplication::translate("Server", "Server Port", Q_NULLPTR));
        startStopButton->setText(QApplication::translate("Server", "Start Server", Q_NULLPTR));
        keyLabel->setText(QApplication::translate("Server", "Key", Q_NULLPTR));
        certificateLabel->setText(QApplication::translate("Server", "Certificate", Q_NULLPTR));
        keyButton->setText(QApplication::translate("Server", "...", Q_NULLPTR));
        certificateButton->setText(QApplication::translate("Server", "...", Q_NULLPTR));
        allerchat->setText(QApplication::translate("Server", "aller vers chat", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Server: public Ui_Server {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_H
