#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "Date.h"
using namespace std;

class Item{
public:
    string name;
    int quantity;
    double revenue;
    double price;
    Item();
    Item(string name, int quantity, double revenue, double price);
    bool isName(string name);
    void changePrice(double price);
};

#endif
