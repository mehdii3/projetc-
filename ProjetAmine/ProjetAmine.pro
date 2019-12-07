#-------------------------------------------------
#
# Project created by QtCreator 2019-10-15T17:22:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = ProjetAmine
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    dialog.cpp \
    dialog2.cpp \
    ajouter_un_vol.cpp \
    afficher_vols.cpp \
    promotions.cpp \
    vol.cpp \
    connexion.cpp \
    modifier.cpp \
    classprormo.cpp \
    affecterpro.cpp \
    statistiques.cpp \
    qcustomplot.cpp

HEADERS += \
        mainwindow.h \
    dialog.h \
    dialog2.h \
    ajouter_un_vol.h \
    afficher_vols.h \
    promotions.h \
    vol.h \
    connexion.h \
    modifier.h \
    classprormo.h \
    affecterpro.h \
    statistiques.h \
    qcustomplot.h


FORMS += \
        mainwindow.ui \
    dialog.ui \
    dialog2.ui \
    ajouter_un_vol.ui \
    afficher_vols.ui \
    promotions.ui \
    modifier.ui \
    affecterpro.ui \
    statistiques.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
QT+=sql
CONFIG+=console

DISTFILES += \
    73242153_526098924907137_3442955984744480768_n.png \
    newbackground.png \
    newbackground.png \
    newbackground.png \
    newbackground.png
