#include "dialog.h"
#include "ui_dialog.h"
#include <QPushButton>
#include <QDialog>
#include "mainwindow.h"
#include "dialog2.h"
#include "promotions.h"

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
void Dialog::setnom(QString n)
{
    ui->lineEdit_iDdialog->setText(n);

}




void Dialog::on_pushButton_gestionsvols_clicked()
{
    Dialog2 d2;
    d2.exec();

}

void Dialog::on_pushButton_promotions_clicked()
{
    promotions p;
    p.exec();
}
