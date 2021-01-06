#include "XmlFile.h"

/*bool XmlFile::isFileEmpty()
{
    bool empty = true;
    fstream xmlFile;
    xmlFile.open(getFileName().c_str(), ios::app);

    if (xmlFile.good() == true)
    {
        xmlFile.seekg(0, ios::end);
        if (xmlFile.tellg() != 0)
            empty = false;
    }

    xmlFile.close();
    return empty;
}

string XmlFile::getFileName()
{
    return FILE_NAME;
}*/

XmlFile::XmlFile(string fileName):FILE_NAME(fileName){}

XmlFile::XmlFile():FILE_NAME("textxml.xml"){};
