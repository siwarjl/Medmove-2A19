#ifndef PRODUITANG_H
#define PRODUITANG_H

#include <QDialog>
#include"produitc.h"

namespace Ui {
class produitang;
}

class produitang : public QDialog
{
    Q_OBJECT

public:
    explicit produitang(QWidget *parent = nullptr);
    ~produitang();

private slots:
    void on_pushButton_27_clicked();

    void on_ajout_clicked();

    void on_ajout_3_clicked();

    void on_ajout_4_clicked();

    void on_view_activated(const QModelIndex &index);

    void on_pushButton_13_clicked();

    void on_pushButton_17_clicked();

    void on_label1_linkActivated(const QString &link);

    void on_pushButton_26_clicked();

private:
    Ui::produitang *ui;
     produitc p1;
};

#endif // PRODUITANG_H
