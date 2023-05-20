/********************************************************************************
** Form generated from reading UI file 'adminmainpage.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINMAINPAGE_H
#define UI_ADMINMAINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adminMainPage
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_sales;
    QPushButton *pushButton_2_members;

    void setupUi(QDialog *adminMainPage)
    {
        if (adminMainPage->objectName().isEmpty())
            adminMainPage->setObjectName("adminMainPage");
        adminMainPage->resize(553, 428);
        widget = new QWidget(adminMainPage);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(90, 50, 361, 261));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(28);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_sales = new QPushButton(widget);
        pushButton_sales->setObjectName("pushButton_sales");

        horizontalLayout->addWidget(pushButton_sales);

        pushButton_2_members = new QPushButton(widget);
        pushButton_2_members->setObjectName("pushButton_2_members");

        horizontalLayout->addWidget(pushButton_2_members);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(adminMainPage);

        QMetaObject::connectSlotsByName(adminMainPage);
    } // setupUi

    void retranslateUi(QDialog *adminMainPage)
    {
        adminMainPage->setWindowTitle(QCoreApplication::translate("adminMainPage", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("adminMainPage", "Bulk Club", nullptr));
        pushButton_sales->setText(QCoreApplication::translate("adminMainPage", "Sales", nullptr));
        pushButton_2_members->setText(QCoreApplication::translate("adminMainPage", "Members", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adminMainPage: public Ui_adminMainPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINMAINPAGE_H
