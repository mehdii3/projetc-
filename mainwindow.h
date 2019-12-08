#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "reservation.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_tabetudiant_doubleClicked(const QModelIndex &index);

    void on_tabetudiant_activated(const QModelIndex &index);

    void on_Modifier_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_recherche_textEdited(const QString &arg1);
    void Mise_plot();


    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    reservation tmpreservation;
};

#endif // MAINWINDOW_H
