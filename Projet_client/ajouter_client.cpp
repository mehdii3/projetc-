#include "ajouter_client.h"
#include "ui_ajouter_client.h"
#include "dialog.h"
#include "client.h"
#include "affiche_client.h"
#include <QMessageBox>
#include "connexion.h"
#include <QtDebug>
#include <QApplication>



Ajouter_Client::Ajouter_Client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ajouter_Client)
{
    ui->setupUi(this);
    QRegExp rx("[A-Za-z_]+");//[A-Za-z0-9_]
    QRegExp rx1("[0-9_]+");
    QValidator *validator = new QRegExpValidator(rx, this);
    QValidator *validator2 = new QRegExpValidator(rx1, this);
    ui->lineEdit_nom->setValidator(validator);
    ui->lineEdit_prenom->setValidator(validator);
    ui->lineEdit_nat->setValidator(validator);
    ui->lineEdit_cin->setValidator(validator2);
    ui->lineEdit_nbvol->setValidator(validator2);
    ui->lineEdit_id->setValidator(validator2);
    client tclient;
    ui->tableView_affiche->setModel(tclient.afficher());
   // ui->tableView_affiche->sizeHintForColumn(9);
    ui->tableView_affiche->setMinimumHeight(9);
    for (int i=0;i<9;i++)
     ui->tableView_affiche->setColumnWidth(i,  ui->tableView_affiche->width()/9);


    ui->pushButton_valider->hide();
}

Ajouter_Client::~Ajouter_Client()
{
    delete ui;
}

void Ajouter_Client::on_pushButton_clicked()
{
   Ajouter_Client::hide();
   Dialog g;
   g.exec();
}


void Ajouter_Client::on_pushButton_2_clicked()
{

    client c1(ui->lineEdit_nom->text(),ui->lineEdit_prenom->text(),ui->lineEdit_cin->text().toInt(),ui->lineEdit_nat->text(),ui->dateEdit_ddn->date(),ui->lineEdit_contact->text(),ui->lineEdit_nbvol->text().toInt(),ui->lineEdit_id->text().toInt(),ui->dateEdit_ddi->date(),0);
    QSqlQuery query_id;
    QSqlQuery query_cin;
    QString id = ui->lineEdit_id->text();
    QString cin=ui->lineEdit_cin->text();
     if(!((ui->lineEdit_nom->text()=="")||(ui->lineEdit_prenom->text()=="")||(ui->lineEdit_cin->text().toInt()==0)||(ui->lineEdit_nat->text()=="")||(ui->lineEdit_contact->text()=="")||(ui->lineEdit_nbvol->text().toInt()==0)||(ui->lineEdit_id->text().toInt()==0)))
     {
    query_id.prepare("SELECT IDENTIFIANT from client where IDENTIFIANT = :id ");
    query_cin.prepare("SELECT CIN from client where CIN = :cin ");
    query_id.bindValue(":id", id);
    query_cin.bindValue(":cin", cin);
    query_id.exec();
    query_cin.exec();

    /* Connexion c;
    QSqlQueryModel * x;
    try {
       bool t= c.ouvrirConnexion();
        qDebug()<<"hhhhhh"<<t;

    } catch (QString s) {
        qDebug()<<s;

    }
*/
    if (query_cin.next()&& query_id.next())
    {
        QMessageBox::information(nullptr, QObject::tr("Probleme D'ajout"),
                          QObject::tr("CIN ET ID EXISTE DEJA .\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else if (query_id.next())
    {
        QMessageBox::information(nullptr, QObject::tr("Probleme D'ajout"),
                          QObject::tr("ID EXISTE DEJA .\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }else if (query_cin.next())
    {
        QMessageBox::information(nullptr, QObject::tr("Probleme D'ajout"),
                          QObject::tr("CIN EXISTE DEJA .\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }

    else
    {
    c1.ajouterClient();
    QMessageBox::information(nullptr, QObject::tr("Ajout"),
                      QObject::tr("Client Ajouté .\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tableView_affiche->setModel(c1.afficher());
    }
     }
//ui->tableView->setModel(c1.afficher());


}

void Ajouter_Client::on_pushButton_recherche_clicked()
{
    client tclient;
    ui->tableView_affiche->setModel(tclient.afficher_id(ui->lineEdit_iddemande->text()));
    if (ui->lineEdit_iddemande->text()=="")
    {
        ui->tableView_affiche->setModel(tclient.afficher());
    }
}

void Ajouter_Client::on_pushButton_supprimer_clicked()
{
    client tclient;
    QSqlQuery query_id;
    query_id.prepare("SELECT IDENTIFIANT from client where IDENTIFIANT = :id ");
    query_id.bindValue(":id",ui->lineEdit_iddemande->text());
    query_id.exec();

    if (!(query_id.next()))
    {
        QMessageBox::information(nullptr, QObject::tr("Probleme De Suppression"),
                          QObject::tr("Client N'existe Pas .\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }

     else
    tclient.supprimer(ui->lineEdit_iddemande->text());

    ui->tableView_affiche->setModel(tclient.afficher());
}

void Ajouter_Client::on_comboBox_currentTextChanged(const QString &arg1)
{
    client tclient;
    if (arg1=="Ordre Alphabetique")
    {
        ui->tableView_affiche->setModel(tclient.afficher_Alph());
    }
    else if (arg1=="Identifiant")
    {
        ui->tableView_affiche->setModel(tclient.afficher_id());
    }
    else if (arg1=="Nombre De Vols")
    {
        ui->tableView_affiche->setModel(tclient.afficher_vol());
    }
    else if (arg1=="Date D'Inscription")
    {
        ui->tableView_affiche->setModel(tclient.afficher_date());
    }
}

void Ajouter_Client::on_lineEdit_cin_editingFinished()
{


}

void Ajouter_Client::on_lineEdit_id_editingFinished()
{
   /* QSqlQuery query;
    QString a;
    a=ui->lineEdit_id->text();

    query.prepare("SELECT IDENTIFIANT from client where IDENTIFIANT = :id ");
    query.bindValue(":id", a);
    query.exec();
    if(query.next())
    {
    ui->lineEdit_id->setText("exist deja ");
    ui->lineEdit_id->setStyleSheet("QLineEdit#id{color:red}");
    }
    else
    {
        ui->lineEdit_id->setText("n'exist pas");
    }*/

}

void Ajouter_Client::on_pushButton_modifier_clicked()
{
    QPalette *palette = new QPalette();
    palette->setColor(QPalette::Base,Qt::gray);
    palette->setColor(QPalette::Text,Qt::darkGray);
    QSqlQuery query;



     int  a=ui->lineEdit_iddemande->text().toInt();
     QString res=QString::number(a);
    query.prepare("select NOM,PRENOM,CIN,NATIONNALITE,DATE_NAISSANCE,CONTACT,NBVOL,IDENTIFIANT,DATE_INSCRIPTION,NBPOINTS from client WHERE IDENTIFIANT = :id");
    query.bindValue(":id",a);
   query.exec();
   if (query.next()){
        query.first();
    QString Nom = query.value(0).toString();
    QString prenom = query.value(1).toString();
    QString cin = query.value(2).toString();
    QString nat = query.value(3).toString();
    QDate dat = query.value(4).toDate();
    QString cont = query.value(5).toString();
    QString nbvol = query.value(6).toString();
    QString id = query.value(7).toString();
    QDate dati = query.value(8).toDate();
    ui->lineEdit_nom->setText(Nom);
    ui->lineEdit_prenom->setText(prenom);
    ui->lineEdit_cin->setText(cin);
    ui->lineEdit_nat->setText(nat);
    ui->dateEdit_ddn->setDate(dat);
    ui->lineEdit_contact->setText(cont);
    ui->lineEdit_nbvol->setText(nbvol);
    ui->lineEdit_id->setText(id);
    ui->dateEdit_ddi->setDate(dati);


    ui->lineEdit_nom->setReadOnly(true);
    ui->lineEdit_prenom->setReadOnly(true);
    ui->lineEdit_cin->setReadOnly(true);
    ui->lineEdit_nat->setReadOnly(true);
    ui->dateEdit_ddn->setReadOnly(true);
    ui->lineEdit_id->setReadOnly(true);
    ui->dateEdit_ddi->setReadOnly(true);


    ui->lineEdit_nom->setPalette(*palette);
    ui->lineEdit_prenom->setPalette(*palette);
    ui->lineEdit_cin->setPalette(*palette);
    ui->lineEdit_nat->setPalette(*palette);
    ui->dateEdit_ddi->setPalette(*palette);
    ui->lineEdit_id->setPalette(*palette);
    ui->dateEdit_ddn->setPalette(*palette);
}
    ui->pushButton_valider->show();
}



void Ajouter_Client::on_pushButton_valider_clicked()
{

    QPalette *palette = new QPalette();
    palette->setColor(QPalette::Base,Qt::white);
    palette->setColor(QPalette::Text,Qt::black);

    int nb = ui->lineEdit_nbvol->text().toInt();
   QString contact = ui->lineEdit_contact->text();
   int id = ui->lineEdit_iddemande->text().toInt();

    client c;

   c.modifierClient(nb,contact,id);

{
    ui->lineEdit_nom->setReadOnly(false);
    ui->lineEdit_prenom->setReadOnly(false);
    ui->lineEdit_cin->setReadOnly(false);
    ui->lineEdit_nat->setReadOnly(false);
    ui->dateEdit_ddn->setReadOnly(false);
    ui->lineEdit_id->setReadOnly(false);
    ui->dateEdit_ddi->setReadOnly(false);

    ui->lineEdit_nom->setPalette(*palette);
    ui->lineEdit_prenom->setPalette(*palette);
    ui->lineEdit_cin->setPalette(*palette);
    ui->lineEdit_nat->setPalette(*palette);
    ui->dateEdit_ddi->setPalette(*palette);
    ui->lineEdit_id->setPalette(*palette);
    ui->dateEdit_ddn->setPalette(*palette);

    ui->lineEdit_nom->setText("");
    ui->lineEdit_nbvol->setText("");
    ui->lineEdit_contact->setText("");
    ui->lineEdit_prenom->setText("");
    ui->lineEdit_cin->setText("");
    ui->lineEdit_nat->setText("");
    ui->dateEdit_ddn->setReadOnly(false);
    ui->lineEdit_id->setText("");
    ui->dateEdit_ddi->setReadOnly(false);
}
    ui->tableView_affiche->setModel(c.afficher());
    ui->pushButton_valider->hide();

}
