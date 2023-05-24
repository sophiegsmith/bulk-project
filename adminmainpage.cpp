#include "adminmainpage.h"
#include "ui_adminmainpage.h"
#include<QDesktopServices>
#include<QUrl>

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
}


void adminMainPage::on_pushButton_sales_clicked()
{
    report = new sales(this);
    report -> show();
}



void adminMainPage::on_github_push_button_clicked()
{
    //button connects to GitHub page
    QUrl githubUrl("https://github.com/sophiegsmith/bulk-project");
    QDesktopServices::openUrl(githubUrl);
}

