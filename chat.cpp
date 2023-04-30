#include "chat.h"
#include "ui_chat.h"
#include <QTcpSocket>
#include "dumessengerconnectiondialog.h"
#include<QTextStream>
namespace DuarteCorporation {
chat::chat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chat)
{
    ui->setupUi(this);
    mSocket = new QTcpSocket(this);
    connect(mSocket, &QTcpSocket::readyRead, [&](){
      QTextStream T(mSocket);
      auto text = T.readAll();
              ui->textEdit->append(text);
    });}

chat::~chat()
{
    delete ui;
}




}
void DuarteCorporation::chat::on_sent_clicked()
{
    QTextStream T(mSocket);
    T<< ui->name->text()<<": "<<ui->message->text();
    mSocket->flush();
    ui->message->clear();
}

void DuarteCorporation::chat::on_bind_clicked()
{
    DUMessengerConnectionDialog D (this);
  if (D.exec()==QDialog::Rejected) {
      return;
  }
  mSocket->connectToHost(D.hostname(),D.port());
}
