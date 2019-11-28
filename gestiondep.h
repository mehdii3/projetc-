#ifndef GESTIONDEP_H
#define GESTIONDEP_H

#include <QDialog>

namespace Ui {
class gestiondep;
}

class gestiondep : public QDialog
{
    Q_OBJECT

public:
    explicit gestiondep(QWidget *parent = nullptr);
    ~gestiondep();

private slots:
    void on_pushButton_clicked();

    void on_ajouterdep_clicked();

private:
    Ui::gestiondep *ui;
};

#endif // GESTIONDEP_H
