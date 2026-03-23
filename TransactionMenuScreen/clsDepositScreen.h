#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsDepositScreen : protected clsScreen
{
	static void _PrintClientCard(clsBankClient Client)
	{
		cout << "=====================================\n";
		cout << "First Name: " << Client.FirstName << endl;
		cout << "Last Name: " << Client.LastName << endl;
		cout << "Full Name: " << Client.FullName() << endl;
		cout << "Email: " << Client.Email << endl;
		cout << "Phone: " << Client.PhoneNumber << endl;
		cout << "Account Number: " << Client.getAccountNumber() << endl;
		cout << "Account Balance: " << Client.AccountBalance << endl;
		cout << "=====================================\n";
	}

	static string _ReadAccountNumber()
	{
		string AccountNumber;

		cout << "Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		return AccountNumber;
	}

public:

	static void ShowDepositScreen()
	{
		_DrawScreenHeader("\t\tDeposit Screen");
		string AccountNumber;
		double Amount = 0;

		AccountNumber = _ReadAccountNumber();

		while(!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\n\nAccount Number is Not Exist, Please Enter Another Account Number? ";
			AccountNumber = _ReadAccountNumber();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		_PrintClientCard(Client);

		cout << "\n\nEnter Deposit Amount: ";
		Amount = clsInputValidate::ReadDblNumber();

		char Answer = 'n';
		cout << "\n\nAre You Sure To Deposit " << Amount << " To Account Number: " << Client.getAccountNumber() << " [Y/N]? ";
		cin >> Answer;

		
		if (toupper(Answer) == 'Y')
		{
			Client.Deposit(Amount);
			cout << "\n\nAmount Deposited Successfully.\n";
			cout << "New Account Balance: " << Client.AccountBalance << endl;
		}
		else
		{
			cout << "\n\nDeposit Cancelled.\n";
		}
		

	}
};

