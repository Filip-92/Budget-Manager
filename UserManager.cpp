#include "UserManager.h"

void UserManager::userRegistration()
{
    User user = inputNewUserData();

    users.push_back(user);
    fileWithUsers.addUserToFile(user);

    cout << endl << "Account has been created successfully." << endl << endl;
    system("pause");
}

User UserManager::inputNewUserData()
{
    User user;

    user.setUserId(getNewUserId());
    string name, surname, login;
    do
    {
        cout << endl << "Input name: ";
        cin >> name;
        cout << "Input surname: ";
        cin >> surname;
        user.setName(name);
        user.setSurname(surname);
    } while (doesUserExist(name, surname));

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
        return users.back().getUserId() + 1;
}

bool UserManager::doesLoginExist(string login)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            {
                cout << endl << "User with such login already exists." << endl;
                return true;
            }
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

void UserManager::displayAllUsers()
{
    for (int i = 0; i < users.size(); i++)
    {
        cout << users[i].getUserId() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;
        cout << users[i].getName() << endl;
        cout << users[i].getSurname() << endl;
    }
}

string UserManager::changeTheFirstLetterToUppercaseAndTheRestToLowercase(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

int UserManager::userLogIn()
{
    User user;
    string login = "", password= "";

    cout << endl << "Input login: ";
    login = auxiliaryMethods.loadLine();

    for (int i = 0 ; i < users.size(); i++)
    {
        if (login == users[i].getLogin())
        {
            for (int attempt = 3; attempt > 0; attempt--)
            {
                cout << "Enter your password. Attempts left: "  << attempt << ": ";
                password = auxiliaryMethods.loadLine();

                if (users[i].getPassword() == password)
                {
                    cout << endl << "Logged in successfully." << endl << endl;
                    system("pause");
                    loggedInUser.setLogin(users[i].getLogin());
                    loggedInUser.setPassword(users[i].getPassword());
                    loggedInUser.setUserId(users[i].getUserId());
                    loggedInUser.setName(users[i].getName());
                    loggedInUser.setSurname(users[i].getSurname());
                    return loggedInUser.getUserId();
                }
            }
            cout << "Incorrect password has been entered 3 times." << endl;
            system("pause");
            return 0;
        }
    }
    cout << "No user with such login exists." << endl << endl;
    system("pause");
    return 0;
}

void UserManager::signOutUser ()
{
    loggedInUser.setUserId(0);
}

bool UserManager::isTheUserSignIn()
{
    if (loggedInUser.getUserId() > 0)
        return true;
    else
        return false;
}

User UserManager::getLoggedInUser()
{
    return loggedInUser;
}

void UserManager::changePasswordOfLoggedUser ()
{
    system("cls");
    string newPassword = "";
    string newPassword1 = "";
    cout << "Input new password: ";
    newPassword = auxiliaryMethods.loadLine();;
    cout << "Please repeat your new password: ";
    newPassword1 = auxiliaryMethods.loadLine();;

    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getUserId () == loggedInUser.getUserId())
        {
            if (newPassword == newPassword1)
            {
            users[i].setPassword(newPassword);
            loggedInUser.setPassword(newPassword);
            cout << "Password has been changed successfully." << endl << endl;
            system("pause");
            }
            else
                cout << "Passwords do not match each other. Try again.";
        }
    }
    fileWithUsers.changePasswordSignInUser (loggedInUser);
}
