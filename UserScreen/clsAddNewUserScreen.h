#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
class clsAddNewUserScreen : protected clsScreen
{
	static void _ReadUserInfo(clsUser& User)
	{
		cout << "\nEnter FirstName: ";
		User.FirstName = clsInputValidate::ReadString();
		cout << "\nEnter LastName: ";
		User.LastName = clsInputValidate::ReadString();
		cout << "\nEnter Email: ";
		User.Email = clsInputValidate::ReadString();
		cout << "\nEnter PhoneNumber: ";
		User.PhoneNumber = clsInputValidate::ReadString();
		cout << "\nEnter PassWord: ";
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

public :

	static void ShowAddNewUserScreen()
	{
		_DrawScreenHeader("Add New User Screen");
		string UserName;
		cout << "Enter User Name: ";
		UserName = clsInputValidate::ReadString();

		while (clsUser::IsUserExist(UserName))
		{
			cout << "User Name Is Already Exist , Enter Another User Name: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser NewUser = clsUser::GetNewUserObject(UserName);

		_ReadUserInfo(NewUser);

		clsUser::enSaveResult SaveResult;

		SaveResult = NewUser.Save();

		switch (SaveResult)
		{
		case clsUser::SaveSucceeded:
			cout << "\nSave Succeeded\n";
			_PrintUserCard(NewUser);
			break;
		case clsUser::SaveFailed:
			cout << "\nSave Failed";
			break;
		case clsUser::svFailedUserNameExist:
			cout << "\nSave Failed User Name Already Exist";
			break;
		default:
			break;
		}
	

	}
};

