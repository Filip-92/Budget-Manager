#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H
#include <iostream>
#include <sstream>

using namespace std;

class AuxiliaryMethods
{
    public:
    string loadLine();
    char loadCharacter();
    int conversionStringToInt(string integer);
    string converionIntToString(int integer);
    string converionFloatToString( float number);
};
#endif
