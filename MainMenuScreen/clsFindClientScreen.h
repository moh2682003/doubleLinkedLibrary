#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
class clsFindClientScreen : protected clsScreen
{
	static void _PrintClientCard(clsBankClient Client)
	{
		cout << "===============================\n";
		cout << "First Name: " << Client.FirstName << endl;
		cout << "Last Name: " << Client.LastName << endl;
		cout << "Full Name: " << Client.FullName() << endl;
		cout << "Email: " << Client.Email << endl;
		cout << "Phone: " << Client.PhoneNumber << endl;
		cout << "Account Number: " << Client.getAccountNumber() << endl;
		cout << "Account Balance: " << Client.AccountBalance << endl;
		cout << "===============================\n";
	}

public:

	static void ShowFindClientScreen()
	{
		if (!CheckAccessRight(clsUser::pFindClient))
		{
			return;
		}
		clsScreen::_DrawScreenHeader("Find Client Screen");
		string AccountNumber;
		cout << "Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();
		
		if (clsBankClient::IsClientExist(AccountNumber))
		{
			clsBankClient Client = clsBankClient::Find(AccountNumber);
			cout << "\n\nClient Found :)\n\n";

			cout << "==========Client Card ==============\n";
			_PrintClientCard(Client);
		}
		else
		{
			cout << "Client with Account Number: " << AccountNumber << " is Not Exist :(\n";
		}
	}
};

