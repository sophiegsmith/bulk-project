#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <iomanip>

using namespace std;

struct Membership {
    string name;
    string number;
    string type;
    string expiration_date;
    double total_spent;
    double rebate_amount;
};

int main() {
    // Read membership information from warehouse_shoppers.txt
    ifstream membership_file("warehouse_shoppers.txt");
    vector<Membership> memberships;

    if (!membership_file) {
        cerr << "Error: Membership file could not be opened" << endl;
        return 1;
    }

    string name, number, type, expiration_date;
    while (membership_file >> name >> number >> type >> expiration_date) {
        Membership m = {name, number, type, expiration_date, 0, 0};
        memberships.push_back(m);
    }

    // Read purchase information from day1.txt through day7.txt
    unordered_map<string, double> rebate_eligible;
    for (int day = 1; day <= 7; day++) {
        string filename = "day" + to_string(day) + ".txt";
        ifstream purchase_file(filename);

        if (!purchase_file) {
            cerr << "Error: Purchase file " << filename << " could not be opened" << endl;
            continue;
        }

        string date, number, item;
        double price;
        int quantity;

        while (purchase_file >> date >> number >> item >> price >> quantity) {
            for (Membership& m : memberships) {
                if (m.number == number) {
                    m.total_spent += price * quantity;

                    if (m.type == "Executive") {
                        double rebate = price * quantity * 0.02;
                        m.rebate_amount += rebate;
                        rebate_eligible[m.number] += rebate;
                    }
                }
            }
        }
    }

    // Print updated membership information
    cout << left << setw(20) << "Name"
         << setw(20) << "Membership Number"
         << setw(15) << "Type"
         << setw(20) << "Expiration Date"
         << setw(25) << "Total Amount Spent"
         << setw(20) << "Rebate Amount"
         << endl;

    for (Membership m : memberships) {
        cout << left << setw(20) << m.name
             << setw(20) << m.number
             << setw(15) << m.type
             << setw(20) << m.expiration_date
             << setw(25) << fixed << setprecision(2) << m.total_spent
             << setw(20) << fixed << setprecision(2) << m.rebate_amount;

        cout << endl;
    }

    // Print total rebate amount for all Executive members
    double total_rebate = 0;
    for (Membership m : memberships) {
        if (m.type == "Executive") {
            total_rebate += rebate_eligible[m.number];
        }
    }
    cout << "Total Rebate Amount for all Executive Members: $" << fixed << setprecision(2) << total_rebate << endl;

    return 0;
}
