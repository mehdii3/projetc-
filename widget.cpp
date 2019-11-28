#include "widget.h"
#include "ui_widget.h"
#include "personnel.h"
#include "QMessageBox"
#include"sos.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    personnel P;
    ui->tableView_2->setModel(P.Read());

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_2_clicked()
{
    if(ui->id->text()!="" && ui->nom->text()!="" && ui->prenom->text()!="" && ui->passe->text()!="" && ui->tlp->text()!=""  && ui->mail->text()!=""  && ui->type->currentText()!=""  && ui->sexe->currentText()!="" )
    {
 personnel p;
 if(!p.create(ui->id->text(),ui->nom->text(), ui->prenom->text(), ui->mail->text(), ui->tlp->text().toInt(),ui->date->date(),ui->sexe->currentText(), ui->passe->text(), ui->type->currentText()))
    {
    QMessageBox::warning(nullptr,"erreur","erreur");
    }
 else {
     QMessageBox::information(nullptr,"succe","s");
     ui->tableView_2->setModel(p.Read());
 }
    }


}

void Widget::on_pushButton_clicked()
{
    if(ui->tableView_2->currentIndex().row()!=-1)
        {
          personnel p ;
          if(!p.Delete(ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->currentIndex().row(),0)).toString()))
    {
          QMessageBox::warning(nullptr,"Attention!",ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->currentIndex().row(),0)).toString());

    }
          else


          {

              QMessageBox::information(nullptr,"Attention!","blaaa !");

              ui->tableView_2->setModel(p.Read());




          }
        }
    else {
        QMessageBox::information(nullptr,"Attention!","blaaass !");
    }
}




void Widget::on_lineEdit_textChanged(const QString &arg1)
{
    personnel he;
        if(ui->lineEdit->text()=="")
            ui->tableView_2->setModel(he.Read());
        else
            ui->tableView_2->setModel(he.Read1(ui->lineEdit->text()));
}

void Widget::on_pushButton_4_clicked()
{
    personnel he;
        if(ui->lineEdit->text()=="")
            ui->tableView_2->setModel(he.Sort());
        else
            ui->tableView_2->setModel(he.Sort1(ui->lineEdit->text()));
}





void Widget::on_pushButton_5_clicked()
{
    if(ui->tableView_2->currentIndex().row()!=-1)
    {if(ui->nom->text()!=""&& ui->prenom->text()!="")
        {
            personnel p;
            if (! p.update(ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->currentIndex().row(),0)).toString(),ui->nom->text(),ui->prenom->text(),ui->date->date())){

                QMessageBox::information(nullptr,"Attention!","blaaahhh !");

            }
            else{
                ui->tableView_2->setModel(p.Read());
      QMessageBox::information(nullptr,"Attention!","dbhebc !");
            }


        }else QMessageBox::information(nullptr,"Attention!","erreur !");
    } else QMessageBox::information(nullptr,"Attention!","indexe invalide!");
}



