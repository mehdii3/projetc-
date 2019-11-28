#ifndef FIDEL_H
#define FIDEL_H
#include "client.h"
#include <QDialog>

namespace Ui {
class fidel;
}

class fidel : public QDialog
{
    Q_OBJECT

public:
    explicit fidel(QWidget *parent = nullptr);
    ~fidel();

private:
    Ui::fidel *ui;
};

class clientFidel : protected client

{
public:
    void afficher();
};

#endif // FIDEL_H
