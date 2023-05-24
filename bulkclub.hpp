/**
 * @brief A class to represent the membership information file.
 */
#include <QString>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <vector>
#include <ctime>
#include <iomanip>
#include <sstream>

using namespace std;

#include "dailypurchases.hpp"
typedef struct Member {
    QString name;
    QString number;
    QString type;
    QString expiration_date;
    double total_spent;
    double rebate_amount;
    Member(QString name, QString number, QString type, QString expiration_date, double total_spent, double rebate_amount) {
        this->name = name;
        this->number = number;
        this->type = type;
        this->expiration_date = expiration_date;
        this->total_spent = total_spent;
        this->rebate_amount = rebate_amount;
    }
      // Default constructor
    Member() : name(""), number(""), type(""), expiration_date(""), total_spent(0.0), rebate_amount(0.0) {}

    ~Member() {}
    bool empty() {
        return (this->name == "" && this->number == "" && this->type == "" && this->expiration_date == "" && this->total_spent == 0.0 && this->rebate_amount == 0.0);
    }

}Member;

const double EXEC_TO_REGULAR_THRESHOLD = 200.00;
const double EXECUTIVE_MEMBERSHIP_FEE = 500.00;
const double REGULAR_MEMBERSHIP_FEE = 100.00;

class BulkClub {
public:
    /**
     * @brief Default constructor for the BulkClub class.
     */
    BulkClub();

    /**
     * @brief Destructor for the BulkClub class.
     */
    ~BulkClub();

    /**
     * @brief Reads membership information from a file and populates the members vector.
     *
     * @param filename The name of the file to read from.
     *
     * @return True if the file was successfully read and members were populated, false otherwise.
     */
    bool readFromFile(const std::string& filename);

    /**
     * @brief Updates the membership information with the provided member.
     *
     * @param member The member to add to the membership information.
     */
    void updateMemberInfo(const Member& member);

    /**
     * @brief Updates daily sales.
     *
     */
    void updateDailySales(void);

    /**
     * @brief Display a sales report for a given day.
     *
     * @param day The day to generate the report.
     */
    QString displaySalesReport(int day);

    /**
     * @brief Generate the sales report (including tax) for a given day by membership type.
     *
     * @param day The day to generate the report.
     */
    void generateSalesReportByMembershipType(int day);

    /**
     * @brief Display the total purchases for each member, including tax, sorted by membership number.
     *
     */
    void displayTotalPurchases(void);

    /**
     * @brief Display the quantity of each item sold, sorted by item name, and the total revenue (without tax) for each item.
     *
     */
    void displayItemSales() const;

    /**
     * @brief Display the rebate of all the Executive members, sorted by membership number.
     *        Rebates are based on purchases before tax.
     *
     */
    void displayExecutiveMemberRebates() const;

    /**
     * @brief Display all members whose memberships expire in a given month, as well as the cost to renew their memberships.
     *
     * @param month The month for which to display expiring members.
     */
    void displayExpiringMembers(const std::string& month) const;
    std::vector<Member> displayExpiringMembers(int month);
    std::vector<Member> displayExpiringMembers(int month, int day, int year);

    /**
     * @brief Calculate the renewal cost based on the member's current membership information.
     *
     * @param member The member for which to calculate the renewal cost.
     * @return The renewal cost for the member.
     */
    double calculateMembershipRenewalCost(const Member& member) const;

    /**
     * @brief Display the quantity of a specific item sold, as well as the total revenue (without tax) for the item.
     *        No other items should be displayed.
     *
     * @param itemName The name of the item to display sales for.
     */
    void displayItemSales(const std::string& itemName);

    /**
     * @brief Enter a membership number or name and display the total purchases including tax for that member.
     *
     * @param memberInfo The membership number or name of the member.
     */
    void displayTotalPurchasesForMember(const std::string& memberInfo) const;

    /**
     * @brief Determine if any Regular customer should convert their membership to Executive status using the given sales data.
     *        Display the number of recommended conversions.
     *
     */
    void recommendMembershipConversion() const;

    /**
     * @brief Determine if any Executive customer should convert their membership to Regular status using the given sales data.
     *        Display the number of recommended conversions.
     *
     * @return The number of recommended Executive to Regular membership conversions.
    */
    int countRecommendedExecutiveToRegularConversions() const;

    /**
     * @brief Save the member list to a file.
     *
     * @param filename The name of the file to save the member list to.
     *
     */
    void saveMemberList(const std::string& filename);
    /**
     * @brief Get the list of members.
     *
     * @return A vector containing all the members.
     */
    std::vector<Member> getMembers() const{
        return members;
    }
    /**
     * @brief Delete a member from the membership list.
     *
     * @param memberInfo The membership number or name of the member to delete.
     * @return True if the member was successfully deleted, false otherwise.
     */
    bool deleteMember(const Member& member);

    /**
     * @brief Find a member in the membership list by membership number or name.
     *
     * @param memberInfo The membership number or name of the member to find.
     * @return A pointer to the found member, or nullptr if the member was not found.
     */
    Member* findMember(const Member& member);

    // ... existing member function declarations ...

    private:
        std::tm parseDate(const QString& dateStr);
        vector<string> splitString(const string& line, char delimiter);
        std::vector<Member> members;  /**< The list of members. */
        DailyPurchases dailyPurchases;  /**< The list of total daily sales. */

};
