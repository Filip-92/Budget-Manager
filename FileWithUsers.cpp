#include "FileWithUsers.h"

void FileWithUsers::saveUsersToFile (vector <User> users)
{
    CMarkup xml;
    bool fileExists = xml.Load( getNameFile() );
    if (!fileExists)
    {
        xml.SetDoc( "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n" );
        xml.AddElem("USERS");
    }
    xml.IntoElem();
    for (int i=0;i<users.size();i++)
    {
        xml.AddElem("USERS");
        xml.IntoElem();
        xml.AddElem("ID",users.at(i).getId());
        xml.AddElem("NAME",users.at(i).getName());
        xml.AddElem("SURNAME",users.at(i).getSurname());
        xml.AddElem("LOGIN",users.at(i).getLogin());
        xml.AddElem("PASSWORD",users.at(i).getPassword());
        xml.OutOfElem();
    }
    xml.Save(getNameFile());
}

vector <User> FileWithUsers::loadUsersFromTheFile()
{
    User user;
    vector <User> users;
    CMarkup xml;
    int i = 0;
    xml.Load(getNameFile());
        xml.FindElem("USERS");
        xml.IntoElem();
        while ( xml.FindElem("USERS")) {
            xml.IntoElem();
            xml.FindElem("ID");
            user.setId(stoi(xml.GetData()));
            xml.FindElem("NAME");
            user.name=xml.GetData();
            xml.FindElem("SURNAME");
            user.surname=xml.GetData();
            xml.FindElem("LOGIN");
            user.login=xml.GetData();
            xml.FindElem("PASSWORD");
            user.password=xml.GetData();
            xml.OutOfElem();
            users.push_back(user);
        }
        cout << "Number of users is: " << users.size() << endl;
        Sleep(100);
        return users;

}
