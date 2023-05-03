#include "dumessengersocket.h"
namespace DuarteCorporation{

DuMessengerSocket::DuMessengerSocket(qintptr handle, QObject *parent)
  : QTcpSocket(parent)
{
setSocketDescriptor(handle);
connect(this,&DuMessengerSocket::readyRead, [&](){
    emit DuReadyRead(this) ;
});
connect(this, &DuMessengerSocket::stateChanged, [&](int s)
{
    emit DustateChanged(this, s);
});
}}
