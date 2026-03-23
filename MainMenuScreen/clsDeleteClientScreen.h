#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

class clsClientDeleteScreen : protected clsScreen
{
	static void _PrintClientCard(clsBankClient &Client)
	{
		cout << "=============================================\n";
		cout << "First Name: " << Client.FirstName << endl;
		cout << "Last Name: " << Client.LastName << endl;
		cout << "Full Name: " << Client.FullName() << endl;
		cout << "Email: " << Client.Email << endl;
		cout << "Phone: " << Client.PhoneNumber << endl;
		cout << "Account Number: " << Client.getAccountNumber() << endl;
		cout << "Account Balance: " << Client.AccountBalance << endl;
		cout << "=============================================\n";
	}

public:
	
	static void ShowDeleteClientScreen()
	{
		if (!CheckAccessRight(clsUser::pDeleteClient))
		{
			return;
		}

		_DrawScreenHeader("Delete Client Screen");
		string AccountNumber;
		cout << "Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Account Number is Not Exist, Enter Another Account Number? ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClientCard(Client);

		char Answer = 'n';

		cout << "Are You Sure You Want Delete This Client ? [y/n]: ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Client.Delete();
			cout << "\nClient Deleted Successfully.\n";
			_PrintClientCard(Client);
		}
		else
		{
			cout << "\nClient Deletion Cancelled\n";
		}
	}

	
};

