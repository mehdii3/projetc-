#ifndef MODIFIER_CLIENT_H
#define MODIFIER_CLIENT_H

#include <QDialog>

namespace Ui {
class modifier_client;
}

class modifier_client : public QDialog
{
    Q_OBJECT

public:
    explicit modifier_client(QWidget *parent = nullptr);
    ~modifier_client();

private:
    Ui::modifier_client *ui;
};

#endif // MODIFIER_CLIENT_H
