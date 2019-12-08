#ifndef AVION_H
#define AVION_H
#include <QMainWindow>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QPrinter>
#include<QFileDialog>
#include <QTextDocument>
#include  "crud.h"
#include<QPushButton>

//#include "piste.h"
class Avion
{public:
    Avion();
    Avion(QString Reference,QString type,QString etat,QString etat_reservoir,QDate date_premiere_sortie,int nbr_passagers,int distance_franchissable,int vitesse_croisiere);
    QString get_Reference();
    QString get_type();
    QString get_etat_reservoir();
    QString get_etat();
    QDate get_date_premiere_sortie();
    int get_nbr_passagers();
    int get_distance_franchissable();
    bool ajouter();
    int get_vitesse_croisiere();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool modifier();
    QSqlQueryModel * Tri();
    QSqlQueryModel* recherche(QString reference);

    //void makePlot();


private:
    QString Reference, type, etat, etat_reservoir;
    QDate date_premiere_sortie;
    int nbr_passagers,distance_franchissable;
    int vitesse_croisiere;
};
namespace Ui {
class avion;
}

class avion : public QMainWindow
{
    Q_OBJECT

public:
    explicit avion(QWidget *parent = nullptr);
    ~avion();



private slots:

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::avion *ui;
   // crud *c;


};

#endif // AVION_H
