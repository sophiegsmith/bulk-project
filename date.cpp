#include "Date.h"

bool operator==(const Date& lhs, const Date& rhs)
{
    return (lhs.month == rhs.month) && (lhs.date == rhs.date) && (lhs.year == rhs.year);
}
