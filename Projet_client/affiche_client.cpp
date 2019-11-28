#include "affiche_client.h"
#include "client.h"
#include<QtDebug>
#include<QSqlQueryModel>
#include "ui_affiche_client.h"
#include "ajouter_client.h"


affiche_client::affiche_client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::affiche_client)
{
    ui->setupUi(this);
    client tclient;
    ui->tableView->setModel(tclient.afficher());

}

affiche_client::~affiche_client()
{
    delete ui;
}




void affiche_client::on_pushButton_clicked()
{
    client tclient;
    tclient.supprimer(ui->lineEdit_champ->text());
    ui->tableView->setModel(tclient.afficher());
}




void affiche_client::on_pushButton_rechercher_clicked()
{
    client tclient;
    ui->tableView->setModel(tclient.afficher_id(ui->lineEdit_champ->text()));


}

void affiche_client::on_tableView_viewportEntered()
{

}

void affiche_client::on_pushButton_2_clicked()
{
    //client tclient;
    //ui->tableView->setModel(tclient.afficher_id(ui->lineEdit_champ->text()));
    QSqlQuery requeteSQL;
        requeteSQL.prepare("SELECT * FROM client");
        if (requeteSQL.exec())
        {
            requeteSQL.first();

                qDebug()<<(requeteSQL.value(1).toString());
        }
}
