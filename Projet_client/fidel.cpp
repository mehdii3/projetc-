#include "fidel.h"
#include "ui_fidel.h"
#include <QSqlQuery>

fidel::fidel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fidel)
{
    ui->setupUi(this);
     QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select NOM,PRENOM,CIN,NATIONNALITE,DATE_NAISSANCE,CONTACT,NBVOL,IDENTIFIANT,DATE_INSCRIPTION,NBVOL*10 from client where NBVOL > 5 ");

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

    ui->tableView->setModel(model);


}

fidel::~fidel()
{
    delete ui;
}
