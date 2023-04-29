/********************************************************************************
** Form generated from reading UI file 'chat.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chat
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *hostnameLabel;
    QLineEdit *hostnameLineEdit;
    QLabel *portLabel;
    QSpinBox *portSpinBox;
    QSpacerItem *horizontalSpacer;
    QPushButton *connectDisconnectButton;
    QFrame *line;
    QTextEdit *chatDisplayTextEdit;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *inputLineEdit;
    QPushButton *sendButton;

    void setupUi(QMainWindow *chat)
    {
        if (chat->objectName().isEmpty())
            chat->setObjectName(QStringLiteral("chat"));
        chat->resize(827, 485);
        chat->setStyleSheet(QLatin1String("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 102, 125, 11), stop:0.423729 rgba(180, 47, 126, 13), stop:0.855932 rgba(255, 170, 255, 20), stop:1 rgba(255, 170, 255, 13));\n"
"color: rgb(255, 255, 255);"));
        centralWidget = new QWidget(chat);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        hostnameLabel = new QLabel(centralWidget);
        hostnameLabel->setObjectName(QStringLiteral("hostnameLabel"));

        horizontalLayout->addWidget(hostnameLabel);

        hostnameLineEdit = new QLineEdit(centralWidget);
        hostnameLineEdit->setObjectName(QStringLiteral("hostnameLineEdit"));

        horizontalLayout->addWidget(hostnameLineEdit);

        portLabel = new QLabel(centralWidget);
        portLabel->setObjectName(QStringLiteral("portLabel"));

        horizontalLayout->addWidget(portLabel);

        portSpinBox = new QSpinBox(centralWidget);
        portSpinBox->setObjectName(QStringLiteral("portSpinBox"));
        portSpinBox->setMinimum(1024);
        portSpinBox->setMaximum(65535);
        portSpinBox->setValue(32767);

        horizontalLayout->addWidget(portSpinBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        connectDisconnectButton = new QPushButton(centralWidget);
        connectDisconnectButton->setObjectName(QStringLiteral("connectDisconnectButton"));
        connectDisconnectButton->setEnabled(false);

        horizontalLayout->addWidget(connectDisconnectButton);


        verticalLayout->addLayout(horizontalLayout);

        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        chatDisplayTextEdit = new QTextEdit(centralWidget);
        chatDisplayTextEdit->setObjectName(QStringLiteral("chatDisplayTextEdit"));
        chatDisplayTextEdit->setReadOnly(true);

        verticalLayout->addWidget(chatDisplayTextEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        inputLineEdit = new QLineEdit(centralWidget);
        inputLineEdit->setObjectName(QStringLiteral("inputLineEdit"));
        inputLineEdit->setEnabled(false);

        horizontalLayout_2->addWidget(inputLineEdit);

        sendButton = new QPushButton(centralWidget);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sendButton->setEnabled(false);

        horizontalLayout_2->addWidget(sendButton);


        verticalLayout->addLayout(horizontalLayout_2);

        chat->setCentralWidget(centralWidget);

        retranslateUi(chat);
        QObject::connect(connectDisconnectButton, SIGNAL(clicked()), chat, SLOT(connectDisconnectButtonPressed()));
        QObject::connect(sendButton, SIGNAL(clicked()), chat, SLOT(sendButtonPressed()));

        QMetaObject::connectSlotsByName(chat);
    } // setupUi

    void retranslateUi(QMainWindow *chat)
    {
        chat->setWindowTitle(QApplication::translate("chat", "QSsl Chat Client", Q_NULLPTR));
        hostnameLabel->setText(QApplication::translate("chat", "Hostname", Q_NULLPTR));
        hostnameLineEdit->setText(QApplication::translate("chat", "localhost", Q_NULLPTR));
        portLabel->setText(QApplication::translate("chat", "Port", Q_NULLPTR));
        connectDisconnectButton->setText(QApplication::translate("chat", "Connect", Q_NULLPTR));
        sendButton->setText(QApplication::translate("chat", "Send", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class chat: public Ui_chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
