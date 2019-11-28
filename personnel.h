#ifndef PERSONNEL_H
#define PERSONNEL_H
#include "QDate"
#include "QString"
#include<QSqlQueryModel>


class personnel
{
public:
    personnel();
    bool create (QString,QString,QString,QString,int,QDate,QString,QString,QString);

        bool update (QString,QString ,QString ,QDate );

        bool Delete (QString);

        QSqlQueryModel* Read();
        QSqlQueryModel *Read1(QString ID);
        QSqlQueryModel* Sort();
        QSqlQueryModel* Sort1(QString ID);



};

#endif // PERSONNEL_H
