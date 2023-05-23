
#include "admin.h"
#include "ui_admin.h"
#include <QMessageBox>

admin::admin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::admin)
{
    ui->setupUi(this);
}

admin::~admin()
{
    delete ui;
}



void admin::on_pushButton_clicked()
{
    QString username = ui->lineEdit_usernameinput->text();
    QString password = ui->lineEdit_2_passwordinput->text();

    if ((username == "williamwu" && password == "admin1") || (username == "sophiesmith" && password == "admin2") || (username == "micahusui" && password == "manager")){
        QMessageBox::information(this, "Login", "Successful!");
        hide();
        adminMP = new adminMainPage(this);
        adminMP->show();
    }
    else{
        QMessageBox::warning(this, "Login", "Username and password is not correct");
    }
}

