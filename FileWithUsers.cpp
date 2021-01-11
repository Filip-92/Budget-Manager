#include "FileWithUsers.h"

void FileWithUsers::addUserToFile (User user)
{
    CMarkup xml;
    bool fileExists = xml.Load( getNameFile() );
    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getUserId());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());
    xml.Save(getNameFile());
}
vector <User> FileWithUsers::loadUsersFromFile()
{
    vector<User> users;
    CMarkup xml;
    int i = 0;
    xml.Load(getNameFile());
    while (xml.FindChildElem("User"))
    {
        users.push_back(User());
        xml.IntoElem();
        xml.FindChildElem("UserId");
        users[i].setUserId(atoi(xml.GetChildData().c_str()));
        xml.FindChildElem("Login");
        users[i].setLogin(xml.GetChildData());
        xml.FindChildElem("Password");
        users[i].setPassword(xml.GetChildData());
        xml.FindChildElem("Name");
        users[i].setName(xml.GetChildData());
        xml.FindChildElem("Surname");
        users[i].setSurname(xml.GetChildData());
        xml.OutOfElem();
        i++;
    }

    return users;
}
void FileWithUsers::changePasswordSignInUser (User loggedInUser)
{
    CMarkup xml;
    xml.Load(getNameFile());
    while (xml.FindChildElem("User"))
    {
        xml.IntoElem();
        xml.FindChildElem("UserId");
        if (atoi(xml.GetChildData().c_str()) == loggedInUser.getUserId())
        {
            xml.FindChildElem("Password");
            xml.RemoveChildElem();
            xml.AddChildElem("Password", loggedInUser.getPassword());
            xml.Save(getNameFile());
            return;
        }
        xml.OutOfElem();
    }
}




