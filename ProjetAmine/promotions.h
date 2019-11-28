#ifndef PROMOTIONS_H
#define PROMOTIONS_H
#include <QSqlQuery>
#include <QDialog>
#include <classprormo.h>

namespace Ui {
class promotions;
}

class promotions : public QDialog
{
    Q_OBJECT

public:
    explicit promotions(QWidget *parent = nullptr);
    ~promotions();

private slots:
    void on_pushButton_ajouterpromo_clicked();

    void on_pushButton_afficher_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_rechercherpro_clicked();

    void on_pushButton_pourmodifier_clicked();

    void on_pushButton_clicked();

    void on_pushButton_supprimerpro_clicked();

    void on_pushButton_affectepro_clicked();

private:
    Ui::promotions *ui;
    classprormo tmppromo;
};

#endif // PROMOTIONS_H
