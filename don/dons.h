#ifndef DONS_H
#define DONS_H

#include <QDialog>
#include "donc.h"

namespace Ui {
class Dons;
}

class Dons : public QDialog
{
    Q_OBJECT

public:
    explicit Dons(QWidget *parent = nullptr);
    ~Dons();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_33_clicked();

    void on_ajout_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_28_clicked();

    void on_view_activated(const QModelIndex &index);

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_37_clicked();

    void on_recherche_cursorPositionChanged(int arg1, int arg2);

    void on_calendarWidget_clicked(const QDate &date);

private:
    Ui::Dons *ui;
    donc d;
};

#endif // DONS_H
