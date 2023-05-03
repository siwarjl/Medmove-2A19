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
<<<<<<< HEAD
<<<<<<< HEAD
    void on_pushButton_clicked();

    void on_pushButton_employees_4_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::tache *ui;
=======
    void on_pushButton_employees_2_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::tache *ui;

>>>>>>> origin/gestionAmbulance
=======
    void on_pushButton_5_clicked();

    void on_pushButton_produit_2_clicked();

    void on_pushButton_employees_4_clicked();

private:
    Ui::tache *ui;
>>>>>>> origin/produit
};

#endif // TACHE_H
