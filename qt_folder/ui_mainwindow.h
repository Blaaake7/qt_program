/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *pageSelectClient;
    QPushButton *clientButton1;
    QPushButton *clientButton2;
    QPushButton *clientButton3;
    QPushButton *clientButton4;
    QPushButton *clientButton5;
    QPushButton *clientButton6;
    QWidget *pageClientData;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *backButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 800, 600));
        pageSelectClient = new QWidget();
        pageSelectClient->setObjectName(QString::fromUtf8("pageSelectClient"));
        clientButton1 = new QPushButton(pageSelectClient);
        clientButton1->setObjectName(QString::fromUtf8("clientButton1"));
        clientButton1->setGeometry(QRect(100, 200, 100, 50));
        clientButton2 = new QPushButton(pageSelectClient);
        clientButton2->setObjectName(QString::fromUtf8("clientButton2"));
        clientButton2->setGeometry(QRect(250, 200, 100, 50));
        clientButton3 = new QPushButton(pageSelectClient);
        clientButton3->setObjectName(QString::fromUtf8("clientButton3"));
        clientButton3->setGeometry(QRect(400, 200, 100, 50));
        clientButton4 = new QPushButton(pageSelectClient);
        clientButton4->setObjectName(QString::fromUtf8("clientButton4"));
        clientButton4->setGeometry(QRect(550, 200, 100, 50));
        clientButton5 = new QPushButton(pageSelectClient);
        clientButton5->setObjectName(QString::fromUtf8("clientButton5"));
        clientButton5->setGeometry(QRect(200, 300, 100, 50));
        clientButton6 = new QPushButton(pageSelectClient);
        clientButton6->setObjectName(QString::fromUtf8("clientButton6"));
        clientButton6->setGeometry(QRect(450, 300, 100, 50));
        stackedWidget->addWidget(pageSelectClient);
        pageClientData = new QWidget();
        pageClientData->setObjectName(QString::fromUtf8("pageClientData"));
        label = new QLabel(pageClientData);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 20, 300, 30));
        label_2 = new QLabel(pageClientData);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 60, 300, 30));
        label_3 = new QLabel(pageClientData);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 100, 300, 30));
        label_4 = new QLabel(pageClientData);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(50, 140, 300, 30));
        label_5 = new QLabel(pageClientData);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 180, 300, 30));
        backButton = new QPushButton(pageClientData);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setGeometry(QRect(150, 240, 100, 30));
        stackedWidget->addWidget(pageClientData);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        clientButton1->setText(QCoreApplication::translate("MainWindow", "Client 1", nullptr));
        clientButton2->setText(QCoreApplication::translate("MainWindow", "Client 2", nullptr));
        clientButton3->setText(QCoreApplication::translate("MainWindow", "Client 3", nullptr));
        clientButton4->setText(QCoreApplication::translate("MainWindow", "Client 4", nullptr));
        clientButton5->setText(QCoreApplication::translate("MainWindow", "Client 5", nullptr));
        clientButton6->setText(QCoreApplication::translate("MainWindow", "Client 6", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Client Data", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "ADC Value:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "PWM Duty Cycle:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Distance:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "LED State:", nullptr));
        backButton->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
