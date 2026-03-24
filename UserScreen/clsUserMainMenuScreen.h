#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUserListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpDateUserScreen.h"
#include "clsFindUserScreen.h"

class clsUserMainMenuScreen : protected clsScreen 
{
	enum enUserMainMenuOption
	{
		eListUser = 1, eAddNewUser = 2, eDeleteUser = 3,
		eUpDateUser = 4, eFindUser = 5, eMainMenu
	};

	static void _ShowListUserScreen()
	{
		system("cls");
		clsUserListScreen::ShowUserList();
	}

	static void _ShowAddNewUserScreen()
	{
		system("cls");
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}

	static void _ShowDeleteScreen()
	{
		system("cls");
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpDateScreen()
	{
		system("cls");
		clsUpDateUserScreen::ShowUpDateUserScreen();
	}

	static void _ShowFindUserScreen()
	{
		system("cls");
		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _GoBackUserMainMenu()
	{
		cout << "\n\nPress Any Key To Go Back To User Main Menu...\n\n";
		system("pause > 0");
		ShowUserMainMenu();
	}

	static void _MainMenu()
	{

	}

	static short ReadUserMainMenuOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadNumberBetween(1, 6, "Enter Number between 1 to 6? ");
		return Choice;
	}

	static void _PerFormUserMainMenuOption(enUserMainMenuOption UserMainMenuOption)
	{
		switch (UserMainMenuOption)
		{
		case enUserMainMenuOption::eListUser:
			_ShowListUserScreen();
			_GoBackUserMainMenu();
			break;
		case enUserMainMenuOption::eAddNewUser:
			_ShowAddNewUserScreen();
			_GoBackUserMainMenu();
			break;
		case enUserMainMenuOption::eDeleteUser:
			_ShowDeleteScreen();
			_GoBackUserMainMenu();
			break;
		case enUserMainMenuOption::eUpDateUser:
			_ShowUpDateScreen();
			_GoBackUserMainMenu();
			break;
		case enUserMainMenuOption::eFindUser:
			_ShowFindUserScreen();
			_GoBackUserMainMenu();
			break;
		case enUserMainMenuOption::eMainMenu:
			_MainMenu();
			break;
		}
	}

public:
	static void ShowUserMainMenu()
	{
		if (!CheckAccessRight(clsUser::pManageUserMainMenu))
		{
			return;
		}
		system("cls");
		_DrawScreenHeader("Manage User Screen");


		cout << "\t\t\t\t\t==============================\n";
		cout << "\t\t\t\t\t User Main Menu\n";
		cout << "\t\t\t\t\t==============================\n";
		cout << "\t\t\t\t\t1- List Users.\n";
		cout << "\t\t\t\t\t2- Add New User.\n";
		cout << "\t\t\t\t\t3- Delete User.\n";
		cout << "\t\t\t\t\t4- Update User Info.\n";
		cout << "\t\t\t\t\t5- Find User.\n";
		cout << "\t\t\t\t\t6- Main Menu.\n";
		cout << "\t\t\t\t\t==============================\n";
		_PerFormUserMainMenuOption(enUserMainMenuOption(ReadUserMainMenuOption()));


	}
};

