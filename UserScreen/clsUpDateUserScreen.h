#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsUpDateUserScreen : protected clsScreen
{
	static void _PrintUserCard(clsUser& User)
	{
		cout << "\n__________________________\n";
		cout << "\nUser Name: " << User.UserName;
		cout << "\nFirst Name: " << User.FirstName;
		cout << "\nLast Name: " << User.LastName;
		cout << "\nEmail: " << User.Email;
		cout << "\nPhone: " << User.PhoneNumber;
		cout << "\nPassword: " << User.PassWord;
		cout << "\nPermission: " << User.Permission;
		cout << "\n__________________________\n";
	}

	static void _ReadUserInfo(clsUser & User)
	{
		cout << "\nPlease enter First Name: ";
		User.FirstName = clsInputValidate::ReadString();
		cout << "\nPlease enter Last Name: ";
		User.LastName = clsInputValidate::ReadString();
		cout << "\nPlease enter Email: ";
		User.Email = clsInputValidate::ReadString();
		cout << "\nPlease enter Phone: ";
		User.PhoneNumber = clsInputValidate::ReadString();
		cout << "Please enter Password: ";
		User.PassWord = clsInputValidate::ReadString();
		User.Permission = _ReadPermissionsToSet();
	}

	static int _ReadPermissionsToSet()
	{
		int Permission = 0;
		char Answer = 'n';
		cout << "\nChoose Permissions To Set For This User: \n\n";

		cout << "\naccess all permissions [y/n]? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
			return -1;

		cout << "\nShow All Clients [y/n]? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
			Permission += clsUser::enPermissions::pShowAllClient;

		cout << "\nAdd New Client [y/n]? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
			Permission += clsUser::enPermissions::pAddNewClient;

		cout << "\nDelete Client [y/n]? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
			Permission += clsUser::enPermissions::pDeleteClient;

		cout << "\nUpDate Client [y/n]?";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
			Permission += clsUser::enPermissions::pUpDateClient;

		cout << "\nTransaction Menu [y/n]?";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
			Permission += clsUser::enPermissions::pTransactionMainMenu;

		cout << "\nManage User Menu[y/n]?";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
			Permission += clsUser::enPermissions::pManageUserMainMenu;

		cout << "\nRegister Login Screen[y/n]?";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
			Permission += clsUser::enPermissions::pRegisterLogin;

		return Permission;

	}


public:

	static void ShowUpDateUserScreen()
	{
		_DrawScreenHeader("UpDate User Screen");
		string UserName;
		cout << "\nPlease enter User Name: ";
		UserName = clsInputValidate::ReadString();

		while(!clsUser::IsUserExist(UserName))
		{
			cout << "\nUser Name is not exist, Enter another User Name: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(UserName);

		_PrintUserCard(User);

		char Answer = 'n';
		cout << "\n\nDo you want to upDate this User? y/n? ";
		cin >> Answer;


		if(toupper(Answer) == 'Y')
		{
			_ReadUserInfo(User);
			clsUser::enSaveResult SaveResult = User.Save();
			switch (SaveResult)
			{
			case clsUser::SaveSucceeded:
				cout << "\n\nUser UpDate Successfully.\n";
				_PrintUserCard(User);
				break;
			case clsUser::SaveFailed:
				cout << "\n\nUser UpDate Failed.\n";
				break;
			case clsUser::svFailedUserNameExist:
				cout << "\n\nUser Name is already exist, User UpDate Failed.\n";
				break;
			}
		}
		else
		{
			cout << "\n\nUser UpDate Cancelled.\n";
		}
	}
};

