#ifndef CHATBOX_H
#define CHATBOX_H

#include <QDialog>
QT_BEGIN_NAMESPACE
namespace Ui {
class chatbox;
}
QT_END_NAMESPACE
class QTcpSocket;
namespace DuarteCorporation {

class chatbox : public QDialog
{
    Q_OBJECT

public:
    explicit chatbox(QWidget *parent = nullptr);
    ~chatbox();
private slots:
    void on_sent_clicked();
    void on_appeler_clicked();
    void on_audio_data_received(QByteArray audioData);
    void on_call_socket_readyRead();

    void on_bind_clicked();
private:
    Ui::chatbox *ui;
    QTcpSocket *mSocket;
    QTcpSocket* mCallSocket;

    QTcpSocket* mStream;

};}

#endif // CHATBOX_H
