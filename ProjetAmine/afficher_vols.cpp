#include "afficher_vols.h"
#include "ui_afficher_vols.h"
#include "vol.h"
afficher_vols::afficher_vols(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::afficher_vols)
{
    ui->setupUi(this);
}

afficher_vols::~afficher_vols()
{
    delete ui;
}

void afficher_vols::on_pushButton_afficher_clicked()
{
    vol v;
       ui->tableView->setModel(v.afficher());
}

void afficher_vols::on_Supprimer_clicked()
{
    QString id =ui->lineEdit_saisiid->text();
    bool test=tmpvol.supprimer(id);
    if(test)
    ui->tableView->setModel(tmpvol.afficher());
}

void afficher_vols::on_pushButton_rechercher_clicked()
{
    vol v;
    QString id =ui->lineEdit_saisiid->text();
    ui->tableView->setModel(tmpvol.afficher2(id));
}

/*void afficher_vols::on_comboBox_activated(const QString &arg1)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    if(arg1=="destination")


    model->setQuery("select * from vols order by destination");
   //if(ui->comboBox->currentText()=="destination")

   //if((ui->comboBox->currentText()==arg1)&&(arg1=="destination"))
       // model->setQuery("select * from vols order by destination");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nb_place"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("destination"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("dateheur"));
    ui->tableView->setModel(model);
}*/




void afficher_vols::on_comboBox_activated(const QString &arg1)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    if(arg1=="ID")
model->setQuery("select * from vols order by ID");
    if(arg1=="destination")
   //if(ui->comboBox->currentText()=="destination")

   //if((ui->comboBox->currentText()==arg1)&&(arg1=="destination"))
        model->setQuery("select * from vols order by destination");
    if(arg1=="nombre de place")
        model->setQuery("select * from vols order by nb_place");
    if(arg1=="heur")
         model->setQuery("select * from vols order by dateheur");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nb_place"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("destination"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("dateheur"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("taux"));

    ui->tableView->setModel(model);
}

