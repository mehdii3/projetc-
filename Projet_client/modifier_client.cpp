#include "modifier_client.h"
#include "ui_modifier_client.h"

modifier_client::modifier_client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifier_client)
{
    ui->setupUi(this);
}

modifier_client::~modifier_client()
{
    delete ui;
}
