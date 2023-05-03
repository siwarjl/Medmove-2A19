#ifndef DUMESSENGERCONNECTIONDIALOG_H
#define DUMESSENGERCONNECTIONDIALOG_H
#include <QTcpSocket>
#include <QDialog>


namespace Ui {
class DUMessengerConnectionDialog;
}
namespace DuarteCorporation {


class DUMessengerConnectionDialog : public QDialog
{
    Q_OBJECT

public:

    explicit DUMessengerConnectionDialog(QDialog *parent = nullptr);
    ~DUMessengerConnectionDialog();
//QString hostname () const;
//quint16 port() const;
private slots:
    void on_ok_clicked();

    void on_cancel_clicked();

public:
    Ui::DUMessengerConnectionDialog *ui;

QString mHostname;
    quint16 mPort;
    inline QString hostname() const {
        return mHostname;
    }
   inline quint16 port() const {
        return mPort;
    }
};}


#endif // DUMESSENGERCONNECTIONDIALOG_H
