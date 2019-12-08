#ifndef PISTE_H
#define PISTE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDialog>

class piste1
{public:
    piste1();
    piste1(QString disp,QString nom,int lonegur);
    QString get_disp();
    QString get_nom();
    int get_longeur();
    bool ajouter_piste();
    QSqlQueryModel * afficher_piste();
    bool supprimer_piste(QString);
    bool modifier_piste();

private:
    QString disp, nom;
    int longeur;

};
namespace Ui {
class piste;
}

class piste : public QDialog
{
    Q_OBJECT

public:
    explicit piste(QWidget *parent = nullptr);
    ~piste();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::piste *ui;
};

#endif // PISTE_H
