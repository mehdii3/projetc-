#include "dialog.h"
#include "ui_dialog.h"
#include "QPushButton"
#include "mainwindow.h"
#include "ajouter_client.h"
#include "reclamation.h"
#include "fidel.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}



void Dialog::on_pushButton_gererclient_clicked()
{


        Ajouter_Client g;
        Dialog::hide();

       g.exec();
       Dialog::show();



}

void Dialog::on_pushButton_4_clicked()
{

    Dialog::hide();

}

void Dialog::on_pushButton_reclamation_clicked()
{
    reclamation r;
    Dialog::hide();
    r.exec();
    Dialog::show();

}

void Dialog::on_pushButton_clicked()
{
    fidel f;
    Dialog::hide();
    f.exec();
    Dialog::show();
}
