#ifndef FTPEVENTHELPER_H
#define FTPEVENTHELPER_H

#include <QObject>
#include "MyEvent.h"
#include "MyFtp.h"
#include "MainWindow.h"

#include <QApplication>

class FtpEventHelper : public QObject
{
    Q_OBJECT
public:
    FtpEventHelper(MyFtp *b)
        : body(b) {}
protected:
    MyFtp *body;
    bool event(QEvent *e)
    {
        QObject::event(e);
        if (MyEvent::isMyEvent(e)) {
            MyEvent *ev = (MyEvent *)e;
            switch(e->type())
            {
            case MyEvent::FtpLogin:
                QApplication::postEvent(MainWindow::me, new MyEvent(MyEvent::UpdataLogin, new QVariant(body->login(ev->o1->toString(), ev->o2->toString()))));
                break;
            case MyEvent::FtpCd:
                body->cd(ev->o1->toString());
                body->list();
                break;
            case MyEvent::FtpDown:
                {
                    QFile f(ev->o2->toString() + ev->o1->toString());
                    f.open(QIODevice::ReadWrite);
                    body->downloadFile(ev->o1->toString(), f);
                    f.close();
                }
                break;
            case MyEvent::FtpList:
                QApplication::postEvent(MainWindow::me, new MyEvent(MyEvent::UpdateDir, new QVariant(body->list(ev->o1->toString()))));
                break;
            default:
                break;
            }
        }
        return true;
    }
};

#endif // FTPEVENTHELPER_H
