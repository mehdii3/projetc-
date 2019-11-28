#include "afficher_dep.h"
#include "ui_afficher_dep.h"
#include "avion.h"

afficher_dep::afficher_dep(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::afficher_dep)
{
    ui->setupUi(this);

}

afficher_dep::~afficher_dep()
{
    delete ui;
}
