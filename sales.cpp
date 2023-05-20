#include "sales.h"
#include "ui_sales.h"

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
