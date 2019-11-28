#ifndef SER_H
#define SER_H

#include <QWidget>

namespace Ui {
class ser;
}

class ser : public QWidget
{
    Q_OBJECT

public:
    explicit ser(QWidget *parent = nullptr);
    ~ser();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ser *ui;
};

#endif // SER_H
