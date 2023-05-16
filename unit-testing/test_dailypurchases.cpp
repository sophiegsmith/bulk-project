#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <iomanip>
#include <string>
#include "../dailypurchases.hpp"

using namespace std;

int main() {
    DailyPurchases dailyPurchases;


   for (int day = 1; day <= 7; day++) {
        string filename = "../day" + to_string(day) + ".txt";

        // Read purchases from file
        if (dailyPurchases.readFromFile(filename)) {
            std::cout << "Successfully read purchases from file!" << std::endl;
        }
   }

    // Print out all purchases
    std::vector<Purchase> purchases = dailyPurchases.getPurchases();

    for (const auto& p : purchases) {
        std::cout << "Purchase date: " << p.purchaseDate << std::endl;
        std::cout << "Membership number: " << p.membershipNumber << std::endl;
        std::cout << "Item purchased: " << p.itemPurchased << std::endl;
        std::cout << "Sales price: " << p.salesPrice << std::endl;
        std::cout << "Quantity purchased: " << p.quantityPurchased << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
