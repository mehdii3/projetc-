#include "supprimeravion.h"
#include "ui_supprimeravion.h"
#include "avion.h"
#include <QMessageBox>

SupprimerAvion::SupprimerAvion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SupprimerAvion)
{
    ui->setupUi(this);
}

SupprimerAvion::~SupprimerAvion()
{
    delete ui;
}

void SupprimerAvion::on_pushButton_clicked()
{
    QString a;
    a= ui->id_supp->text();
    Avion s;
    bool test = s.supprimer(a);

    if(test)
  {//ui->avion->setModel(tmprdv.afficher());//refresh
  QMessageBox::information(nullptr, QObject::tr("Supprimer un Avion"),
                    QObject::tr("Avion Supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un Avion"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
