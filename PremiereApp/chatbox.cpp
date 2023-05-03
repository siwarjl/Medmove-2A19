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
void DuarteCorporation::chatbox::on_appeler_clicked()
{
    // Créez un nouveau socket TCP
    mCallSocket = new QTcpSocket(this);

    // Connectez-vous à l'adresse IP de l'autre utilisateur
    QString ipAddress = "192.168.1.124"; // Adresse IP de l'autre utilisateur
    quint16 port = 12345; // Port à utiliser pour l'appel
    mCallSocket->connectToHost(ipAddress, port);

    // Vérifiez si la connexion a réussi
    if (!mCallSocket->waitForConnected()) {
        // Afficher un message d'erreur si la connexion a échoué
        ui->textEdit->append("Impossible de se connecter à l'autre utilisateur.");
        delete mCallSocket;
        mCallSocket = nullptr;
        return;
    }

    // La connexion a réussi, affichez un message indiquant que l'appel est lancé
    ui->textEdit->append("Appel en cours...");
}
void DuarteCorporation::chatbox::on_audio_data_received(QByteArray audioData)
{
    // Vérifiez si le socket est connecté
    if (!mCallSocket || !mCallSocket->isOpen()) {
        return;
    }

    // Envoyer les données audio via le socket
    mCallSocket->write(audioData);
}
void DuarteCorporation::chatbox::on_call_socket_readyRead()
{
    // Lire les données audio/vidéo à partir du socket et les décode
    QByteArray audioData = mCallSocket->readAll();

    // Traiter les données audio/vidéo reçues
    // ...
}
