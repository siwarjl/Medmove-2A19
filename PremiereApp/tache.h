#ifndef TACHE_H
#define TACHE_H

#include <QDialog>

namespace Ui {
class tache;
}

class tache : public QDialog
{
    Q_OBJECT

public:
    explicit tache(QWidget *parent = nullptr);
    ~tache();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_produit_2_clicked();

    void on_pushButton_employees_4_clicked();

    void on_pushButton_employees_clicked();

    void on_pushButton_client_2_clicked();

private:
    Ui::tache *ui;
};

#endif // TACHE_H
