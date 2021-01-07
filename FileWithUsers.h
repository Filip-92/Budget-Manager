#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include <windows.h>
#include "XmlFile.h"
#include <fstream>
#include <cstdlib>

#include "User.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithUsers : public XmlFile
{
    const string USERS_FILE_NAME;
public:
    FileWithUsers(string fileWithUsersName);
    bool doesFileExist();
    void saveUsersToFile(vector<User> users);
    vector <User> loadUsersFromTheFile();
};

#endif
