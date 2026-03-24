#pragma once
#include "clsScreen.h"
#include <iomanip>
#include "clsInputValidate.h"
#include "clsCurrencyListScreen.h"

class clsCurrencyExchangeMainMenu : protected clsScreen
{
	enum enCurrencyMenu
	{
		cListCurrency = 1 , cFindCurrency = 2,
		cUpDateCurrency = 3 , cCurrencyCalculter = 4 ,
		cMainMenu = 5 
	};

	static short _ReadCurrencyMaunMenuOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		short Choose = clsInputValidate::ReadNumberBetween(1, 5, "Enter Number between 1 to 8? ");
		return Choose;
	}

	static void _ShowListScreen()
	{
		system("cls");
		clsCurrencyListScreen::ShowCurrencyListScreen();
	}

	static void _ShowFindScreen()
	{
		system("cls");
		cout << "Find screen Will Be Here\n";
	}

	static void _ShowUpDateScreen()
	{
		system("cls");
		cout << "UpDate Screen Will be here \n";
	}

	static void _ShowCurrencyCalculator()
	{
		system("cls");
		cout << "Currency Calculator Will Be Here\n";
	}

	static void _GoBackToCurrencyMainMenu()
	{
		cout << "\n\nPress Any Key To Go Back To Main Menu...\n\n";
		system("pause > 0");
		system("cls");
		ShowCurrencyMainMenu();
	}

	static void _GoBackToMainMenu()
	{

	}

	static void _PerFormCurrencyMainMenu(enCurrencyMenu Currency)
	{
		switch (Currency)
		{
		case enCurrencyMenu::cListCurrency:
			_ShowListScreen();
			_GoBackToCurrencyMainMenu();
			break;
		case enCurrencyMenu::cFindCurrency:
			_ShowFindScreen();
			_GoBackToCurrencyMainMenu();
			break;
		case enCurrencyMenu::cUpDateCurrency:
			_ShowUpDateScreen();
			_GoBackToCurrencyMainMenu();
			break;
		case enCurrencyMenu::cCurrencyCalculter:
			_ShowCurrencyCalculator();
			_GoBackToCurrencyMainMenu();
			break;
		case enCurrencyMenu::cMainMenu:
			_GoBackToMainMenu();
		}
	}

public:

	static void ShowCurrencyMainMenu()
	{
		_DrawScreenHeader("Currency Main Menu");

		cout << "\n\t\t\t\t\t===================================\n";
		cout << "\t\t\t\t\t[1] List Currency\n";
		cout << "\t\t\t\t\t[2] Find Currency\n";
		cout << "\t\t\t\t\t[3] UpDate Rate\n";
		cout << "\t\t\t\t\t[4] Currency Calculator\n";
		cout << "\t\t\t\t\t[5] GoBack To Main Menu\n";
		cout << "\t\t\t\t\t======================================\n";

		_PerFormCurrencyMainMenu(enCurrencyMenu(_ReadCurrencyMaunMenuOption()));
		
	}
};

