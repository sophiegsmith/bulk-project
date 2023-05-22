#include "sales.h"
#include "ui_sales.h"

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

}


void sales::on_pushButton_3_clicked()
{
    rev = new itemRevenue(this);
    rev -> show();
}

