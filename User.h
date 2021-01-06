#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H

#include <iostream>

using namespace std;

class User
{
        int id;
        string name;
        string surname;
        string login;
        string password;

    public:
        void setId(int newId);
        void setName(string newName);
        void setSurname(string newSurname);
        void setLogin(string newLogin);
        void setPassword(string newPassword);

        int getId();
        string getName();
        string getSurname();
        string getLogin();
        string getPassword();
        friend class FileWithUsers;
};

#endif
