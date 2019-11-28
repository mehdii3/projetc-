#ifndef RECLAMATION_H
#define RECLAMATION_H
#include<QDate>
#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>

namespace Ui {
class reclamation;
}

class reclamation : public QDialog
{
    Q_OBJECT



public:
    explicit reclamation(QWidget *parent = nullptr);
    ~reclamation();

private slots:
    void on_ajouter_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_valider_clicked();

private:
    Ui::reclamation *ui;
};

class reclamation1
{
private :
    QString titre;
    QString idClient;
    QString idReclamation;
    QString text;
    QDate date_reclamation;

public :
    reclamation1(QString titre,QString idClient,QString idReclamation,QString text,QDate date_reclamation);
    reclamation1(){}
    bool ajouterReclamation();
    QSqlQueryModel * afficherReclamation ();
    QSqlQueryModel * afficherid ();
    bool modifierReclamation (QString,QString);


};

#endif // RECLAMATION_H
