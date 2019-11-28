#include "mainwindow.h"
#include "dialog.h"
#include <QMessageBox>
#include "connexion.h"
#include <QtDebug>
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    Connexion c;
    try {
       bool t= c.ouvrirConnexion();
        qDebug()<<"hhhhhh"<<t;
        w.show();

    } catch (QString s) {
        qDebug()<<s;

    }



w.show();

    return a.exec();
}
