/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Client
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_ip;
    QLabel *label_2;
    QSpinBox *spinBox;
    QPushButton *pushButton_connect;
    QListWidget *listWidget_message;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_message;
    QPushButton *pushButton_send;

    void setupUi(QWidget *Client)
    {
        if (Client->objectName().isEmpty())
            Client->setObjectName(QString::fromUtf8("Client"));
        verticalLayout = new QVBoxLayout(Client);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Client);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        lineEdit_ip = new QLineEdit(Client);
        lineEdit_ip->setObjectName(QString::fromUtf8("lineEdit_ip"));
        lineEdit_ip->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lineEdit_ip);

        label_2 = new QLabel(Client);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_2);

        spinBox = new QSpinBox(Client);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setAlignment(Qt::AlignCenter);
        spinBox->setMinimum(1);
        spinBox->setMaximum(65535);

        horizontalLayout->addWidget(spinBox);

        pushButton_connect = new QPushButton(Client);
        pushButton_connect->setObjectName(QString::fromUtf8("pushButton_connect"));

        horizontalLayout->addWidget(pushButton_connect);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 3);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 3);
        horizontalLayout->setStretch(4, 1);

        verticalLayout->addLayout(horizontalLayout);

        listWidget_message = new QListWidget(Client);
        listWidget_message->setObjectName(QString::fromUtf8("listWidget_message"));

        verticalLayout->addWidget(listWidget_message);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineEdit_message = new QLineEdit(Client);
        lineEdit_message->setObjectName(QString::fromUtf8("lineEdit_message"));

        horizontalLayout_2->addWidget(lineEdit_message);

        pushButton_send = new QPushButton(Client);
        pushButton_send->setObjectName(QString::fromUtf8("pushButton_send"));

        horizontalLayout_2->addWidget(pushButton_send);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Client);

        QMetaObject::connectSlotsByName(Client);
    } // setupUi

    void retranslateUi(QWidget *Client)
    {
        Client->setWindowTitle(QCoreApplication::translate("Client", "Client", nullptr));
        label->setText(QCoreApplication::translate("Client", "IP", nullptr));
        label_2->setText(QCoreApplication::translate("Client", "Port", nullptr));
        pushButton_connect->setText(QCoreApplication::translate("Client", "CONNECT", nullptr));
        pushButton_send->setText(QCoreApplication::translate("Client", "SEND", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Client: public Ui_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
