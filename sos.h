#ifndef SOS_H
#define SOS_H
#include"widget.h"
#include"ser.h"

#include <QWidget>

namespace Ui {
class sos;
}

class sos : public QWidget
{
    Q_OBJECT

public:
    explicit sos(QWidget *parent = nullptr);
    ~sos();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::sos *ui;
    Widget widget ;
    ser ser;
};

#endif // SOS_H
