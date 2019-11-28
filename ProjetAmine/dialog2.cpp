#include "dialog2.h"
#include "ui_dialog2.h"
#include "ajouter_un_vol.h"
#include "afficher_vols.h"
#include "modifier.h"

Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
}

Dialog2::~Dialog2()
{
    delete ui;
}

void Dialog2::on_pushButton_2_clicked()
{
    ajouter_un_vol a;
    a.exec();

}



void Dialog2::on_pushButton_clicked()
{
    afficher_vols a;
    a.exec();

}

void Dialog2::on_pushButton_modifiervol_clicked()
{
    modifier m;
    m.exec();
}
