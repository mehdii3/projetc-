#include "ajout_dep.h"
#include "ui_ajout_dep.h"
#include "ui_avion.h"
#include "avion.h"
#include<QMessageBox>

ajout_dep::ajout_dep(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajout_dep)
{
    ui->setupUi(this);
}

ajout_dep::~ajout_dep()
{
    delete ui;
}

void ajout_dep::on_pushButton_clicked()
{
        QString Ref = ui->ref->text();
        QString nom =ui->nom->text();
        int cap_max = ui->capmax->text().toInt();
        depot d(Ref,nom,cap_max);
        bool test=d.ajouter_dep();
        if(test)
      {//ui->avion->setModel(tmprdv.afficher());//refresh
      QMessageBox::information(nullptr, QObject::tr("Ajouter un Dépot"),
                        QObject::tr("Dépot ajouté.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

      }
        else
            QMessageBox::critical(nullptr, QObject::tr("Ajouter un Dépot"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }

