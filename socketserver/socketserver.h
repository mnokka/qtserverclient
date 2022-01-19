// original example from https://www.bogotobogo.com/cplusplus/sockets_server_client_QT.php
// use telnet to connect
// telnet> open 127.0.0.1 3000


#ifndef SOCKETSERVER_H
#define SOCKETSERVER_H


#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>
#include <iostream>


class SocketServer : public QObject
{
    Q_OBJECT
public:
    explicit SocketServer(QObject *parent = 0);

signals:

public slots:
    void newConnection();

private:
    QTcpServer *server;
    QString ipAddress;

};





#endif // SOCKETSERVER_H
