#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <vector>

class client
{
protected:
    QString nom;
    QString prenom;
    int CIN;
    QString nationnalite;
    QDate date_naissance;
    QString contact;
    int nbVol;
    int identifiant;
    QDate date_inscription;
    int nbpoints;
public:
    client();
    client(QString nom,QString prenom,int CIN,QString nationnalite,QDate date_naissace,QString contact,int nbvol,int identifiant,QDate date_inscription,int nbpoints);
    bool ajouterClient();
    bool supprimer(QString idd);
    QSqlQueryModel * afficher_id(QString idd);
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher_Alph();
    QSqlQueryModel * afficher_id();
    QSqlQueryModel * afficher_date();
    QSqlQueryModel * afficher_vol();
    QString getNom() {return(nom);}
    QString getPrenom(){return(prenom);}
    int getNbpoints(){return nbpoints;}
    int getCin(){return(CIN);}
    QString getNat(){return(nationnalite);}
    QDate getNaissance(){return(date_naissance);}
    QString getContact(){return(contact);}
    int getNbVol(){return nbVol;}
    int getId(){return identifiant;}
    QDate getInscription(){return date_inscription;}
    void setNom(QString nom){this->nom=nom;}
    void setPrenom(QString prenom){this->prenom=prenom;}

    bool modifierClient(int nbvol,QString contact,int id);
};




#endif // CLIENT_H
