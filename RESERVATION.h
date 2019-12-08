#ifndef RESERVATION_H
#define RESERVATION_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class reservation
{public:
    reservation();
    reservation(int,QString,QString,QString,QString,QString);
    QString get_nom();
    QString get_prenom();
     QString get_date_depart();
      QString get_date_retour();
       QString get_destination();

    int get_id();
    bool ajouter();
    bool modifier();
    QSqlQueryModel * afficher();
     QSqlQueryModel * afficherParDestination(QString destination);
    bool supprimer(int);
    int conteur();

private:
    QString nom,prenom,date_depart,date_retour,destination;
    int id;
};

#endif //RESERVATION_H
