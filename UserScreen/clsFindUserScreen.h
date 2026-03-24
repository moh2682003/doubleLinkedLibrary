#pragma once
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

class clsFindUserScreen : protected clsScreen
{
	static void _PrintUserCard(clsUser User)
	{
		cout << "\n=======================================\n";
		cout << "\nFirst Name   : " << User.FirstName;
		cout << "\nLast Name    : " << User.LastName;
		cout << "\nFull Name    : " << User.FullName();
		cout << "\nEmail        : " << User.Email;
		cout << "\nPhone Number : " << User.PhoneNumber;
		cout << "\nUser Name    : " << User.UserName;
		cout << "\nPassWord     : " << User.PassWord;
		cout << "\nPermissions  : " << User.Permission;
		cout << "\n=======================================\n";
	}
public:

	static void ShowFindUserScreen()
	{
		_DrawScreenHeader("Find User Screen");

		string UserName;
		cout << "Enter User Name To Find: ";
		UserName = clsInputValidate::ReadString();
		
		if (clsUser::IsUserExist(UserName))
		{
			clsUser User = clsUser::Find(UserName);

			_PrintUserCard(User);

			if (!User.IsEmpty())
			{
				cout << "\nUser Found Successfully... :)\n";
			}
			else
			{
				cout << "\nUser Not Found... :(\n";
			}
		}
		else
		{
			cout << "\nUser Not Found... :(\n";
		}

		
	}

};

