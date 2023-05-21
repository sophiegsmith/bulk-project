#include "itemrevenue.h"
#include "ui_itemrevenue.h"

itemRevenue::itemRevenue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::itemRevenue)
{
    ui->setupUi(this);
}

itemRevenue::~itemRevenue()
{
    delete ui;
}
