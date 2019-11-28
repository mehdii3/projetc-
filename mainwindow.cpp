#include "mainwindow.h"
#include "avion.h"
#include "connexion.h"
#include "ui_mainwindow.h"
#include "ajoutavion.h"
#include "modifieravion.h"
#include "supprimeravion.h"
#include "afficheravion.h"
#include "recherche.h"
#include "tri.h"
#include "gestiondep.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    gestiondep g;
    g.show();
    MainWindow::hide();
    g.exec();


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_ajouter_clicked()
{
    AjoutAvion a;
    a.show();
    MainWindow::hide();
    a.exec();
}

void MainWindow::on_modifier_clicked()
{
    ModifierAvion m;
    m.show();
    MainWindow::hide();
    m.exec();
}

void MainWindow::on_supprimer_clicked()
{
    SupprimerAvion s;
    s.show();
    MainWindow::hide();
    s.exec();
}

void MainWindow::on_afficher_clicked()
{
    AfficherAvion a;
    a.show();
    MainWindow::hide();
    a.exec();
}



void MainWindow::on_pushButton_clicked()
{
    AjoutAvion a;
    a.show();
    MainWindow::hide();
    a.exec();
}

void MainWindow::on_trier_clicked()
{
    tri t;
    t.show();
    MainWindow::hide();
    t.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    recherche r;
    r.show();
    MainWindow::hide();
    r.exec();
}




void MainWindow::on_pushButton_3_clicked()
{
    gestiondep g;
    g.show();
    MainWindow::hide();
    g.exec();
}
