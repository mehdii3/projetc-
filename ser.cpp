#include "ser.h"
#include "ui_ser.h"
#include"services.h"
#include "QMessageBox"

ser::ser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ser)
{
    ui->setupUi(this);
   // services s;
    //ui->tableView_5->setModel(s.Read());
}

ser::~ser()
{
    delete ui;
}

//void ser::on_pushButton_clicked()
//{
  //  if(ui->idser->text()!="" && ui->nomser->text()!="" &&ui->nbser->text()!=""  )
   // {
 //services s;
 //if(!s.create(ui->idser->text(),ui->nomser->text(),ui->nbser->text()))
 //{

  //  QMessageBox::warning(nullptr,"erreur","erreur");
 //   }
 //else {
 //    QMessageBox::information(nullptr,"succe","s");
  //   ui->tableView_5->setModel(s.Read());
// }


//}}
