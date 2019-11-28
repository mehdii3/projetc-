#include "modifier_dep.h"
#include "ui_modifier_dep.h"
#include "avion.h"
#include <QMessageBox>

modifier_dep::modifier_dep(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifier_dep)
{
    ui->setupUi(this);
}

modifier_dep::~modifier_dep()
{
    delete ui;
}

void modifier_dep::on_pushButton_clicked()
{

    QString Ref = ui->ref->text();
    QString nom =ui->nom->text();
    int cap_max = ui->capmax->text().toInt();
    depot d(Ref,nom,cap_max);
    bool test=d.modifier_dep();
    if(test)
      {//ui->avion->setModel(tmprdv.afficher());//refresh
      QMessageBox::information(nullptr, QObject::tr("Modifier un Dépot"),
                        QObject::tr("Dépot Modifié.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

      }
        else
            QMessageBox::critical(nullptr, QObject::tr("Modifier un Dépot"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
    }

