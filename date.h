#ifndef DATE_H
#define DATE_H
#include <string>

using namespace std;

struct Date
{
    int month;
    int date;
    int year;
};

bool operator==(const Date& lhs, const Date& rhs);

#endif
