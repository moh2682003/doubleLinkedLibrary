#pragma once
#include "Global.h"
#include "clsDateLibrary.h"

using namespace std;

class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        system("cls");
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";

        cout << "\n\t\t\t\t\tUser: " << CuurrentUser.UserName << endl;
        cout << "\t\t\t\t\tDate:" << clsDateLibrary::DateToString(clsDateLibrary()) << endl << endl;

    }

    static bool CheckAccessRight(clsUser::enPermissions Permission)
    {
        if (!CuurrentUser.CheckAccessPermissions(Permission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  " << "Access Denied , Contact Your Admin";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }
    }


};

