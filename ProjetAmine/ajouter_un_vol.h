#ifndef AJOUTER_UN_VOL_H
#define AJOUTER_UN_VOL_H
#include <vol.h>

#include <QDialog>

namespace Ui {
class ajouter_un_vol;
}

class ajouter_un_vol : public QDialog
{
    Q_OBJECT

public:
    explicit ajouter_un_vol(QWidget *parent = nullptr);
    ~ajouter_un_vol();

private slots:
    void on_pushButton_ajouter_clicked();

private:
    Ui::ajouter_un_vol *ui;
};

#endif // AJOUTER_UN_VOL_H
