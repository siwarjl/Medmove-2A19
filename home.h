#ifndef HOME_H
#define HOME_H

#include <QDialog>

namespace Ui {
class home;
}

class home : public QDialog
{
    Q_OBJECT

public:
    explicit home(QWidget *parent = nullptr);
    ~home();

private slots:
    void on_pushButton_16_clicked();

    void on_pushButton_12_clicked();

private:
    Ui::home *ui;
};

#endif // HOME_H
