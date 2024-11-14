/********************************************************************************
** Form generated from reading UI file 'datawindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATAWINDOW_H
#define UI_DATAWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataWindow
{
public:
    QLabel *label;
    QPushButton *backButton;

    void setupUi(QWidget *DataWindow)
    {
        if (DataWindow->objectName().isEmpty())
            DataWindow->setObjectName(QString::fromUtf8("DataWindow"));
        DataWindow->resize(400, 300);
        label = new QLabel(DataWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 50, 300, 50));
        backButton = new QPushButton(DataWindow);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setGeometry(QRect(150, 200, 100, 30));

        retranslateUi(DataWindow);

        QMetaObject::connectSlotsByName(DataWindow);
    } // setupUi

    void retranslateUi(QWidget *DataWindow)
    {
        DataWindow->setWindowTitle(QCoreApplication::translate("DataWindow", "Client Data", nullptr));
        label->setText(QCoreApplication::translate("DataWindow", "Client Data", nullptr));
        backButton->setText(QCoreApplication::translate("DataWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DataWindow: public Ui_DataWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAWINDOW_H
