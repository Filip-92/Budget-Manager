#ifndef TEXTFILE_H
#define TEXTFILE_H

#include <iostream>
#include "Markup.h"

using namespace std;

class TextFile
{
        const string NAME_FILE;

public:

    TextFile(string nameFile) : NAME_FILE(nameFile) {
    }

    string getNameFile()
    {
        return NAME_FILE;
    }
};
#endif
