#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QModelIndex>
#include <QDir>

class MyFtp;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    static class MainWindow *me;
    static void logInfo(QString who, QString msg);
protected:
    void changeEvent(QEvent *e);
    bool event(QEvent *e);
private:
    Ui::MainWindow *ui;
    bool inited;
    MyFtp *ftp;
    QDir localDir;

    void updateLocal();
private slots:
    void on_checkBox_clicked();
    void on_lstLocal_doubleClicked(QModelIndex index);
    void on_lstRemote_doubleClicked(QModelIndex index);
    void on_cmbHint_currentIndexChanged(int index);
    void on_btnSave_clicked();
    void on_btnConnect_clicked();
};

#endif // MAINWINDOW_H
