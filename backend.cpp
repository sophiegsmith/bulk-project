#include <QCoreApplication>
#include <QMessageBox>
#include <QString>
#include "bulkclub.hpp"


BulkClub::BulkClub()
{
    // constructor implementation
}

BulkClub::~BulkClub()
{
    // destructor implementation
}

bool BulkClub::readFromFile(const std::string& filename)
{
    // implementation to read from file and populate the members vector
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file \"" << filename << "\" for reading.\n";
        return false;
    }
    vector<QString> record;
    std::string line;
    while (!file.eof() ){
        std::getline(file, line);
        record.push_back(line.c_str());
        std::cout << line << "\n";
        if (record.size() == 4){
            Member m = {};
            m.expiration_date = record[3];
            m.name = record[0];
            m.number = record[1];
            m.type = record[2];
        members.push_back(m);
            record.erase(record.begin(),record.end());
            std::getline(file, line);
    }
    }

    //while (file >> name >> number >> type >> expiration_date) {
    //    Member m = Member(name, number, type, expiration_date, 0.0, 0.0);
    //    members.push_back(m);
    //}

    file.close();
    return true;
}

void BulkClub::updateMemberInfo(const Member& member)
{
    members.push_back(member);
}

void BulkClub::updateDailySales(void)
{
    dailyPurchases.deleteAllPurchases();

   for (int day = 1; day <= 7; day++) {
        string filename = "../day" + to_string(day) + ".txt";

        // Read purchases from file
        if (dailyPurchases.readFromFile(filename)) {
            std::cout << "Successfully read purchases from file!" << std::endl;
        }
   }

    //Slow way O(n^2 )
    for (Member& m : members) {
        std::vector<Purchase> purchases = dailyPurchases.getPurchases();

        for (auto it = purchases.begin(); it != purchases.end(); ++it) {
            const Purchase& purchase = *it;

            if (purchase.membershipNumber == m.number) {
                m.total_spent += purchase.salesPrice * purchase.quantityPurchased;
                if (m.type == "Executive") {
                    double rebate = purchase.salesPrice * purchase.quantityPurchased * 0.02;
                    m.rebate_amount += rebate;
                }
            }
        }
    }
}
QString BulkClub::displaySalesReport(int day)
{
    DailyPurchases dayPurchases;
    QString buildFolderPath = QCoreApplication::applicationDirPath();
    QString filePath = buildFolderPath;
    QString itemDetails;
    QString memberNames;
    // Get the purchases for the given day
    string filename = filePath.toStdString() + "/day" + to_string(day) + ".txt";

    if (!dayPurchases.readFromFile(filename)) {
        std::cerr << "Error: Could not read purchases for day " << day << std::endl;
        return "";
    }
    // Display the sales report
    std::cout << "Sales Report for Day " << day << std::endl;
    // Calculate total revenue (including tax) for the given day
    double totalRevenue = 0.0;
    std::vector<Purchase> purchases = dayPurchases.getPurchases();
    for (const Purchase& purchase : purchases) {
        totalRevenue += purchase.salesPrice * purchase.quantityPurchased;
    }
    std::cout << "Total Revenue: $" << totalRevenue << std::endl;
    // Create the sales report HTML content
    QString report = QString("<html><body>"
                             "<h2>Sales Report for Day %1</h2>"
                             "<p>Total Revenue: $%2</p>"
                             "<h3>Items sold on Day %1:</h3>"
                             "<ul>")
                     .arg(day)
                     .arg(totalRevenue, 0, 'f', 2);

    // Get the unique members who shopped on the given day
    std::vector<QString> uniqueExecutiveMembers;
    std::vector<QString> uniqueRegularMembers;
    for (const Purchase& purchase : purchases) {
        const QString membershipNumber = purchase.membershipNumber;
        //bool isExecutiveMember = false;
        for (const Member& member : members) {
            if (member.number == membershipNumber) {
                if (member.type == "Executive") {
                    if (std::find(uniqueExecutiveMembers.begin(), uniqueExecutiveMembers.end(), membershipNumber) == uniqueExecutiveMembers.end()) {
                        uniqueExecutiveMembers.push_back(membershipNumber);
                    }
                    //isExecutiveMember = true;
                } else if (member.type == "Regular") {
                    if (std::find(uniqueRegularMembers.begin(), uniqueRegularMembers.end(), membershipNumber) == uniqueRegularMembers.end()) {
                        uniqueRegularMembers.push_back(membershipNumber);
                    }
                }
                break;
            }
        }
    }

    // Display the list of items and quantities sold on the given day
    std::cout << "Items sold on Day " << day << ":" << std::endl;
    for (const Purchase& purchase : purchases) {
        std::cout << "Item: " << purchase.itemPurchased.toStdString() << ", Quantity: " << purchase.quantityPurchased<< std::endl;
        QString item = QString("<li>Item: %1, Quantity: %2</li>")
                       .arg(purchase.itemPurchased)
                       .arg(purchase.quantityPurchased);
        report += item;
    }

    // Display the names of the members who shopped on the given day
    std::cout << "Members who shopped on Day " << day << ":" << std::endl;
    report += QString("</ul>"
                      "<h3>Members who shopped on Day %1:</h3>"
                      "<ul>")
              .arg(day);

    for (const Purchase& purchase : purchases) {
        const QString& membershipNumber = purchase.membershipNumber;
        for (const Member& member : members) {
            if (member.number == membershipNumber) {
                std::cout << member.name.toStdString() << std::endl;
                QString memberName = QString("<li>%1</li>").arg(member.name);
                report += memberName;
                break;
            }
        }
    }

    // Display the number of unique Executive and Regular members who shopped on the given day
    std::cout << "Number of unique Executive members who shopped: " << uniqueExecutiveMembers.size() << std::endl;
    std::cout << "Number of unique Regular members who shopped: " << uniqueRegularMembers.size() << std::endl;
    report += QString("</ul>"
                      "<p>Number of unique Executive members who shopped: %1</p>"
                      "<p>Number of unique Regular members who shopped: %2</p>"
                      "</body></html>")
              .arg(uniqueExecutiveMembers.size())
              .arg(uniqueRegularMembers.size());

    return report;
}

void BulkClub::generateSalesReportByMembershipType(int day)
{
    // Get the purchases for the given day
    string filename = "day" + to_string(day) + ".txt";
    if (!dailyPurchases.readFromFile(filename)) {
    std::

    cerr << "Error: Could not read purchases for day " << day << std::endl;
    return;
    }

    // Calculate total revenue (including tax) for the given day by membership type
    double executiveRevenue = 0.0;
    double regularRevenue = 0.0;
    std::vector<Purchase> purchases = dailyPurchases.getPurchases();
    for (const Purchase& purchase : purchases) {
        const QString& membershipNumber = purchase.membershipNumber;
        for (const Member& member : members) {
            if (member.number == membershipNumber) {
                if (member.type == "Executive") {
                    executiveRevenue += purchase.salesPrice * purchase.quantityPurchased;
                }
                else if (member.type == "Regular") {
                    regularRevenue += purchase.salesPrice * purchase.quantityPurchased;
                }
                break;
            }
        }
    }

    // Display the sales report by membership type
    std::cout << "Sales Report for Day " << day << " (by Membership Type)" << std::endl;
    std::cout << "Executive Member Revenue: $" << std::fixed << std::setprecision(2) << executiveRevenue << std::endl;
    std::cout << "Regular Member Revenue: $" << std::fixed << std::setprecision(2) << regularRevenue << std::endl;

}
// Helper function to check if a member's number matches a given membership number
bool isMemberNumberMatch(const Member& member, const std::string& membershipNumber) {
    return member.number == membershipNumber.c_str();
}

void BulkClub::displayTotalPurchases() {
    std::map<QString, double> memberPurchases;
    double grandTotal = 0.0;

    for (const Member& member : members) {
        double memberTotal = 0.0;

        for (const Purchase& purchase : dailyPurchases.getPurchases()) {
            if (purchase.membershipNumber == member.number) {
                double purchaseTotal = purchase.salesPrice * purchase.quantityPurchased;
                memberTotal += purchaseTotal;
                grandTotal += purchaseTotal;
            }
        }

        memberPurchases[member.number] = memberTotal;
    }

    std::cout << "Total Purchases by Member (Sorted by Membership Number):" << std::endl;

    for (const auto& pair : memberPurchases) {
        const QString& membershipNumber = pair.first;
        const double totalPurchases = pair.second;

        // Find the member with the given membership number
        const Member* foundMember = nullptr;
        for (const Member& member : members) {
            if (member.number == membershipNumber) {
                foundMember = &member;
                break;
            }
        }

        if (foundMember != nullptr) {
            const Member& member = *foundMember;
            std::cout << "Member Name: " << member.name.toStdString() << std::endl;
            std::cout << "Membership Number: " << member.number.toStdString() << std::endl;
            std::cout << "Total Purchases (Including Tax): $" << std::fixed << std::setprecision(2) << totalPurchases << std::endl;
            std::cout << "------------------------------" << std::endl;
        }
    }

    std::cout << "Grand Total of All Purchases (Including Tax): $" << std::fixed << std::setprecision(2) << grandTotal << std::endl;
}


void BulkClub::displayItemSales() const
{
    // Map to store item name as key and sales quantity and revenue as values
    std::map<std::string, std::pair<int, double > > itemSales;

    // Calculate item sales quantity and revenue
    for (const Purchase& purchase : dailyPurchases.getPurchases()) {
        std::string itemName = purchase.itemPurchased.toStdString();
        double revenue = purchase.salesPrice * purchase.quantityPurchased;

        // Check if item already exists in the map
        if (itemSales.find(itemName) != itemSales.end()) {
            // Update the quantity and revenue
            itemSales[itemName].first += purchase.quantityPurchased;
            itemSales[itemName].second += revenue;
        } else {
            // Add the item to the map
            itemSales[itemName] = std::make_pair(purchase.quantityPurchased, revenue);
        }
    }

    // Display the item sales
    std::cout << "Item Sales Report:" << std::endl;
    std::cout << "------------------" << std::endl;

    for (const auto& entry : itemSales) {
        std::string itemName = entry.first;
        int quantitySold = entry.second.first;
        double revenue = entry.second.second;

        std::cout << "Item Name: " << itemName << std::endl;
        std::cout << "Quantity Sold: " << quantitySold << std::endl;
        std::cout << "Total Revenue: " << revenue << std::endl;
        std::cout << "------------------" << std::endl;
    }
}

// Comparison function for sorting Executive members by membership number
bool compareByMembershipNumber(const Member& m1, const Member& m2) {
    return m1.number < m2.number;
}

void BulkClub::displayExecutiveMemberRebates(){
    // Create a vector to store Executive members' rebates
    std::vector<Member> executiveMembers;

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

    QMessageBox::information(nullptr, "Rebate Total", QString("Total Rebate Amount: $%1").arg(rebateTotal));
}

void BulkClub::displayExpiringMembers(const std::string& month) const {
    std::cout << "Memberships Expiring in " << month << ":" << std::endl;

    // Filter members whose expiration month matches the provided month
    std::vector<Member> expiringMembers;
    for (const Member& m : members) {
        std::string memberExpirationMonth = (m.expiration_date.toStdString()).substr(0, 2);
        if (memberExpirationMonth == month) {
            expiringMembers.push_back(m);
        }
    }

    // Sort expiring members by membership number
    std::sort(expiringMembers.begin(), expiringMembers.end(), compareByMembershipNumber);

    // Display expiring members and their renewal cost
    for (const Member& m : expiringMembers) {
        double renewalCost = calculateMembershipRenewalCost(m);
        std::cout << "Membership Number: " << m.number.toStdString() << std::endl;
        std::cout << "Name: " << m.name.toStdString() << std::endl;
        std::cout << "Renewal Cost: $" << std::fixed << std::setprecision(2) << renewalCost << std::endl;
        std::cout << std::endl;
    }
}
std::vector<Member> BulkClub::displayExpiringMembers(int month) {
    std::vector<Member> expiredMembers;

    // Check for expired members
    for (const Member& member : members) {
        //std::istringstream(member.expiration_date) >> std::get_time(&expirationDate, "%m/%d/%Y");
        std::tm expirationDate = parseDate(member.expiration_date);
        if (expirationDate.tm_mon < month ) {
            expiredMembers.push_back(member);
        }
    }

    return expiredMembers;
}
std::vector<Member> BulkClub::displayExpiringMembers(int month, int day, int year) {
    std::vector<Member> expiredMembers;

    // Check for expired members
    for (const Member& member : members) {
        //std::istringstream(member.expiration_date) >> std::get_time(&expirationDate, "%m/%d/%Y");
        std::tm expirationDate = parseDate(member.expiration_date);
        if (/*expirationDate.tm_mon < month && expirationDate.tm_mday == day  &&*/ expirationDate.tm_year < year) {
            expiredMembers.push_back(member);
        }
    }

    return expiredMembers;
}

double BulkClub::calculateMembershipRenewalCost(const Member& member) const {
    // Calculate the renewal cost based on the member's membership type and total spent
    if (member.type == "Executive") {
        // Executive members receive a 10% discount on their renewal cost
        double renewalCost = 0.9 * EXECUTIVE_MEMBERSHIP_FEE;
        return renewalCost;
    } else if (member.type == "Regular") {
        // Regular members pay the full membership fee
        return REGULAR_MEMBERSHIP_FEE;
    } else {
        // Unknown membership type, return 0 as the renewal cost
        return 0.0;
    }
}

void BulkClub::displayItemSales(const std::string& itemName)
{
    int totalQuantitySold = 0;
    double totalRevenue = 0.0;

    // Iterate through each purchase
    for (const Purchase& purchase : dailyPurchases.getPurchases()) {
        if (purchase.itemPurchased == itemName.c_str()) {
            totalQuantitySold += purchase.quantityPurchased;
            totalRevenue += purchase.salesPrice * purchase.quantityPurchased;
        }
    }

    // Display the results
    std::cout << "Item: " << itemName << std::endl;
    std::cout << "Total Quantity Sold: " << totalQuantitySold << std::endl;
    std::cout << "Total Revenue: $" << totalRevenue << std::endl;
}

void BulkClub::displayTotalPurchasesForMember(const std::string& memberInfo) const {
    bool found = false;
    //double totalPurchases = 0.0;

    // Search for the member by membership number or name
    for (const Member& member : members) {
        if (member.number == memberInfo.c_str() || member.name == memberInfo.c_str()) {
            found = true;
            const double taxRate = 0.0775; // 7 3/4% sales tax rate
            double totalRevenue = 0.0;

            // Calculate the total purchases for the member
            for (const Purchase& purchase : dailyPurchases.getPurchases()) {
                if (purchase.membershipNumber == member.number) {
                    double purchaseTotal = purchase.salesPrice * purchase.quantityPurchased;
                    double taxAmount = purchaseTotal * taxRate;
                    totalRevenue += purchaseTotal + taxAmount;
                }
            }

            std::cout << "Member: " << member.name.toStdString() << std::endl;
            std::cout << "Membership Number: " << member.number.toStdString() << std::endl;
            std::cout << "Total Purchases (Including Tax): $" << totalRevenue << std::endl;

            break; // Stop searching after finding the member
        }
    }

    if (!found) {
        std::cout << "Member not found." << std::endl;
    }
}

void BulkClub::recommendMembershipConversion() const {
    //@brief
    int recommendedConversions = 0;

    for (const Member& member : members) {
        if (member.type == "Regular") {
            double totalSpent = 0.0;

            // Calculate the total spent by the member
            for (const Purchase& purchase : dailyPurchases.getPurchases()) {
                if (purchase.membershipNumber == member.number) {
                    totalSpent += purchase.salesPrice * purchase.quantityPurchased;
                }
            }

            if (totalSpent >= 2000.0) {
                recommendedConversions++;
            }
        }
    }

    std::cout << "Number of recommended conversions: " << recommendedConversions << std::endl;
}

int BulkClub::countRecommendedExecutiveToRegularConversions() const
{
    int conversionCount = 0;

    for (const Member& m : members) {
        if (m.type == "Executive") {
            // Calculate the total rebate amount earned by the Executive member
            double totalRebateAmount = 0.0;
            for (const Purchase& p : dailyPurchases.getPurchases()) {
                if (p.membershipNumber == m.number) {
                    totalRebateAmount += p.salesPrice * p.quantityPurchased * 0.02;
                }
            }
            // Check if the total rebate amount is below the conversion threshold
            if (totalRebateAmount < EXEC_TO_REGULAR_THRESHOLD) {
                conversionCount++;
            }
        }
    }

    return conversionCount;
}

std::tm BulkClub::parseDate(const QString& dateStr) {
    std::tm datetm={};
    std::string date = dateStr.toStdString();
    std::istringstream iss(date);

    std::string monthStr, dayStr, yearStr;
    getline(iss, monthStr, '/');
    getline(iss, dayStr, '/');
    getline(iss, yearStr);

    int month = std::stoi(monthStr);
    int day = std::stoi(dayStr);
    int year = std::stoi(yearStr);

    datetm.tm_year=year;
    datetm.tm_mon=month;
    datetm.tm_mday=day;

    return datetm;
}
void BulkClub::saveMemberList(const std::string& filename)  {
    std::ofstream outFile(filename, std::ios::out | std::ios::trunc);
    if (!outFile.is_open()) {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }

    for (const auto& member : members) {
        outFile << member.name.toStdString() << "\n"
                << member.number.toStdString() << "\n"
                << member.type.toStdString() << "\n"
                << member.expiration_date.toStdString() << "\n"
                << "\n";
    }

    outFile.close();
}
bool BulkClub::deleteMember(const Member& member) {
    auto it = std::find_if(members.begin(), members.end(), [&](const Member& m) {
        return (m.number == member.number && m.name == member.name);
    });

    if (it != members.end()) {
        members.erase(it);
        return true;
    }

    return false;
}

Member* BulkClub::findMember(const Member& memberInfo) {
    auto it = std::find_if(members.begin(), members.end(), [&](const Member& member) {
        return (member.number == memberInfo.number && member.name == memberInfo.name);
    });

    if (it != members.end()) {
        return &(*it);
    }

    return nullptr;
}
