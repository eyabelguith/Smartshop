
QT       += core gui sql charts
QT       += core gui multimedia multimediawidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
QT += printsupport
 QT +=network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Atelier_Connexion
TEMPLATE = app

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CL.cpp \
    commande.cpp \
    connexion.cpp \
    livraison.cpp \
    mailCl.cpp \
    main.cpp \
    mainwindow.cpp \
    statCm.cpp

HEADERS += \
    CL.h \
    commande.h \
    connexion.h \
    livraison.h \
    mailCl.h \
    mainwindow.h \
    statCm.h

FORMS += \
    CL.ui \
    mainwindow.ui \
    statCm.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
