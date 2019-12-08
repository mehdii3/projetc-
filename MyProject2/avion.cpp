#include "avion.h"
#include "ui_avion.h"
#include "crud.h"
#include"dep.h"
#include "piste.h"
#include "mail.h"
#include "statistiques.h"

//#include "piste.h"

avion::avion(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::avion)
{
    ui->setupUi(this);
}

avion::~avion()
{
    delete ui;
}





void avion::on_pushButton_clicked()
{
crud c;
c.exec();
}



void avion::on_pushButton_2_clicked()
{
    dep d ;
    d.exec();
}

void avion::on_pushButton_3_clicked()
{
    piste p;
    p.exec();
}

void avion::on_pushButton_4_clicked()
{
    mail m;
    m.exec();

}

void avion::on_pushButton_5_clicked()
{
    statistiques s;
    s.exec();
}
