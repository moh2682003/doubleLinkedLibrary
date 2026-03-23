#pragma once
#include "clsScreen.h"
#include <iomanip>
#include "clsMainMenuScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithDrawScreen.h"
#include "clsTotalBalanceScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferRegisterScreen.h"

class clsTransactionMainMenuScreen : protected clsScreen 
{
	enum enTransactionMainMenuOptions
	{
		eDeposit = 1, eWithdraw = 2 , eTotalBalance = 3 , eTransfer = 4 ,eTransferRegister = 5,eMainMenu = 6
	};

	static short _ReadTransactionMainMenuOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadNumberBetween(1, 6, "Enter Number between 1 to 4? ");
		return Choice;
	}

	static void _DepositScreen()
	{
		system("cls");
		clsDepositScreen::ShowDepositScreen();
	}

	static void _WithDrawScreen()
	{
		system("cls");
		clsWithDrawScreen::ShowWithDrawScreen();
	}

	static void _TotalBalanceScreen()
	{
		system("cls");
		clsTotalBalanceScreen::ShowTotalBalances();
	}

	static void _TransferScreen()
	{
		system("cls");
		clsTransferScreen::ShowTransferScreen();
	}

	static void _TransferRegisterLog()
	{
		clsTransferRegisterScreen::ShowTransferLogScreen();
	}

	static void _GoBackToMainMenu()
	{
		
	}

	static void _GoBackToTransactionMenu()
	{
		cout << "\n\nPress Any Key To Go Back To Transaction Main Menu...\n\n";
		system("pause > 0");
		ShowTransactionMainMenuScreen();
	}

	static void _PerFromTransactionMenuOpetion(enTransactionMainMenuOptions TransactionMenuOpetion)
	{
		switch (TransactionMenuOpetion)
		{
		case enTransactionMainMenuOptions::eDeposit:
			_DepositScreen();
			_GoBackToTransactionMenu();
			break;
		case enTransactionMainMenuOptions::eWithdraw:
			_WithDrawScreen();
			_GoBackToTransactionMenu();
			break;
		case enTransactionMainMenuOptions::eTotalBalance:
			_TotalBalanceScreen();
			_GoBackToTransactionMenu();
			break;
		case enTransactionMainMenuOptions::eTransfer:
			_TransferScreen();
			_GoBackToTransactionMenu();
			break;
		case enTransactionMainMenuOptions::eTransferRegister:clsTransferRegisterScreen::ShowTransferLogScreen();
			_TransferRegisterLog();
			_GoBackToTransactionMenu();
			break;
		case enTransactionMainMenuOptions::eMainMenu:
			_GoBackToMainMenu();
			break;
		}
	}

public:

	static void ShowTransactionMainMenuScreen()
	{
		system("cls");

		if (!CheckAccessRight(clsUser::pTransactionMainMenu))
		{
			return;
		}

		_DrawScreenHeader("Transaction Menu Screen");
		cout << "\t\t\t\t\t======================================\n";
		cout << "\t\t\t\t\t1. Deposit\n";
		cout << "\t\t\t\t\t2. Withdraw\n";
		cout << "\t\t\t\t\t3. Total Balance\n";
		cout << "\t\t\t\t\t4. Transfer\n";
		cout << "\t\t\t\t\t5. Transfer Register\n";
		cout << "\t\t\t\t\t6. Main Menu\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerFromTransactionMenuOpetion(enTransactionMainMenuOptions(_ReadTransactionMainMenuOption()));
	}

};

