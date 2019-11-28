#include "widget.h"
#include <QApplication>
#include<connection.h>
#include<QtDebug>
#include"sos.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connection c;
    if(c.createconnect())
        qDebug()<<"database connected";
    sos s;
    s.show();


    //Widget w;
   // w.show();

    return a.exec();
}
