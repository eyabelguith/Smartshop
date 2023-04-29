/********************************************************************************
** Form generated from reading UI file 'gestion_produit_fournisseur.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GESTION_PRODUIT_FOURNISSEUR_H
#define UI_GESTION_PRODUIT_FOURNISSEUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gestion_produit_fournisseur
{
public:
    QTabWidget *tabWidget;
    QWidget *PRODUIT;
    QTabWidget *tabWidget_2;
    QWidget *AJOuter;
    QPushButton *ajout;
    QLineEdit *lineEdit_ref;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_14;
    QLineEdit *lineEdit_prix;
    QLabel *label_5;
    QLabel *label_3;
    QLineEdit *lineEdit_nom;
    QLineEdit *lineEdit_stock;
    QComboBox *comboBox_2;
    QLabel *label_6;
    QWidget *tab_2;
    QLabel *label_7;
    QComboBox *idmodif;
    QLabel *label_9;
    QLabel *label_8;
    QPushButton *modif;
    QLineEdit *lineEdit_5;
    QLabel *label_10;
    QLineEdit *lineEdit_6;
    QLabel *label_11;
    QLabel *label_15;
    QComboBox *comboBox_4;
    QLineEdit *lineEdit_7;
    QWidget *tab_3;
    QTableView *tableView;
    QLabel *label_13;
    QWidget *tab_4;
    QLabel *label_12;
    QTableView *produit_2;
    QGroupBox *groupBox_2;
    QPushButton *pushButton_2;
    QPushButton *cherchep;
    QLineEdit *cherchp;
    QPushButton *trie;
    QPushButton *pushButton;
    QWidget *tab_8;
    QLabel *label_18;
    QTableView *tableView_mailing;
    QGroupBox *groupBox_3;
    QLabel *label_25;
    QLineEdit *server;
    QLineEdit *port;
    QLabel *label_28;
    QLineEdit *uname;
    QLabel *label_29;
    QLineEdit *paswd;
    QLabel *label_30;
    QLineEdit *rcpt;
    QLabel *label_31;
    QLineEdit *subject;
    QLabel *label_32;
    QLineEdit *file;
    QLabel *label_33;
    QPushButton *browseBtn;
    QLabel *label_34;
    QPushButton *sendBtn;
    QPlainTextEdit *msg;
    QWidget *tab;
    QLabel *label_16;
    QTableView *tableView_2;
    QWidget *gridLayoutWidget;
    QGridLayout *customizeLayout;
    QComboBox *comboBox_color;
    QLabel *label_errorCor;
    QComboBox *comboBox_errorlvl;
    QSpinBox *spinBox_borderSize;
    QLabel *label_color;
    QLabel *label_borderSize;
    QPushButton *generateButton;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *directoryLayout;
    QLabel *label_saveto;
    QLineEdit *lineEdit_fileDirectory;
    QPushButton *browseButton;
    QPushButton *pushButton_5;
    QPushButton *exitButton;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *inputLayout;
    QHBoxLayout *textLayout;
    QLabel *label_text;
    QSpacerItem *horizontalSpacer;
    QPushButton *pasteButton;
    QPushButton *clearButton;
    QPlainTextEdit *userTextInput;
    QWidget *tab_7;
    QLabel *label_17;
    QTableView *tableView_4;
    QLabel *label_36;
    QLabel *update_arduino;
    QWidget *FORNISSEUR;
    QTabWidget *tabWidget_3;
    QWidget *tab_5;
    QPushButton *ajoutf;
    QLineEdit *lineEdit_a;
    QLabel *label_26;
    QLabel *label_19;
    QLineEdit *lineEdit_m;
    QLineEdit *lineEdit_e;
    QLabel *label_20;
    QLineEdit *lineEdit_t;
    QLineEdit *lineEdit_n;
    QLabel *label_27;
    QLabel *label_21;
    QLabel *label_22;
    QWidget *tab_6;
    QLabel *label_23;
    QPushButton *pushButton_3;
    QPushButton *rech;
    QLineEdit *recherche;
    QPushButton *pushButton_9;
    QTableView *fournisseurtable;
    QGroupBox *groupBox;
    QWidget *tab_9;
    QLineEdit *lineEdit_numf;
    QLabel *label_35;
    QLabel *label_37;
    QPushButton *pushButton_modf;
    QLineEdit *lineEdit_ad;
    QComboBox *comboBox_mat;
    QLabel *label_38;
    QLineEdit *lineEdit_mail;
    QLabel *label_39;
    QLabel *label_40;
    QLineEdit *lineEdit_nf;
    QLabel *label_41;
    QWidget *tab_10;
    QTableView *tableView_3;
    QLabel *label_24;
    QWidget *tab_11;
    QToolButton *toolButton_6;
    QToolButton *toolButton_9;
    QLabel *label_42;
    QLabel *label;
    QSlider *horizontalSlider;
    QToolButton *start;
    QToolButton *stop;

    void setupUi(QDialog *gestion_produit_fournisseur)
    {
        if (gestion_produit_fournisseur->objectName().isEmpty())
            gestion_produit_fournisseur->setObjectName(QStringLiteral("gestion_produit_fournisseur"));
        gestion_produit_fournisseur->resize(1004, 641);
        tabWidget = new QTabWidget(gestion_produit_fournisseur);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(20, 50, 961, 581));
        tabWidget->setAutoFillBackground(true);
        tabWidget->setStyleSheet(QStringLiteral("font: 20pt \"MV Boli\";"));
        tabWidget->setTabBarAutoHide(false);
        PRODUIT = new QWidget();
        PRODUIT->setObjectName(QStringLiteral("PRODUIT"));
        tabWidget_2 = new QTabWidget(PRODUIT);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(-10, -10, 971, 551));
        tabWidget_2->setAutoFillBackground(false);
        tabWidget_2->setStyleSheet(QStringLiteral(""));
        AJOuter = new QWidget();
        AJOuter->setObjectName(QStringLiteral("AJOuter"));
        ajout = new QPushButton(AJOuter);
        ajout->setObjectName(QStringLiteral("ajout"));
        ajout->setGeometry(QRect(510, 240, 291, 61));
        ajout->setStyleSheet(QLatin1String("font: 16pt \"MS Shell Dlg 2\";\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 30px;\n"
"background-color: rgb(170, 0, 0);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/rs/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        ajout->setIcon(icon);
        ajout->setIconSize(QSize(50, 50));
        lineEdit_ref = new QLineEdit(AJOuter);
        lineEdit_ref->setObjectName(QStringLiteral("lineEdit_ref"));
        lineEdit_ref->setGeometry(QRect(220, 50, 191, 31));
        lineEdit_ref->setStyleSheet(QLatin1String("font: italic 22pt \"High Tower Text\";\n"
"background-color: rgb(255, 255, 255);\n"
"background-color: rgb(255, 255, 255);"));
        label_4 = new QLabel(AJOuter);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, 290, 201, 111));
        QFont font;
        font.setFamily(QStringLiteral("MV Boli"));
        font.setPointSize(20);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label_4->setFont(font);
        label_4->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_2 = new QLabel(AJOuter);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 20, 171, 61));
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_14 = new QLabel(AJOuter);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(10, 370, 201, 111));
        label_14->setFont(font);
        label_14->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        lineEdit_prix = new QLineEdit(AJOuter);
        lineEdit_prix->setObjectName(QStringLiteral("lineEdit_prix"));
        lineEdit_prix->setGeometry(QRect(220, 160, 191, 31));
        lineEdit_prix->setStyleSheet(QLatin1String("font: italic 22pt \"High Tower Text\";\n"
"background-color: rgb(255, 255, 255);"));
        label_5 = new QLabel(AJOuter);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 100, 171, 71));
        label_5->setFont(font);
        label_5->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_3 = new QLabel(AJOuter);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 210, 151, 81));
        label_3->setFont(font);
        label_3->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
""));
        lineEdit_nom = new QLineEdit(AJOuter);
        lineEdit_nom->setObjectName(QStringLiteral("lineEdit_nom"));
        lineEdit_nom->setGeometry(QRect(220, 260, 191, 31));
        lineEdit_nom->setStyleSheet(QLatin1String("font: italic 22pt \"High Tower Text\";\n"
"background-color: rgb(255, 255, 255);"));
        lineEdit_stock = new QLineEdit(AJOuter);
        lineEdit_stock->setObjectName(QStringLiteral("lineEdit_stock"));
        lineEdit_stock->setGeometry(QRect(220, 340, 191, 31));
        lineEdit_stock->setStyleSheet(QLatin1String("font: italic 22pt \"High Tower Text\";\n"
"background-color: rgb(255, 255, 255);"));
        comboBox_2 = new QComboBox(AJOuter);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(250, 420, 111, 31));
        comboBox_2->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"font: 8pt \"MS Shell Dlg 2\";"));
        label_6 = new QLabel(AJOuter);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(0, 0, 971, 511));
        label_6->setStyleSheet(QStringLiteral("background-image: url(:/img/rs/ajoutempback.jpg);"));
        tabWidget_2->addTab(AJOuter, QString());
        label_6->raise();
        ajout->raise();
        lineEdit_ref->raise();
        label_4->raise();
        label_2->raise();
        label_14->raise();
        lineEdit_prix->raise();
        label_5->raise();
        label_3->raise();
        lineEdit_nom->raise();
        lineEdit_stock->raise();
        comboBox_2->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(0, -10, 971, 521));
        label_7->setStyleSheet(QStringLiteral("background-image: url(:/img/rs/ajoutempback.jpg);"));
        idmodif = new QComboBox(tab_2);
        idmodif->setObjectName(QStringLiteral("idmodif"));
        idmodif->setGeometry(QRect(250, 40, 221, 51));
        idmodif->setCursor(QCursor(Qt::PointingHandCursor));
        idmodif->setFocusPolicy(Qt::WheelFocus);
        idmodif->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"font: 8pt \"MS Shell Dlg 2\";"));
        idmodif->setIconSize(QSize(16, 16));
        idmodif->setFrame(true);
        label_9 = new QLabel(tab_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 280, 201, 111));
        label_9->setFont(font);
        label_9->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 190, 201, 111));
        label_8->setFont(font);
        label_8->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        modif = new QPushButton(tab_2);
        modif->setObjectName(QStringLiteral("modif"));
        modif->setGeometry(QRect(540, 160, 231, 61));
        modif->setStyleSheet(QLatin1String("font: 20pt \"MS Shell Dlg 2\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(170, 0, 0);\n"
"border-radius: 30px;"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/rs/update.png"), QSize(), QIcon::Normal, QIcon::Off);
        modif->setIcon(icon1);
        modif->setIconSize(QSize(50, 50));
        lineEdit_5 = new QLineEdit(tab_2);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(250, 130, 211, 41));
        lineEdit_5->setStyleSheet(QLatin1String("font: italic 18pt \"High Tower Text\";\n"
"background-color: rgb(255, 255, 255);"));
        label_10 = new QLabel(tab_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 80, 201, 111));
        label_10->setFont(font);
        label_10->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        lineEdit_6 = new QLineEdit(tab_2);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(250, 230, 221, 41));
        lineEdit_6->setStyleSheet(QLatin1String("font: italic 18pt \"High Tower Text\";\n"
"background-color: rgb(255, 255, 255);"));
        label_11 = new QLabel(tab_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 0, 201, 111));
        label_11->setFont(font);
        label_11->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_15 = new QLabel(tab_2);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(10, 350, 201, 111));
        label_15->setFont(font);
        label_15->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        comboBox_4 = new QComboBox(tab_2);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));
        comboBox_4->setEnabled(false);
        comboBox_4->setGeometry(QRect(290, 400, 111, 31));
        comboBox_4->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        comboBox_4->setEditable(true);
        lineEdit_7 = new QLineEdit(tab_2);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(250, 320, 221, 41));
        lineEdit_7->setStyleSheet(QLatin1String("font: italic 18pt \"High Tower Text\";\n"
"background-color: rgb(255, 255, 255);"));
        tabWidget_2->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tableView = new QTableView(tab_3);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(120, 30, 621, 381));
        tableView->setStyleSheet(QLatin1String("font: 16pt \"MS Shell Dlg 2\";\n"
"background-color: rgb(170, 0, 0,60%);"));
        label_13 = new QLabel(tab_3);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(0, 0, 981, 501));
        label_13->setStyleSheet(QStringLiteral("background-image: url(:/img/rs/ajoutempback.jpg);"));
        tabWidget_2->addTab(tab_3, QString());
        label_13->raise();
        tableView->raise();
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        label_12 = new QLabel(tab_4);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(0, -10, 961, 521));
        label_12->setStyleSheet(QStringLiteral("background-image: url(:/img/rs/ajoutempback.jpg);"));
        produit_2 = new QTableView(tab_4);
        produit_2->setObjectName(QStringLiteral("produit_2"));
        produit_2->setEnabled(true);
        produit_2->setGeometry(QRect(0, 80, 601, 331));
        produit_2->setStyleSheet(QLatin1String("background-color: rgb(170, 0, 0,80%);\n"
"font: 16pt \"MS Shell Dlg 2\";\n"
""));
        groupBox_2 = new QGroupBox(tab_4);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(640, 30, 301, 441));
        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 270, 281, 61));
        pushButton_2->setStyleSheet(QLatin1String("font: 16pt \"MS Shell Dlg 2\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(170, 0, 0);\n"
"border-radius: 30px;"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/rs/mailing.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon2);
        pushButton_2->setIconSize(QSize(60, 60));
        cherchep = new QPushButton(groupBox_2);
        cherchep->setObjectName(QStringLiteral("cherchep"));
        cherchep->setGeometry(QRect(50, 170, 221, 61));
        cherchep->setStyleSheet(QLatin1String("font: 16pt \"MS Shell Dlg 2\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(170, 0, 0);\n"
"border-radius: 30px;"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/img/rs/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        cherchep->setIcon(icon3);
        cherchep->setIconSize(QSize(60, 60));
        cherchp = new QLineEdit(groupBox_2);
        cherchp->setObjectName(QStringLiteral("cherchp"));
        cherchp->setGeometry(QRect(70, 130, 171, 31));
        cherchp->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        trie = new QPushButton(groupBox_2);
        trie->setObjectName(QStringLiteral("trie"));
        trie->setGeometry(QRect(50, 20, 211, 61));
        trie->setStyleSheet(QLatin1String("font: 16pt \"MS Shell Dlg 2\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(170, 0, 0);\n"
"border-radius: 30px;"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/img/rs/trie.png"), QSize(), QIcon::Normal, QIcon::Off);
        trie->setIcon(icon4);
        trie->setIconSize(QSize(60, 60));
        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(40, 360, 231, 61));
        pushButton->setStyleSheet(QLatin1String("font: 16pt \"MS Shell Dlg 2\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(170, 0, 0);\n"
"border-radius: 30px;"));
        pushButton->setIcon(icon1);
        pushButton->setIconSize(QSize(50, 50));
        tabWidget_2->addTab(tab_4, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QStringLiteral("tab_8"));
        label_18 = new QLabel(tab_8);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(0, -10, 961, 521));
        label_18->setStyleSheet(QStringLiteral("background-image: url(:/img/rs/ajoutempback.jpg);"));
        tableView_mailing = new QTableView(tab_8);
        tableView_mailing->setObjectName(QStringLiteral("tableView_mailing"));
        tableView_mailing->setGeometry(QRect(20, 50, 371, 401));
        tableView_mailing->setStyleSheet(QLatin1String("background-color: rgb(170, 0, 0,80%);\n"
"font: 16pt \"MS Shell Dlg 2\";\n"
""));
        groupBox_3 = new QGroupBox(tab_8);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(430, 10, 501, 471));
        groupBox_3->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:0.176, y1:0.284091, x2:0.98995, y2:0.977, stop:0 rgba(170, 0, 0, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));\n"
"font: 8pt \"MS Shell Dlg 2\";"));
        label_25 = new QLabel(groupBox_3);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(40, 20, 91, 41));
        label_25->setStyleSheet(QLatin1String("font: 10pt \"MS Shell Dlg 2\";\n"
"background-color: rgb(255, 255, 255,20%);"));
        server = new QLineEdit(groupBox_3);
        server->setObjectName(QStringLiteral("server"));
        server->setGeometry(QRect(150, 30, 151, 31));
        server->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        port = new QLineEdit(groupBox_3);
        port->setObjectName(QStringLiteral("port"));
        port->setGeometry(QRect(150, 80, 151, 31));
        port->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_28 = new QLabel(groupBox_3);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(40, 70, 91, 41));
        label_28->setStyleSheet(QLatin1String("font: 10pt \"MS Shell Dlg 2\";\n"
"background-color: rgb(255, 255, 255,20%);"));
        uname = new QLineEdit(groupBox_3);
        uname->setObjectName(QStringLiteral("uname"));
        uname->setGeometry(QRect(150, 130, 151, 31));
        uname->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_29 = new QLabel(groupBox_3);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(40, 120, 91, 41));
        label_29->setStyleSheet(QLatin1String("font: 10pt \"MS Shell Dlg 2\";\n"
"background-color: rgb(255, 255, 255,20%);"));
        paswd = new QLineEdit(groupBox_3);
        paswd->setObjectName(QStringLiteral("paswd"));
        paswd->setGeometry(QRect(150, 180, 151, 31));
        paswd->setAutoFillBackground(false);
        paswd->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        paswd->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText|Qt::ImhSensitiveData);
        label_30 = new QLabel(groupBox_3);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(40, 170, 91, 41));
        label_30->setStyleSheet(QLatin1String("font: 10pt \"MS Shell Dlg 2\";\n"
"background-color: rgb(255, 255, 255,20%);"));
        rcpt = new QLineEdit(groupBox_3);
        rcpt->setObjectName(QStringLiteral("rcpt"));
        rcpt->setGeometry(QRect(150, 230, 151, 31));
        rcpt->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_31 = new QLabel(groupBox_3);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(40, 220, 111, 41));
        label_31->setStyleSheet(QLatin1String("font: 10pt \"MS Shell Dlg 2\";\n"
"background-color: rgb(255, 255, 255,20%);"));
        subject = new QLineEdit(groupBox_3);
        subject->setObjectName(QStringLiteral("subject"));
        subject->setGeometry(QRect(150, 280, 151, 31));
        subject->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"font: 8pt \"MS Shell Dlg 2\";"));
        label_32 = new QLabel(groupBox_3);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setGeometry(QRect(40, 270, 91, 41));
        label_32->setStyleSheet(QLatin1String("font: 12pt \"MS Shell Dlg 2\";\n"
"background-color: rgb(255, 255, 255,20%);"));
        file = new QLineEdit(groupBox_3);
        file->setObjectName(QStringLiteral("file"));
        file->setGeometry(QRect(150, 330, 151, 31));
        file->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_33 = new QLabel(groupBox_3);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setGeometry(QRect(40, 320, 111, 41));
        label_33->setStyleSheet(QLatin1String("font: 10pt \"MS Shell Dlg 2\";\n"
"background-color: rgb(255, 255, 255,20%);"));
        browseBtn = new QPushButton(groupBox_3);
        browseBtn->setObjectName(QStringLiteral("browseBtn"));
        browseBtn->setGeometry(QRect(320, 340, 75, 23));
        browseBtn->setStyleSheet(QStringLiteral("font: 12pt \"MS Shell Dlg 2\";"));
        label_34 = new QLabel(groupBox_3);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setGeometry(QRect(40, 370, 91, 41));
        label_34->setStyleSheet(QLatin1String("font: 10pt \"MS Shell Dlg 2\";\n"
"background-color: rgb(255, 255, 255,20%);"));
        sendBtn = new QPushButton(groupBox_3);
        sendBtn->setObjectName(QStringLiteral("sendBtn"));
        sendBtn->setGeometry(QRect(320, 210, 171, 71));
        sendBtn->setStyleSheet(QLatin1String("font: 15pt \"MS Shell Dlg 2\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(170, 0, 0);\n"
"border-radius: 30px;"));
        sendBtn->setIcon(icon2);
        sendBtn->setIconSize(QSize(65, 65));
        msg = new QPlainTextEdit(groupBox_3);
        msg->setObjectName(QStringLiteral("msg"));
        msg->setGeometry(QRect(140, 370, 251, 101));
        msg->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        tabWidget_2->addTab(tab_8, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label_16 = new QLabel(tab);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(0, -10, 971, 511));
        label_16->setStyleSheet(QStringLiteral("background-image: url(:/img/rs/ajoutempback.jpg);"));
        tableView_2 = new QTableView(tab);
        tableView_2->setObjectName(QStringLiteral("tableView_2"));
        tableView_2->setGeometry(QRect(470, 100, 481, 271));
        tableView_2->setStyleSheet(QLatin1String("background-color: rgb(170, 0, 0,80%);\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
""));
        gridLayoutWidget = new QWidget(tab);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 390, 371, 61));
        customizeLayout = new QGridLayout(gridLayoutWidget);
        customizeLayout->setObjectName(QStringLiteral("customizeLayout"));
        customizeLayout->setContentsMargins(0, 0, 0, 0);
        comboBox_color = new QComboBox(gridLayoutWidget);
        comboBox_color->setObjectName(QStringLiteral("comboBox_color"));
        comboBox_color->setStyleSheet(QLatin1String("font: 10pt \"MS Shell Dlg 2\";\n"
"background-color: rgb(255, 255, 255);"));

        customizeLayout->addWidget(comboBox_color, 3, 2, 1, 1);

        label_errorCor = new QLabel(gridLayoutWidget);
        label_errorCor->setObjectName(QStringLiteral("label_errorCor"));
        label_errorCor->setStyleSheet(QLatin1String("background-color: rgb(170, 0, 0);\n"
"font: 10pt \"MS Shell Dlg 2\";"));

        customizeLayout->addWidget(label_errorCor, 1, 0, 1, 1);

        comboBox_errorlvl = new QComboBox(gridLayoutWidget);
        comboBox_errorlvl->setObjectName(QStringLiteral("comboBox_errorlvl"));
        comboBox_errorlvl->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"font: 10pt \"MS Shell Dlg 2\";"));

        customizeLayout->addWidget(comboBox_errorlvl, 3, 0, 1, 1);

        spinBox_borderSize = new QSpinBox(gridLayoutWidget);
        spinBox_borderSize->setObjectName(QStringLiteral("spinBox_borderSize"));
        spinBox_borderSize->setStyleSheet(QStringLiteral("font: 10pt \"MS Shell Dlg 2\";"));
        spinBox_borderSize->setMinimum(4);
        spinBox_borderSize->setMaximum(40);
        spinBox_borderSize->setValue(4);

        customizeLayout->addWidget(spinBox_borderSize, 3, 1, 1, 1);

        label_color = new QLabel(gridLayoutWidget);
        label_color->setObjectName(QStringLiteral("label_color"));
        label_color->setStyleSheet(QLatin1String("background-color: rgb(170, 0, 0);\n"
"font: 10pt \"MS Shell Dlg 2\";"));

        customizeLayout->addWidget(label_color, 1, 2, 1, 1);

        label_borderSize = new QLabel(gridLayoutWidget);
        label_borderSize->setObjectName(QStringLiteral("label_borderSize"));
        label_borderSize->setStyleSheet(QLatin1String("background-color: rgb(170, 0, 0);\n"
"font: 10pt \"MS Shell Dlg 2\";"));

        customizeLayout->addWidget(label_borderSize, 1, 1, 1, 1);

        generateButton = new QPushButton(tab);
        generateButton->setObjectName(QStringLiteral("generateButton"));
        generateButton->setEnabled(false);
        generateButton->setGeometry(QRect(540, 390, 140, 70));
        QFont font1;
        font1.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font1.setPointSize(15);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        generateButton->setFont(font1);
        generateButton->setStyleSheet(QLatin1String("font: 15pt \"MS Shell Dlg 2\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(170, 0, 0);\n"
"border-radius: 30px;"));
        horizontalLayoutWidget = new QWidget(tab);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(150, 20, 671, 42));
        directoryLayout = new QHBoxLayout(horizontalLayoutWidget);
        directoryLayout->setObjectName(QStringLiteral("directoryLayout"));
        directoryLayout->setContentsMargins(0, 0, 0, 0);
        label_saveto = new QLabel(horizontalLayoutWidget);
        label_saveto->setObjectName(QStringLiteral("label_saveto"));
        label_saveto->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: 14pt \"MS Shell Dlg 2\";"));

        directoryLayout->addWidget(label_saveto);

        lineEdit_fileDirectory = new QLineEdit(horizontalLayoutWidget);
        lineEdit_fileDirectory->setObjectName(QStringLiteral("lineEdit_fileDirectory"));
        lineEdit_fileDirectory->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"font: 8pt \"MS Shell Dlg 2\";"));

        directoryLayout->addWidget(lineEdit_fileDirectory);

        browseButton = new QPushButton(horizontalLayoutWidget);
        browseButton->setObjectName(QStringLiteral("browseButton"));
        browseButton->setStyleSheet(QLatin1String("font: 14pt \"MS Shell Dlg 2\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(170, 0, 0);\n"
"border-radius: 30px;"));

        directoryLayout->addWidget(browseButton);

        pushButton_5 = new QPushButton(horizontalLayoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setStyleSheet(QLatin1String("font: 14pt \"MS Shell Dlg 2\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(170, 0, 0);\n"
"border-radius: 30px;background-color: rgb(170, 0, 0);"));

        directoryLayout->addWidget(pushButton_5);

        exitButton = new QPushButton(tab);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setGeometry(QRect(740, 400, 141, 61));
        exitButton->setStyleSheet(QLatin1String("font: 15pt \"MS Shell Dlg 2\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(170, 0, 0);\n"
"border-radius: 30px;"));
        verticalLayoutWidget = new QWidget(tab);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 130, 421, 211));
        inputLayout = new QVBoxLayout(verticalLayoutWidget);
        inputLayout->setObjectName(QStringLiteral("inputLayout"));
        inputLayout->setContentsMargins(0, 0, 0, 0);
        textLayout = new QHBoxLayout();
        textLayout->setObjectName(QStringLiteral("textLayout"));
        label_text = new QLabel(verticalLayoutWidget);
        label_text->setObjectName(QStringLiteral("label_text"));
        label_text->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: 10pt \"MS Shell Dlg 2\";"));

        textLayout->addWidget(label_text);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        textLayout->addItem(horizontalSpacer);

        pasteButton = new QPushButton(verticalLayoutWidget);
        pasteButton->setObjectName(QStringLiteral("pasteButton"));
        pasteButton->setStyleSheet(QLatin1String("font: 10pt \"MS Shell Dlg 2\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(170, 0, 0);\n"
"border-radius: 30px;"));

        textLayout->addWidget(pasteButton);

        clearButton = new QPushButton(verticalLayoutWidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        clearButton->setEnabled(false);
        clearButton->setStyleSheet(QLatin1String("font: 10pt \"MS Shell Dlg 2\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(170, 0, 0);\n"
"border-radius: 30px;"));

        textLayout->addWidget(clearButton);


        inputLayout->addLayout(textLayout);

        userTextInput = new QPlainTextEdit(verticalLayoutWidget);
        userTextInput->setObjectName(QStringLiteral("userTextInput"));
        userTextInput->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"font: 16pt \"MS Shell Dlg 2\";"));

        inputLayout->addWidget(userTextInput);

        tabWidget_2->addTab(tab, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        label_17 = new QLabel(tab_7);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(0, -10, 971, 511));
        label_17->setStyleSheet(QStringLiteral("background-image: url(:/img/rs/ajoutempback.jpg);"));
        tableView_4 = new QTableView(tab_7);
        tableView_4->setObjectName(QStringLiteral("tableView_4"));
        tableView_4->setGeometry(QRect(100, 240, 741, 181));
        tableView_4->setStyleSheet(QLatin1String("background-color: rgb(170, 0, 0,80%);\n"
"font: 16pt \"MS Shell Dlg 2\";"));
        label_36 = new QLabel(tab_7);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setGeometry(QRect(40, 20, 211, 161));
        label_36->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"background-image: url(:/img/rs/qr-code.jpg);"));
        update_arduino = new QLabel(tab_7);
        update_arduino->setObjectName(QStringLiteral("update_arduino"));
        update_arduino->setGeometry(QRect(330, 40, 431, 131));
        update_arduino->setStyleSheet(QLatin1String("font: 20pt \"MS Shell Dlg 2\";\n"
"border-color: rgb(255, 255, 255);\n"
"color: rgb(255, 255, 255);"));
        tabWidget_2->addTab(tab_7, QString());
        tabWidget->addTab(PRODUIT, QString());
        FORNISSEUR = new QWidget();
        FORNISSEUR->setObjectName(QStringLiteral("FORNISSEUR"));
        tabWidget_3 = new QTabWidget(FORNISSEUR);
        tabWidget_3->setObjectName(QStringLiteral("tabWidget_3"));
        tabWidget_3->setGeometry(QRect(0, -10, 961, 551));
        tabWidget_3->setStyleSheet(QStringLiteral(""));
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        ajoutf = new QPushButton(tab_5);
        ajoutf->setObjectName(QStringLiteral("ajoutf"));
        ajoutf->setGeometry(QRect(460, 200, 311, 61));
        ajoutf->setStyleSheet(QLatin1String("font: 16pt \"MS Shell Dlg 2\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(170, 0, 0);\n"
"border-radius: 30px;"));
        ajoutf->setIcon(icon);
        ajoutf->setIconSize(QSize(50, 50));
        lineEdit_a = new QLineEdit(tab_5);
        lineEdit_a->setObjectName(QStringLiteral("lineEdit_a"));
        lineEdit_a->setGeometry(QRect(210, 120, 161, 31));
        lineEdit_a->setStyleSheet(QLatin1String("font: italic 22pt \"High Tower Text\";\n"
"background-color: rgb(255, 255, 255);"));
        label_26 = new QLabel(tab_5);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(40, 290, 141, 41));
        label_26->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_19 = new QLabel(tab_5);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(40, 20, 151, 41));
        label_19->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        lineEdit_m = new QLineEdit(tab_5);
        lineEdit_m->setObjectName(QStringLiteral("lineEdit_m"));
        lineEdit_m->setGeometry(QRect(210, 30, 161, 31));
        lineEdit_m->setStyleSheet(QLatin1String("font: italic 22pt \"High Tower Text\";\n"
"background-color: rgb(255, 255, 255);"));
        lineEdit_e = new QLineEdit(tab_5);
        lineEdit_e->setObjectName(QStringLiteral("lineEdit_e"));
        lineEdit_e->setGeometry(QRect(210, 300, 161, 31));
        lineEdit_e->setStyleSheet(QLatin1String("font: italic 22pt \"High Tower Text\";\n"
"background-color: rgb(255, 255, 255);"));
        label_20 = new QLabel(tab_5);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(40, 200, 141, 41));
        label_20->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        lineEdit_t = new QLineEdit(tab_5);
        lineEdit_t->setObjectName(QStringLiteral("lineEdit_t"));
        lineEdit_t->setGeometry(QRect(210, 390, 161, 31));
        lineEdit_t->setStyleSheet(QLatin1String("font: italic 22pt \"High Tower Text\";\n"
"background-color: rgb(255, 255, 255);"));
        lineEdit_n = new QLineEdit(tab_5);
        lineEdit_n->setObjectName(QStringLiteral("lineEdit_n"));
        lineEdit_n->setGeometry(QRect(210, 210, 161, 31));
        lineEdit_n->setStyleSheet(QLatin1String("font: italic 22pt \"High Tower Text\";\n"
"background-color: rgb(255, 255, 255);"));
        label_27 = new QLabel(tab_5);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(40, 380, 141, 41));
        label_27->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_21 = new QLabel(tab_5);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(40, 110, 141, 41));
        label_21->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_22 = new QLabel(tab_5);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(0, 0, 951, 501));
        label_22->setStyleSheet(QStringLiteral("background-image: url(:/img/rs/ajoutempback.jpg);"));
        tabWidget_3->addTab(tab_5, QString());
        label_22->raise();
        ajoutf->raise();
        lineEdit_a->raise();
        label_26->raise();
        label_19->raise();
        lineEdit_m->raise();
        lineEdit_e->raise();
        label_20->raise();
        lineEdit_t->raise();
        lineEdit_n->raise();
        label_27->raise();
        label_21->raise();
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        label_23 = new QLabel(tab_6);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(0, -10, 951, 511));
        label_23->setStyleSheet(QStringLiteral("background-image: url(:/img/rs/ajoutempback.jpg);"));
        pushButton_3 = new QPushButton(tab_6);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(660, 70, 231, 61));
        pushButton_3->setStyleSheet(QLatin1String("font: 16pt \"MS Shell Dlg 2\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(170, 0, 0);\n"
"border-radius: 30px;"));
        pushButton_3->setIcon(icon4);
        pushButton_3->setIconSize(QSize(60, 60));
        rech = new QPushButton(tab_6);
        rech->setObjectName(QStringLiteral("rech"));
        rech->setGeometry(QRect(650, 240, 241, 61));
        rech->setStyleSheet(QLatin1String("font: 16pt \"MS Shell Dlg 2\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(170, 0, 0);\n"
"border-radius: 30px;"));
        rech->setIcon(icon3);
        rech->setIconSize(QSize(50, 50));
        recherche = new QLineEdit(tab_6);
        recherche->setObjectName(QStringLiteral("recherche"));
        recherche->setGeometry(QRect(680, 190, 191, 31));
        recherche->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));
        pushButton_9 = new QPushButton(tab_6);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(650, 340, 241, 61));
        pushButton_9->setStyleSheet(QLatin1String("font: 16pt \"MS Shell Dlg 2\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(170, 0, 0);\n"
"border-radius: 30px;"));
        pushButton_9->setIcon(icon1);
        pushButton_9->setIconSize(QSize(50, 50));
        fournisseurtable = new QTableView(tab_6);
        fournisseurtable->setObjectName(QStringLiteral("fournisseurtable"));
        fournisseurtable->setGeometry(QRect(10, 50, 601, 361));
        fournisseurtable->setStyleSheet(QLatin1String("background-color: rgb(170, 0, 0,80%);\n"
"font: 16pt \"MS Shell Dlg 2\";\n"
""));
        fournisseurtable->setSortingEnabled(false);
        groupBox = new QGroupBox(tab_6);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(640, 50, 281, 391));
        tabWidget_3->addTab(tab_6, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName(QStringLiteral("tab_9"));
        lineEdit_numf = new QLineEdit(tab_9);
        lineEdit_numf->setObjectName(QStringLiteral("lineEdit_numf"));
        lineEdit_numf->setGeometry(QRect(280, 220, 201, 31));
        lineEdit_numf->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_35 = new QLabel(tab_9);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setGeometry(QRect(40, 380, 191, 61));
        label_35->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: 24pt \"MS Shell Dlg 2\";"));
        label_37 = new QLabel(tab_9);
        label_37->setObjectName(QStringLiteral("label_37"));
        label_37->setGeometry(QRect(40, 200, 191, 61));
        label_37->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: 24pt \"MS Shell Dlg 2\";"));
        pushButton_modf = new QPushButton(tab_9);
        pushButton_modf->setObjectName(QStringLiteral("pushButton_modf"));
        pushButton_modf->setGeometry(QRect(620, 200, 251, 61));
        pushButton_modf->setStyleSheet(QLatin1String("font: 20pt \"MS Shell Dlg 2\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(170, 0, 0);\n"
"border-radius: 30px;"));
        pushButton_modf->setIcon(icon1);
        pushButton_modf->setIconSize(QSize(50, 50));
        lineEdit_ad = new QLineEdit(tab_9);
        lineEdit_ad->setObjectName(QStringLiteral("lineEdit_ad"));
        lineEdit_ad->setGeometry(QRect(280, 310, 201, 31));
        lineEdit_ad->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        comboBox_mat = new QComboBox(tab_9);
        comboBox_mat->setObjectName(QStringLiteral("comboBox_mat"));
        comboBox_mat->setGeometry(QRect(280, 30, 201, 31));
        comboBox_mat->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"font: 8pt \"MS Shell Dlg 2\";"));
        label_38 = new QLabel(tab_9);
        label_38->setObjectName(QStringLiteral("label_38"));
        label_38->setGeometry(QRect(40, 110, 191, 61));
        label_38->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: 24pt \"MS Shell Dlg 2\";"));
        lineEdit_mail = new QLineEdit(tab_9);
        lineEdit_mail->setObjectName(QStringLiteral("lineEdit_mail"));
        lineEdit_mail->setGeometry(QRect(280, 400, 201, 31));
        lineEdit_mail->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_39 = new QLabel(tab_9);
        label_39->setObjectName(QStringLiteral("label_39"));
        label_39->setGeometry(QRect(40, 20, 191, 61));
        label_39->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: 24pt \"MS Shell Dlg 2\";"));
        label_40 = new QLabel(tab_9);
        label_40->setObjectName(QStringLiteral("label_40"));
        label_40->setGeometry(QRect(40, 290, 191, 61));
        label_40->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: 24pt \"MS Shell Dlg 2\";"));
        lineEdit_nf = new QLineEdit(tab_9);
        lineEdit_nf->setObjectName(QStringLiteral("lineEdit_nf"));
        lineEdit_nf->setGeometry(QRect(280, 130, 201, 31));
        lineEdit_nf->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_41 = new QLabel(tab_9);
        label_41->setObjectName(QStringLiteral("label_41"));
        label_41->setGeometry(QRect(0, -10, 961, 511));
        label_41->setStyleSheet(QStringLiteral("background-image: url(:/img/rs/ajoutempback.jpg);"));
        tabWidget_3->addTab(tab_9, QString());
        label_41->raise();
        lineEdit_numf->raise();
        label_35->raise();
        label_37->raise();
        pushButton_modf->raise();
        lineEdit_ad->raise();
        comboBox_mat->raise();
        label_38->raise();
        lineEdit_mail->raise();
        label_39->raise();
        label_40->raise();
        lineEdit_nf->raise();
        tab_10 = new QWidget();
        tab_10->setObjectName(QStringLiteral("tab_10"));
        tableView_3 = new QTableView(tab_10);
        tableView_3->setObjectName(QStringLiteral("tableView_3"));
        tableView_3->setGeometry(QRect(130, 60, 661, 361));
        tableView_3->setStyleSheet(QLatin1String("background-color: rgb(170, 0, 0,80%);\n"
"font: 16pt \"MS Shell Dlg 2\";\n"
""));
        label_24 = new QLabel(tab_10);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(-10, 0, 971, 501));
        label_24->setStyleSheet(QStringLiteral("background-image: url(:/img/rs/ajoutempback.jpg);"));
        tabWidget_3->addTab(tab_10, QString());
        label_24->raise();
        tableView_3->raise();
        tab_11 = new QWidget();
        tab_11->setObjectName(QStringLiteral("tab_11"));
        toolButton_6 = new QToolButton(tab_11);
        toolButton_6->setObjectName(QStringLiteral("toolButton_6"));
        toolButton_6->setGeometry(QRect(170, 200, 251, 91));
        toolButton_6->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"border-radius: 32px;\n"
"background-color: rgb(170, 0, 0);\n"
"font: 20pt \"MV Boli\";\n"
""));
        toolButton_9 = new QToolButton(tab_11);
        toolButton_9->setObjectName(QStringLiteral("toolButton_9"));
        toolButton_9->setGeometry(QRect(510, 210, 241, 81));
        toolButton_9->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"border-radius: 32px;\n"
"background-color: rgb(170, 0, 0);\n"
"font: 20pt \"MV Boli\";\n"
""));
        label_42 = new QLabel(tab_11);
        label_42->setObjectName(QStringLiteral("label_42"));
        label_42->setGeometry(QRect(-10, -10, 971, 511));
        label_42->setStyleSheet(QStringLiteral("background-image: url(:/img/rs/ajoutempback.jpg);"));
        tabWidget_3->addTab(tab_11, QString());
        label_42->raise();
        toolButton_6->raise();
        toolButton_9->raise();
        tabWidget->addTab(FORNISSEUR, QString());
        label = new QLabel(gestion_produit_fournisseur);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 1001, 641));
        label->setStyleSheet(QStringLiteral("background-image: url(:/img/rs/Macarons.jpg);"));
        horizontalSlider = new QSlider(gestion_produit_fournisseur);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(610, 10, 171, 31));
        horizontalSlider->setAutoFillBackground(false);
        horizontalSlider->setStyleSheet(QStringLiteral(""));
        horizontalSlider->setMaximum(100);
        horizontalSlider->setValue(100);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setInvertedAppearance(false);
        horizontalSlider->setInvertedControls(false);
        horizontalSlider->setTickPosition(QSlider::TicksBothSides);
        start = new QToolButton(gestion_produit_fournisseur);
        start->setObjectName(QStringLiteral("start"));
        start->setGeometry(QRect(890, 0, 71, 61));
        start->setStyleSheet(QLatin1String("font: 18pt \"MS Shell Dlg 2\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(170, 0, 0);\n"
"border-radius: 30px;"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/img/rs/on.png"), QSize(), QIcon::Normal, QIcon::Off);
        start->setIcon(icon5);
        start->setIconSize(QSize(30, 30));
        start->setAutoRaise(true);
        stop = new QToolButton(gestion_produit_fournisseur);
        stop->setObjectName(QStringLiteral("stop"));
        stop->setGeometry(QRect(810, 0, 71, 61));
        stop->setStyleSheet(QLatin1String("font: 18pt \"MS Shell Dlg 2\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(170, 0, 0);\n"
"border-radius: 30px;"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/img/rs/off.png"), QSize(), QIcon::Normal, QIcon::Off);
        stop->setIcon(icon6);
        stop->setIconSize(QSize(30, 30));
        stop->setAutoRaise(false);
        label->raise();
        tabWidget->raise();
        horizontalSlider->raise();
        start->raise();
        stop->raise();
#ifndef QT_NO_SHORTCUT
        label_errorCor->setBuddy(comboBox_errorlvl);
        label_color->setBuddy(comboBox_color);
        label_borderSize->setBuddy(spinBox_borderSize);
        label_text->setBuddy(userTextInput);
#endif // QT_NO_SHORTCUT

        retranslateUi(gestion_produit_fournisseur);

        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(5);
        generateButton->setDefault(true);
        tabWidget_3->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(gestion_produit_fournisseur);
    } // setupUi

    void retranslateUi(QDialog *gestion_produit_fournisseur)
    {
        gestion_produit_fournisseur->setWindowTitle(QApplication::translate("gestion_produit_fournisseur", "gestion_produit_fournisseur", Q_NULLPTR));
        ajout->setText(QApplication::translate("gestion_produit_fournisseur", "Appuyez ici pour ajouter ", Q_NULLPTR));
        label_4->setText(QApplication::translate("gestion_produit_fournisseur", "Stock :", Q_NULLPTR));
        label_2->setText(QApplication::translate("gestion_produit_fournisseur", "Reference :", Q_NULLPTR));
        label_14->setText(QApplication::translate("gestion_produit_fournisseur", "Fournisseur :", Q_NULLPTR));
        label_5->setText(QApplication::translate("gestion_produit_fournisseur", "Prix :", Q_NULLPTR));
        label_3->setText(QApplication::translate("gestion_produit_fournisseur", "Nom :", Q_NULLPTR));
        label_6->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(AJOuter), QApplication::translate("gestion_produit_fournisseur", "Ajouter", Q_NULLPTR));
        label_7->setText(QString());
        label_9->setText(QApplication::translate("gestion_produit_fournisseur", "Prix :", Q_NULLPTR));
        label_8->setText(QApplication::translate("gestion_produit_fournisseur", "Stock :", Q_NULLPTR));
        modif->setText(QApplication::translate("gestion_produit_fournisseur", "Modifier", Q_NULLPTR));
        label_10->setText(QApplication::translate("gestion_produit_fournisseur", "Nom :", Q_NULLPTR));
        label_11->setText(QApplication::translate("gestion_produit_fournisseur", "Reference :", Q_NULLPTR));
        label_15->setText(QApplication::translate("gestion_produit_fournisseur", "Fournisseur :", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_2), QApplication::translate("gestion_produit_fournisseur", "Modifier", Q_NULLPTR));
        label_13->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("gestion_produit_fournisseur", "Supprimer", Q_NULLPTR));
        label_12->setText(QString());
        groupBox_2->setTitle(QString());
        pushButton_2->setText(QApplication::translate("gestion_produit_fournisseur", "envoyer un mail", Q_NULLPTR));
        cherchep->setText(QApplication::translate("gestion_produit_fournisseur", "Chercher", Q_NULLPTR));
        cherchp->setInputMask(QString());
        cherchp->setText(QApplication::translate("gestion_produit_fournisseur", "tapez i\303\247i", Q_NULLPTR));
        trie->setText(QApplication::translate("gestion_produit_fournisseur", "Tri", Q_NULLPTR));
        pushButton->setText(QApplication::translate("gestion_produit_fournisseur", "PDF", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("gestion_produit_fournisseur", "Afficher", Q_NULLPTR));
        label_18->setText(QString());
        groupBox_3->setTitle(QString());
        label_25->setText(QApplication::translate("gestion_produit_fournisseur", "<html><head/><body><p><span style=\" font-size:11pt;\">Smtp-server :</span></p></body></html>", Q_NULLPTR));
        server->setText(QApplication::translate("gestion_produit_fournisseur", "smtp.gmail.com", Q_NULLPTR));
        port->setText(QApplication::translate("gestion_produit_fournisseur", "465", Q_NULLPTR));
        label_28->setText(QApplication::translate("gestion_produit_fournisseur", "<html><head/><body><p><span style=\" font-size:11pt;\">Smtp-port :</span></p></body></html>", Q_NULLPTR));
        uname->setText(QApplication::translate("gestion_produit_fournisseur", "epastry2020@gmail.com", Q_NULLPTR));
        label_29->setText(QApplication::translate("gestion_produit_fournisseur", "<html><head/><body><p><span style=\" font-size:11pt;\">mon Email :</span></p></body></html>", Q_NULLPTR));
        paswd->setText(QApplication::translate("gestion_produit_fournisseur", "college159", Q_NULLPTR));
        label_30->setText(QApplication::translate("gestion_produit_fournisseur", "mot de passe :", Q_NULLPTR));
        label_31->setText(QApplication::translate("gestion_produit_fournisseur", "Email fournisseur :", Q_NULLPTR));
        label_32->setText(QApplication::translate("gestion_produit_fournisseur", "Sujet :", Q_NULLPTR));
        label_33->setText(QApplication::translate("gestion_produit_fournisseur", "Image ou fichier :", Q_NULLPTR));
        browseBtn->setText(QApplication::translate("gestion_produit_fournisseur", "Image", Q_NULLPTR));
        label_34->setText(QApplication::translate("gestion_produit_fournisseur", "<html><head/><body><p><span style=\" font-size:11pt;\">Message :</span></p></body></html>", Q_NULLPTR));
        sendBtn->setText(QApplication::translate("gestion_produit_fournisseur", "envoyer", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_8), QApplication::translate("gestion_produit_fournisseur", "Mailing", Q_NULLPTR));
        label_16->setText(QString());
        comboBox_color->clear();
        comboBox_color->insertItems(0, QStringList()
         << QApplication::translate("gestion_produit_fournisseur", "Black (Default)", Q_NULLPTR)
         << QApplication::translate("gestion_produit_fournisseur", "Red", Q_NULLPTR)
         << QApplication::translate("gestion_produit_fournisseur", "Pink", Q_NULLPTR)
         << QApplication::translate("gestion_produit_fournisseur", "Purple", Q_NULLPTR)
         << QApplication::translate("gestion_produit_fournisseur", "Deep Purple", Q_NULLPTR)
         << QApplication::translate("gestion_produit_fournisseur", "Indigo", Q_NULLPTR)
         << QApplication::translate("gestion_produit_fournisseur", "Blue", Q_NULLPTR)
         << QApplication::translate("gestion_produit_fournisseur", "Cyan", Q_NULLPTR)
         << QApplication::translate("gestion_produit_fournisseur", "Teal", Q_NULLPTR)
         << QApplication::translate("gestion_produit_fournisseur", "Green", Q_NULLPTR)
         << QApplication::translate("gestion_produit_fournisseur", "Orange", Q_NULLPTR)
         << QApplication::translate("gestion_produit_fournisseur", "Deep Orange", Q_NULLPTR)
         << QApplication::translate("gestion_produit_fournisseur", "Brown", Q_NULLPTR)
         << QApplication::translate("gestion_produit_fournisseur", "Grey", Q_NULLPTR)
        );
        label_errorCor->setText(QApplication::translate("gestion_produit_fournisseur", "Error Correction:", Q_NULLPTR));
        comboBox_errorlvl->clear();
        comboBox_errorlvl->insertItems(0, QStringList()
         << QApplication::translate("gestion_produit_fournisseur", "Low (Default)", Q_NULLPTR)
        );
        label_color->setText(QApplication::translate("gestion_produit_fournisseur", "Color:", Q_NULLPTR));
        label_borderSize->setText(QApplication::translate("gestion_produit_fournisseur", "Border Size:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        generateButton->setToolTip(QApplication::translate("gestion_produit_fournisseur", "Generate Button", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        generateButton->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        generateButton->setText(QApplication::translate("gestion_produit_fournisseur", "Generate", Q_NULLPTR));
        label_saveto->setText(QApplication::translate("gestion_produit_fournisseur", "Save to:", Q_NULLPTR));
        browseButton->setText(QApplication::translate("gestion_produit_fournisseur", "Browse...", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("gestion_produit_fournisseur", "ouvrir", Q_NULLPTR));
        exitButton->setText(QApplication::translate("gestion_produit_fournisseur", "Exit", Q_NULLPTR));
        label_text->setText(QApplication::translate("gestion_produit_fournisseur", "Text:", Q_NULLPTR));
        pasteButton->setText(QApplication::translate("gestion_produit_fournisseur", "Paste", Q_NULLPTR));
        clearButton->setText(QApplication::translate("gestion_produit_fournisseur", "Clear", Q_NULLPTR));
        userTextInput->setPlainText(QString());
        userTextInput->setPlaceholderText(QApplication::translate("gestion_produit_fournisseur", "Enter your text to be put into the QR Code...", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab), QApplication::translate("gestion_produit_fournisseur", "Gene Qrcode", Q_NULLPTR));
        label_17->setText(QString());
        label_36->setText(QString());
        update_arduino->setText(QApplication::translate("gestion_produit_fournisseur", "<html><head/><body><p><span style=\" color:#ffffff;\"><br/></span></p></body></html>", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_7), QApplication::translate("gestion_produit_fournisseur", "Aff Qrcode", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(PRODUIT), QApplication::translate("gestion_produit_fournisseur", "PRODUIT", Q_NULLPTR));
        ajoutf->setText(QApplication::translate("gestion_produit_fournisseur", "Appuyez ici pour ajouter ", Q_NULLPTR));
        label_26->setText(QApplication::translate("gestion_produit_fournisseur", "<html><head/><body><p><span style=\" font-size:24pt;\">Email :</span></p></body></html>", Q_NULLPTR));
        label_19->setText(QApplication::translate("gestion_produit_fournisseur", "<html><head/><body><p><span style=\" font-size:24pt;\">Matricule :</span></p></body></html>", Q_NULLPTR));
        label_20->setText(QApplication::translate("gestion_produit_fournisseur", "<html><head/><body><p><span style=\" font-size:24pt;\">Nom :</span></p></body></html>", Q_NULLPTR));
        label_27->setText(QApplication::translate("gestion_produit_fournisseur", "<html><head/><body><p><span style=\" font-size:24pt;\">n\302\260tel :</span></p></body></html>", Q_NULLPTR));
        label_21->setText(QApplication::translate("gestion_produit_fournisseur", "<html><head/><body><p><span style=\" font-size:24pt;\">Adresse :</span></p></body></html>", Q_NULLPTR));
        label_22->setText(QString());
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_5), QApplication::translate("gestion_produit_fournisseur", "Ajouter", Q_NULLPTR));
        label_23->setText(QString());
        pushButton_3->setText(QApplication::translate("gestion_produit_fournisseur", "Tri", Q_NULLPTR));
        rech->setText(QApplication::translate("gestion_produit_fournisseur", "Recherche", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("gestion_produit_fournisseur", "PDF", Q_NULLPTR));
        groupBox->setTitle(QString());
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_6), QApplication::translate("gestion_produit_fournisseur", "Afficher", Q_NULLPTR));
        label_35->setText(QApplication::translate("gestion_produit_fournisseur", "E_MAIL : ", Q_NULLPTR));
        label_37->setText(QApplication::translate("gestion_produit_fournisseur", "NUMERO : ", Q_NULLPTR));
        pushButton_modf->setText(QApplication::translate("gestion_produit_fournisseur", "Modifier", Q_NULLPTR));
        label_38->setText(QApplication::translate("gestion_produit_fournisseur", "NOM : ", Q_NULLPTR));
        label_39->setText(QApplication::translate("gestion_produit_fournisseur", "MATRICULE : ", Q_NULLPTR));
        label_40->setText(QApplication::translate("gestion_produit_fournisseur", "ADRESSE : ", Q_NULLPTR));
        label_41->setText(QString());
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_9), QApplication::translate("gestion_produit_fournisseur", "Modifier", Q_NULLPTR));
        label_24->setText(QString());
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_10), QApplication::translate("gestion_produit_fournisseur", "Supprimer", Q_NULLPTR));
        toolButton_6->setText(QApplication::translate("gestion_produit_fournisseur", "STATISTIQUE", Q_NULLPTR));
        toolButton_9->setText(QApplication::translate("gestion_produit_fournisseur", "BOITE-MAIL", Q_NULLPTR));
        label_42->setText(QString());
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_11), QApplication::translate("gestion_produit_fournisseur", "Autre fonctionnalit\303\251s", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(FORNISSEUR), QApplication::translate("gestion_produit_fournisseur", "FORNISSEUR", Q_NULLPTR));
        label->setText(QApplication::translate("gestion_produit_fournisseur", "TextLabel", Q_NULLPTR));
        start->setText(QApplication::translate("gestion_produit_fournisseur", "start", Q_NULLPTR));
        stop->setText(QApplication::translate("gestion_produit_fournisseur", "stop", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class gestion_produit_fournisseur: public Ui_gestion_produit_fournisseur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTION_PRODUIT_FOURNISSEUR_H
