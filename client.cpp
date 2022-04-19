#include "client.h"
#include "ui_client.h"

Client::Client(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::Client)
    , mp_socket(new QTcpSocket)
    , m_socketState(false)
{
    ui->setupUi(this);
    ui->lineEdit_message->setEnabled(false);
    ui->pushButton_send->setEnabled(false);

    connect(mp_socket, &QTcpSocket::readyRead, this, &Client::readyReadSlot);
    connect(mp_socket, &QTcpSocket::disconnected, this, &Client::disconnectedSlot);
}

Client::~Client()
{
    mp_socket->abort();
    delete mp_socket;
    delete ui;
}

void Client::on_pushButton_connect_clicked()
{

    // socket isn't in use
    if (!m_socketState) {
        ui->spinBox->setValue(ui->spinBox->minimum());

        QString ip = ui->lineEdit_ip->text();
        quint16 port = ui->spinBox->text().toUInt();

        mp_socket->setProxy(QNetworkProxy::NoProxy);
        mp_socket->connectToHost(ip, port);

        // connection is successful
        if (mp_socket->waitForConnected()) {
            m_socketState = true;

            ui->pushButton_connect->setText("DISCONNECT");
            ui->lineEdit_message->setEnabled(true);
            ui->pushButton_send->setEnabled(true);
            ui->lineEdit_ip->setEnabled(false);
            ui->spinBox->setEnabled(false);
        } else {
            QMessageBox::critical(this, "Error", mp_socket->errorString());
        }
    } else {
        mp_socket->abort();
        m_socketState = false;

        ui->pushButton_connect->setText("CONNECT");
        ui->lineEdit_message->setEnabled(false);
        ui->pushButton_send->setEnabled(false);
        ui->lineEdit_ip->setEnabled(true);
        ui->spinBox->setEnabled(true);
    }
}

void Client::on_pushButton_send_clicked()
{
    QString message = ui->lineEdit_message->text();
    // can't send empty message
    if (message.isEmpty())
        return;

    if (mp_socket->state() == QAbstractSocket::ConnectedState) {
        if (mp_socket->isWritable()) {
            mp_socket->write(message.toLocal8Bit());
            ui->listWidget_message->addItem(
                QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") + '\n' + message);
            ui->lineEdit_message->clear();
        }
    }
}

void Client::readyReadSlot()
{
    QByteArray data = mp_socket->readAll();
    QString message = QString::fromLocal8Bit(data);
    if (message.isEmpty())
        return;

    if (message.startsWith("Port")) {
        message.erase(message.begin(), message.begin() + 4);
        ui->spinBox->setValue(message.toUInt());
    } else
        ui->listWidget_message->addItem(
            QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")
            + '\n'
            + message);
}

void Client::disconnectedSlot()
{
    ui->lineEdit_message->clear();
    ui->listWidget_message->clear();

    // forced to disconnect
    if (m_socketState) {
        m_socketState = false;

        ui->pushButton_connect->setText("CONNECT");
        ui->lineEdit_message->setEnabled(false);
        ui->pushButton_send->setEnabled(false);
        ui->lineEdit_ip->setEnabled(true);
        ui->spinBox->setEnabled(true);
    }
}
