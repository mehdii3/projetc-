#include "mail.h"
#include "ui_mail.h"

mail::mail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mail)
{
    ui->setupUi(this);
    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
}

mail::~mail()
{
    delete ui;
}
void mail::sendMail()
{
    Smtp* smtp = new Smtp("maryem.bessrour@esprit.tn","holapepsicola", "smtp.gmail.com",465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail("maryem.bessrour@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void mail::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}
