#include "dumessengerserver.h"
#include "dumessengersocket.h"
#include <QDebug>
#include <QTextStream>
namespace DuarteCorporation{

DuMessengerServer::DuMessengerServer(QObject *parent)
    :QTcpServer(parent)
{

}
bool DuMessengerServer::startServer(qint16 port)
{
    return listen(QHostAddress::Any, port);

}

void DuMessengerServer::incomingConnection(qintptr handle)

{
  qDebug()<<"client connected with handle:"<<handle;
    auto socket = new DuMessengerSocket(handle , this);
    mSockets << socket;
    for (auto stocket : mSockets){
      QTextStream T(stocket);
      T<< "se ha connectado:"<< handle;
      stocket->flush();
    }
    connect(socket, &DuMessengerSocket::DuReadyRead, [&](DuMessengerSocket *S)
    {
        qDebug() << "DuReqdyRead";
        QTextStream T(S);
        auto text = T.readAll();
        for (auto socket : mSockets) {
            QTextStream K(socket);
            K << text;
            socket->flush();
        }
   }  );
    connect(socket, &DuMessengerSocket::DustateChanged,
            [&](DuMessengerSocket *S, int ST) {
        qDebug() << "DuStateChanged with handle :"
                 <<S->socketDescriptor();
     if (ST == QTcpSocket::UnconnectedState){
                    qDebug() << "Unconnected state with handle"
                             <<S->socketDescriptor();

       mSockets.removeOne(S);
       for (auto socket : mSockets) {
           QTextStream k(socket);
           k<<"Server:El cliente"
           <<S->socketDescriptor()
           <<"se ha desconectado...";
           socket->flush();
       }
     }

});
}}
