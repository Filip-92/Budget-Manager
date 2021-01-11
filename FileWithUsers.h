#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include "TextFile.h"
#include "Markup.h"
#include "User.h"
#include <vector>

using namespace std;

class FileWithUsers : public TextFile
{
public:
    FileWithUsers(string nameFileWtihUsers) : TextFile(nameFileWtihUsers) {};
    void addUserToFile (User user);
    vector <User> loadUsersFromFile();
    void changePasswordSignInUser (User);

};
#endif
