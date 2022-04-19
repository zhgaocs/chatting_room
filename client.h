#ifndef CLIENT_H
#define CLIENT_H

#include <QDateTime>
#include <QMessageBox>
#include <QNetworkProxy>
#include <QTcpSocket>
#include <QWidget>

namespace Ui {
class Client;
}

class Client : public QWidget {
    Q_OBJECT

public:
    explicit Client(QWidget* parent = nullptr);
    ~Client();

private slots:
    void on_pushButton_connect_clicked();

    void on_pushButton_send_clicked();

    void readyReadSlot();

    void disconnectedSlot();

private:
    Ui::Client* ui;
    QTcpSocket* mp_socket;
    bool m_socketState;
};

#endif // CLIENT_H
