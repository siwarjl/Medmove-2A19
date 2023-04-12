#ifndef CLIENT_H
#define CLIENT_H
#include "patient.h"
#include <QDialog>

namespace Ui {
class client;
}

class client : public QDialog
{
    Q_OBJECT

public:
    explicit client(QWidget *parent = nullptr);
    ~client();

private slots:
    void on_pushButton_14_clicked();

    void on_pushButton_33_clicked();



    void on_liste_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_40_clicked();

    void on_pushButton_41_clicked();

    void on_liste_activated(const QModelIndex &index);

    void on_recherche_cursorPositionChanged(int arg1, int arg2);

    void on_tri_clicked();

    void on_pushButton_37_clicked();

    void on_pushButton_39_clicked();

    void on_pb_statistique_2_clicked();


    void on_pushButton_38_clicked();

    void on_email_clicked();

    void on_tri_2_clicked();

    void on_statistique_clicked();

    void on_pushButton_42_clicked();
void sendMail();
void mailSent(QString status);
void browse();

private:
    Ui::client *ui;
    patient p1;
     QStringList files;
};

#endif // CLIENT_H
