#ifndef AFFICHE_CLIENT_H
#define AFFICHE_CLIENT_H
#include "client.h"
#include <QDialog>

namespace Ui {
class affiche_client;
}

class affiche_client : public QDialog
{
    Q_OBJECT

public:
    explicit affiche_client(QWidget *parent = nullptr);
    ~affiche_client();

private slots:
    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_rechercher_clicked();

    void on_tableView_viewportEntered();

private:
    Ui::affiche_client *ui;
    //client tclient;
};

#endif // AFFICHE_CLIENT_H
