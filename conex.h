#ifndef CONEX_H
#define CONEX_H

#include <QDialog>

namespace Ui {
class conex;
}

class conex : public QDialog
{
    Q_OBJECT

public:
    explicit conex(QWidget *parent = nullptr);
    ~conex();

private:
    Ui::conex *ui;
};

#endif // CONEX_H
