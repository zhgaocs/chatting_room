/********************************************************************************
** Form generated from reading UI file 'server.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_H
#define UI_SERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Server
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_2;
    QSpinBox *spinBox;
    QListWidget *listWidget_message;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_listen;
    QListWidget *listWidget_client;

    void setupUi(QWidget *Server)
    {
        if (Server->objectName().isEmpty())
            Server->setObjectName(QString::fromUtf8("Server"));
        Server->resize(545, 253);
        horizontalLayout_2 = new QHBoxLayout(Server);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Server);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(Server);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);

        label_2 = new QLabel(Server);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_2);

        spinBox = new QSpinBox(Server);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setAlignment(Qt::AlignCenter);
        spinBox->setMinimum(1);
        spinBox->setMaximum(65535);

        horizontalLayout->addWidget(spinBox);


        verticalLayout_2->addLayout(horizontalLayout);

        listWidget_message = new QListWidget(Server);
        listWidget_message->setObjectName(QString::fromUtf8("listWidget_message"));

        verticalLayout_2->addWidget(listWidget_message);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton_listen = new QPushButton(Server);
        pushButton_listen->setObjectName(QString::fromUtf8("pushButton_listen"));

        verticalLayout->addWidget(pushButton_listen);

        listWidget_client = new QListWidget(Server);
        listWidget_client->setObjectName(QString::fromUtf8("listWidget_client"));

        verticalLayout->addWidget(listWidget_client);


        horizontalLayout_2->addLayout(verticalLayout);

        horizontalLayout_2->setStretch(0, 5);
        horizontalLayout_2->setStretch(1, 2);

        retranslateUi(Server);

        QMetaObject::connectSlotsByName(Server);
    } // setupUi

    void retranslateUi(QWidget *Server)
    {
        Server->setWindowTitle(QCoreApplication::translate("Server", "Server", nullptr));
        label->setText(QCoreApplication::translate("Server", "IP", nullptr));
        label_2->setText(QCoreApplication::translate("Server", "Port", nullptr));
        pushButton_listen->setText(QCoreApplication::translate("Server", "LISTEN", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Server: public Ui_Server {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_H
