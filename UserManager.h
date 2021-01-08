#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <vector>
#include <algorithm>

#include "User.h"
#include "FileWithUsers.h"

using namespace std;

class UserManager
{
    int loggedInUserId;
    vector <User> users;

    User inputNewUserData();
    User loggedInUser;
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
    string changeTheFirstLetterToUppercaseAndTheRestToLowercase(string text);
    void displayAllUsers();
    void userLogout();
    bool isUserLoggedIn();
    int getLoggedInUserId();
    int userLoggingIn();
    void changePasswordOfLoggedUser();
    void saveAllUsersInTheFile();
};

#endif
