// original example from https://www.bogotobogo.com/cplusplus/sockets_server_client_QT.php

#ifndef SOCKETCLIENT_H
#define SOCKETCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>

class SocketClient : public QObject
{
    Q_OBJECT
public:
    explicit SocketClient(QObject *parent = 0);

    void Connect();

signals:

public slots:

private:
    QTcpSocket *socket;

};


#endif // SOCKETCLIENT_H
