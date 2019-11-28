#ifndef AJOUTAVION_H
#define AJOUTAVION_H
#include <QDialog>

namespace Ui {
class AjoutAvion;
}


class AjoutAvion : public QDialog
{
    Q_OBJECT

public:
    explicit AjoutAvion(QWidget *parent = nullptr);
    ~AjoutAvion();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AjoutAvion *ui;

};

#endif // AJOUTAVION_H
