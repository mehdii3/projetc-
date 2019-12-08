#include "avion.h"

#include <QDebug>
Avion::Avion()
{
Reference="";
type="";
etat_reservoir="";
etat="";
nbr_passagers=0;
distance_franchissable=0;
vitesse_croisiere=0;
}
Avion:: Avion(QString Reference,QString type,QString etat,QString etat_reservoir,QDate date_premiere_sortie,int nbr_passagers,int distance_franchissable,int vitesse_croisiere)
{
    this->Reference=Reference;
    this->type=type;
    this->etat=etat;
    this->etat_reservoir=etat_reservoir;
    this->date_premiere_sortie=date_premiere_sortie;
    this->nbr_passagers=nbr_passagers;
    this->distance_franchissable=distance_franchissable;
    this->vitesse_croisiere=vitesse_croisiere;
}
QString Avion::get_Reference(){return  Reference;}
QString Avion::get_type(){return type;}
QString Avion::get_etat(){return etat;}
QString Avion::get_etat_reservoir(){return  etat_reservoir;}
QDate Avion::get_date_premiere_sortie(){return  date_premiere_sortie;}
int Avion::get_nbr_passagers(){return  nbr_passagers;}
int Avion::get_distance_franchissable(){return  distance_franchissable;}
int Avion::get_vitesse_croisiere(){return  vitesse_croisiere;}


bool Avion::ajouter()
{
QSqlQuery query;
QString res = QString::number(nbr_passagers);
QString res1 = QString::number(distance_franchissable);
QString res2 = QString::number(vitesse_croisiere);
query.prepare("INSERT INTO avion (reference,type,etat,etat_reservoir,date_premiere_sortie,nbr_passagers,distance_franchissable,vitesse_croisiere) "
                    "VALUES (:r,:t,:e,:er,:dps,:np,:df,:vc)");
query.bindValue(":r", Reference);
query.bindValue(":t", type);
query.bindValue(":e", etat);
query.bindValue(":er", etat_reservoir );
query.bindValue(":dps", date_premiere_sortie);
query.bindValue(":np", res);
query.bindValue(":df", res1);
query.bindValue(":vc", res2);


return    query.exec();
}

QSqlQueryModel * Avion::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from avion");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERENCE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ETAT"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("RESERVOIR"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("NBR"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("DISTANCE"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("VITESSE"));
    return model;
}

bool Avion::supprimer(QString idd)
{
QSqlQuery query;

query.prepare("Delete from avion where reference = :r ");
query.bindValue(":r", idd);
return    query.exec();
}

bool Avion::modifier()
{
    QSqlQuery query;
    QString res = QString::number(nbr_passagers);
    QString res1 = QString::number(distance_franchissable);
    QString res2 = QString::number(vitesse_croisiere);

    query.prepare("Update avion set Reference=:r,TYPE=:t ,ETAT=:e ,ETAT_RESERVOIR=:er ,DATE_PREMIERE_SORTIE=:dps ,NBR_PASSAGERS=:np,DISTANCE_FRANCHISSABLE=:df,VITESSE_CROISIERE=:vc where REFERENCE=:r");
    query.bindValue(":r", Reference);
    query.bindValue(":t", type);
    query.bindValue(":e", etat);
    query.bindValue(":er", etat_reservoir );
    query.bindValue(":dps", date_premiere_sortie);
    query.bindValue(":np", res);
    query.bindValue(":df", res1);
    query.bindValue(":vc", res2);
     query.exec();
     if (query.next())
           return (1);
         else
             return(0);
}


QSqlQueryModel * Avion::Tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select REFERENCE,TYPE,ETAT,ETAT_RESERVOIR,DATE_PREMIERE_SORTIE,NBR_PASSAGERS,DISTANCE_FRANCHISSABLE,VITESSE_CROISIERE from avion order by REFERENCE desc");

    query.exec();
    model->setQuery(query);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERENCE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ETAT"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("RESERVOIR"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("NBR"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("DISTANCE"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("VITESSE"));
        return model;

}
QSqlQueryModel* Avion ::recherche(QString reference)
{
    QSqlQueryModel * model= new QSqlQueryModel();
   QSqlQuery query;
   //model->setQuery("select  *from avion where REFERENCE=:reference");
   query.prepare("select *from avion where REFERENCE =:reference ");
   query.bindValue(":reference", reference);
   query.exec();

   model->setQuery(query);


   model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERENCE"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("ETAT"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("RESERVOIR"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("NBR"));
   model->setHeaderData(6, Qt::Horizontal, QObject::tr("DISTANCE"));
   model->setHeaderData(7, Qt::Horizontal, QObject::tr("VITESSE"));
       return model;
}







