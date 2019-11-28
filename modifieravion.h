#ifndef MODIFIERAVION_H
#define MODIFIERAVION_H

#include <QDialog>

namespace Ui {
class ModifierAvion;
}

class ModifierAvion : public QDialog
{
    Q_OBJECT

public:
    explicit ModifierAvion(QWidget *parent = nullptr);
    ~ModifierAvion();

private slots:
    void on_lineEdit_5_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ModifierAvion *ui;
};

#endif // MODIFIERAVION_H
