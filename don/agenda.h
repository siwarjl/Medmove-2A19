#ifndef AGENDA_H
#define AGENDA_H

#include <QDialog>

namespace Ui {
class agenda;
}

class agenda : public QDialog
{
    Q_OBJECT

public:
    explicit agenda(QWidget *parent = nullptr);
    ~agenda();

private:
    Ui::agenda *ui;
};

#endif // AGENDA_H
