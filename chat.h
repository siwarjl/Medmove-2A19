#ifndef CHAT_H
#define CHAT_H

#include <QWidget>
QT_BEGIN_NAMESPACE
namespace Ui {
class chat;
}
QT_END_NAMESPACE
class QTcpSocket;
namespace DuarteCorporation {

class chat : public QWidget
{
    Q_OBJECT

public:
   // explicit chat(QWidget *parent = nullptr);
    chat(QWidget *parent = nullptr);
    ~chat();
private slots:
    void on_sent_clicked();

    void on_bind_clicked();
private:
    Ui::chat *ui;
    QTcpSocket *mSocket;

};
}
#endif // CHAT_H
