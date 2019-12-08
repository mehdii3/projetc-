#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "RESERVATION.h"
#include "modifier_reservation.h"
#include <statistique.h>

#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)


{
ui->setupUi(this);
QPixmap pix ("C:\\Users\\asus\\Downloads\\icons8-chercher-24.png");
ui->lab_pic->setPixmap(pix.scaled(10,10));

ui->tabetudiant->setModel(tmpreservation.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pb_supprimer_clicked()
{
int id = ui->lineEdit_id_3->text().toInt();

QMessageBox::information(nullptr, QObject::tr("Supprimer un étudiant"),
            QObject::tr("reservation supprimé.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);

bool test=tmpreservation.supprimer(id);
ui->tabetudiant->setModel(tmpreservation.afficher());
if(test)
{ui->tabetudiant->setModel(tmpreservation.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un étudiant"),
                QObject::tr("reservation supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

    ui->lineEdit_id_3->setText("");
    ui->lineEdit_nom_2->setText("");
    ui->lineEdit_prenom_2->setText("");
    ui->lineEdit_destination_2->setText("");
    ui->lineEdit_date_depart_2->setText("");
    ui->lineEdit_retour_2->setText("");

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer une reservation"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_ajouter_clicked()
{
    int id= ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    QString date_depart=ui->lineEdit_date_depart->text();
    QString date_retour=ui->lineEdit_retour->text();
    QString destination=ui->lineEdit_destination->text();

  reservation r(id,nom,prenom,date_depart,date_retour,destination);
  bool test=r.ajouter();
  ui->tabetudiant->setModel(tmpreservation.afficher());

  if(test)
{ui->tabetudiant->setModel(tmpreservation.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une reservation"),
                  QObject::tr("reservation ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une réservation"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}


void MainWindow::on_tabetudiant_activated(const QModelIndex &index)
{
    QString val =ui->tabetudiant->model()->data(index).toString();
        QSqlQuery query;
        query.prepare("SELECT * FROM reservation WHERE identifiant ='"+val+"' or nom='"+val+"' or prenom='"+val+"' or destination=' "+val+"' or date_depart='"+val+"' or date_retour='"+val+"'");
        query.exec();
    while(query.next())
        {


            ui->lineEdit_id_3->setText(query.value(0).toString());
            ui->lineEdit_nom_2->setText(query.value(1).toString());
            ui->lineEdit_prenom_2->setText(query.value(2).toString());
            ui->lineEdit_destination_2->setText(query.value(3).toString());
            ui->lineEdit_date_depart_2->setText(query.value(4).toString());
            ui->lineEdit_retour_2->setText(query.value(5).toString());



        }
}

void MainWindow::on_Modifier_clicked()
{
    int id= ui->lineEdit_id_3->text().toInt();
    QString nom= ui->lineEdit_nom_2->text();
    QString prenom= ui->lineEdit_prenom_2->text();
    QString date_depart=ui->lineEdit_date_depart_2->text();
    QString date_retour=ui->lineEdit_retour_2->text();
    QString destination=ui->lineEdit_destination_2->text();

  reservation r(id,nom,prenom,date_depart,date_retour,destination);
  bool test=r.modifier();
  if(test)
{ui->tabetudiant->setModel(tmpreservation.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Modifier une reservation"),
                  QObject::tr("reservation modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier une réservation"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}



void MainWindow::on_recherche_textEdited(const QString &arg1)
{
    QString destination= ui->recherche->text();
    ui->tabetudiant->setModel(tmpreservation.afficherParDestination(arg1));
}

void MainWindow::on_pushButton_clicked()
{
    Statistique stat;
    stat.setModal(true);
    stat.exec();
}
