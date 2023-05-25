#include "adminmainpage.h"
#include "ui_adminmainpage.h"

adminMainPage::adminMainPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminMainPage)
{
    ui->setupUi(this);
}

adminMainPage::~adminMainPage()
{
    delete ui;
}

void adminMainPage::on_pushButton_2_members_clicked()
{
    info = new memberinfo(this);
    info -> show();
    hide();
    this -> close();
}


void adminMainPage::on_pushButton_sales_clicked()
{
    report = new sales(this);
    report -> show();
    hide();
    this -> close();
}


