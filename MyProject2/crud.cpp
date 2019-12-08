#include "crud.h"
#include "ui_crud.h"
#include "avion.h"
#include <qmessagebox.h>




crud::crud(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::crud)
{
    ui->setupUi(this);
    QRegExp rx("[A-Za-z_]+");//[A-Za-z0-9_]
       QRegExp rx1("[0-9_]+");
       QValidator *validator = new QRegExpValidator(rx, this);
       QValidator *validator2 = new QRegExpValidator(rx1, this);
       ui->ref->setValidator(validator);
       ui->idsupp->setValidator(validator);
       ui->rech->setValidator(validator);
       ui->ref_2->setValidator(validator);
       ui->type->setValidator(validator);
       ui->type_2->setValidator(validator);
       //ui->etat->setValidator(validator);
       //ui->etat_2->setValidator(validator);
       ui->distance->setValidator(validator2);
       ui->distance_2->setValidator(validator2);
       ui->vitesse->setValidator(validator2);
       ui->vitesse_2->setValidator(validator2);
       ui->nbr_pass->setValidator(validator2);
       ui->nbr_pass_2->setValidator(validator2);
}

crud::~crud()
{
    delete ui;
}

void crud::on_pushButton_4_clicked()
{
     QSqlQuery qry;
    QString ref = ui->ref->text();
       QString type =ui->type->text();
       QString etat_res = ui->etat_res->text();

       QDate date = ui->date->date();
       QString etat = "";
       if(ui->radioButton->isChecked()) etat="Non Fonctionnel";
       else etat="Fonctionnel";
       int dist = ui->distance->text().toInt();
       int vit =ui->vitesse->text().toInt();
       int nbr = ui->nbr_pass->text().toInt();

        int x=0;

        qry.prepare("select *from avion where REFERENCE =:reference ");
        qry.bindValue(":reference", ref);
            if (qry.exec())
            {
                while (qry.next())
                {
                   x++;
              }
            }
            if(x==0)
            {
                Avion a(ref,type,etat,etat_res,date,nbr,dist,vit);
                bool test=a.ajouter();
                if(test)
              {
              QMessageBox::information(nullptr, QObject::tr("Ajouter un Avion"),
                                QObject::tr("Avion ajouté.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

              }
                else
                    QMessageBox::critical(nullptr, QObject::tr("Ajouter un Avion"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
            }
            else {
                QMessageBox::critical(nullptr, QObject::tr("Ajouter un Avion"),
                            QObject::tr("Réference deja existante!.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
            }

}




void crud::on_pushButton_2_clicked()
{
    QString a;
       a= ui->idsupp->text();
       Avion s;
       bool test = s.supprimer(a);

       if(test)
     {
     QMessageBox::information(nullptr, QObject::tr("Supprimer un Avion"),
                       QObject::tr("Avion Supprimé.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

     }
       else
           QMessageBox::critical(nullptr, QObject::tr("Supprimer un Avion"),
                       QObject::tr("Erreur !.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
}


void crud::on_pushButton_clicked()
{

       // ui->setupUi(this);
        Avion tavion;
        ui->table->setModel(tavion.afficher());
}

void crud::on_pushButton_3_clicked()
{
     //ui->setupUi(this);
    QString ref = ui->ref_2->text();
      QString type =ui->type_2->text();
      QString etat_res = ui->etat_res_2->text();
      QString etat = "";
      if(ui->radioButton_3->isChecked()) etat="Non Fonctionnel";
      else etat="Fonctionnel";
      QDate date = ui->date_2->date();
      int dist = ui->distance_2->text().toInt();
      int vit =ui->vitesse_2->text().toInt();
      int nbr = ui->nbr_pass_2->text().toInt();
      Avion a(ref,type,etat,etat_res,date,nbr,dist,vit);
      bool test=a.modifier();
      if(test)
    {ui->table->setModel(a.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Modifier un Avion"),
                      QObject::tr("Avion Modifié.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Modifier un Avion"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}

void crud::on_comboBox_activated(const QString &arg1)
{
    QSqlQueryModel * model= new QSqlQueryModel();
            if(arg1=="Référence")
        model->setQuery("select * from avion order by REFERENCE");
            if(arg1=="Type")

                model->setQuery("select * from avion order by TYPE");
            if(arg1=="Date première sortie")
                model->setQuery("select * from avion order by DATE_PREMIERE_SORTIE");


            model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERENCE"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("ETAT"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("RESERVOIR"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE"));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("NBR"));
            model->setHeaderData(6, Qt::Horizontal, QObject::tr("DISTANCE"));
            model->setHeaderData(7, Qt::Horizontal, QObject::tr("VITESSE"));
           ui->tabletri->setModel(model);
}

void crud::on_pushButton_5_clicked()//recherche
{
   Avion a;
   QString reference=ui->rech->text();
    ui->tableView->setModel(a.recherche(reference));
}







