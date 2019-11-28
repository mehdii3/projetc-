#include "ajoutavion.h"
#include "ui_ajoutavion.h"
#include "avion.h"
#include <QMessageBox>

AjoutAvion::AjoutAvion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjoutAvion)
{
    ui->setupUi(this);
}

AjoutAvion::~AjoutAvion()
{
    delete ui;
}



void AjoutAvion::on_pushButton_clicked()
{
    QString ref = ui->ref->text();
    QString type =ui->type->text();
    QString etat_res = ui->etat_res->text();
    QString etat = ui->etat->text();
    QDate date = ui->date->date();
    int dist = ui->distance->text().toInt();
    int vit =ui->vitesse->text().toInt();
    int nbr = ui->nbr_pass->text().toInt();
    Avion a(ref,type,etat,etat_res,date,nbr,dist,vit);
    bool test=a.ajouter();
    if(test)
  {//ui->avion->setModel(tmprdv.afficher());//refresh
  QMessageBox::information(nullptr, QObject::tr("Ajouter un Avion"),
                    QObject::tr("Avion ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un rendez vous"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}


