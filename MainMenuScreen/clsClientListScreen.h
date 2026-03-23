#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsBankClient.h"

class clsClientListScreen : protected clsScreen
{
	static void PrintClientRecordLine(clsBankClient Client)
	{
		cout << setw(6) << left << ""; 
		cout << "|" << setw(18) << left << Client.getAccountNumber();
		cout << "|" << setw(23) << left << Client.FullName();
		cout << "|" << setw(23) << left << Client.Email;
		cout << "|" << setw(10) << left << Client.PhoneNumber;
		cout << "|" << setw(16) << left << Client.PinCode;
		cout << "|" << setw(13) << left << Client.AccountBalance;
		
	}

public:

	static void ShowClientListScreen()
	{

		if (!CheckAccessRight(clsUser::pShowAllClient))
		{
			return;
		}
		vector <clsBankClient> Vclient = clsBankClient::GetClientList();
		string Title = "Client List Screen\n";
		string subTitle = "Number of Clients: " + to_string(Vclient.size());

		_DrawScreenHeader(Title, subTitle);

		cout << setw(14) << left << "" << "==================================================================================================\n";
		cout << setw(14) << left << "" << "|" << setw(18) << left << "Account Number";
		cout << "|" << setw(23) << left << "Client Name";
		cout << "|" << setw(23) << left << "Email";
		cout << "|" << setw(10) << left << "Phone";
		cout << "|" << setw(16) << left << "Pin Code";
		cout << "|" << setw(13) << left << "Balance";
		cout << "\n" << setw(14) << left << "" << "==================================================================================================\n";
		

		for (clsBankClient& C : Vclient)
		{
			cout << setw(8) << left << "";
			PrintClientRecordLine(C);
			cout << "\n";
		}

	}
};

