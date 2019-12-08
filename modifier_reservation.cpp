#include "modifier_reservation.h"
#include "ui_modifier_reservation.h"

modifier_reservation::modifier_reservation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifier_reservation)
{
    ui->setupUi(this);
}

modifier_reservation::~modifier_reservation()
{
    delete ui;
}
void modifier_reservation::on_buttonBox_accepted()
{
    hide();
    EspaceAdmin espaceAdmin;
    espaceAdmin.setModal(true);
    espaceAdmin.exec();
}

void modifier_reservation::on_buttonBox_rejected()
{
    hide();
    EspaceAdmin espaceAdmin;
    espaceAdmin.setModal(true);
    espaceAdmin.exec();
}
