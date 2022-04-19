#ifndef SERVER_H
#define SERVER_H

#include <QDateTime>
#include <QHostAddress>
#include <QMessageBox>
#include <QNetworkInterface>
#include <QTcpServer>
#include <QTcpSocket>
#include <QWidget>

namespace Ui {
class Server;
}

class Server : public QWidget {
    Q_OBJECT

public:
    explicit Server(QWidget* parent = nullptr);
    ~Server();

private slots:
    void on_pushButton_listen_clicked();
    void newConnectionSlot();
    void readyReadSlot();
    void disconnectedSlot();

private:
    void enumIPAddress();

private:
    Ui::Server* ui;
    QTcpServer* mp_server;
    QTcpSocket* mp_socket;
    QList<QTcpSocket*> m_clientList;
};

#endif // SERVER_H
