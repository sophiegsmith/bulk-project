#include "sales.h"
#include "ui_sales.h"
#include <iostream>
#include<QString>
using namespace std;
int purchaseNumber;
QString purchaseName;
int purchaseQuantity;

sales::sales(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sales)
{
    ui->setupUi(this);
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
//<<<<<<< HEAD
//    StoreDashboard *store = store->getInstance();
//    Item *findItem = store->findItem(purchaseName);
//    if (findItem != NULL)
//    {
//        Sale newSale = Sale(Date{12,12,2022}, purchaseNumber, purchaseName, findItem->price, purchaseQuantity);
//        store->addSale(newSale);
//    }
//=======

}


void sales::on_pushButton_3_clicked()
{
    rev = new itemRevenue(this);
    rev -> show();
//>>>>>>> c97b26aa3f0764c3f64feee9a9403079be73f751
}

