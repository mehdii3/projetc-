
#include "RESERVATION.h"
#include <QDebug>

reservation::reservation()
{
id=0;
nom="";
prenom="";
destination="";
date_depart="";
date_retour="";

}
reservation::reservation(int id,QString nom,QString prenom,QString date_depart,QString date_retour,QString destination)
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
     this->destination=destination;
     this->date_retour=date_retour;
     this->date_depart=date_depart;


}
QString reservation::get_nom(){return  nom;}
QString reservation::get_prenom(){return prenom;}
int reservation::get_id(){return  id;}
QString reservation::get_destination(){return destination;}
QString reservation::get_date_depart(){return date_depart;}
QString reservation::get_date_retour(){return date_retour;}


bool reservation::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO reservation (identifiant, nom, prenom,destination,date_depart,date_retour) "
                    "VALUES (:id, :nom, :prenom,:destination,:date_depart,:date_retour)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":destination", destination);
query.bindValue(":date_depart", date_depart);
query.bindValue(":date_retour", date_retour);


return    query.exec();
}

bool reservation::modifier()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("update  reservation set nom=:nom, prenom=:prenom,destination=:destination,date_depart=:date_depart,date_retour=:date_retour where IDENTIFIANT = :id"
                   );
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":destination", destination);
query.bindValue(":date_depart", date_depart);
query.bindValue(":date_retour", date_retour);


return    query.exec();
}
QSqlQueryModel * reservation::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from reservation");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDENTIFIANT"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_depart"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("date_retour"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("destination"));

    return model;
}

QSqlQueryModel * reservation::afficherParDestination(QString destination)
{QSqlQueryModel * model= new QSqlQueryModel();
QString nom =QString("%%1%").arg(destination);
model->setQuery("select * from reservation where destination like '"+nom+"' or nom like '"+nom+"' or prenom like '"+nom+"' ");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDENTIFIANT"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_depart"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("date_retour"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("destination"));

    return model;
}
bool reservation::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("delete from reservation where IDENTIFIANT = :id ");
query.bindValue(":id", res);
return    query.exec();
}
int reservation ::conteur()
{
QSqlQuery q;
QString a;
q.prepare("select count(*) from COMMANDES");
q.exec();
while(q.next())
{
    a=q.value(0).toString();
}
int n=a.toInt();
return n;
}


