QT       += core gui sql multimedia charts multimediawidgets printsupport serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    BitBuffer.cpp \
    QrCode.cpp \
    QrSegment.cpp \
    arduino.cpp \
    connection.cpp \
    fournisseur.cpp \
    main.cpp \
    gestion_produit_fournisseur.cpp \
    produit.cpp \
    smtphakim.cpp \
    stat_fournisseur.cpp

HEADERS += \
    BitBuffer.hpp \
    QrCode.hpp \
    QrSegment.hpp \
    arduino.h \
    connection.h \
    fournisseur.h \
    gestion_produit_fournisseur.h \
    produit.h \
    smtphakim.h \
    stat_fournisseur.h

FORMS += \
    gestion_produit_fournisseur.ui \
    stat_fournisseur.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    rs.qrc
