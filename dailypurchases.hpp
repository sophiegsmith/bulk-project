#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// Define a Purchase struct to represent individual purchases
struct Purchase {
    std::string purchaseDate;
    std::string membershipNumber;
    std::string itemPurchased;
    double salesPrice;
    int quantityPurchased;
     // Default constructor
    Purchase() : purchaseDate(""), membershipNumber(""), itemPurchased(""), salesPrice(0.0), quantityPurchased(0) {}

    bool empty() const {
        return purchaseDate.empty() && membershipNumber.empty() && itemPurchased.empty() && salesPrice == 0.0 && quantityPurchased == 0;
    }
};

class DailyPurchases {
private:
    std::vector<Purchase> purchases;

public:
    // Default constructor
    DailyPurchases() {}

    // Destructor
    ~DailyPurchases() {}

    // Read purchases from file and add to purchases vector
    bool readFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error opening file: " << filename << std::endl;
            return false;
        }

        // Read in purchases from file
        Purchase p;
        while (file >> p.purchaseDate >> p.membershipNumber >> p.itemPurchased >> p.salesPrice >> p.quantityPurchased) {
            purchases.push_back(p);
            std::cout << "Read record: " << p.purchaseDate << " " << p.membershipNumber << " " << p.itemPurchased << " " << p.salesPrice << " " << p.quantityPurchased << std::endl;

        }

        file.close();
        return true;
    }

    // Add a new purchase to the purchases vector
    void addPurchase(const Purchase& p) {
        purchases.push_back(p);
    }

    // Delete a purchase from the purchases vector
    void deletePurchase(int index) {
        purchases.erase(purchases.begin() + index);
    }

    void deleteAllPurchases() {
        purchases.clear();
    }

    // Update a purchase in the purchases vector
    void updatePurchase(int index, const Purchase& p) {
        purchases[index] = p;
    }

    const Purchase& getPurchaseByMembershipNumber(const std::string& membershipNumber) const {

        for (const auto& p : purchases) {
            if (p.membershipNumber == membershipNumber) {
                return p;
            }
        }

    }

    // Getters
    std::vector<Purchase> getPurchases() const {
        return purchases;
    }
};


