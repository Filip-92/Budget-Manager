#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "User.h"
#include "FileWithUsers.h"
#include "AuxiliaryMethods.h"
#include <vector>
#include <algorithm>

using namespace std;

class UserManager
{
    FileWithUsers fileWithUsers;
    AuxiliaryMethods auxiliaryMethods;
    vector<User> users;

    User inputNewUserData();
    User loggedInUser;
    int getNewUserId();
    bool doesLoginExist(string login);
    bool doesUserExist(string, string);
    string changeTheFirstLetterToUppercaseAndTheRestToLowercase(string text);

public:
    UserManager (string nameFileWithUsers): fileWithUsers (nameFileWithUsers)
    {
        users = fileWithUsers.loadUsersFromFile();
        loggedInUser.setUserId(0);
    };
    void userRegistration();
    void displayAllUsers();
    int userLogIn();
    void signOutUser ();
    bool isTheUserSignIn();
    User getLoggedInUser();
    void changePasswordOfLoggedUser ();

};
#endif
