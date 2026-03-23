#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "Global.h"
#include "clsMainMenuScreen.h"

class clsLoginScreen : protected clsScreen
{
	static bool _Login()
	{
		string UserName, PassWord;
		bool LoginFailed = false;
		int LoginTrail = 0;

		do
		{
			if (LoginFailed)
			{
				cout << "\nInvalid UserName/PassWord\n";
				LoginTrail++;
				cout << "You have " << (3- LoginTrail ) << " to Login\n\n";
			}

			cout << "Enter UserName: ";
			UserName = clsInputValidate::ReadString();
			cout << "PassWord: ";
			PassWord = clsInputValidate::ReadString();

			CuurrentUser = clsUser::Find(UserName, PassWord);

			LoginFailed = CuurrentUser.IsEmpty();

			if (LoginTrail == 3)
			{
				cout << "\n\nYou Are Locked After 3 Failed Trails\n\n";
				return false ;
			}

		} while (LoginFailed);

		CuurrentUser.RegisterLogIn();
		clsMainMenuScreen::ShowMainMenu();
		return true;
	}

public:
	
	static bool CheckLogin;

	static bool ShowLoginScreen()
	{
		_DrawScreenHeader("Login Screen");
		return _Login();
		
	}
};

