#ifndef TACHEENG_H
#define TACHEENG_H

#include <QDialog>

namespace Ui {
class tacheeng;
}

class tacheeng : public QDialog
{
    Q_OBJECT

public:
    explicit tacheeng(QWidget *parent = nullptr);
    ~tacheeng();

private:
    Ui::tacheeng *ui;
};

#endif // TACHEENG_H
