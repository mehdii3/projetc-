#ifndef GESTION_CLIENT_H
#define GESTION_CLIENT_H

#include <QDialog>

namespace Ui {
class Gestion_client;
}

class Gestion_client : public QDialog
{
    Q_OBJECT

public:
    explicit Gestion_client(QWidget *parent = nullptr);
    ~Gestion_client();

private slots:
    void on_pushButton_clicked();

    void on_commandLinkButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Gestion_client *ui;
};

#endif // GESTION_CLIENT_H
