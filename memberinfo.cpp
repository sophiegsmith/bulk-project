#include "memberinfo.h"
#include "ui_memberinfo.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QStandardItemModel>
#include "bulkclub.hpp"
#include"adminmainpage.h"

memberinfo::memberinfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::memberinfo)
{
    ui->setupUi(this);
    m_model = new QStandardItemModel(this);
    ui->tableView->setModel(m_model);
    m_model->setHorizontalHeaderLabels({ "Name", "Number", "Type", "Expiration Date" });

    connect(ui->pushButton_6, &QPushButton::clicked, this, &memberinfo::on_pushButton_6_clicked);
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


void memberinfo::on_tableWidget_cellActivated(int row, int column)
{
    row = row +1;
    column = column + 1;
}


void memberinfo::on_tableWidget_cellChanged(int row, int column)
{
    row = row +1;
    column = column + 1;

}


void memberinfo::on_tableWidget_cellClicked(int row, int column)
{
    row = row +1;
    column = column + 1;

}


void memberinfo::on_tableWidget_cellDoubleClicked(int row, int column)
{
    row = row +1;
    column = column + 1;

}


void memberinfo::on_tableWidget_cellEntered(int row, int column)
{
    row = row +1;
    column = column + 1;

}


void memberinfo::on_tableWidget_cellPressed(int row, int column)
{
    row = row +1;
    column = column + 1;

}


void memberinfo::on_pushButton_3_clicked()
{
    //rebate
}


void memberinfo::on_pushButton_2_clicked()
{
    BulkClub club;
    // Read membership information from a file
    if (club.readFromFile("warehouse_shoppers.txt")) {
        cout << "Membership information successfully loaded." << endl;
    } else {
        cout << "Failed to load membership information." << endl;
        return;
    }
    //Since we don't have a UI field to input the, let just the current month.
    std::time_t currentTime = std::time(nullptr);
    std::tm* currentDate = std::localtime(&currentTime);
    int currentMonth = currentDate->tm_mon + 1; // Add 1 because tm_mon ranges from 0 to 11
    int currentDay = currentDate->tm_mday;
    int currentYear = currentDate->tm_year + 1900; // Add 1900 because tm_year represents years since 1900
    std::vector<Member> expiredMembers = club.displayExpiringMembers(currentMonth, currentDay, currentYear);
    m_model->clear();
    m_model->setHorizontalHeaderLabels({ "Name", "Number", "Type", "Expiration Date" });

    int row = 0;
    for (const Member& member : expiredMembers) {
        m_model->setItem(row, 0, new QStandardItem(member.name));
        m_model->setItem(row, 1, new QStandardItem(member.number));
        m_model->setItem(row, 2, new QStandardItem(member.type));
        m_model->setItem(row, 3, new QStandardItem(member.expiration_date));
        row++;
    }
}


void memberinfo::on_pushButton_6_clicked()
{
    //this is a main page button that will connect back to main page
    adminMainPage *back = new adminMainPage();
    back->show();

    this->close();
}

