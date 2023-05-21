/********************************************************************************
** Form generated from reading UI file 'adminlogin.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINLOGIN_H
#define UI_ADMINLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

namespace Ui {
    class admin: public Ui_admin {};
} // namespace Ui

class Ui_admin
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_username;
    QLineEdit *lineEdit_usernameinput;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2_password;
    QLineEdit *lineEdit_2_passwordinput;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *admin)
    {
        if (admin->objectName().isEmpty())
            admin->setObjectName("admin");
        admin->resize(800, 600);
        centralwidget = new QWidget(admin);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(270, 170, 271, 201));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_username = new QLabel(groupBox);
        label_username->setObjectName("label_username");

        horizontalLayout->addWidget(label_username);

        lineEdit_usernameinput = new QLineEdit(groupBox);
        lineEdit_usernameinput->setObjectName("lineEdit_usernameinput");

        horizontalLayout->addWidget(lineEdit_usernameinput);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2_password = new QLabel(groupBox);
        label_2_password->setObjectName("label_2_password");

        horizontalLayout_2->addWidget(label_2_password);

        lineEdit_2_passwordinput = new QLineEdit(groupBox);
        lineEdit_2_passwordinput->setObjectName("lineEdit_2_passwordinput");

        horizontalLayout_2->addWidget(lineEdit_2_passwordinput);


        verticalLayout->addLayout(horizontalLayout_2);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);

        admin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(admin);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        admin->setMenuBar(menubar);
        statusbar = new QStatusBar(admin);
        statusbar->setObjectName("statusbar");
        admin->setStatusBar(statusbar);

        retranslateUi(admin);

        QMetaObject::connectSlotsByName(admin);
    } // setupUi

    void retranslateUi(QMainWindow *admin)
    {
        admin->setWindowTitle(QCoreApplication::translate("admin", "admin", nullptr));
        groupBox->setTitle(QCoreApplication::translate("admin", "Admin Access", nullptr));
        label_username->setText(QCoreApplication::translate("admin", "Username", nullptr));
        label_2_password->setText(QCoreApplication::translate("admin", "Password", nullptr));
        pushButton->setText(QCoreApplication::translate("admin", "Login", nullptr));
    } // retranslateUi

};


QT_END_NAMESPACE

#endif // UI_ADMINLOGIN_H
