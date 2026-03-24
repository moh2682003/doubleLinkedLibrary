#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>

class clsUserListScreen : protected clsScreen
{
	static void  _PrintUserRecordLine(clsUser User)
	{
		cout << setw(8) << left << "" << "| " << setw(12) << left << User.UserName;
		cout << "| " << setw(25) << left << User.FullName();
		cout << "| " << setw(12) << left << User.PhoneNumber;
		cout << "| " << setw(20) << left << User.Email;
		cout << "| " << setw(10) << left << User.PassWord;
		cout << "| " << setw(12) << left << User.Permission;

	}

public:

	static void ShowUserList()
	{
		vector <clsUser> User = clsUser::GetUserList();

		string Title = "Users List Screen";
		string SubTitle = User.size() == 0 ? "No Users Available In The System!" : "No. of Users: " + to_string(User.size());
		_DrawScreenHeader(Title,SubTitle);
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(12) << "UserName";
        cout << "| " << left << setw(25) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (User.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else

            for (clsUser User : User)
            {

                _PrintUserRecordLine(User);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }
};

