#include "memberinfo.h"
#include "ui_memberinfo.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

memberinfo::memberinfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::memberinfo)
{
    ui->setupUi(this);
}

memberinfo::~memberinfo()
{
    delete ui;
}

void memberinfo::on_pushButton_clicked()
{
    /*
    QFile file("warehouse_shoppers.txt");
    if (!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(0, "Info", file.errorString());
    }
    QTextStream in(&file);

    ui->textBrowser->setText(in.readAll());
    */
}

