#include "vol.h"
#include <QString>

vol::vol()
{

}
vol::vol(QString id,float prix,QString depart ,QString destination,int nb_place,float duree,QDate date,int etat)
{
    this->id=id;
    this->prix=prix;

    this->destination=destination;
    this->nb_place=nb_place;
    this->duree=duree;
    this->depart=depart;
    this->date=date;
    this->etat=etat;



}
bool vol::ajouter_vol()
{
QSqlQuery query;
QString res1= QString::number(duree);
QString res2= QString::number(nb_place);

query.prepare("INSERT INTO vols (id, DESTINATION,DUREE,NB_PLACE,DEPART,DATEHEUR) "
                    "VALUES (:id, :destination, :DUREE, :NB_PLACE, :DEPART, :DATEHEUR)");
query.bindValue(":id",id);
query.bindValue(":destination", destination);
query.bindValue(":DEPART", depart);
query.bindValue(":DUREE", res1);
query.bindValue(":NB_PLACE", res2);
query.bindValue(":DATEHEUR",date);

return    query.exec();
}
QSqlQueryModel * vol::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from vols ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nb_place"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("duree"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("taux"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("destination"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("etat"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("depart"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("dateheur"));




    return model;
}
bool vol::supprimer(QString idd)
{
QSqlQuery query;
//QString res= QString::number(idd);
query.prepare("Delete from vols where ID = :id ");
query.bindValue(":id", idd);
return    query.exec();
}



/////////////////////
QSqlQueryModel * vol::afficher2(QString idd)
{
 QSqlQueryModel * model= new QSqlQueryModel();
QSqlQuery query;
//model->setQuery("select  *from vols where ID=:id");
query.prepare("select *from vols where ID = :id ");
query.bindValue(":id", idd);
query.exec();

model->setQuery(query);


model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nb_place"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("destination"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("dateheur"));
    return model;
    
    
}
bool vol::modifier(QString)
{

    QSqlQuery query;
    QString res1= QString::number(duree);
    QString res2= QString::number(nb_place);
    query.prepare("UPDATE vols set nb_place=:nb_place,duree=:duree,destination=:destination,depart=:depart,dateheur=:dateheur where ID=:id");
    query.bindValue(":id", id);
 query.bindValue(":destination", destination);
   query.bindValue(":duree", res1);

   // query.bindValue(":etat", etat);
    query.bindValue(":depart", depart);
    query.bindValue(":dateheur", date);

     query.bindValue(":nb_place", res2);
    return query.exec();
}
bool vol::modifier2(QString)
{
    QSqlQuery query;
    query.prepare("UPDATE vols set etat=:etat where ID=:id");
    query.bindValue(":id", id);
    query.bindValue(":etat",1);
    return query.exec();
}


