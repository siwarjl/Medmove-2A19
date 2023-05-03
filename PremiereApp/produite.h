#ifndef PRODUITE_H
#define PRODUITE_H

#include <QDialog>

namespace Ui {
class produite;
}

class produite : public QDialog
{
    Q_OBJECT

public:
    explicit produite(QWidget *parent = nullptr);
    ~produite();

private:
    Ui::produite *ui;
};

#endif // PRODUITE_H
