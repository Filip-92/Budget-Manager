#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Markup.h"

using namespace std;

class XmlFile {

    const string FILE_NAME;

public:
    XmlFile();
    XmlFile(string fileName);
protected:
    virtual bool doesFileExist()=0;
    CMarkup xml;
};

#endif
