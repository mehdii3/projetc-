#include "promotions.h"
#include "ui_promotions.h"
#include "affecterpro.h"

promotions::promotions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::promotions)
{
    ui->setupUi(this);
}

promotions::~promotions()
{
    delete ui;
}

void promotions::on_pushButton_ajouterpromo_clicked()
{
    QSqlQuery query;
    QDate d1;
    d1.currentDate();
    QString id=ui->lineedit_idpromo->text();
    query.prepare("select *from promotions where ID = :id ");
    query.bindValue(":id", id);
    query.exec();

    QDate datedebut=ui->dateEdit_datedebutpro->date();
    QDate datefin=ui->dateEdit_finpromo->date();
    float  taux=ui->lineEdit_taux->text().toFloat();
   classprormo p(id,datedebut,datefin,taux);
   if((id!="")&&(taux!=0)&&(!query.first())&&(p.ajouter_promo())&&(datedebut>d1)&&(datefin>datedebut))
   {
   QMessageBox::information(nullptr, QObject::tr("Ajouter promo"),
                     QObject::tr("promo ajoute.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

   }
      else {

            QMessageBox::critical(nullptr, QObject::tr("Ajouter promo"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
           }

}

void promotions::on_pushButton_afficher_clicked()
{
    classprormo r;
       ui->tableView->setModel(r.afficher());
       ui->lineedit_idpromo->setReadOnly(false);

       for (int i=0;i<4;i++)
            ui->tableView->setColumnWidth(i,  ui->tableView->width()/4);
}

void promotions::on_comboBox_activated(const QString &arg1)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    if(arg1=="ID")
model->setQuery("select * from promotions order by ID");
    if(arg1=="datedebut")
   //if(ui->comboBox->currentText()=="destination")

   //if((ui->comboBox->currentText()==arg1)&&(arg1=="destination"))
        model->setQuery("select * from promotions order by datedebut");
    if(arg1=="datefin")
        model->setQuery("select * from promotions order by datefin");
    if(arg1=="taux")
         model->setQuery("select * from promotions order by taux");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("datedebut"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("datefin"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("taux"));
    ui->tableView->setModel(model);
}

void promotions::on_pushButton_rechercherpro_clicked()
{
    classprormo v;
    QString id =ui->lineEdit_rechercheid->text();
    ui->tableView->setModel(tmppromo.recherche(id));
}

void promotions::on_pushButton_pourmodifier_clicked()
{
    QSqlQuery query;
    QPalette *palette = new QPalette();
        palette->setColor(QPalette::Base,Qt::red);
        palette->setColor(QPalette::Text,Qt::white);
    QString id=ui->lineEdit_rechercheid->text();
    //model->setQuery("select  *from vols where ID=:id");
    query.prepare("select *from promotions where ID = :id ");
    query.bindValue(":id", id);
    query.exec();
    ui->lineedit_idpromo->setReadOnly(true);
    ui->lineedit_idpromo->setPalette(*palette);

    if(query.exec())
    {
        while(query.next()){
        ui->lineedit_idpromo->setText(query.value(0).toString());
        ui->dateEdit_datedebutpro->setDate(query.value(1).toDate());
        ui->dateEdit_finpromo->setDate(query.value(2).toDate());
        ui->lineEdit_taux->setText(query.value(3).toString());


        }
    }
}

void promotions::on_pushButton_clicked()
{
    QString id=ui->lineedit_idpromo->text();
    QDate datedebut=ui->dateEdit_datedebutpro->date();
     QDate datefin=ui->dateEdit_finpromo->date();

    float  taux=ui->lineEdit_taux->text().toFloat();

    classprormo v(id,datedebut,datefin,taux);
    bool test=v.modifier(id);

}

void promotions::on_pushButton_supprimerpro_clicked()
{
    QString id =ui->lineEdit_rechercheid->text();
    QSqlQuery query;
    QSqlQuery query_promo2;
    query.prepare("UPDATE vols set taux=:taux where idpromo=:idpromo");
    query.bindValue(":taux",0);
    query.bindValue(":idpromo",id);
    query.exec();
    bool test=tmppromo.supprimer(id);

   query_promo2.prepare("UPDATE vols set idpromo=:idpromo where taux=:taux");
   query_promo2.bindValue(":taux",NULL);
   query_promo2.bindValue(":idpromo","");
   query_promo2.exec();

    if(test)
    ui->tableView->setModel(tmppromo.afficher());
}

void promotions::on_pushButton_affectepro_clicked()
{
    affecterpro a;
    a.exec();
}
