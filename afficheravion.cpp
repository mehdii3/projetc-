#include "afficheravion.h"
#include "ui_afficheravion.h"

AfficherAvion::AfficherAvion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AfficherAvion)
{
    ui->setupUi(this);
    ui->table->setModel(tmptable.afficher());
}

AfficherAvion::~AfficherAvion()
{
    delete ui;
}
