/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed Jun 23 21:10:02 2010
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDockWidget>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *frame;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *cmbHint;
    QLabel *labIP;
    QLineEdit *txtHost;
    QLabel *labPort;
    QLineEdit *txtPort;
    QPushButton *btnConnect;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labUser;
    QLineEdit *txtUser;
    QLabel *labPasswd;
    QLineEdit *txtPasswd;
    QCheckBox *checkBox;
    QPushButton *btnSave;
    QGroupBox *gbLocal;
    QTableView *lstLocal;
    QGroupBox *gbRemote;
    QTableView *lstRemote;
    QLabel *labStatus;
    QStatusBar *statusBar;
    QDockWidget *dockLog;
    QWidget *dockLogContent;
    QTextEdit *txtLog;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(815, 728);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 811, 81));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayoutWidget = new QWidget(frame);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 0, 791, 71));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(verticalLayoutWidget->sizePolicy().hasHeightForWidth());
        verticalLayoutWidget->setSizePolicy(sizePolicy2);
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetNoConstraint);
        cmbHint = new QComboBox(verticalLayoutWidget);
        cmbHint->setObjectName(QString::fromUtf8("cmbHint"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(cmbHint->sizePolicy().hasHeightForWidth());
        cmbHint->setSizePolicy(sizePolicy3);
        cmbHint->setEditable(false);

        horizontalLayout_2->addWidget(cmbHint);

        labIP = new QLabel(verticalLayoutWidget);
        labIP->setObjectName(QString::fromUtf8("labIP"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(labIP->sizePolicy().hasHeightForWidth());
        labIP->setSizePolicy(sizePolicy4);

        horizontalLayout_2->addWidget(labIP);

        txtHost = new QLineEdit(verticalLayoutWidget);
        txtHost->setObjectName(QString::fromUtf8("txtHost"));
        sizePolicy3.setHeightForWidth(txtHost->sizePolicy().hasHeightForWidth());
        txtHost->setSizePolicy(sizePolicy3);

        horizontalLayout_2->addWidget(txtHost);

        labPort = new QLabel(verticalLayoutWidget);
        labPort->setObjectName(QString::fromUtf8("labPort"));
        sizePolicy4.setHeightForWidth(labPort->sizePolicy().hasHeightForWidth());
        labPort->setSizePolicy(sizePolicy4);

        horizontalLayout_2->addWidget(labPort);

        txtPort = new QLineEdit(verticalLayoutWidget);
        txtPort->setObjectName(QString::fromUtf8("txtPort"));
        sizePolicy.setHeightForWidth(txtPort->sizePolicy().hasHeightForWidth());
        txtPort->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(txtPort);

        btnConnect = new QPushButton(verticalLayoutWidget);
        btnConnect->setObjectName(QString::fromUtf8("btnConnect"));
        sizePolicy.setHeightForWidth(btnConnect->sizePolicy().hasHeightForWidth());
        btnConnect->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(btnConnect);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        labUser = new QLabel(verticalLayoutWidget);
        labUser->setObjectName(QString::fromUtf8("labUser"));
        sizePolicy4.setHeightForWidth(labUser->sizePolicy().hasHeightForWidth());
        labUser->setSizePolicy(sizePolicy4);

        horizontalLayout_3->addWidget(labUser);

        txtUser = new QLineEdit(verticalLayoutWidget);
        txtUser->setObjectName(QString::fromUtf8("txtUser"));
        sizePolicy3.setHeightForWidth(txtUser->sizePolicy().hasHeightForWidth());
        txtUser->setSizePolicy(sizePolicy3);

        horizontalLayout_3->addWidget(txtUser);

        labPasswd = new QLabel(verticalLayoutWidget);
        labPasswd->setObjectName(QString::fromUtf8("labPasswd"));
        sizePolicy4.setHeightForWidth(labPasswd->sizePolicy().hasHeightForWidth());
        labPasswd->setSizePolicy(sizePolicy4);

        horizontalLayout_3->addWidget(labPasswd);

        txtPasswd = new QLineEdit(verticalLayoutWidget);
        txtPasswd->setObjectName(QString::fromUtf8("txtPasswd"));
        sizePolicy3.setHeightForWidth(txtPasswd->sizePolicy().hasHeightForWidth());
        txtPasswd->setSizePolicy(sizePolicy3);

        horizontalLayout_3->addWidget(txtPasswd);

        checkBox = new QCheckBox(verticalLayoutWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        sizePolicy.setHeightForWidth(checkBox->sizePolicy().hasHeightForWidth());
        checkBox->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(checkBox);

        btnSave = new QPushButton(verticalLayoutWidget);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        sizePolicy.setHeightForWidth(btnSave->sizePolicy().hasHeightForWidth());
        btnSave->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(btnSave);


        verticalLayout->addLayout(horizontalLayout_3);

        gbLocal = new QGroupBox(centralWidget);
        gbLocal->setObjectName(QString::fromUtf8("gbLocal"));
        gbLocal->setGeometry(QRect(10, 90, 400, 430));
        lstLocal = new QTableView(gbLocal);
        lstLocal->setObjectName(QString::fromUtf8("lstLocal"));
        lstLocal->setGeometry(QRect(10, 20, 381, 401));
        lstLocal->setEditTriggers(QAbstractItemView::NoEditTriggers);
        lstLocal->setSelectionMode(QAbstractItemView::SingleSelection);
        lstLocal->setSelectionBehavior(QAbstractItemView::SelectRows);
        lstLocal->horizontalHeader()->setVisible(false);
        lstLocal->verticalHeader()->setVisible(false);
        gbRemote = new QGroupBox(centralWidget);
        gbRemote->setObjectName(QString::fromUtf8("gbRemote"));
        gbRemote->setGeometry(QRect(410, 90, 400, 430));
        lstRemote = new QTableView(gbRemote);
        lstRemote->setObjectName(QString::fromUtf8("lstRemote"));
        lstRemote->setGeometry(QRect(10, 20, 381, 401));
        lstRemote->setEditTriggers(QAbstractItemView::NoEditTriggers);
        lstRemote->setSelectionMode(QAbstractItemView::SingleSelection);
        lstRemote->setSelectionBehavior(QAbstractItemView::SelectRows);
        lstRemote->horizontalHeader()->setVisible(false);
        lstRemote->verticalHeader()->setVisible(false);
        labStatus = new QLabel(centralWidget);
        labStatus->setObjectName(QString::fromUtf8("labStatus"));
        labStatus->setGeometry(QRect(370, 540, 46, 13));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        dockLog = new QDockWidget(MainWindow);
        dockLog->setObjectName(QString::fromUtf8("dockLog"));
        sizePolicy1.setHeightForWidth(dockLog->sizePolicy().hasHeightForWidth());
        dockLog->setSizePolicy(sizePolicy1);
        dockLog->setFeatures(QDockWidget::DockWidgetMovable|QDockWidget::DockWidgetVerticalTitleBar);
        dockLogContent = new QWidget();
        dockLogContent->setObjectName(QString::fromUtf8("dockLogContent"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(dockLogContent->sizePolicy().hasHeightForWidth());
        dockLogContent->setSizePolicy(sizePolicy5);
        txtLog = new QTextEdit(dockLogContent);
        txtLog->setObjectName(QString::fromUtf8("txtLog"));
        txtLog->setGeometry(QRect(40, 20, 31, 31));
        txtLog->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        txtLog->setReadOnly(false);
        dockLog->setWidget(dockLogContent);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dockLog);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MyFtp", 0, QApplication::UnicodeUTF8));
        labIP->setText(QApplication::translate("MainWindow", "Host:", 0, QApplication::UnicodeUTF8));
        labPort->setText(QApplication::translate("MainWindow", "Port:", 0, QApplication::UnicodeUTF8));
        btnConnect->setText(QApplication::translate("MainWindow", "Connect", 0, QApplication::UnicodeUTF8));
        labUser->setText(QApplication::translate("MainWindow", "User:", 0, QApplication::UnicodeUTF8));
        labPasswd->setText(QApplication::translate("MainWindow", "Passwd:", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("MainWindow", "Anonymous", 0, QApplication::UnicodeUTF8));
        btnSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        gbLocal->setTitle(QString());
        gbRemote->setTitle(QString());
        labStatus->setText(QApplication::translate("MainWindow", "labStatus", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
