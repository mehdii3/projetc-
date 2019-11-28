#-------------------------------------------------
#
# Project created by QtCreator 2019-10-14T22:57:11
#
#-------------------------------------------------

QT       += core gui
QT+=sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Avion
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
    ajoutavion.cpp \
    modifieravion.cpp \
    supprimeravion.cpp \
    afficheravion.cpp \
    connexion.cpp \
    avion.cpp \
    recherche.cpp \
    tri.cpp \
    ajout_dep.cpp \
    afficher_dep.cpp \
    modifier_dep.cpp \
    supprimer_dep.cpp \
    gestiondep.cpp

HEADERS += \
        mainwindow.h \
    ajoutavion.h \
    ajoutavion.h \
    modifieravion.h \
    supprimeravion.h \
    afficheravion.h \
    connexion.h \
    avion.h \
    recherche.h \
    tri.h \
    ajout_dep.h \
    afficher_dep.h \
    modifier_dep.h \
    supprimer_dep.h \
    gestiondep.h

FORMS += \
        mainwindow.ui \
    ajoutavion.ui \
    modifieravion.ui \
    supprimeravion.ui \
    afficheravion.ui \
    connexion.ui \
    recherche.ui \
    tri.ui \
    ajout_dep.ui \
    afficher_dep.ui \
    modifier_dep.ui \
    supprimer_dep.ui \
    gestiondep.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
