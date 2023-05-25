#include "sales.h"
#include "ui_sales.h"
<<<<<<< Updated upstream
=======
#include "bulkclub.hpp"
#include"adminmainpage.h"
#include <QMessageBox>
>>>>>>> Stashed changes

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


void sales::on_pushButton_addpur_clicked()
{
    QString quan;
    Purchase p;
    p.itemPurchased = ui->lineEdit->text();
    p.membershipNumber = ui->lineEdit_2->text();
    quan = ui->lineEdit_3-> text();

    QMessageBox::information(this, " ", "Purchase Added!");

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
}


void sales::on_pushButton_3_clicked()
{
    /*
    QString name = ui -> lineEdit_5 -> text();

    m_model = new QStandardItemModel(this);
    ui->tableView->setModel(m_model);

    m_model->setHorizontalHeaderLabels({ "Quantity","Revenue PreTax"});
    sales item;
    club.readFromFile("warehouse_shoppers.txt");
    std::vector<Purchase> items = club.getMembers();
    m_model->setItem(row, 0, new QStandardItem(member.name));
    m_model->setItem(row, 1, new QStandardItem(member.number));
    m_model->setItem(row, 2, new QStandardItem(member.type));
    m_model->setItem(row, 3, new QStandardItem(member.expiration_date));

    ui->lineEdit_5->clear();
    */
}

