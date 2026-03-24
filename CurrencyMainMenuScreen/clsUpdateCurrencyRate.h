#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"

class clsUpdateCurrencyRate : clsScreen
{
	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "\n==========Currency Card==========\n";
		cout << "Country: " << Currency.Country() << endl;
		cout << "Code   : " << Currency.CountryCode() << endl;
		cout << "Name   : " << Currency.CurrencyName() << endl;
		cout << "Rate   : " << Currency.Rate();
		cout << "\n=============================\n\n";
	}

	static double _ReadRate()
	{
		double Rate;
		cout << "\nEnter New Rate: ";
		Rate = clsInputValidate::ReadDblNumber();
		return Rate;
	}

public:

	static void ShowUpDateCurrencyRate()
	{
		_DrawScreenHeader("UpDate Currency Rate");
		string CurrencyCode;
		cout << "Enter Currency Code: ";
		CurrencyCode = clsInputValidate::ReadString();
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		while (Currency.IsEmpty())
		{
			cout << "\nCurrency Not Found :)";
			cout << "\nEnter Another Currency Code: ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		_PrintCurrencyCard(Currency);

		char Answer = 'n';
		cout << "\nAre You Sure To Update Currency Rate? [y/n]: ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Currency.UpdateRate(_ReadRate());
			_PrintCurrencyCard(Currency);
			cout << "\nSuccessfully UpDate Rate :)\n";
		}
		else
		{
			cout << "\nCancelled Rate Update :)";
		}

	}
};

