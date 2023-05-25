#include <QString>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// Define a Purchase struct to represent individual purchases
typedef struct Purchase {
    QString purchaseDate;
    QString  membershipNumber;
    QString  itemPurchased;
    double salesPrice;
    int quantityPurchased;
     // Default constructor
    Purchase() : purchaseDate(""), membershipNumber(""), itemPurchased(""), salesPrice(0.0), quantityPurchased(0) {}

    bool empty() const {
        return purchaseDate.isEmpty() && membershipNumber.isEmpty() && itemPurchased.isEmpty() && salesPrice == 0.0 && quantityPurchased == 0;
    }
}Purchase;

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
        Purchase p ={};
        std::string pd,n,i,s,q;
        while (file >> pd >> n >> i >>  p.salesPrice  >> p.quantityPurchased){

            p.purchaseDate = pd.c_str();
            p.membershipNumber = n.c_str();
            p.itemPurchased= i.c_str();
            purchases.push_back(p);
            std::cout << "Read record: " << p.purchaseDate.toStdString() << " " << p.membershipNumber.toStdString() << " " << p.itemPurchased.toStdString() << " " << p.salesPrice << " " << p.quantityPurchased << std::endl;

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

    bool findPurchaseByMembershipNumber(const std::string& membershipNumber, const Purchase*& foundPurchase) const {
        for (const auto& p : purchases) {
            if (p.membershipNumber == membershipNumber.c_str()) {
                foundPurchase = &p;
                return true;
            }
        }
        return false;
    }

    // Getters
    std::vector<Purchase> getPurchases() const {
        return purchases;
    }
};


