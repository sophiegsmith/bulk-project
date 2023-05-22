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
    search = new memberSearch(this);
    search -> show();
}

