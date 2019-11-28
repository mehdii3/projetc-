#ifndef AFFICHER_DEP_H
#define AFFICHER_DEP_H

#include <QDialog>

namespace Ui {
class afficher_dep;
}

class afficher_dep : public QDialog
{
    Q_OBJECT

public:
    explicit afficher_dep(QWidget *parent = nullptr);
    ~afficher_dep();

private:
    Ui::afficher_dep *ui;
};

#endif // AFFICHER_DEP_H
