#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

class clsTransferScreen : protected clsScreen
{

	static void _PrintClientCard(clsBankClient &Client)
	{
		cout << "\n=============Client Card==================\n";
		cout << "=========================================\n";
		cout << "AccountNumber: " << Client.getAccountNumber() << endl ;
		cout << "AccountName  : " << Client.FullName() << endl ;
		cout << "Total Balance: " << Client.AccountBalance << endl ;
		cout << "=========================================\n";
	}

	static string _ReadAccountNumber()
	{
		string AccountNumber = "";
		AccountNumber = clsInputValidate::ReadString();


		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient With [" << AccountNumber << "] Not Found :(\n";
			cout << "Please Enter Another AccountNumber: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		return AccountNumber;
	}

	static double _ReadAmount(clsBankClient SourceClient)
	{
		double Amount;
		cout << "\nEnter Transfer Amount: ";
		cin >> Amount;
		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds your balance, Maximum you can transfer is: " << SourceClient.AccountBalance;
			cout << "\nEnter another amount: ";
			Amount = clsInputValidate::ReadDblNumber();
		}
		return Amount;
	}

	


public:

	
	static void ShowTransferScreen()
	{
		_DrawScreenHeader("Transfer Screen");

		cout << "\nEnter Account Number To Transfer From: ";
		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());
		_PrintClientCard(SourceClient);
		

		cout << "\nEnter Account Number To Transfer To: ";
		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());
		_PrintClientCard(DestinationClient);


		while (SourceClient.getAccountNumber() == DestinationClient.getAccountNumber())
		{
			cout << "\nCannot transfer to the same account. Enter another one: \n";
			DestinationClient = clsBankClient::Find(_ReadAccountNumber());
			_PrintClientCard(DestinationClient);
		}

		double Amount = _ReadAmount(SourceClient);

		char Answer = 'n';
		cout << "\nAre You Sure To Transfer " << Amount << " Doller From " << SourceClient.getAccountNumber() << " To " << DestinationClient.getAccountNumber() << ": ";
		cin >> Answer;

			

		if (toupper(Answer) == 'Y')
		{
			cout << "\nSuccessful Transfer\n";
			SourceClient.Transfer(DestinationClient, Amount);
			_PrintClientCard(SourceClient);
			_PrintClientCard(DestinationClient);
		}
		else
		{
			cout << "\nTransfer Canceled :)";
		}
	}
};

