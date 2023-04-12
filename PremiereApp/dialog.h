#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QFileDialog>




namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void sendMail();
    void mailSent(QString);
    void browse();

    void on_browse_clicked();

    void on_envoyer_clicked();

private:
    Ui::Dialog *ui;
    QStringList files;
};

#endif // DIALOG_H
