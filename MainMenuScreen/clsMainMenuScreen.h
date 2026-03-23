#pragma once
#include <iostream>
#include "clsInputValidate.h" 
#include <string.h>
#include <iomanip>
#include "clsScreen.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpDateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionMainMenuScreen.h"
#include "clsUserMainMenuScreen.h"
#include "Global.h"
#include "clsRegisterLoginScreen.h"


class clsMainMenuScreen : protected clsScreen
{

	static short _ReadMainMenuOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 8]? ";
		short Choice = clsInputValidate::ReadNumberBetween(1, 9, "Enter Number between 1 to 8? ");
		return Choice;
	}



	static void _ShowAllClientScreen()
	{
		system("cls");	
		clsClientListScreen::ShowClientListScreen();

	}

	static void _AddNewClientScreen()
	{
		system("cls");
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}

	static void _DeleteClientScreen()
	{
		system("cls");
		clsClientDeleteScreen::ShowDeleteClientScreen();

		
	}

	static void _UpdateClientScreen()
	{
		system("cls");
		clsUpDateClientScreen::ShowClientScreen();
		
	}

	static void _FindClientScreen()
	{
		system("cls");
		clsFindClientScreen::ShowFindClientScreen();	
	
	}

	static void _TransactionMenuScreen()
	{
		system("cls");
		clsTransactionMainMenuScreen::ShowTransactionMainMenuScreen();
	} 

	static void _UserManageScreen()
	{
		system("cls");
		clsUserMainMenuScreen::ShowUserMainMenu();
	}

	static void _LoginRegisterScreen()
	{
		system("cls");
		clsRegisterLoginScreen::ShowLoginRegisterScreen();
	}

	static void _LogoutScreen()
	{
		system("cls");
		_LogOut();
	}

	static void _GoBackToMainMenu()
	{
		cout << "\n\nPress Any Key To Go Back To Main Menu...\n\n";
		system("pause > 0");
		ShowMainMenu();
	}

	enum enMainMenuOptions { eShowClient = 1, eAddNewClient = 2, eDeleteClient = 3, eUpdateClient = 4, 
		eFindClient = 5, eTransactionMenu = 6, eUserManage = 7,eRegisterLogin = 8 ,eLogout = 9 };

	static void _PerFromMainMenuOpetion(enMainMenuOptions MainMenuOpetion)
	{
		switch (MainMenuOpetion)
		{
		case enMainMenuOptions::eShowClient:
			_ShowAllClientScreen();
			_GoBackToMainMenu();
			break;
		case enMainMenuOptions::eAddNewClient:
			_AddNewClientScreen();
			_GoBackToMainMenu();
			break;
		case enMainMenuOptions::eDeleteClient:
			_DeleteClientScreen();
			_GoBackToMainMenu();
			break;
		case enMainMenuOptions::eUpdateClient:
			_UpdateClientScreen();
			_GoBackToMainMenu();
			break;
		case enMainMenuOptions::eFindClient:
			_FindClientScreen();
			_GoBackToMainMenu();
			break;
		case enMainMenuOptions::eTransactionMenu:
			_TransactionMenuScreen();
			_GoBackToMainMenu();
			break;
		case enMainMenuOptions::eUserManage:
			_UserManageScreen();
			_GoBackToMainMenu();
			break;
		case enMainMenuOptions::eRegisterLogin:
			_LoginRegisterScreen();
			_GoBackToMainMenu();
			break;
		case enMainMenuOptions::eLogout:
			_LogoutScreen();
			break;
		}
	}

	static void _LogOut()
	{
		CuurrentUser = clsUser::Find("", "");
	}

public:

	static void ShowMainMenu()
	{
		system("cls");
		_DrawScreenHeader("\t\tMain Screen");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menu\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] Register Login.\n";
		cout << setw(37) << left << "" << "\t[9] Logout.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerFromMainMenuOpetion(enMainMenuOptions(_ReadMainMenuOption()));
	}
};

