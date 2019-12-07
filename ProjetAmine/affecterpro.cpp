#include "affecterpro.h"
#include "ui_affecterpro.h"
#include "vol.h"
#include <QtDebug>

affecterpro::affecterpro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::affecterpro)
{
    ui->setupUi(this);
}

affecterpro::~affecterpro()
{
    delete ui;
}

void affecterpro::on_pushButton_afficherliste_clicked()
{
    vol v;
    ui->tableView->setModel(v.afficher());
}

void affecterpro::on_pushButton_affecter_clicked()
{

    QSqlQuery query_vol;
    QSqlQuery query_modif;
    QSqlQuery query_promo;
    QSqlQuery query_promo2;
    QSqlQuery query;
    QString id_vol=ui->lineEdit_affecter->text();
    QString id_promo=ui->lineEdit_idpromo->text();
    query_vol.prepare("select *from vols where ID = :id  ");
    query_vol.bindValue(":id",id_vol);

     query_vol.exec();
     query_promo.prepare("select *from promotions where ID = :id ");
     query_promo.bindValue(":id",id_promo);

     query_promo.exec();
    vol v(id_vol);
    if((query_vol.first())&&(query_promo.first()))

    {
        QString taux=query_promo.value(3).toString();
        QString idpromo=query_promo.value(0).toString();
        query_modif.prepare("UPDATE vols set taux=:taux where id=:id");
        query_modif.bindValue(":id",id_vol);
        query_modif.bindValue(":taux",taux);
        query_modif.exec();
        query.prepare("UPDATE vols set idpromo=:idpromo where id=:id");
        query.bindValue(":id",id_vol);
        query.bindValue(":idpromo",id_promo);
        query.exec();




}
}









