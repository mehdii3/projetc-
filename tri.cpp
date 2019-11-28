#include "tri.h"
#include "ui_tri.h"
#include "avion.h"
#include <QSqlQuery>


tri::tri(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tri)
{
    ui->setupUi(this);
}

tri::~tri()
{
    delete ui;
}

void tri::on_comboBox_activated(const QString &arg1)
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
        ui->tableView->setModel(model);


}
