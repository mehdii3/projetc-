#ifndef AFFICHERAVION_H
#define AFFICHERAVION_H

#include <QDialog>
#include "avion.h"
namespace Ui {
class AfficherAvion;
}

class AfficherAvion : public QDialog
{
    Q_OBJECT

public:
    explicit AfficherAvion(QWidget *parent = nullptr);
    ~AfficherAvion();

private:
    Ui::AfficherAvion *ui;
    Avion tmptable;
};

#endif // AFFICHERAVION_H
