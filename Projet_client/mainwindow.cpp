#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "smtp.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_connecter_clicked()
{
     Dialog d;
   /* QString nom;
    QString prenom;

    nom = ui->lineEdit_Id->text();
    prenom = ui->lineEdit_mdp->text();
    int id=123;

    */
    MainWindow::hide();
    d.exec();
    MainWindow::show();

   // Smtp *newMail  = new Smtp("mehditaieb.amri@esprit.tn","mehditaieb.amri@esprit.tn"," Your Subject","My body text");

}
