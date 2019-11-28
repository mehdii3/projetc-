#ifndef TRI_H
#define TRI_H

#include <QDialog>
#include <QSqlQuery>
namespace Ui {
class tri;
}

class tri : public QDialog
{
    Q_OBJECT

public:
    explicit tri(QWidget *parent = nullptr);
    ~tri();

private slots:
    void on_comboBox_activated(const QString &arg1);

private:
    Ui::tri *ui;
};

#endif // TRI_H
