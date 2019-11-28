#include "reclamation.h"
#include "ui_reclamation.h"
//#include <client.cpp>


reclamation::reclamation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reclamation)
{
    ui->setupUi(this);
    QRegExp rx("[A-Za-z_]+");//[A-Za-z0-9_]
    QRegExp rx1("[0-9_]+");
    QValidator *validator = new QRegExpValidator(rx, this);
    QValidator *validator2 = new QRegExpValidator(rx1, this);

    ui->idc->setValidator(validator2);
    ui->idr->setValidator(validator2);

    reclamation1 r;
    ui->affiche->setModel(r.afficherReclamation());
    for (int i=0;i<9;i++)
     ui->affiche->setColumnWidth(i,  ui->affiche->width()/5);
    ui->valider->hide();

}

reclamation::~reclamation()
{
    delete ui;
}


reclamation1::reclamation1(QString titre,QString idClient,QString idReclamation,QString text,QDate date_reclamation)
{
    this->titre=titre;
    this->idClient=idClient;
    this->idReclamation=idReclamation;
    this->date_reclamation=date_reclamation;
    this->text=text;

}
bool reclamation1::ajouterReclamation()
{
    QSqlQuery query;


    query.prepare("INSERT INTO reclamation (titre, idclient, idreclamation, text, datereclamation) "
                        "VALUES (:titre, :idclient, :idreclamation, :text, :datereclamation)");
    query.bindValue(":titre", titre);
    query.bindValue(":idclient",idClient );
    query.bindValue(":idreclamation", idReclamation);
    query.bindValue(":text", text);
    query.bindValue(":datereclamation", date_reclamation);


    return    query.exec();


}

QSqlQueryModel * reclamation1::afficherReclamation()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select titre,idclient,idreclamation,datereclamation,text from reclamation");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("  titre  "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("  ID Client  "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("  ID Reclamation  "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("  Date Reclamation  "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("  Text  "));


    return model;
}


void reclamation::on_ajouter_clicked()
{
    QSqlQuery query_id_client,query_id_reclamation;
    reclamation1 r(ui->titre->text(),ui->idc->text(),ui->idr->text(),ui->text->text(),ui->dateEdit->date());
    if (!((ui->idc->text()=="")||(ui->titre->text()=="")||(ui->idr->text()=="")||(ui->text->text()=="")))
    {
        query_id_client.prepare("SELECT IDENTIFIANT from client where IDENTIFIANT = :id");
        query_id_client.bindValue(":id", ui->idc->text());
        query_id_client.exec();
        query_id_reclamation.prepare("SELECT IDRECLAMATION from reclamation where IDRECLAMATION = :id1");
        query_id_reclamation.bindValue(":id1", ui->idr->text());
        query_id_reclamation.exec();
       if ((query_id_client.next())&&(!(query_id_reclamation.next())))
       {
           r.ajouterReclamation();
           ui->affiche->setModel(r.afficherReclamation());
        }

    }
}

void reclamation::on_pushButton_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select titre,idclient,idreclamation,datereclamation,text from reclamation where idreclamation= :id");
    query.bindValue(":id",ui->demande->text());
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("  titre  "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("  ID Client  "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("  ID Reclamation  "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("  Date Reclamation  "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("  Text  "));
    ui->affiche->setModel(model);


}

void reclamation::on_pushButton_2_clicked()
{
    QSqlQuery query;
    reclamation1 r;
    query.prepare("Delete from reclamation where idreclamation = :id");
    query.bindValue(":id",ui->demande->text());
    query.exec();
    ui->affiche->setModel(r.afficherReclamation());
}

bool reclamation1::modifierReclamation (QString text,QString id)
{
    QSqlQuery query;
    query.prepare("UPDATE reclamation SET text= :text WHERE IDRECLAMATION = :id");
    query.bindValue(":text",text);
    query.bindValue(":id",id);
    query.exec();
    if (query.next())
      return (1);
    else
        return(0);
}

void reclamation::on_pushButton_3_clicked()
{
    QPalette *palette = new QPalette();
    palette->setColor(QPalette::Base,Qt::gray);
    palette->setColor(QPalette::Text,Qt::darkGray);
    QSqlQuery query;

    query.prepare("select * from reclamation WHERE IDRECLAMATION = :id");
    query.bindValue(":id",ui->demande->text());
   query.exec();
   if (query.next())
   {
       query.first();
   QString titre= query.value(0).toString();
   QString idc = query.value(1).toString();
   QString idr = query.value(2).toString();
   QString text = query.value(3).toString();
   QDate dat = query.value(4).toDate();
       ui->text->setText(text);
       ui->idc->setText(idc);
       ui->titre->setText(titre);
       ui->idr->setText(idr);
       ui->dateEdit->setDate(dat);

       ui->titre->setReadOnly(true);
       ui->idc->setReadOnly(true);
       ui->idr->setReadOnly(true);
       ui->dateEdit->setReadOnly(true);

       ui->titre->setPalette(*palette);
       ui->idc->setPalette(*palette);
       ui->idr->setPalette(*palette);
       ui->dateEdit->setPalette(*palette);

       ui->valider->show();
   }




}

void reclamation::on_pushButton_4_clicked()
{



}

void reclamation::on_valider_clicked()
{
    QPalette *palette = new QPalette();
    palette->setColor(QPalette::Base,Qt::white);
    palette->setColor(QPalette::Text,Qt::black);

    reclamation1 r;
    r.modifierReclamation(ui->text->text(),ui->idr->text());

    ui->titre->setReadOnly(false);
    ui->idc->setReadOnly(false);
    ui->idr->setReadOnly(false);
    ui->dateEdit->setReadOnly(false);

    ui->titre->setPalette(*palette);
    ui->idc->setPalette(*palette);
    ui->idr->setPalette(*palette);
    ui->dateEdit->setPalette(*palette);

    ui->affiche->setModel(r.afficherReclamation());
    ui->valider->hide();
}
