//<<<<<<< HEAD
//<<<<<<< HEAD
//=======

//>>>>>>> bd2b559065e0a26f730cf772bce1ca4e2d64b587
#include "admin.h"
#include "ui_admin.h"
//=======

#include "admin.h"
//#include "ui_adminlogin.h"
//>>>>>>> bd2b559065e0a26f730cf772bce1ca4e2d64b587
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

    if (username == "williamwu" && password == "admin1" || username == "sophiesmith" && password == "admin2" || username == "micahusui" && password == "manager"){
        QMessageBox::information(this, "Login", "Successful!");
        hide();
        adminMP = new adminMainPage(this);
        adminMP->show();
    }
    else{
        QMessageBox::warning(this, "Login", "Username and password is not correct");
    }
}
//<<<<<<< HEAD
//<<<<<<< HEAD
//=======

//>>>>>>> bd2b559065e0a26f730cf772bce1ca4e2d64b587
//=======

//>>>>>>> bd2b559065e0a26f730cf772bce1ca4e2d64b587
