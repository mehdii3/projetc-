#ifndef AFFICHER_VOLS_H
#define AFFICHER_VOLS_H
#include "vol.h"

#include <QDialog>

namespace Ui {
class afficher_vols;
}

class afficher_vols : public QDialog
{
    Q_OBJECT

public:
    explicit afficher_vols(QWidget *parent = nullptr);
    ~afficher_vols();

private slots:
    void on_pushButton_afficher_clicked();

    void on_Supprimer_clicked();

    void on_pushButton_rechercher_clicked();





    void on_comboBox_activated(const QString &arg1);


private:
    Ui::afficher_vols *ui;
    vol tmpvol;
};

#endif // AFFICHER_VOLS_H
