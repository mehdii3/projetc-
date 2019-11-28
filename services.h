#ifndef SERVICES_H
#define SERVICES_H
#include "QString"
#include<QSqlQueryModel>

class services
{
public:
 services();
    bool create (QString ,QString,QString);

        bool update (QString,QString,QString );

        bool Delete (QString) ;

        QSqlQueryModel* Read();
};

#endif // SERVICES_H
