#include <algorithm>

#include "AuxiliaryMethods.h"

double AuxiliaryMethods::fixDouble(string number)
{
    size_t found;
    found=number.find(',');
    if (found!=string::npos)
        number.replace(found,1,1,'.');
    return stod(number);
}
