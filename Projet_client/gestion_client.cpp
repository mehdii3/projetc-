#include "gestion_client.h"
#include "ui_gestion_client.h"
#include "ajouter_client.h"
#include "affiche_client.h"

Gestion_client::Gestion_client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Gestion_client)
{
    ui->setupUi(this);
}

Gestion_client::~Gestion_client()
{
    delete ui;
}

void Gestion_client::on_pushButton_clicked()
{
    Ajouter_Client a;
    Gestion_client::hide();
    a.exec();

}

void Gestion_client::on_commandLinkButton_clicked()
{

}

void Gestion_client::on_pushButton_2_clicked()
{
    Ajouter_Client a;
    Gestion_client::hide();
    a.exec();


}
