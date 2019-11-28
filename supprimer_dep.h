#ifndef SUPPRIMER_DEP_H
#define SUPPRIMER_DEP_H

#include <QDialog>

namespace Ui {
class supprimer_dep;
}

class supprimer_dep : public QDialog
{
    Q_OBJECT

public:
    explicit supprimer_dep(QWidget *parent = nullptr);
    ~supprimer_dep();

private slots:
    void on_pushButton_clicked();

private:
    Ui::supprimer_dep *ui;
};

#endif // SUPPRIMER_DEP_H
