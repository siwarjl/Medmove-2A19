#ifndef LOCALISATION_H
#define LOCALISATION_H

#include <QDialog>
#include <QSettings>
//#include "mapping.h"

namespace Ui {
class localisation;
}

class localisation : public QDialog
{
    Q_OBJECT

public:
    explicit localisation(QWidget *parent = nullptr);
    ~localisation();
    void map();

private slots:
    void on_pushButton_26_clicked();

private:
    Ui::localisation *ui;
};

#endif // LOCALISATION_H
