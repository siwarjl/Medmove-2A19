#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
<<<<<<< HEAD
<<<<<<< HEAD
#include "arduino.h"
#include "ard.h"
=======

>>>>>>> origin/gestionAmbulance
=======

>>>>>>> origin/produit
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
<<<<<<< HEAD
<<<<<<< HEAD
 void update_label();
    void on_pushButton_28_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_24_clicked();

private:
    Ui::MainWindow *ui;
    Arduino A;
    QByteArray data;
      ard temp;
=======
    void on_pushButton_8_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
>>>>>>> origin/gestionAmbulance
=======
    void on_pushButton_12_clicked();

    void on_pushButton_17_clicked();

    void on_chatbox_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
>>>>>>> origin/produit
};
#endif // MAINWINDOW_H
