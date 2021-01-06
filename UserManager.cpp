#include "UserManager.h"

User UserManager::inputNewUserData()
{
    User user;

    user.setId(getNewUserId());

    string name, surname, login;
    //do
    {
        cout << "Input name: ";
        cin >> name;
        cout << "Input surname: ";
        cin >> surname;
        user.setName(name);
        user.setSurname(surname);
    } //while (doesUserExist(user.getName()) == true && (user.getSurname()) == true);

    do
    {
        cout << "Input login: ";
        cin >> login;
        user.setLogin(login);
    } while (doesLoginExist(user.getLogin()) == true);

    string password;
    cout << "Input password: ";
    cin >> password;
    user.setPassword(password);

    return user;
}

int UserManager::getNewUserId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::doesLoginExist(string login)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            cout <<  "User with such login already exists." << endl;
            return true;
        }
    }
    return false;
}

bool UserManager::doesUserExist(string name, string surname)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getName() == name && users[i].getSurname() == surname)
        {
            cout <<  "User with such credentials is already registered." << endl;
            return true;
        }
    }
    return false;
}

int UserManager::userLoggingIn()
{
    User user;
    string login = "", password = "";

    cout << "Input login: ";
    cin >> login;

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr->getLogin() == login)
        {
            for (int attempts = 3; attempts > 0; attempts--)
            {
                cout << "Input your password. Attempts left: " << attempts << ": ";
                cin >> password;
                user.setPassword(password);

                if (itr->getPassword() == password)
                {
                    cout << endl << "Logged in successfully." << endl << endl;
                    system("pause");
                    loggedInUserId = itr->getId();
                    return loggedInUserId;
                }
            }
            cout << "Incorrect password has been input 3 times." << endl;
            system("pause");
            return 0;
        }
        itr++;
    }
    cout << "No user with such login exists." << endl << endl;
    system("pause");
    return 0;
}

void UserManager::userLogout()
{
    loggedInUserId = 0;
}

bool UserManager::isUserLoggedIn()
{
    if (loggedInUserId > 0) {
        return true;
    }
    else
        return false;
}

int UserManager::getLoggedInUserId()
{
    return loggedInUserId;
}

void UserManager::userRegistration() {

    User user = inputNewUserData();
    users.push_back(user);
    fileWithUsers.saveUsersToFile(users);

    cout << endl << "Account has been created successfully" << endl << endl;
    system("pause");
}

void UserManager::changePasswordOfLoggedUser()
{
    string newPassword = "";
    string newPassword1 = "";
    cout << "Input new password: ";
    cin >> newPassword;
    cout << "Please repeat your new password: ";
    cin >> newPassword1;

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr->getId() == loggedInUserId)
        {
            if (newPassword == newPassword1)
            {
            itr->setPassword(newPassword);
            cout << "Password has been changed successfully." << endl << endl;
            system("pause");
            }
            else
                cout << "Passwords do not match each other. Try again.";
        }
    }
    fileWithUsers.saveUsersToFile(users);
}

void UserManager::displayAllUsers()
{
    for (int i = 0; i < users.size(); i++) {
        cout << users[i].getId() << endl;
        cout << users[i].getName() << endl;
        cout << users[i].getSurname() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;
    }
}

void UserManager::saveAllUsersInTheFile()
{
    fileWithUsers.saveUsersToFile(users);
}
