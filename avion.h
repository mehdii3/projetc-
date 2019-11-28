#ifndef AVION_H
#define AVION_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

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

private:
    QString Reference, type, etat, etat_reservoir;
    QDate date_premiere_sortie;
    int nbr_passagers,distance_franchissable;
    int vitesse_croisiere;

};

class depot
{public:
    depot();
    depot(QString Ref,QString nom,int cap_max);
    QString get_Ref();
    QString get_nom();
    int get_cap_max();
    bool ajouter_dep();
    QSqlQueryModel * afficher_dep();
    bool supprimer_dep(QString);
    bool modifier_dep();

private:
    QString Ref, nom;
    int cap_max;

};


#endif // AVION_H
