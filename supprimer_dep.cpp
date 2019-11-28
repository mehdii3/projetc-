#include "supprimer_dep.h"
#include "ui_supprimer_dep.h"
#include"avion.h"
#include <QMessageBox>

supprimer_dep::supprimer_dep(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::supprimer_dep)
{
    ui->setupUi(this);
}

supprimer_dep::~supprimer_dep()
{
    delete ui;
}

void supprimer_dep::on_pushButton_clicked()
{
    QString a;
    a= ui->idsupp->text();
    depot s;
    bool test = s.supprimer_dep(a);

    if(test)
  {//ui->avion->setModel(tmprdv.afficher());//refresh
  QMessageBox::information(nullptr, QObject::tr("Supprimer un Dépot"),
                    QObject::tr("Dépot Supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un Dépot"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

