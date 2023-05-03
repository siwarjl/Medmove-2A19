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

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_produit_2_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

private:
    Ui::tacheeng *ui;
};

#endif // TACHEENG_H
