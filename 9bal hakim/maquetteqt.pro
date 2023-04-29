

QT       += core gui sql charts printsupport
QT       += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia multimediawidgets

CONFIG += c++11
QT +=network
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CL.cpp \
    arduino.cpp \
    cadeau.cpp \
    categories.cpp \
    chat.cpp \
    client.cpp \
    clients_cadeaux.cpp \
    commande.cpp \
    conges.cpp \
    connexion.cpp \
    employes.cpp \
    excel.cpp \
    gesempcong.cpp \
    gestion.cpp \
    gestion_categories_reclamations.cpp \
    gestion_materiaux_maintenances.cpp \
    jeu.cpp \
    livraison.cpp \
    mail.cpp \
    mailCl.cpp \
    main.cpp \
    maintenanceetat.cpp \
    maintenances.cpp \
    mainwindow.cpp \
    materiaux.cpp \
    projeth.cpp \
    reclamationbar.cpp \
    reclamations.cpp \
    securite.cpp \
    server.cpp \
    smtp.cpp \
    sslserver.cpp \
    stat.cpp \
    statCm.cpp \
    statemp.cpp \
    statistique.cpp \
    statistiquereclamations.cpp\
    stat_fournisseur.cpp \
      produit.cpp \
    fournisseur.cpp \
    QrCode.cpp \
        QrSegment.cpp \
     gestion_produit_fournisseur.cpp \
     smtphakim.cpp \
     BitBuffer.cpp\
     traiterimage.cpp


HEADERS += \
    CL.h \
    arduino.h \
    cadeau.h \
    categories.h \
    chat.h \
    client.h \
    clients_cadeaux.h \
    commande.h \
    conges.h \
    connexion.h \
    employes.h \
    excel.h \
    gesempcong.h \
    gestion.h \
    gestion_categories_reclamations.h \
    gestion_materiaux_maintenances.h \
    jeu.h \
    livraison.h \
    mail.h \
    mailCl.h \
    maintenanceetat.h \
    maintenances.h \
    mainwindow.h \
    materiaux.h \
    projeth.h \
    reclamationbar.h \
    reclamations.h \
    securite.h \
    server.h \
    smtp.h \
    sslserver.h \
    stat.h \
    statCm.h \
    statemp.h \
    statistique.h \
    statistiquereclamations.h\
    smtphakim.h \
     stat_fournisseur.h \
   produit.h \
    fournisseur.h \
   gestion_produit_fournisseur.h \
   QrCode.hpp \
       QrSegment.hpp \
       BitBuffer.hpp\
       traiterimage.h

FORMS += \
    CL.ui \
    chat.ui \
    clients_cadeaux.ui \
    gesempcong.ui \
    gestion.ui \
    gestion_categories_reclamations.ui \
    gestion_materiaux_maintenances.ui \
    maintenanceetat.ui \
    mainwindow.ui \
    reclamationbar.ui \
    securite.ui \
    server.ui \
    stat.ui \
    statCm.ui \
    statemp.ui \
    statistiquereclamations.ui\
    gestion_produit_fournisseur.ui \
       stat_fournisseur.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    commande_livraison.pro.user \
    commande_livraison.pro.user.044f71f \
    maquetteqt.pro.user \
    maquetteqt.pro.user.3203d7d \
    maquetteqt.pro.user.576aff2

SUBDIRS += \
    commande_livraison.pro \
    commande_livraison.pro

RESOURCES += \
    rs.qrc \
    rs.qrc \
    rs.qrc
