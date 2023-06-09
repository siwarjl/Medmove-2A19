#ifndef EMPLOYE_H
#define EMPLOYE_H
#include "employec.h"
#include "localisation.h"

#include <QDialog>

namespace Ui {
class employe;
}

class employe : public QDialog
{
    Q_OBJECT

public:
    explicit employe(QWidget *parent = nullptr);
    ~employe();

private slots:
    void on_pushButton_9_clicked();

    void on_pushButton_44_clicked();

    void on_pushButton_45_clicked();

    void on_pushButton_46_clicked();

    void on_pushButton_8_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_pushButton_17_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_29_clicked();

    void on_view_activated(const QModelIndex &index);

    void on_pushButton_11_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_12_clicked();

    void on_recherche_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_15_clicked();


    void on_pb_statistique_2_clicked();

    void on_local_clicked();

    void on_pdf2_clicked();

private:
    Ui::employe *ui;
    employec e;
    localisation *l;
};

#endif // EMPLOYE_H
