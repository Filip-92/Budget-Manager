#include "FileWithIncomes.h"

    FileWithIncomes(string fileWithIncomesName);
    bool doesFileExist();
    void saveIncomesToFile(vector<Income> incomes);
    vector <Income> loadIncomesFromTheFile();

FileWithIncomes::FileWithIncomes(string FileWithIncomes):INCOMES_FILE_NAME(FileWithIncomes){}

bool FileWithIncomes::doesFileExist()
{
    ifstream ifile(INCOMES_FILE_NAME.c_str());
    return ifile.good();
}

void FileWithIncomes::saveIncomesToFile (vector <Income> incomes)
{
    cout<<"saving incomes file"<<endl;
    xml.SetDoc( "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n" );
    xml.AddElem("INCOME");
    xml.IntoElem();
    for (int i=0;i<incomes.size();i++)
    {
        xml.AddElem("INCOME");
        xml.IntoElem();
        xml.AddElem("TRANSACTIONID",incomes.at(i).transactionId);
        xml.AddElem("USERID",incomes.at(i).userId);
        xml.AddElem("DATE",incomes.at(i).date);
        xml.AddElem("DAYNR",incomes.at(i).dayNr);
        xml.AddElem("ITEM",incomes.at(i).item);
        xml.AddElem("AMOUNT",incomes.at(i).amount*100);
        xml.OutOfElem();
    }
    xml.Save(INCOMES_FILE_NAME);
}

vector <Income> FileWithIncomes::loadIncomesFromTheFile()
{
    Income income;
    vector <User> incomes;
    if (doesFileExist()){
        xml.Load(USERS_FILE_NAME);
        xml.FindElem("INCOME");
        xml.IntoElem();
        while ( xml.FindElem("INCOME")) {
            xml.IntoElem();
            xml.FindElem("TRANSACTIONID");
            income.transactionId(stoi(xml.GetData()));
            xml.FindElem("USERID");
            income.userId=xml.GetData();
            xml.FindElem("DATE");
            income.date=xml.GetData();
            xml.FindElem("DAYNR");
            income.dayNr=xml.GetData();
            xml.FindElem("AMOUNT");
            income.amount=xml.GetData();
            xml.OutOfElem();
            incomes.push_back(income);
        }
        cout << "Number of incomes is: " << incomes.size() << endl;
        Sleep(100);
        return incomes;

    }
    else {
        return incomes;
    }

}
