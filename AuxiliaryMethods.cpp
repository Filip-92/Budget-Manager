#include "AuxiliaryMethods.h"


string AuxiliaryMethods::loadLine()
{
    string in = "";
    getline(cin, in);
    return in;
}
char AuxiliaryMethods::loadCharacter()
{
    string in = "";
    char character  = {0};

    while (true)
    {
        getline(cin, in);

        if (in.length() == 1)
        {
            character = in[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return character;
}
int AuxiliaryMethods::conversionStringToInt(string integer)
{
    int number;
    istringstream iss(integer);
    iss >> number;

    return number;
}
string AuxiliaryMethods::converionIntToString(int integer)
{
    ostringstream ss;
    ss << integer;
    string str = ss.str();
    return str;
}
string AuxiliaryMethods::converionFloatToString( float number )
{
    stringstream FloatToStr;
    string str;

    FloatToStr << number;
    FloatToStr >> str;
    FloatToStr.clear();

    return str;
}
