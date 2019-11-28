#include "recherche.h"
#include "ui_recherche.h"

recherche::recherche(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::recherche)
{
    ui->setupUi(this);
}

recherche::~recherche()
{
    delete ui;
}

/*void recherche::on_lineEdit_textChanged(const QString &arg1)
{

}*/

void recherche::on_pushButton_recherche_clicked()
{
QString reference=ui->lineEdit_rechercher->text();
ui->tableView->setModel(tmpavion.recherche(reference));
}
