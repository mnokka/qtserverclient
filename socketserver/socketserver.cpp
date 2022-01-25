#include "socketserver.h"

SocketServer::SocketServer(QObject *parent) :
    QObject(parent)
{
    server = new QTcpServer(this);

    connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));

    if(!server->listen(QHostAddress::Any, 3000))
    {
        qDebug() << "SERVER: Error cant start";
    }
    else
    {
        qDebug() << "SERVER: Started OK!";
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
        qDebug() << "IP:" << ipAddress <<" Port: " << server->serverPort() ;
    }
}

void SocketServer::newConnection()
{
    QTcpSocket *socket = server->nextPendingConnection();
    socket->setSocketOption(QAbstractSocket::LowDelayOption,1);
    socket->write("SERVER MESSAGE: New connection detected\r\n");
    socket->flush();
    //qDebug() << "entering forloop#";
    //for (int i=10;i<10;i++) {
    //    qDebug() << "forloo:" <<i;
      //  std::cout << "sdfgwg";
        socket->waitForBytesWritten(3000);
        socket->waitForReadyRead(3000);


        //socket->write("SERVER MESSAGEvvvv: New connection detected\r\n");
        //socket->flush();


        qDebug() << "SERVER: reading: " << socket->bytesAvailable() <<" bytes";
       rosmessage = socket->readAll();
        //qDebug() << socket->readAll();
        qDebug() << rosmessage;
        ParseMEssage(rosmessage);
        qDebug() << "------------------------------------------------";
        socket->flush();
//}

    socket->close();
}

void SocketServer::ParseMEssage(QString message) {
     qDebug() << "SERVER: message parser got " << message;

     QRegularExpression re("(\\d*)(\\D*)(\\d*)");
               QRegularExpressionMatch match = re.match(message);
               if (match.hasMatch()) {
                   QString e = match.captured(3);
                   qDebug() << "Exctracted number value:" << e;
               }


}
