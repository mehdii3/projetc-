#include "services.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtDebug>
bool services::create( QString noms , QString ids, QString nombr){
      QSqlQuery q ;
    q.prepare("INSERT INTO SERVICES VALUES(:noms,:nombr,:ids,'')");
    q.bindValue(":noms",noms);
    q.bindValue(":nombr",nombr);
    q.bindValue(":id",ids);
   return(q.exec());
}
bool services::Delete(QString ids)
{QSqlQuery q;
    q.prepare("DELETE FROM SERVICE WHERE ID_S=:ids");
    q.bindValue(":ids",ids);
    return(q.exec());

}
bool services::update(QString noms, QString ids, QString nombr){
    QSqlQuery q;
    q.prepare("UPDATE SERVICES SET NOMDUSERVICE=:nom ,NBRP=:nombr  WHERE ID_S=:ids");
    q.bindValue(":ids",ids);
    q.bindValue(":NOMDUSERVICE",noms);
      q.bindValue(":nbrp",nombr);
      return(q.exec());
}
QSqlQueryModel *services::Read()
{
    QSqlQueryModel* Model=new QSqlQueryModel;
    Model->setQuery("SELECT * FROM SERVICES");
    Model->setHeaderData(0,Qt::Horizontal,QObject::tr("ids"));
    Model->setHeaderData(1,Qt::Horizontal,QObject::tr("noms"));
    Model->setHeaderData(3,Qt::Horizontal,QObject::tr("nombr"));


    return Model;
}

