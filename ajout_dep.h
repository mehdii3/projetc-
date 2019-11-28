#ifndef AJOUT_DEP_H
#define AJOUT_DEP_H

#include <QDialog>

namespace Ui {
class ajout_dep;
}

class ajout_dep : public QDialog
{
    Q_OBJECT

public:
    explicit ajout_dep(QWidget *parent = nullptr);
    ~ajout_dep();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ajout_dep *ui;
};

#endif // AJOUT_DEP_H
