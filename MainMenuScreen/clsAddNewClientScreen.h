#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"


class clsAddNewClientScreen : protected clsScreen
{
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

	static void _PrintClientCard(clsBankClient Client)
	{
		cout << "Client Card\n";
		cout << "=====================\n";
		cout << "First Name : " << Client.FirstName << endl;
		cout << "Last Name : " << Client.LastName << endl;
		cout << "Full Name: " << Client.FullName() << endl;
		cout << "Email : " << Client.Email << endl;
		cout << "Phone Number : " << Client.PhoneNumber << endl;
		cout << "Account Number : " << Client.getAccountNumber() << endl;
		cout << "Pin Code : " << Client.PinCode << endl;
		cout << "Account Balance : " << Client.AccountBalance << endl;
		cout << "=====================\n";
	}

public :
	
	static void ShowAddNewClientScreen()
	{

		if (!CheckAccessRight(clsUser::pAddNewClient))
		{
			return;
		}

		_DrawScreenHeader("Add New Client Screen");

		cout << "Enter Account Number? ";
		string AccountNumber = clsInputValidate::ReadString();

		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Account Number is Already Exist, Enter Another Account Number? ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

		_ReadClientInfo(NewClient);

		clsBankClient::enSaveResult SaveResult;

		SaveResult = NewClient.Save();

		switch (SaveResult)
		{
		case clsBankClient::SaveSucceeded:
			cout << "\nNew Client Added Successfully.\n\n";
			_PrintClientCard(NewClient);
			break;
		case clsBankClient::svFailedAccountNumberExist:
			cout << "\nFailed to Add New Client, Account Number is Already Exist.\n\n";
			break;
		case clsBankClient::SaveFailed:
			cout << "\nFailed to Add New Client, Empty Date \n\n";
			break;
		}
	}
};

