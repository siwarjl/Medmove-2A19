#include "chatbox.h"
#include "ui_chatbox.h"
#include <QTcpSocket>
#include "dumessengerconnectiondialog.h"
#include<QTextStream>
namespace DuarteCorporation {
chatbox::chatbox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chatbox)
{
    ui->setupUi(this);
    mSocket = new QTcpSocket(this);
    connect(mSocket, &QTcpSocket::readyRead, [&](){
      QTextStream T(mSocket);
      auto text = T.readAll();
              ui->textEdit->append(text);
    });
}

chatbox::~chatbox()
{
    delete ui;
}

void DuarteCorporation::chatbox::on_sent_clicked()
{
    QTextStream T(mSocket);
    T<< ui->name->text()<<": "<<ui->message->text();
    mSocket->flush();
    ui->message->clear();
}


void DuarteCorporation::chatbox::on_bind_clicked()
{
    DUMessengerConnectionDialog D (this);
  if (D.exec()==QDialog::Rejected) {
      return;
  }
  mSocket->connectToHost(D.hostname(),D.port());
}
}
