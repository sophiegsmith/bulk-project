#include "item.h"

Item::Item() : name(""), quantity(0), revenue(0.0), price(0.0)
{
}

Item::Item(string name, int quantity, double revenue, double price) : name(name), quantity(quantity), revenue(revenue), price(price)
{
}

bool Item::isName(string name)
{
    return this->name == name;
}

void Item::changePrice(double price)
{
    this->price = price;
}
