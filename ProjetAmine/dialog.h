#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);

void setnom(QString n);
    ~Dialog();



private slots:
void on_pushButton_gestionsvols_clicked();

void on_pushButton_promotions_clicked();

private:
    QPushButton *m_bouton;
    Ui::Dialog *ui;
};

#endif // DIALOG_H
