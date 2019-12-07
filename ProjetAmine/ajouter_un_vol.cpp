#include "ajouter_un_vol.h"
#include "ui_ajouter_un_vol.h"



ajouter_un_vol::ajouter_un_vol(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajouter_un_vol)
{
    ui->setupUi(this);
    QDate d;
    ui->dateEdit->setDate(d.currentDate());
    QRegExp rx ("[A-Za-z]+");
    ui->lineEdit_destination->setValidator(new QRegExpValidator(rx,this));
   ui->lineEdit_depart->setValidator(new QRegExpValidator (rx,this));

}

ajouter_un_vol::~ajouter_un_vol()
{
    delete ui;
}

void ajouter_un_vol::on_pushButton_ajouter_clicked()
{
    QSqlQuery query;
    QString id=ui->lineedit_idvol->text();
    QDate date=ui->dateEdit->date();
    QString destination=ui->lineEdit_destination->text();
    QString depart=ui->lineEdit_depart->text();
    float  duree=ui->lineEdit_duree->text().toFloat();
    int nb_place=ui->lineEdit_nb_place->text().toInt();

   vol v(id,0,depart,destination,nb_place,duree,date,1);


   query.prepare("select *from vols where ID = :id ");
   query.bindValue(":id", id);
   query.exec();
   if((id!="")&&(duree>0)&&(nb_place>0)&&(depart!="")&&(destination!="")&&(!query.first())&&(v.ajouter_vol()))

{
QMessageBox::information(nullptr, QObject::tr("Ajouter un vol"),
                  QObject::tr("vol ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
   else {

         QMessageBox::critical(nullptr, QObject::tr("Ajouter un vol"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
        }

}
