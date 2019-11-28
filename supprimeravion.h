#ifndef SUPPRIMERAVION_H
#define SUPPRIMERAVION_H

#include <QDialog>

namespace Ui {
class SupprimerAvion;
}

class SupprimerAvion : public QDialog
{
    Q_OBJECT

public:
    explicit SupprimerAvion(QWidget *parent = nullptr);
    ~SupprimerAvion();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SupprimerAvion *ui;
};

#endif // SUPPRIMERAVION_H
