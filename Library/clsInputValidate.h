#include <iostream>
#include "clsDateLibrary.h"
#pragma once

using namespace std;

class clsInputValidate
{
public:

	static bool IsNumberBetween(short Number, short From, short To)
	{
		return Number <= To && Number >= From;
	}

	static bool IsNumberBetween(int Number, int From, int To)
	{
		return Number <= To && Number >= From;
	}

	static bool IsNumberBetween(float Number, float From, float To)
	{
		return Number <= To && Number >= From;
	}
	
	static bool IsNumberBetween(double Number, double From, double To)
	{
		return Number <= To && Number >= From;
	}

	static bool IsDateBetween(clsDateLibrary Date, clsDateLibrary FromDate, clsDateLibrary ToDate)
	{
		return !clsDateLibrary::IsDate1AfterDate2(FromDate, Date) &&
			!clsDateLibrary::IsDate1AfterDate2(Date, ToDate);
	}

	static int ReadIntNumber(string ErrorMessage = "InValid Number Enter Number Again: ")
	{
		int Number;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize> ::max(), '\n');

			cout << ErrorMessage << endl;
		}
		return Number;
	}

	static double ReadDblNumber(string ErrorMessage = "InValid Number Enter Number Again: ")
	{
		double Number;
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage << endl;
		}
		return Number;
	}

	static int ReadNumberBetween(int From , int To , string ErrorMessage = "InValid Number Enter Number Again: ")
	{
		int Number  = ReadIntNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}
		return Number;
	}

	static bool IsValidDate(clsDateLibrary Date)
	{
		return clsDateLibrary::IsValidDate(Date);
	}

	static string ReadString()
	{
		string S1;
		getline(cin >> ws, S1);

		return S1;
	}

	static char ReadChar()
	{
		char C;

		cin >>  C;
		return C;
	}

};

