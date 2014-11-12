#include <QInputDialog>
#include <QStandardItemModel>
#include <QList>

#include "MyEvent.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ConnectionPoint.h"
#include "MyFtp.h"
#include "FtpEventHelper.h"

MainWindow *MainWindow::me = NULL;

void MainWindow::logInfo(QString who, QString msg)
{
    QString fmt;
    fmt = "<font color=red>";
    fmt.append(who);
    fmt.append("</font> ");
    fmt.append(msg);
    QApplication::postEvent(MainWindow::me, new MyEvent(MyEvent::UpdateLog, new QVariant(fmt)));
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    ftp(NULL)
{
    inited = false;
    ui->setupUi(this);
    ui->cmbHint->addItem(tr("..New connection point"));
    ui->dockLog->setWidget(ui->txtLog);
    inited = true;
    this->statusBar()->addPermanentWidget(this->ui->labStatus);
    this->ui->labStatus->setText("");
    this->localDir.setPath("e:\\");
    this->ui->gbRemote->setTitle("Remote dir:");
    updateLocal();
    MainWindow::me = this;
}

MainWindow::~MainWindow()
{
    if (ftp) {
        emit on_btnConnect_clicked();
    }
    delete ui;
}

bool MainWindow::event(QEvent *e)
{
    QMainWindow::event(e);
    if (MyEvent::isMyEvent(e)) {
        MyEvent *ev = (MyEvent *)e;
        switch (e->type())
        {
        case MyEvent::UpdateLog:
            this->ui->txtLog->append(ev->o1->toString());
            break;
        case MyEvent::UpdateDir:
            {
                // format:
                // permission who owner group size month day year/time name
                QRegExp re("([drwx-]+)\\s*(\\d*)\\s*(\\S*)\\s*(\\S*)\\s*(\\d*)\\s*(\\S*)\\s*(\\d*)\\s*([\\d:]*)(\\s*)([^\r\n]*)\r\n");
                int pos = 0;
                QString const &str = ev->o1->toString();
                QStringList fsl;
                QStandardItemModel *model = new QStandardItemModel(this);
                model->setColumnCount(3);
                bool hasUp = false;
                while ((pos = re.indexIn(str, pos)) != -1) {
                    QList<QStandardItem *> row;
                    row.append(new QStandardItem(re.cap(1)));
                    row.append(new QStandardItem(re.cap(5)));
                    QString fname = re.cap(10);
                    row.append(new QStandardItem(fname));
                    if (fname == "..")
                        hasUp = true;
                    model->appendRow(row);
                    pos += re.cap(0).length();
                }
                if (!hasUp) {
                    QList<QStandardItem *> row;
                    row.append(new QStandardItem("d------"));
                    row.append(new QStandardItem("0"));
                    row.append(new QStandardItem(".."));
                    model->insertRow(0, row);
                    row.clear();
                    row.append(new QStandardItem("d------"));
                    row.append(new QStandardItem("0"));
                    row.append(new QStandardItem("."));
                    model->insertRow(0, row);
                }
                this->ui->lstRemote->setModel(model);
                this->updateLocal();
            }
            break;
        case MyEvent::UpdataLogin:
            if (ev->o1->toBool()) {
                this->ui->labStatus->setText(tr("Login sucessful!"));
                QApplication::postEvent(this->ftp->getEventChannel(), new MyEvent(MyEvent::FtpList, new QVariant("")));
            } else {
                this->ui->labStatus->setText(tr("Login failed, bad user or password!"));
                emit on_btnConnect_clicked();
            }
            break;
        default:
            break;
        }
    }
    return true;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::on_btnConnect_clicked()
{
    // check
    // ftp protocol
    if (this->ftp) {
        // disconnect
        this->ftp->quit();
        while (this->ftp->inited );
        delete this->ftp;
        this->ftp = NULL;
        this->ui->btnConnect->setText("Connect");
        this->ui->lstRemote->setModel(NULL);
    } else {
        // connect
        this->ftp = new MyFtp(this->ui->txtHost->text(), this->ui->txtPort->text().toInt());
        this->ftp->start();
        while (!this->ftp->inited) ;
        QApplication::postEvent(ftp->getEventChannel(), new MyEvent(MyEvent::FtpLogin, new QVariant(this->ui->txtUser->text()), new QVariant(this->ui->txtPasswd->text())));
        this->ui->btnConnect->setText("Disconnect");
    }
}

void MainWindow::on_btnSave_clicked()
{
    QComboBox *cmb = this->ui->cmbHint;
    ConnectionPoint newCp;
    QVariant data;

    newCp.ip = this->ui->txtHost->text();
    newCp.port = this->ui->txtPort->text().toInt();
    newCp.user = this->ui->txtUser->text();
    newCp.passwd = this->ui->txtPasswd->text();
    data.setValue(newCp);
    cmb->setItemData(cmb->currentIndex(), data);
}

void MainWindow::on_cmbHint_currentIndexChanged(int index)
{
    if (index == 0) {
        // new connection point
        bool ok = true;
        QString name;
        if (inited)
        name = QInputDialog::getText(this, tr("New connection point"),
                                                tr("Connection point:"), QLineEdit::Normal,
                                                tr(""), &ok);
        else
            name = "kenmark";
        if (ok) {
            QComboBox *cmb = this->ui->cmbHint;
            QVariant data;

            data.setValue(ConnectionPoint());
            cmb->addItem(QIcon(), name, data);
            cmb->setCurrentIndex(cmb->count() - 1);
        }
    } else {
        // exisiting connection point
        QComboBox *cmb = this->ui->cmbHint;
        ConnectionPoint const &cp = cmb->itemData(cmb->currentIndex()).value<ConnectionPoint>();
        this->ui->txtHost->setText(cp.ip);
        this->ui->txtPort->setText(QString().setNum(cp.port));
        this->ui->txtUser->setText(cp.user);
        this->ui->txtPasswd->setText(cp.passwd);
    }
}

void MainWindow::on_lstRemote_doubleClicked(QModelIndex index)
{
    QModelIndex const &iprop = this->ui->lstRemote->model()->index(index.row(), 0);
    QModelIndex const &ifname = this->ui->lstRemote->model()->index(index.row(), 2);
    QVariant const &prop = this->ui->lstRemote->model()->data(iprop);
    QVariant const &fname = this->ui->lstRemote->model()->data(ifname);
    if (prop.toString()[0] == 'd') {
        QApplication::postEvent(this->ftp->getEventChannel(), new MyEvent(MyEvent::FtpCd, new QVariant(fname)));
        QApplication::postEvent(this->ftp->getEventChannel(), new MyEvent(MyEvent::FtpList, new QVariant("")));
    } else {
        QApplication::postEvent(this->ftp->getEventChannel(), new MyEvent(MyEvent::FtpDown, new QVariant(fname), new QVariant(localDir.path())));
    }
}

void MainWindow::updateLocal()
{
    QStandardItemModel *model = new QStandardItemModel(this);
    model->setColumnCount(3);
    QFileInfoList const &infos = localDir.entryInfoList();
    for (int i = 0; i < infos.count(); ++i) {
        QList<QStandardItem *> row;
        row.append(new QStandardItem(infos.at(i).isDir() ? "drwxrwxrwx" : "-rwxrwxrwx"));
        row.append(new QStandardItem(0));
        row.append(new QStandardItem(infos.at(i).fileName()));
        model->appendRow(row);
    }
    this->ui->lstLocal->setModel(model);
    this->ui->gbLocal->setTitle(QString("LocalDir:")+localDir.path());
}

void MainWindow::on_lstLocal_doubleClicked(QModelIndex index)
{
    QModelIndex const &iprop = this->ui->lstLocal->model()->index(index.row(), 0);
    QModelIndex const &ifname = this->ui->lstLocal->model()->index(index.row(), 2);
    QVariant const &prop = this->ui->lstLocal->model()->data(iprop);
    QVariant const &fname = this->ui->lstLocal->model()->data(ifname);
    if (prop.toString()[0] == 'd') {
        localDir.cd(fname.toString());
        updateLocal();
    } else {
        // TODO upload
        // QApplication::postEvent(this->ftp->getEventChannel(), new MyEvent(MyEvent::FtpUp, new QVariant(fname), new QVariant(localDir.path())));
    }
}

void MainWindow::on_checkBox_clicked()
{
    if (this->ui->checkBox->isChecked()) {
        this->ui->txtUser->setText("anonymous");
        this->ui->txtPasswd->setText("anonoymous@anonoymous.com");
    } else {
        this->ui->txtUser->setText("");
        this->ui->txtPasswd->setText("");
    }
}
