#include "personnel.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtDebug>

personnel::personnel()
{

}

bool personnel::update(QString id, QString nom , QString prenom, QDate date_naissance)
{
    QSqlQuery q;
    q.prepare("UPDATE PERSONNEL SET NOM=:nom ,PRENOM=:prenom,DATE_NAISSANCE=:date_naissance  WHERE ID=:id");
    q.bindValue(":id",id);
    q.bindValue(":nom",nom);
     q.bindValue(":prenom",prenom);
      q.bindValue(":date_naissance",date_naissance);
      return(q.exec());
}

bool personnel::Delete(QString id)
{QSqlQuery q;
    q.prepare("DELETE FROM PERSONNEL WHERE ID=:id");
    q.bindValue(":id",id);
    return(q.exec());

}



bool personnel::create(QString id, QString nom , QString prenom, QString E_mail, int telephone, QDate date_naissance, QString sexe, QString mot_de_passe , QString type)
{
    QSqlQuery q;
    q.prepare("INSERT INTO PERSONNEL VALUES(:id,:nom,:prenom,:E_mail,:telephone,:date_naissance,:sexe,:mot_de_passe,:type,'')");
    q.bindValue(":id",id);
    q.bindValue(":nom",nom);
    q.bindValue(":prenom",prenom);
    q.bindValue(":E_mail",E_mail);
    q.bindValue(":telephone",telephone);
    q.bindValue(":date_naissance",date_naissance);
    q.bindValue(":sexe",sexe);
    q.bindValue(":mot_de_passe",mot_de_passe);
    q.bindValue(":type",type);


    return(q.exec());
}
QSqlQueryModel *personnel::Read()
{
    QSqlQueryModel* Model=new QSqlQueryModel;
    Model->setQuery("SELECT * FROM PERSONNEL");
    Model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    Model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    Model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    Model->setHeaderData(3,Qt::Horizontal,QObject::tr("E_mail"));
    Model->setHeaderData(4,Qt::Horizontal,QObject::tr("tlp"));
    Model->setHeaderData(5,Qt::Horizontal,QObject::tr("date_naissance"));
    Model->setHeaderData(6,Qt::Horizontal,QObject::tr("sexe"));
     Model->setHeaderData(7,Qt::Horizontal,QObject::tr("type"));
    return Model;
}


QSqlQueryModel *personnel::Read1(QString ID)
{
    QSqlQueryModel* Model=new QSqlQueryModel;
    Model->setQuery("SELECT * from PERSONNEL WHERE ID LIKE '%"+ID+"%'");
    Model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    Model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    Model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    Model->setHeaderData(3,Qt::Horizontal,QObject::tr("E_mail"));
    Model->setHeaderData(4,Qt::Horizontal,QObject::tr("tlp"));
    Model->setHeaderData(5,Qt::Horizontal,QObject::tr("date_naissance"));
    Model->setHeaderData(6,Qt::Horizontal,QObject::tr("sexe"));
     Model->setHeaderData(7,Qt::Horizontal,QObject::tr("type"));
     return Model;
}

QSqlQueryModel *personnel::Sort()
{
    QSqlQueryModel* Model=new QSqlQueryModel;
    Model->setQuery("SELECT * FROM PERSONNEL ORDER BY DATE_SYS ");
    Model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    Model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    Model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    Model->setHeaderData(3,Qt::Horizontal,QObject::tr("E_mail"));
    Model->setHeaderData(4,Qt::Horizontal,QObject::tr("tlp"));
    Model->setHeaderData(5,Qt::Horizontal,QObject::tr("date_naissance"));
    Model->setHeaderData(6,Qt::Horizontal,QObject::tr("sexe"));
     Model->setHeaderData(7,Qt::Horizontal,QObject::tr("type"));
     return Model;
}

QSqlQueryModel *personnel::Sort1(QString ID)
{
    QSqlQueryModel* Model=new QSqlQueryModel;
    Model->setQuery("SELECT * from PERSONNEL WHERE ID LIKE '%"+ID+"%' ORDER BY DATE_SYS");
    Model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    Model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    Model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    Model->setHeaderData(3,Qt::Horizontal,QObject::tr("E_mail"));
    Model->setHeaderData(4,Qt::Horizontal,QObject::tr("tlp"));
    Model->setHeaderData(5,Qt::Horizontal,QObject::tr("date_naissance"));
    Model->setHeaderData(6,Qt::Horizontal,QObject::tr("sexe"));
     Model->setHeaderData(7,Qt::Horizontal,QObject::tr("type"));
     return Model;
}




