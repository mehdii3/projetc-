#ifndef CLASSPRORMO_H
#define CLASSPRORMO_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QDate>
#include <QMessageBox>
class classprormo
{
protected:
    QString id;
    QDate datedebut;
    QDate datefin;
    float taux;
public:
    classprormo();
    classprormo(QString id,QDate datedebut,QDate datefin,float taux);
    bool ajouter_promo();
    QSqlQueryModel * afficher();
    QSqlQueryModel * recherche(QString id);
    bool modifier(QString id);
    bool supprimer(QString idd);
};

#endif // CLASSPRORMO_H
