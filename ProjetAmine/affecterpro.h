#ifndef AFFECTERPRO_H
#define AFFECTERPRO_H

#include <QDialog>

namespace Ui {
class affecterpro;
}

class affecterpro : public QDialog
{
    Q_OBJECT

public:
    explicit affecterpro(QWidget *parent = nullptr);
    ~affecterpro();

private slots:
    void on_pushButton_afficherliste_clicked();

    void on_pushButton_affecter_clicked();

private:
    Ui::affecterpro *ui;
};

#endif // AFFECTERPRO_H
