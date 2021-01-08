#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include <windows.h>
#include "XmlFile.h"
#include "Markup.h"
#include <cstdlib>

#include "User.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithUsers : public XmlFile
{
public:
    FileWithUsers(string fileWithUsersName) : XmlFile(fileWithUsersName) {};
    void saveUsersToFile(vector <User> users);
    vector <User> loadUsersFromTheFile();
};

#endif
