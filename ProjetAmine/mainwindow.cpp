#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
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
if(ui->lineEdit_ID->text()=="amine")
  {
     MainWindow::hide();
     d.setnom(ui->lineEdit_ID->text());
     d.exec();
     MainWindow::show();
  }
}
