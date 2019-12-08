#ifndef CRUD_H
#define CRUD_H
#include <QDialog>
#include <QObject>

namespace Ui {
class crud;
}

class crud : public QDialog
{
    Q_OBJECT

public:
    explicit crud(QWidget *parent = nullptr);
    ~crud();

public slots:
    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_5_clicked();


   // void on_tableView_activated(const QModelIndex &index);

private:
    Ui::crud *ui;


};

#endif // CRUD_H
