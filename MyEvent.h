#ifndef MYEVENT_H
#define MYEVENT_H

#include <QEvent>
#include <QVariant>

class MyEvent: public QEvent
{
public:
    static int const lowest = 40000;

    static int const UpdateDir = 40000;
    static int const UpdateLog = 40001;
    static int const UpdataLogin = 40002;

    static int const FtpList = 40003;
    static int const FtpDown = 40004;
    static int const FtpUp = 40005;
    static int const FtpLogin = 40006;
    static int const Ftpa = 40007;
    static int const Ftpb = 40008;
    static int const FtpCd = 40010;

    static int const highest = 40080;

    static bool isMyEvent(QEvent *e)
    {
        return (e->type() >= MyEvent::lowest && e->type() <= MyEvent::highest);
    }

    QVariant *o1, *o2, *o3, *o4;

    MyEvent(int t, QVariant *ob1, QVariant *ob2 = NULL, QVariant *ob3 = NULL, QVariant *ob4 = NULL)
        : QEvent((QEvent::Type)t), o1(ob1), o2(ob2), o3(ob3), o4(ob4) {}

    ~MyEvent()
    {
        if (o1 != NULL)
            delete o1;
        if (o2 != NULL)
            delete o2;
        if (o3 != NULL)
            delete o3;
        if (o4 != NULL)
            delete o4;
    }
};

#endif // MYEVENT_H
