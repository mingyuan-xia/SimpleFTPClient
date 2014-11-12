#ifndef CONNECTIONPOINT_H
#define CONNECTIONPOINT_H

#include <QString>

struct ConnectionPoint
{
    ConnectionPoint()
        : ip("127.0.0.1"), port(21), user("kenmark"), passwd("kenmark")
    {}

    QString ip;
    int port;
    QString user;
    QString passwd;
};

Q_DECLARE_METATYPE(ConnectionPoint)

#endif // CONNECTIONPOINT_H
