
#include "../bulkclub.hpp"

int main() {
    BulkClub club;

    // Read membership information from a file
    if (club.readFromFile("../warehouse_shoppers.txt")) {
        cout << "Membership information successfully loaded." << endl;
    } else {
        cout << "Failed to load membership information." << endl;
        return 1;
    }

    // Update daily sales
    club.updateDailySales();

    // Display sales report for a specific day
    club.displaySalesReport(1);

    // Generate sales report by membership type for a specific day
    club.generateSalesReportByMembershipType(1);

    // Display total purchases for each member
    club.displayTotalPurchases();

    // Display quantity of each item sold and total revenue
    club.displayItemSales();

    // Display rebates of all Executive members
    club.displayExecutiveMemberRebates();

    // Display expiring members for a specific month
    club.displayExpiringMembers("May");

    // Calculate membership renewal cost for a specific member
    Member memberToRenew;
    // Set member information
    double renewalCost = club.calculateMembershipRenewalCost(memberToRenew);
    cout << "Membership renewal cost: $" << renewalCost << endl;

    // Display quantity and revenue for a specific item
    club.displayItemSales("ItemName");

    // Display total purchases including tax for a specific member
    club.displayTotalPurchasesForMember("John Doe");

    // Recommend membership conversion for Regular customers
    club.recommendMembershipConversion();

    // Count recommended membership conversions from Executive to Regular
    int conversionCount = club.countRecommendedExecutiveToRegularConversions();
    cout << "Recommended Executive to Regular conversions: " << conversionCount << endl;

    return 0;
}
