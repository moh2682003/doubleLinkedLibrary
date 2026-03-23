#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsUpDateClientScreen : protected clsScreen
{
	static void _PrintClientCard(clsBankClient Client)
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

	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "Enter First Name? ";
		Client.FirstName = clsInputValidate::ReadString();
		cout << "Enter Last Name? ";
		Client.LastName = clsInputValidate::ReadString();
		cout << "Enter Email? ";
		Client.Email = clsInputValidate::ReadString();
		cout << "Enter Phone Number? ";
		Client.PhoneNumber = clsInputValidate::ReadString();
		cout << "Enter Pin Code? ";
		Client.PinCode = clsInputValidate::ReadString();
		cout << "Enter Account Balance? ";
		Client.AccountBalance = clsInputValidate::ReadDblNumber();
	}

public:

	static void ShowClientScreen()
	{
		if (!CheckAccessRight(clsUser::pUpDateClient))
		{
			return;
		}

		_DrawScreenHeader("UpDate Client Screen");

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

		cout << "\nAre You suer You Want UpDate This Client? [y/n]: ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			cout << "\n\nUpDate Client Info\n";
			cout << "==================================\n";
			_ReadClientInfo(Client);
			clsBankClient::enSaveResult SaveResult;

			SaveResult = Client.Save();

			switch (SaveResult)
			{
			case clsBankClient::enSaveResult::SaveSucceeded:
				cout << "\n\nUpDate Client Info Successfully\n";
				break;
			case clsBankClient::enSaveResult::SaveFailed:
				cout << "UpDate Client Info Failed\n";
				break;
			default:
				cout << "UnKnown Error\n";
			}
		}

		

		
	}

};

