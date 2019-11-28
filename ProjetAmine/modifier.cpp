#include "modifier.h"
#include "ui_modifier.h"
#include "vol.h"

modifier::modifier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifier)
{
    ui->setupUi(this);
}

modifier::~modifier()
{
    delete ui;
}

void modifier::on_pushButton_clicked()
{
    QSqlQuery query;
    QPalette *palette = new QPalette();
        palette->setColor(QPalette::Base,Qt::red);
        palette->setColor(QPalette::Text,Qt::white);
    QString id=ui->lineEdit_rechercheid->text();
    //model->setQuery("select  *from vols where ID=:id");
    query.prepare("select *from vols where ID = :id ");
    query.bindValue(":id", id);
    query.exec();
    ui->lineedit_idvol->setReadOnly(true);
    ui->lineedit_idvol->setPalette(*palette);

    if(query.exec())
    {
        while(query.next()){
        ui->lineedit_idvol->setText(query.value(0).toString());
        ui->lineEdit_nb_place->setText(query.value(1).toString());
        ui->lineEdit_duree->setText(query.value(2).toString());
        ui->dateEdit->setDate(query.value(7).toDate());
        ui->lineEdit_destination->setText(query.value(4).toString());
        ui->lineEdit_depart->setText(query.value(6).toString());

        }
    }

}

void modifier::on_pushButton_modifier_clicked()
{

    QString id=ui->lineedit_idvol->text();
    QDate date=ui->dateEdit->date();
    QString destination=ui->lineEdit_destination->text();
    QString depart=ui->lineEdit_depart->text();
    float  duree=ui->lineEdit_duree->text().toFloat();
    int nb_place=ui->lineEdit_nb_place->text().toInt();
    vol v(id,0,depart,destination,nb_place,duree,date,1);
    bool test=v.modifier(id);



}
