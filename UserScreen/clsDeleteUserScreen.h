#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsDeleteUserScreen : protected clsScreen
{
	static void _PrintUserCard(clsUser &User)
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

	static void ShowDeleteUserScreen()
	{
		_DrawScreenHeader("Delete User Screen");

		string UserName;
		cout << "\nPlease enter user name: ";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUser Name is not exist, Enter another user name: ";
			UserName = clsInputValidate::ReadString();
		}

		if (UserName == "admin")
		{
			cout << "\nCannot Delete admin User :): \n";
			//system("pause > 0");
			return;
		}

		clsUser User = clsUser::Find(UserName);
		_PrintUserCard(User);

		char Answer = 'n';
		cout << "\nAre you sure you want to delete this user [y/n]? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			User.Delete();
			cout << "\nUser Deleted Successfully.\n";
			_PrintUserCard(User);
			
		}
		else
		{
			cout << "\nUser deletion cancelled.\n";
		}
	
	}
};

