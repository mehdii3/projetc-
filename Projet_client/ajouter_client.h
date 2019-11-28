#ifndef AJOUTER_CLIENT_H
#define AJOUTER_CLIENT_H
#include "client.h"
#include <QDialog>

namespace Ui {
class Ajouter_Client;
}

class Ajouter_Client : public QDialog
{
    Q_OBJECT

public:
    explicit Ajouter_Client(QWidget *parent = nullptr);
    ~Ajouter_Client();

private slots:
    void on_pushButton_clicked();



    void on_buttonBox_accepted();

    void on_pushButton_2_clicked();

    void on_pushButton_recherche_clicked();

    void on_pushButton_supprimer_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_lineEdit_cin_editingFinished();

    void on_lineEdit_id_editingFinished();

    void on_pushButton_modifier_clicked();

    void on_valider_clicked();

    void on_pushButton_valider_clicked();

private:
    Ui::Ajouter_Client *ui;

};

#endif // AJOUTER_CLIENT_H
