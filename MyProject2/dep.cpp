#include "dep.h"
#include "ui_dep.h"
#include<qmessagebox.h>


dep::dep(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dep)
{
    ui->setupUi(this);
    QRegExp rx("[A-Za-z_]+");//[A-Za-z0-9_]
          QRegExp rx1("[0-9_]+");
          QValidator *validator = new QRegExpValidator(rx, this);
          QValidator *validator2 = new QRegExpValidator(rx1, this);
          ui->refdep->setValidator(validator);
          ui->nomdep->setValidator(validator);
          ui->cap->setValidator(validator2);
          ui->lineEdit->setValidator(validator);
          ui->lineEdit_2->setValidator(validator);
          ui->lineEdit_3->setValidator(validator2);
          ui->lineEdit_4->setValidator(validator);
          //ui->lineEdit_5->setValidator(validator);

}

dep::~dep()
{
    delete ui;
}

depot1::depot1()
{
Ref="";
nom="";
cap_max=0;
}
depot1:: depot1(QString Ref,QString nom ,int cap_max)
{
  this->Ref=Ref;
  this->nom=nom;
  this->cap_max=cap_max;
}
QString depot1::get_Ref(){return Ref;}
QString depot1::get_nom(){return nom;}
int depot1::get_cap_max(){return cap_max;}

bool depot1::ajouter_dep()
{
QSqlQuery query;
QString res = QString::number(cap_max);
query.prepare("INSERT INTO depot (REFERENCE,NOM,CAPACITE_MAX) "
                    "VALUES (:r,:n,:cm)");
query.bindValue(":r", Ref);
query.bindValue(":n", nom);
query.bindValue(":cm", res);
return    query.exec();
}

QSqlQueryModel * depot1::afficher_dep()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from depot");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERENCE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("CAPACITE_MAX"));

    return model;
}

bool depot1::supprimer_dep(QString Ref)
{
QSqlQuery query;

query.prepare("Delete from depot where REFEREENCE = :r ");
query.bindValue(":r",Ref);
return    query.exec();
}

bool depot1::modifier_dep()
{
    QSqlQuery query;
    //QString res = QString::number(cap_max);

    query.prepare("Update depot set REFERENCE=:r,NOM=:n ,CAPACITE_MAX=:cm ");
    query.bindValue(":r", Ref);
    query.bindValue(":n", nom);
    query.bindValue(":cm", cap_max);
    return query.exec();
}



void dep::on_pushButton_clicked()
{QSqlQuery qry;
                QString Ref = ui->refdep->text();
                QString nom =ui->nomdep->text();
                int cap_max = ui->cap->text().toInt();
                int x=0;

                qry.prepare("select *from depot where REFERENCE =:reference ");
                qry.bindValue(":reference", Ref);
                    if (qry.exec())
                    {
                        while (qry.next())
                        {
                           x++;
                      }
                    }
                    if(x==0)
                    {
                depot1 d (Ref,nom,cap_max);
                bool test=d.ajouter_dep();
                test=1;
                if(test)
                  {
                  QMessageBox::information(nullptr, QObject::tr("Ajouter Dépot"),
                                    QObject::tr("Dépot ajouté.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);

                  }
                    else
                        QMessageBox::critical(nullptr, QObject::tr("Ajouter un Dépot"),
                                    QObject::tr("Erreur !.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
                }
                else {
                    QMessageBox::critical(nullptr, QObject::tr("Ajouter un Avion"),
                                QObject::tr("Réference deja existante!.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
                }

    }



void dep::on_pushButton_3_clicked()
{
    QString Ref = ui->lineEdit->text();
          QString nom =ui->lineEdit_2->text();
          int cap_max = ui->lineEdit_3->text().toInt();
          depot1 d(Ref,nom,cap_max);
          bool test=d.modifier_dep();
          if(test)
        { ui->tableView->setModel(d.afficher_dep());//refresh
        QMessageBox::information(nullptr, QObject::tr("Modifier un Dépot"),
                          QObject::tr("Dépot Modifié.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

        }
          else
              QMessageBox::critical(nullptr, QObject::tr("Modifier un Dépot"),
                          QObject::tr("Erreur !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
}


void dep::on_pushButton_2_clicked()
{
    depot1 tdep;
        ui->tableView->setModel(tdep.afficher_dep());
}

void dep::on_pushButton_4_clicked()
{
    QString a;
    ui->lineEdit_4->text();

           depot1 s;
           bool test = s.supprimer_dep(a);

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
