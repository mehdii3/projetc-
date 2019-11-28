#ifndef MODIFIER_DEP_H
#define MODIFIER_DEP_H

#include <QDialog>

namespace Ui {
class modifier_dep;
}

class modifier_dep : public QDialog
{
    Q_OBJECT

public:
    explicit modifier_dep(QWidget *parent = nullptr);
    ~modifier_dep();

private slots:
    void on_pushButton_clicked();

private:
    Ui::modifier_dep *ui;
};

#endif // MODIFIER_DEP_H
