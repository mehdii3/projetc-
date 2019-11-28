#include "sos.h"
#include "ui_sos.h"
#include"widget.h"
#include"ser.h"



sos::sos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sos)
{
    ui->setupUi(this);
}

sos::~sos()
{
    delete ui;
}







void sos::on_pushButton_clicked()
{

widget.show();


}

void sos::on_pushButton_2_clicked()
{
    ser.show();

}
