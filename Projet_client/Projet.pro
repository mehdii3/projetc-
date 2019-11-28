QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ajouter_client.cpp \
    client.cpp \
    connexion.cpp \
    dialog.cpp \
    fidel.cpp \
    gestion_client.cpp \
    mail.cpp \
    main.cpp \
    mainwindow.cpp \
    reclamation.cpp \
    smtp.cpp \
    statistique.cpp

HEADERS += \
    ajouter_client.h \
    client.h \
    connexion.h \
    dialog.h \
    fidel.h \
    gestion_client.h \
    mail.h \
    mainwindow.h \
    reclamation.h \
    smtp.h \
    statistique.h

FORMS += \
    ajouter_client.ui \
    dialog.ui \
    fidel.ui \
    gestion_client.ui \
    mail.ui \
    mainwindow.ui \
    reclamation.ui \
    statistique.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ../build-Projet-Desktop_Qt_5_9_1_MinGW_32bit-Debug/Photos.qrc \
    resources/ressources.qrc
QT+= sql
CONFIG += console

DISTFILES += \
    resources/fidel.png \
    resources/reclamation bg.png

QT += network
