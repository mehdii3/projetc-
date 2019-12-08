#ifndef MODIFIER_RESERVATION_H
#define MODIFIER_RESERVATION_H

#include <QDialog>

namespace Ui {
class modifier_reservation;
}

class modifier_reservation : public QDialog
{
    Q_OBJECT

public:
    explicit modifier_reservation(QWidget *parent = nullptr);
    ~modifier_reservation();

private:
    Ui::modifier_reservation *ui;
};

#endif // MODIFIER_RESERVATION_H
