#ifndef DUMESSENGERSOCKET_H
#define DUMESSENGERSOCKET_H
#include <QTcpSocket>
namespace DuarteCorporation{

class DuMessengerSocket : public QTcpSocket
{
    Q_OBJECT
public:
    DuMessengerSocket(qintptr handle, QObject *parent =nullptr );
  //  ~DuMessengerSocket();
signals:
    void DuReadyRead(DuMessengerSocket *);
    void DustateChanged(DuMessengerSocket * , int);
};}

#endif // DUMESSENGERSOCKET_H
