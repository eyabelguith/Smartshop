
QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    categories.cpp \
    connexion.cpp \
    gestion.cpp \
    gestion_categories_reclamations.cpp \
    main.cpp \
    mainwindow.cpp \
    reclamations.cpp

HEADERS += \
    categories.h \
    connexion.h \
    gestion.h \
    gestion_categories_reclamations.h \
    mainwindow.h \
    reclamations.h

FORMS += \
    gestion.ui \
    gestion_categories_reclamations.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
