#include "gestiondep.h"
#include "ui_gestiondep.h"
#include "avion.h"
#include "ajout_dep.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"

gestiondep::gestiondep(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestiondep)
{
    ui->setupUi(this);
}

gestiondep::~gestiondep()
{
    delete ui;
}


void gestiondep::on_ajouterdep_clicked()
{
    gestiondep g;
    g.show();
    //MainWindow::hide();
    g.exec();
}

