#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include "date.h"

using namespace std;

class Member{
public:
    string name;
    int number;
    string type;
    Date expiration;
    double total;
    double rebate;
  
    Member();
    Member(string name, int number, string type, Date expiration, double total, double rebate);
    bool isName(string name);
    bool isNumber(int number);
    void addPurchase(double number);
    double getTotalWithTax();
    double getRebate();
    Date expirationDate();
};

#endif
