#ifndef AUTH_H
#define AUTH_H
#include "employec.h"
#include "employe.h"

#include <QDialog>
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QMessageBox>
#include<QDebug>


namespace Ui {
class auth;
}

class auth : public QDialog
{
    Q_OBJECT

public:
    explicit auth(QWidget *parent = nullptr);
    ~auth();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_11_clicked();

private:
    Ui::auth *ui;
};

#endif // AUTH_H
