#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>
#include "Markup.h"

using namespace std;

class XmlFile
{
        const string NAME_FILE;

public:

    XmlFile(string nameFile) : NAME_FILE(nameFile) {
    }

    string getNameFile()
    {
        return NAME_FILE;
    }
};
#endif
