#ifndef RECHERCHE_H
#define RECHERCHE_H
#include "avion.h"

#include <QDialog>

namespace Ui {
class recherche;
}

class recherche : public QDialog
{
    Q_OBJECT

public:
    explicit recherche(QWidget *parent = nullptr);
    ~recherche();

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_recherche_clicked();

private:
    Ui::recherche *ui;
    Avion tmpavion;
};

#endif // RECHERCHE_H
