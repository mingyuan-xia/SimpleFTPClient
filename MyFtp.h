#ifndef MYFTP_H
#define MYFTP_H

#include <QThread>
#include <QTcpSocket>
#include <QFile>
#include <QQueue>

struct FtpEventHelper;

class MyFtp : public QThread
{
    Q_OBJECT
    friend struct FtpEventHelper;
public:
    static const int BufferSize = 1024;

    MyFtp(QString host, int port);
    ~MyFtp();

    void run();
    FtpEventHelper *getEventChannel()
    {
        return helper;
    }
    bool inited;
private:
    bool login(QString user, QString pwd);
    void downloadFile(QString const &name, QFile &f);
    void enterPassiveMode();
    void getcwd();
    bool cd(QString const &path = QString());
    QString list(QString const &path = QString());
private:
    void sendCommand(QString header, QString content);
    void blockReadReply();
    int recvReply(QString *msg = NULL);

    QString host;
    int port;
    QTcpSocket *s;
    QTextStream *ts;
    QQueue<QString> *replyQueue;
    FtpEventHelper *helper;
public slots:
    void displayError(QAbstractSocket::SocketError socketError);
};

#endif // MYFTP_H
