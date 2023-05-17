#include "member.h"

Member::Member() : name(""), number(0), type(""), expiration(Date{0,0,0}), total(0.0), rebate(0.0)
{
}

Member::Member(string name, int number, string type, Date expiration, double total, double rebate) : name(name), number(number), type(type), expiration(expiration), total(total), rebate(rebate)
{
}


bool Member::isName(string name)
{
    return this->name == name;
}

bool Member::isNumber(int number)
{
    return this->number == number;
}

void Member::addPurchase(double number)
{
    total += number * (1.00 / 1.0775);
    rebate = total * 0.02;
}

double Member::getTotalWithTax()
{
    return total * 1.0775;
}

double Member::getRebate()
{
    return rebate;
}

Date Member::expirationDate()
{
    return expiration;
}
