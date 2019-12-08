#ifndef DEP_H
#define DEP_H
#include <QSqlQueryModel>
#include <QString>
#include <QSqlQuery>
#include <QDialog>

class depot1
{public:
    depot1();
    depot1(QString Ref,QString nom,int cap_max);
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
namespace Ui {
class dep;
}

class dep : public QDialog
{
    Q_OBJECT

public:
    explicit dep(QWidget *parent = nullptr);
    ~dep();

public slots:
    void on_pushButton_clicked();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::dep *ui;
};

#endif // DEP_H
