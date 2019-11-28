#include "modifieravion.h"
#include "ui_modifieravion.h"
#include "avion.h"
#include <QMessageBox>

ModifierAvion::ModifierAvion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifierAvion)
{
    ui->setupUi(this);
}

ModifierAvion::~ModifierAvion()
{
    delete ui;
}




void ModifierAvion::on_pushButton_clicked()
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
    bool test=a.modifier();
    if(test)
  {//ui->avion->setModel(tmprdv.afficher());//refresh
  QMessageBox::information(nullptr, QObject::tr("Modifier un Avion"),
                    QObject::tr("Avion Modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier un Avion"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}


