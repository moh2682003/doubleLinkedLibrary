#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "clsString.h"
#include <string>

using namespace std;

class clsCurrency
{
	enum enMode { emptyMode = 0, UpDateMode = 1 };
	string _Country;
	string _CountryCode;
	string _CurrencyName;
	double  _Rate;
	enMode _Mode;

	static clsCurrency _ConvertRecordToLine(string Line, string Separator = "#//#")
	{
		vector <string>  vStr = clsString::SplitFunction(Line,Separator);

		

		return clsCurrency (enMode::UpDateMode, vStr[0], vStr[1], vStr[2], stod(vStr[3]));
		
	}

	static vector <clsCurrency>  _LoadCurrencysDataFromFile()
	{
		vector <clsCurrency> Currency;

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency CurrencyRecord = _ConvertRecordToLine(Line);
				Currency.push_back(CurrencyRecord);
			}
		}
		MyFile.close();
		return Currency;
	}

	static string _ConverCurrencyObjectToLine(clsCurrency C , string Separator= "#//#")
	{
		string Line = "";
		Line += C.Country() + Separator;
		Line += C.CountryCode() + Separator;
		Line += C.CurrencyName() + Separator;
		Line += to_string(C.Rate());
		
		return Line;
	}

	void _SaveCurrencyDataToFile(vector<clsCurrency> Currency)
	{
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);

		if (MyFile.is_open())
		{
			string DateLine;
			for (clsCurrency& C : Currency)
			{
				DateLine = _ConverCurrencyObjectToLine(C);
				MyFile << DateLine << endl;
			}
		}
		MyFile.close();
	}

	static clsCurrency _GetEmptyObject()
	{
		return clsCurrency(enMode::emptyMode, "", "", "", 0);
	}

	void _UpDate()
	{
		vector <clsCurrency> Currency = _LoadCurrencysDataFromFile();

		for (clsCurrency& C : Currency)
		{
			if (C.CountryCode() == CountryCode())
			{
				C = *this;
				break;
			}
		}
		_SaveCurrencyDataToFile(Currency);
	}

public :

	static vector <clsCurrency> GetAllUSDRates()
	{

		return _LoadCurrencysDataFromFile();

	}

	clsCurrency(enMode Mode ,string Country, string CountryCode, string CurrencyName , double Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CountryCode = CountryCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	string Country()
	{
		return _Country;
	}

	string CountryCode()
	{
		return _CountryCode;
	}

	string CurrencyName()
	{
		return _CurrencyName;
	}

	double Rate()
	{
		return _Rate;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::emptyMode);
	}

	static clsCurrency FindByCode(string Code)
	{
		Code = clsString::UpperAllLetters(Code);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
		
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertRecordToLine(Line);
				if (Code == Currency.CountryCode())
				{
					MyFile.close();
					return Currency;

				}
			}
		}
		MyFile.close();
		return _GetEmptyObject();
	}

	static clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllLetters(Country);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertRecordToLine(Line);
				if (Country == clsString::UpperAllLetters(Currency.Country()))
				{
					MyFile.close();
					return Currency;

				}
			}
		}
		MyFile.close();
		return _GetEmptyObject();
	}

	void UpdateRate(double Rate)
	{
		_Rate = Rate;
		_UpDate();
	}

	static bool IsCountryExist(string Country)
	{
		clsCurrency C = FindByCountry(Country);
		return (!C.IsEmpty());
	}

	static vector <clsCurrency> GetCurrenciesList()
	{
		return _LoadCurrencysDataFromFile();
	}

	double ConvertToUsed(double Amount)
	{
		return Amount / Rate();
	}

	double ConvertToOtherCurrency(clsCurrency Currency , double Amount)
	{
		double AmountInUsd = ConvertToUsed(Amount);

		if (Currency.CountryCode() == "USD")
		{
			return AmountInUsd;
		}
		return AmountInUsd * Currency.Rate();
	}
	

};



