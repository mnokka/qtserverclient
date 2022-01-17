#include "socketclient.h"


SocketClient::SocketClient(QObject *parent) :
    QObject(parent)
{
}

void SocketClient::Connect()
{
    socket = new QTcpSocket(this);
    socket->connectToHost("127.0.0.1", 3000);

    if(socket->waitForConnected(3000))
    {

        qDebug() << "CLIENT: Connected!";

        socket->write("CLIENT: Hello server, this is clientr\n");
        socket->waitForBytesWritten(1000);
        socket->waitForReadyRead(3000);
        qDebug() << "CLIENT: reading: " << socket->bytesAvailable() <<" bytes";

        qDebug() << socket->readAll();

        socket->close();
    }
    else
    {
        qDebug() << "Not connected!";
    }

}
