#include "server.h"
#include "ui_server.h"

Server::Server(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::Server)
    , mp_server(new QTcpServer)
    , mp_socket(nullptr)
{
    ui->setupUi(this);
    enumIPAddress();

    connect(mp_server, &QTcpServer::newConnection, this, &Server::newConnectionSlot);
}

Server::~Server()
{
    delete mp_server;
    delete ui;
}

void Server::on_pushButton_listen_clicked()
{
    QString ip = ui->comboBox->currentText();
    quint16 port = ui->spinBox->text().toUInt();

    // the server is listening
    if (mp_server->isListening()) {
        mp_server->close();

        for (int i = 0; i < m_clientList.size();) {
            m_clientList[i]->abort();
        }

        ui->pushButton_listen->setText("LISTEN");
        ui->comboBox->setEnabled(true);
        ui->spinBox->setEnabled(true);
    } else {
        if (mp_server->listen(QHostAddress(ip), port)) {
            ui->pushButton_listen->setText("STOP LISTENNING");
            ui->comboBox->setEnabled(false);
            ui->spinBox->setEnabled(false);
        } else
            QMessageBox::critical(this, "Failure", mp_server->errorString());
    }
}

void Server::newConnectionSlot()
{
    // update the m_clientList
    mp_socket = mp_server->nextPendingConnection();
    m_clientList.append(mp_socket);

    QString port = QString::number(mp_socket->peerPort()),
            message = port + " has joint the chatting room";

    // update the server's listWidget_message and listWidget_client
    ui->listWidget_client->addItem(port);
    ui->listWidget_message->addItem(
        QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")
        + '\n' + message);

    // send the port message to the client that just joint
    mp_socket->write(QString("Port" + port).toLocal8Bit());

    // send the new client message to other clients
    for (int i = 0; i < m_clientList.size() - 1; ++i) {
        if (m_clientList[i]->isWritable()) {
            m_clientList[i]->write(message.toLocal8Bit());
        }
    }

    connect(mp_socket, &QTcpSocket::readyRead, this, &Server::readyReadSlot);
    connect(mp_socket, &QTcpSocket::disconnected, this, &Server::disconnectedSlot);
}

void Server::readyReadSlot()
{
    QByteArray data;
    QTcpSocket* current_client = nullptr;

    // receive just sent message
    for (int i = 0; i < m_clientList.size(); ++i) {
        if (m_clientList[i]->isReadable()) {
            current_client = m_clientList[i];
            data = current_client->readAll();
            if (data.isEmpty())
                continue;
            break;
        }
    }
    QString message = QString::number(current_client->peerPort())
        + ": " + QString::fromLocal8Bit(data);

    // update the server's listWidget_message
    ui->listWidget_message->addItem(
        QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")
        + '\n' + message);

    // send the message to other clients
    for (int i = 0; i < m_clientList.size(); ++i) {
        if (m_clientList[i] != current_client) {
            if (m_clientList[i]->isWritable()) {
                m_clientList[i]->write(message.toLocal8Bit());
            }
        }
    }
}

void Server::disconnectedSlot()
{
    QTcpSocket* left_client = nullptr;

    // find out who have just left
    for (int i = 0; i < m_clientList.size(); ++i) {
        if (m_clientList[i]->state() != QAbstractSocket::ConnectedState) {
            left_client = m_clientList[i];
            break;
        }
    }

    // delete the client that just left
    m_clientList.removeAll(left_client);

    QString port = QString::number(left_client->peerPort()),
            message = port + " has left the chatting room";

    // send the left client message to other clients
    for (int i = 0; i < m_clientList.size(); ++i) {
        if (m_clientList[i]->isWritable()) {
            m_clientList[i]->write(message.toLocal8Bit());
        }
    }

    // update the server's listWidget_message and listWidget_client
    ui->listWidget_message->addItem(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")
        + '\n' + message);
    ui->listWidget_client->clear();
    for (int i = 0; i < m_clientList.size(); ++i) {
        ui->listWidget_client->addItem(QString::number(m_clientList[i]->peerPort()));
    }
}

void Server::enumIPAddress()
{
    QList<QHostAddress> ipList = QNetworkInterface::allAddresses();
    QStringList ipStringList;

    for (int i = 0; i < ipList.size(); ++i) {
        // only IPv4 addresses
        QAbstractSocket::NetworkLayerProtocol protocol = ipList[i].protocol();
        if (QAbstractSocket::IPv4Protocol == protocol)
            ipStringList.append(ipList[i].toString());
    }

    ui->comboBox->addItems(ipStringList);
}
