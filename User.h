#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User
{
    int userId;
    string login;
    string password;
    string name;
    string surname;
public:
    void setLogin(string);
    void setPassword(string);
    void setName(string);
    void setSurname(string);
    void setUserId(int);

    string getLogin ();
    string getPassword ();
    string getName ();
    string getSurname ();
    int getUserId ();
};
#endif
