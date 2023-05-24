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

    m_model->setHorizontalHeaderLabels({ "Name","Number", "Type", "Expiration Date"});
    BulkClub club;
    club.readFromFile("warehouse_shoppers.txt");
    std::vector<Member> members = club.getMembers();

    for (int i = 0; i < members.size(); ++i) {
        const Member& member = members[i];
        m_model->setItem(i, 0, new QStandardItem(member.name));
        m_model->setItem(i, 1, new QStandardItem(member.number));
        m_model->setItem(i, 2, new QStandardItem(member.type));
        m_model->setItem(i, 3, new QStandardItem(member.expiration_date));
        //m_model->setItem(i, 4, new QStandardItem(member.total_spent));
    }

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
    BulkClub club;
    club.displayExecutiveMemberRebates();

    // Calculate the rebate total
    double rebateTotal = 0.0;
    std::vector<Member> executiveMembers = club.getMembers();
    for (const Member& m : executiveMembers) {
        rebateTotal += m.rebate_amount;
    }

    // Display the rebate total in a message box
    QMessageBox::information(this, "Rebate Total", QString("Total Rebate Amount: $%1").arg(rebateTotal));

/*
// Create a vector to store Executive members' rebates
    std::vector<Member> executiveMembers;

    // Calculate the rebate total
    double rebateTotal = 0.0;

    // Collect rebate information for Executive members
    for (const Member& m : members) {
        if (m.type == "Executive") {
            executiveMembers.push_back(m);
            rebateTotal += m.rebate_amount;
        }
    }

    // Sort the Executive members by membership number
    std::sort(executiveMembers.begin(), executiveMembers.end(), compareByMembershipNumber);

    // Display rebate information for Executive members
    for (const Member& m : executiveMembers) {
        std::cout << "Membership Number: " << m.number.toStdString() << std::endl;
        std::cout << "Rebate Amount: $" << m.rebate_amount << std::endl;
        std::cout << std::endl;
    }

    // Display the rebate total in a QMessageBox
    QMessageBox::information(nullptr, "Rebate Total", QString("Total Rebate Amount: $%1").arg(rebateTotal));
*/
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


void memberinfo::on_lineEdit_member_first_name_returnPressed()
{

}


void memberinfo::on_lineEdit_member_last_name_returnPressed()
{

}


void memberinfo::on_lineEdit_member_number_returnPressed()
{

}


void memberinfo::on_lineEdit_member_expiration_date_inputRejected()
{

}


void memberinfo::on_pushButton_member_delete_clicked()
{
    QString first = ui->lineEdit_member_first_name->text();
    QString last = ui->lineEdit_member_last_name->text();
    QString number = ui->lineEdit_member_number->text();
    QString expiration = ui->lineEdit_member_expiration_date->text();
    QString type = ui->lineEdit_member_type->text();

    BulkClub club;
    // Read membership information from a file
    if (club.readFromFile("warehouse_shoppers.txt")) {
        cout << "Membership information successfully loaded." << endl;
    } else {
        cout << "Failed to load membership information." << endl;
        QMessageBox::critical(nullptr, "Error", "Failed to load membership information.");
        return;
    }

    if (first.isEmpty() || last.isEmpty() || number.isEmpty() || expiration.isEmpty()){
        QMessageBox::critical(nullptr, "Error", "Invalid input. Please try again.");
        return;
    }

    Member m = {first + "_" + last, number, type, expiration, 0.0, 0.0};
    club.deleteMember(m);
    club.saveMemberList("warehouse_shoppers.txt");

    std::vector<Member> members = club.getMembers();

    m_model->clear();
    m_model->setHorizontalHeaderLabels({ "Name", "Number", "Type", "Expiration Date" });

    int row = 0;
    for (const Member& member : members) {
        m_model->setItem(row, 0, new QStandardItem(member.name));
        m_model->setItem(row, 1, new QStandardItem(member.number));
        m_model->setItem(row, 2, new QStandardItem(member.type));
        m_model->setItem(row, 3, new QStandardItem(member.expiration_date));
        row++;
    }

    ui->lineEdit_member_first_name->clear();
    ui->lineEdit_member_last_name->clear();
    ui->lineEdit_member_number->clear();
    ui->lineEdit_member_expiration_date->clear();
    ui->lineEdit_member_number->clear();
    ui->lineEdit_member_type->clear();

}


void memberinfo::on_pushButton_add_member_clicked()
{
    QString first = ui->lineEdit_member_first_name->text();
    QString last = ui->lineEdit_member_last_name->text();
    QString number = ui->lineEdit_member_number->text();
    QString expiration = ui->lineEdit_member_expiration_date->text();
    QString type = ui->lineEdit_member_type->text();

    BulkClub club;
    // Read membership information from a file
    if (club.readFromFile("warehouse_shoppers.txt")) {
        cout << "Membership information successfully loaded." << endl;
    } else {
        cout << "Failed to load membership information." << endl;
        QMessageBox::critical(nullptr, "Error", "Failed to load membership information.");
        return;
    }

    if (first.isEmpty() || last.isEmpty() || number.isEmpty() || expiration.isEmpty()){
        QMessageBox::critical(nullptr, "Error", "Invalid input. Please try again.");
        return;
    }

    Member m = {first + "_" + last, number, type, expiration, 0.0, 0.0};
    club.updateMemberInfo (m);
    club.saveMemberList("warehouse_shoppers.txt");

    std::vector<Member> members = club.getMembers();

    m_model->clear();
    m_model->setHorizontalHeaderLabels({ "Name", "Number", "Type", "Expiration Date" });

    int row = 0;
    for (const Member& member : members) {
        m_model->setItem(row, 0, new QStandardItem(member.name));
        m_model->setItem(row, 1, new QStandardItem(member.number));
        m_model->setItem(row, 2, new QStandardItem(member.type));
        m_model->setItem(row, 3, new QStandardItem(member.expiration_date));
        row++;
    }
    ui->lineEdit_member_first_name->clear();
    ui->lineEdit_member_last_name->clear();
    ui->lineEdit_member_number->clear();
    ui->lineEdit_member_expiration_date->clear();
    ui->lineEdit_member_number->clear();
    ui->lineEdit_member_type->clear();
}


void memberinfo::on_lineEdit_member_type_returnPressed()
{

}


void memberinfo::on_pushButton_member_search_clicked()
{
    //added the logic to search member 
    QString first = ui->lineEdit_member_first_name->text();
    QString last = ui->lineEdit_member_last_name->text();
    QString number = ui->lineEdit_member_number->text();
    QString expiration = ui->lineEdit_member_expiration_date->text();
    QString type = ui->lineEdit_member_type->text();

    BulkClub club;
    // Read membership information from a file
    if (club.readFromFile("warehouse_shoppers.txt")) {
        cout << "Membership information successfully loaded." << endl;
    } else {
        cout << "Failed to load membership information." << endl;
        QMessageBox::critical(nullptr, "Error", "Failed to load membership information.");
        return;
    }

    if (first.isEmpty() || last.isEmpty() || number.isEmpty() || expiration.isEmpty()){
        QMessageBox::critical(nullptr, "Error", "Invalid input. Please try again.");
        return;
    }

    Member m = {first + "_" + last, number, type, expiration, 0.0, 0.0};

    Member *found = club.findMember(m);
    if(found != NULL){
        m_model->clear();
        m_model->setHorizontalHeaderLabels({ "Name", "Number", "Type", "Expiration Date" });
        m_model->setItem(0, 0, new QStandardItem(found->name));
        m_model->setItem(0, 1, new QStandardItem(found->number));
        m_model->setItem(0, 2, new QStandardItem(found->type));
        m_model->setItem(0, 3, new QStandardItem(found->expiration_date));
        QMessageBox::critical(nullptr, "Successful!", "Member found.");
    } else {
        QMessageBox::critical(nullptr, "Error", "Member not found.");
        return;
    }
}


void memberinfo::on_tableView_viewportEntered()
{

}


void memberinfo::on_tableView_clicked(const QModelIndex &index)
{
    // Get the selected row index
    int row = index.row();

    // Retrieve data from the model for the selected row
    QString tempName = m_model->index(row, 0).data().toString();
    std::string inputString = tempName.toStdString();

    size_t underscorePos = inputString.find("_");

    //first name
    std::string firstPart = inputString.substr(0, underscorePos);

    //last name
    std::string secondPart = inputString.substr(underscorePos + 1);

    QString firstName = QString::fromStdString(firstPart);
    QString lastName = QString::fromStdString(secondPart);
    QString memberNumber = m_model->index(row, 1).data().toString();
    QString expirationDate = m_model->index(row, 2).data().toString();
    QString memberType = m_model->index(row, 3).data().toString();



    // Update the edit controls with the retrieved data
    ui->lineEdit_member_first_name->setText(firstName);
    ui->lineEdit_member_last_name->setText(lastName);
    ui->lineEdit_member_number->setText(memberNumber);
    ui->lineEdit_member_expiration_date->setText(expirationDate);
    ui->lineEdit_member_type->setText(memberType);
}

