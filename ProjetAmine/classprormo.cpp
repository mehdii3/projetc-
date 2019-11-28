#include "classprormo.h"

classprormo::classprormo()
{

}
classprormo::classprormo(QString id,QDate datedebut,QDate datefin,float taux)
{
    this->id=id;
    this->datedebut=datedebut;
    this->datefin=datefin;
    this->taux=taux;
}
bool classprormo::ajouter_promo()
{
QString res1= QString::number(taux);
    QSqlQuery query;
    query.prepare("INSERT INTO promotions (ID, DATEDEBUT,DATEFIN,TAUX) "
                        "VALUES (:id, :datedebut, :datefin, :taux)");
    query.bindValue(":id",id);
    query.bindValue(":datedebut", datedebut);
    query.bindValue(":datefin", datefin);
    query.bindValue(":taux",res1);


    return    query.exec();
}
QSqlQueryModel * classprormo::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from promotions ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("datedebut"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("datefun"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("taux"));
        return model;

}
QSqlQueryModel* classprormo::recherche(QString id)
{
    QSqlQueryModel * model= new QSqlQueryModel();
   QSqlQuery query;
   //model->setQuery("select  *from vols where ID=:id");
   query.prepare("select *from promotions where ID = :id ");
   query.bindValue(":id", id);
   query.exec();

   model->setQuery(query);


   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("datedebut"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("datefin"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("taux"));
       return model;

}
bool classprormo::modifier(QString id)
{
    QSqlQuery query;
    query.prepare("UPDATE promotions  set ID=:id,datedebut=:datedebut,datefin=:datefin,taux=:taux where ID=:id");
    query.bindValue(":ID", id);
 query.bindValue(":datedebut", datedebut);
   query.bindValue(":datefin", datefin);

   // query.bindValue(":etat", etat);
    query.bindValue(":taux", taux);
   /* query.bindValue(":dateheur", date);

     query.bindValue(":nb_place", res2);*/
    return query.exec();
}
bool classprormo::supprimer(QString idd)
{QSqlQuery query;
    //QString res= QString::number(idd);
    query.prepare("Delete from promotions where ID = :id ");
    query.bindValue(":id", idd);
    return    query.exec();}
