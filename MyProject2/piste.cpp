#include "piste.h"
#include "ui_piste.h"
#include <qmessagebox.h>

piste::piste(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::piste)
{
    ui->setupUi(this);
   /* QRegExp rx("[A-Za-z_]+");//[A-Za-z0-9_]
       QRegExp rx1("[0-9_]+");
       QValidator *validator = new QRegExpValidator(rx, this);
       QValidator *validator2 = new QRegExpValidator(rx1, this);
       ui->disp->setValidator(validator);
       ui->nompiste->setValidator(validator);
       ui->longeur->setValidator(validator2);*/
}


piste::~piste()
{
    delete ui;
}
piste1::piste1()
{
disp="";
nom="";
longeur=0;
}
piste1::piste1(QString disp,QString nom ,int longeur)
{
  this->disp=disp;
  this->nom=nom;
  this->longeur=longeur;
}
QString piste1::get_disp(){return disp;}
QString piste1::get_nom(){return nom;}
int piste1::get_longeur(){return longeur;}

bool piste1::ajouter_piste()
{
QSqlQuery query;
QString res = QString::number(longeur);
query.prepare("INSERT INTO piste (DISP,NOM,LONGEUR) "
                    "VALUES (:r,:n,:cm)");
query.bindValue(":r", disp);
query.bindValue(":n", nom);
query.bindValue(":cm", longeur);
return    query.exec();
}

QSqlQueryModel * piste1::afficher_piste()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from piste");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("DISP"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("LONGEUR"));

    return model;
}

bool piste1::supprimer_piste(QString a)
{
QSqlQuery query;

query.prepare("Delete from piste where NOM = :r ");
query.bindValue(":r",a);
return    query.exec();
}

bool piste1::modifier_piste()
{
    QSqlQuery query;
    QString res = QString::number(longeur);

    query.prepare("Update piste set DISP=:r,NOM=:n ,LONGEUR=:cm ");
    query.bindValue(":r", disp);
    query.bindValue(":n", nom);
    query.bindValue(":cm", longeur);
    return query.exec();
}

void piste::on_pushButton_clicked()
{QSqlQuery qry;
                QString nom= ui->nompiste->text();
                int longeur = ui->longeur->text().toInt();
                QString disp = "oui";
                if(ui->radioButton->isChecked()) disp="oui";
                else disp="non";

                int x=0;

                qry.prepare("select * from piste where NOM =:nom ");
                qry.bindValue(":nom", nom);
                    if (qry.exec())
                    {
                        while (qry.next())
                        {
                           x++;
                      }
                    }
                    if(x==0)
                    {
                        piste1 d (disp,nom,longeur);
                        bool test=d.ajouter_piste();
                test=1;
                if(test)
                  {
                  QMessageBox::information(nullptr, QObject::tr("Ajouter une Piste"),
                                    QObject::tr("Piste ajoutée.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);

                  }
                    else
                        QMessageBox::critical(nullptr, QObject::tr("Ajouter une Piste"),
                                    QObject::tr("Erreur !.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
                }
                else {
                    QMessageBox::critical(nullptr, QObject::tr("Ajouter une Piste"),
                                QObject::tr("Piste deja existante!.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
                }

    }



void piste::on_pushButton_3_clicked()
{
    piste1 tdep;
        ui->tableView->setModel(tdep.afficher_piste());
}


void piste::on_pushButton_4_clicked()
{

    QString a = ui->idsupp->text();

       piste1 s;
       bool test = s.supprimer_piste(a);

       if(test)
     {
     QMessageBox::information(nullptr, QObject::tr("Supprimer une Piste"),
                       QObject::tr("Piste Supprimée.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

     }
       else
           QMessageBox::critical(nullptr, QObject::tr("Supprimer une Piste"),
                       QObject::tr("Erreur !.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
}


void piste::on_pushButton_2_clicked()
{
    //QString disp = ui->->text();
       QString nom =ui->nompiste_2->text();
       int longeur = ui->longeur_2->text().toInt();
       QString disp = "oui";
       if(ui->radioButton_3->isChecked()) disp="oui";
       else disp="non";
       piste1 d(disp,nom,longeur);
       bool test=d.modifier_piste();
       if(test)
     { ui->tableView->setModel(d.afficher_piste());//refresh
     QMessageBox::information(nullptr, QObject::tr("Modifier une Piste"),
                       QObject::tr("Piste Modifiée.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

     }
       else
           QMessageBox::critical(nullptr, QObject::tr("Modifier une Piste"),
                       QObject::tr("Erreur !.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
}
