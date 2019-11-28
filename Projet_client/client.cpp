#include "client.h"
#include "ajouter_client.h"
#include <QDebug>
#include<QDate>
client::client()
{

}
client::client(QString nom,QString prenom,int CIN,QString nationnalite,QDate date_naissace,QString contact,int nbvol,int identifiant,QDate date_inscription,int nbpoints)
{
    this->nom=nom;
    this->prenom = prenom;
    this->CIN=CIN;
    this->nationnalite=nationnalite;
    this->date_naissance=date_naissace;
    this->contact=contact;
    this->nbVol=nbvol;
    this->identifiant=identifiant;
    this->date_inscription=date_inscription;
    this->nbpoints=nbpoints;

}

bool client::ajouterClient()
{

    QSqlQuery query;
    QString res= QString::number(identifiant);
    QString cin= QString::number(CIN);
    QString vol= QString::number(nbVol);
    QString nb= QString::number(nbpoints);
    query.prepare("INSERT INTO client (NOM, PRENOM, CIN, NATIONNALITE, DATE_NAISSANCE, CONTACT, NBVOL, IDENTIFIANT, DATE_INSCRIPTION, NBPOINTS) "
                        "VALUES (:nom, :prenom, :cin, :nationnalite, :date_naissance, :contact, :nbvol, :identifiant, :date_inscription, :nbpoints)");
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":cin", cin);
    query.bindValue(":nationnalite", nationnalite);
    query.bindValue(":date_naissance", date_naissance);
    query.bindValue(":contact", contact);
    query.bindValue(":nbvol", vol);
    query.bindValue(":identifiant", res);
    query.bindValue(":date_inscription", date_inscription);
    query.bindValue(":nbpoints", nb);

    return    query.exec();
}

QSqlQueryModel * client::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select NOM,PRENOM,CIN,NATIONNALITE,DATE_NAISSANCE,CONTACT,NBVOL,IDENTIFIANT,DATE_INSCRIPTION,NBPOINTS from client");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("  Nom  "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("  Prenom  "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("  CIN  "));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("  Nationnalite  "));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("  Date De Naissance  "));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("  Contact  "));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("  Nombre De Vols  "));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("  Identifiant  "));
model->setHeaderData(8, Qt::Horizontal, QObject::tr("  Date D'inscription  "));
model->setHeaderData(9, Qt::Horizontal, QObject::tr("  Nombre De Points  "));
    return model;
}

bool client::supprimer(QString idd)
{
QSqlQuery query;
//QString res= QString::number(idd);
query.prepare("Delete from client where IDENTIFIANT = :id ");
query.bindValue(":id", idd);
return    query.exec();
}
QSqlQueryModel * client::afficher_id(QString idd)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select NOM,PRENOM,CIN,NATIONNALITE,DATE_NAISSANCE,CONTACT,NBVOL,IDENTIFIANT,DATE_INSCRIPTION,NBPOINTS from client where IDENTIFIANT = :id");
    query.bindValue(":id",idd);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("  Nom  "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("  Prenom  "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("  CIN  "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("  Nationnalite  "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("  Date De Naissance  "));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("  Contact  "));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("  Nombre De Vols  "));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("  Identifiant  "));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("  Date D'inscription  "));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("  Nombre De Points  "));
        return model;
}

QSqlQueryModel * client::afficher_Alph()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select NOM,PRENOM,CIN,NATIONNALITE,DATE_NAISSANCE,CONTACT,NBVOL,IDENTIFIANT,DATE_INSCRIPTION,NBPOINTS from client order by NOM");

    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("  Nom  "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("  Prenom  "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("  CIN  "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("  Nationnalite  "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("  Date De Naissance  "));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("  Contact  "));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("  Nombre De Vols  "));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("  Identifiant  "));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("  Date D'inscription  "));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("  Nombre De Points  "));
        return model;

}

QSqlQueryModel * client::afficher_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select NOM,PRENOM,CIN,NATIONNALITE,DATE_NAISSANCE,CONTACT,NBVOL,IDENTIFIANT,DATE_INSCRIPTION,NBPOINTS from client order by IDENTIFIANT desc");

    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("  Nom  "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("  Prenom  "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("  CIN  "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("  Nationnalite  "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("  Date De Naissance  "));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("  Contact  "));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("  Nombre De Vols  "));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("  Identifiant  "));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("  Date D'inscription  "));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("  Nombre De Points  "));
        return model;

}
QSqlQueryModel * client::afficher_date()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select NOM,PRENOM,CIN,NATIONNALITE,DATE_NAISSANCE,CONTACT,NBVOL,IDENTIFIANT,DATE_INSCRIPTION,NBPOINTS from client order by DATE_INSCRIPTION");

    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("  Nom  "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("  Prenom  "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("  CIN  "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("  Nationnalite  "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("  Date De Naissance  "));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("  Contact  "));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("  Nombre De Vols  "));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("  Identifiant  "));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("  Date D'inscription  "));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("  Nombre De Points  "));
        return model;

}

QSqlQueryModel * client::afficher_vol()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select NOM,PRENOM,CIN,NATIONNALITE,DATE_NAISSANCE,CONTACT,NBVOL,IDENTIFIANT,DATE_INSCRIPTION,NBPOINTS from client order by NBVOL ");

    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("  Nom  "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("  Prenom  "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("  CIN  "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("  Nationnalite  "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("  Date De Naissance  "));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("  Contact  "));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("  Nombre De Vols  "));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("  Identifiant  "));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("  Date D'inscription  "));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("  Nombre De Points  "));
        return model;

}
bool client::modifierClient(int nbvol, QString contact,int id)
{
    QSqlQuery query;
    QString res=QString::number(nbvol);
    QString res1=QString::number(id);

    query.prepare("UPDATE client SET NBVOL = :nb,CONTACT = :con WHERE IDENTIFIANT = :id");
    query.bindValue(":nb",res);
    query.bindValue(":con",contact);
    query.bindValue(":id",res1);
    query.exec();
    if (query.next())
      return (1);
    else
        return(0);
}


