#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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


    void on_ajouter_clicked();

    void on_modifier_clicked();

    void on_supprimer_clicked();

    void on_afficher_clicked();

    void on_pushButton_6_clicked();

    void on_trier_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_gererdepot_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
