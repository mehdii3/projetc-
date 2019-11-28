#ifndef VOL_H
#define VOL_H
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QDate>
#include <QMessageBox>


class vol
{
protected:
        QString id;
        float duree;
        int etat;
        QString destination;
        int nb_place;
        float prix;
        QString depart;
        QDate date;



public:
    vol();
    vol(QString id){this->id=id;}
    vol(QString,float,QString,QString,int,float,QDate,int);
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher2(QString idd);
    QString get_id(){return this->id;}
    float get_duree(){return this->duree;}
    bool get_etat(){return this->etat;}
    QString get_destination(){return this->destination;}
    int get_nbplace(){return this->nb_place;}
    float get_prix(){return this->prix;}
    bool supprimer(QString idd);

    bool ajouter_vol();
    bool modifier(QString);
     bool modifier2(QString);

};

#endif // VOL_H
