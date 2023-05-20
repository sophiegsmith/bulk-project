/********************************************************************************
** Form generated from reading UI file 'memberinfo.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEMBERINFO_H
#define UI_MEMBERINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_memberinfo
{
public:
    QPushButton *pushButton;
    QTableWidget *tableWidget;

    void setupUi(QDialog *memberinfo)
    {
        if (memberinfo->objectName().isEmpty())
            memberinfo->setObjectName("memberinfo");
        memberinfo->resize(400, 300);
        pushButton = new QPushButton(memberinfo);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 20, 331, 24));
        tableWidget = new QTableWidget(memberinfo);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(20, 50, 331, 231));

        retranslateUi(memberinfo);

        QMetaObject::connectSlotsByName(memberinfo);
    } // setupUi

    void retranslateUi(QDialog *memberinfo)
    {
        memberinfo->setWindowTitle(QCoreApplication::translate("memberinfo", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("memberinfo", "OPEN TEXT FILE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class memberinfo: public Ui_memberinfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEMBERINFO_H
