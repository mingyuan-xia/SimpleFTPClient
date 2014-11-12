#include "MyFtp.h"
#include "mainwindow.h"
#include "MyEvent.h"
#include "FtpEventHelper.h"

#include <QApplication>
#include <QMessageBox>

MyFtp::MyFtp(QString host, int port)
{
    this->host = host;
    this->port = port;
    this->inited = false;
    MainWindow::logInfo("cnn:", host);
}

MyFtp::~MyFtp()
{
}

void MyFtp::sendCommand(QString header, QString content)
{
    QString str(header);
    str.append(' ');
    str.append(content);
    str.append("\r\n");
    MainWindow::logInfo("ftp>>", str);
    this->s->write(str.toAscii().data(), str.length());
    this->s->waitForBytesWritten();
}

void MyFtp::blockReadReply()
{
    s->waitForReadyRead();
    for (QString str; !this->ts->atEnd(); ) {
        str = ts->readLine();
        replyQueue->enqueue(str);
    }
}

int MyFtp::recvReply(QString *msg)
{
    QString t;
    int ret = 0;

    if (replyQueue->isEmpty())
        blockReadReply();
    QString line(this->replyQueue->dequeue());
    if (line[3] == '-') {
        do {
            t.append(line.right(line.length()-4));
            if (replyQueue->isEmpty())
                blockReadReply();
            line = this->replyQueue->dequeue();
        } while (line[3] == '-');
    }
    if (line[3] == ' ') {
        ret = (line[0].toAscii() - '0') * 100 + (line[1].toAscii() - '0') * 10 + line[2].toAscii() - '0';
        t.append(line.right(line.length()-4));
        QString num;
        num.setNum(ret);
        MainWindow::logInfo(num, t);
        if (msg != NULL)
            *msg = t;
        return ret;
    }
    MainWindow::logInfo("error", "reply piece not agree!");
    return 0;
}

void MyFtp::downloadFile(QString const &name, QFile &f)
{
    char buffer[MyFtp::BufferSize];
    QString msg;
    sendCommand("PASV", "");
    recvReply(&msg);

    QStringList const &sl = msg.mid(msg.indexOf("(") + 1, msg.indexOf(")") - msg.indexOf("(") - 1).split(",");
    QString dsHost = sl[0] + "." + sl[1] + "." + sl[2] + "." + sl[3];
    int dsPort = sl[4].toInt() << 8 | sl[5].toInt();

    sendCommand("SIZE", name);
    // TODO TYPE I
    recvReply(&msg);
    int len = msg.toInt();

    sendCommand("RETR", name);
    QTcpSocket ds;
    // from passive mode
    ds.connectToHost(dsHost, dsPort);
    while (len > 0) {
        ds.waitForReadyRead();
        int l = ds.read(buffer, MyFtp::BufferSize > len ? len : MyFtp::BufferSize);
        f.write(buffer, l);
        len -= l;
    }
    ds.disconnectFromHost();
    recvReply(); // open binary ...
    recvReply(); // transfer ok
}

bool MyFtp::cd(QString const &path)
{
    // TODO
    sendCommand("CWD", path);
    recvReply();
    return true;
}

QString MyFtp::list(QString const &path)
{
    QString msg;

    sendCommand("PASV", "");
    recvReply(&msg);

    QStringList const &sl = msg.mid(msg.indexOf("(") + 1, msg.indexOf(")") - msg.indexOf("(") - 1).split(",");
    QString dsHost = sl[0] + "." + sl[1] + "." + sl[2] + "." + sl[3];
    int dsPort = sl[4].toInt() << 8 | sl[5].toInt();
    sendCommand("LIST", "");
    /*
    if (path.isEmpty())
        sendCommand("LIST", "");
    else
        sendCommand("LIST", path);
    */
    QTcpSocket ds;
    // from passive mode
    ds.connectToHost(dsHost, dsPort);
    ds.waitForReadyRead();
    char *buffer = new char[ds.bytesAvailable()];
    ds.read(buffer, ds.bytesAvailable());
    QString str(buffer);
    delete []buffer;
    ds.close();
    recvReply();
    recvReply();
    return str;
}

void MyFtp::run()
{
    this->s = new QTcpSocket();
    this->ts = new QTextStream(s);
    this->replyQueue = new QQueue<QString>();
    this->helper = new FtpEventHelper(this);
    inited = true;
    connect(s, SIGNAL(error(QAbstractSocket::SocketError)),
                 this, SLOT(displayError(QAbstractSocket::SocketError)));
    this->s->connectToHost(host, port);
    recvReply();
    exec();
    delete s;
    delete ts;
    delete replyQueue;
    delete helper;
    inited = false;
}

bool MyFtp::login(QString user, QString pwd)
{
    sendCommand("USER", user);
    recvReply();
    sendCommand("PASS", pwd);
    return recvReply() / 100 != 5;
}

void MyFtp::getcwd()
{
    // TODO
    sendCommand("CWD", "");
    recvReply();
}

void MyFtp::displayError(QAbstractSocket::SocketError socketError)
 {
     switch (socketError) {
     case QAbstractSocket::RemoteHostClosedError:
         break;
     case QAbstractSocket::HostNotFoundError:
         QMessageBox::information(NULL, tr("MyFtp"),
                                  tr("The host was not found. Please check the "
                                     "host name and port settings."));
         break;
     case QAbstractSocket::ConnectionRefusedError:
         QMessageBox::information(NULL, tr("MyFtp"),
                                  tr("The connection was refused by the peer. "
                                     "Make sure the fortune server is running, "
                                     "and check that the host name and port "
                                     "settings are correct."));
         break;
     default:
         QMessageBox::information(NULL, tr("MyFtp"),
                                  tr("The following error occurred: %1.")
                                  .arg(s->errorString()));
     }
 }
