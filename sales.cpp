#include "sales.h"
#include "ui_sales.h"
#include "bulkclub.hpp"
#include"adminmainpage.h"

int purchaseNumber;
QString purchaseName;
int purchaseQuantity;

sales::sales(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sales)
{
    ui->setupUi(this);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &sales::on_pushButton_4_clicked);
}

sales::~sales()
{
    delete ui;
}

void sales::on_lineEdit_editingFinished()
{
    purchaseNumber = ui->lineEdit->text().toInt();
}


void sales::on_lineEdit_2_editingFinished()
{
    purchaseName = ui->lineEdit_2->text();
}


void sales::on_lineEdit_3_editingFinished()
{
    purchaseQuantity = ui->lineEdit_3->text().toInt();
}


void sales::on_pushButton_clicked()
{

}


void sales::on_pushButton_3_clicked()
{
    rev = new itemRevenue(this);
    rev -> show();
}


void sales::on_pushButton_2_clicked()
{
    BulkClub club;
    int day = (ui->lineEdit_4->text()).toInt();

    QString report = club.displaySalesReport(day);

    ui->textBrowser->setHtml(report);
    ui->textBrowser->setReadOnly(true);
    ui->textBrowser->show();

}


void sales::on_pushButton_4_clicked()
{
    //this button is for going back to the main page
    //connect back to adminmainpage
    adminMainPage *back = new adminMainPage();
    back->show();

    this->close();
}

