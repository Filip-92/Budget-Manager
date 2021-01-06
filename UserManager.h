#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"
#include "FileWithUsers.h"

using namespace std;

class UserManager
{
    int loggedInUserId;
    vector <User> users;

    User inputNewUserData();
    int getNewUserId();
    bool doesLoginExist(string login);
    bool doesUserExist(string name, string surname);
    FileWithUsers fileWithUsers;

  public:
    UserManager(string fileWithUsersName) : fileWithUsers(fileWithUsersName)
    {
    loggedInUserId = 0;
    users = fileWithUsers.loadUsersFromTheFile();
    };
    void userRegistration();
    void displayAllUsers();
    void userLogout();
    bool isUserLoggedIn();
    int getLoggedInUserId();
    int userLoggingIn();
    void changePasswordOfLoggedUser();
    void saveAllUsersInTheFile();
};

#endif
