#include "membersearch.h"
#include "ui_membersearch.h"

memberSearch::memberSearch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::memberSearch)
{
    ui->setupUi(this);
}

memberSearch::~memberSearch()
{
    delete ui;
}
