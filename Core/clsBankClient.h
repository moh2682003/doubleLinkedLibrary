#pragma once
#include <vector>
#include <string>
#include "clsString.h"
#include <fstream>
#include "clsPerson.h"

class clsBankClient : public clsPerson 
{

	enum enMode {EmptyMode = 0 , UpdateMode = 1 , AddNewMode = 3 };

	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	double _AccountBalance;
	bool _MarkToDelete = false ;

	static clsBankClient _ConvertOneLineToClientRecord(string Line, string Separator = "#//#")
	{
		vector <string> Vstring = clsString::SplitFunction(Line, Separator);

		return clsBankClient(enMode::UpdateMode, Vstring[0], Vstring[1], Vstring[2], Vstring[3], Vstring[4], Vstring[5], stod(Vstring[6]));
	}

	static string _ConvertRecordToOneLine(clsBankClient Client , string Separator = "#//#")
	{
		string OneLineDate = "";

		OneLineDate += Client.FirstName + Separator;
		OneLineDate += Client.LastName + Separator;
		OneLineDate += Client.Email + Separator;
		OneLineDate += Client.PhoneNumber + Separator;
		OneLineDate += Client._AccountNumber + Separator;
		OneLineDate += Client.PinCode + Separator;
		OneLineDate += to_string (Client.AccountBalance);

		return OneLineDate;
	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static vector <clsBankClient> _LoadClientDataFromFile()
	{
		fstream MyFile;
		vector <clsBankClient> Vclient;
		

		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertOneLineToClientRecord(Line); 
				Vclient.push_back(Client);
			}
		}
		MyFile.close();
		return Vclient;
	}

	static void _SaveClientDateToFile(vector <clsBankClient> Vclient)
	{
		fstream MyFile;

		MyFile.open("Clients.txt", ios::out);

		string DateLine;

		if (MyFile.is_open())
		{
			for (clsBankClient& C : Vclient)
			{
				if (C._MarkToDelete == false)
				{
					DateLine = _ConvertRecordToOneLine(C);
					MyFile << DateLine << endl;
				}
				
			}
		}

		MyFile.close();
	}

	void _Update()
	{
		vector <clsBankClient> Vclient = _LoadClientDataFromFile();

		for (clsBankClient& C : Vclient)
		{
			if (C.getAccountNumber() == getAccountNumber())
			{
				C = *this;
				break;
			}
		}
		_SaveClientDateToFile(Vclient);
	}

	void _AddNew()
	{
		_AddNewLineToFile(_ConvertRecordToOneLine(*this));
	}
	
	void _AddNewLineToFile(string DateLine)
	{
		fstream MyFile;

		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << DateLine << endl;
		}
	}

	void _RegisterTransferLog(clsBankClient DestinationClient, double Amount)
	{
		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);

		string Line = clsBankClient::_ConvertTransferRecord(*this, DestinationClient, Amount);

		if (MyFile.is_open())
		{
			MyFile << Line << endl;
		}
		MyFile.close();
	}

	static string _ConvertTransferRecord(clsBankClient SourceClient ,clsBankClient DestinationClient, double Amount,string Separator = "#//#")
	{
		string Line = clsDateLibrary::DateToString(clsDateLibrary()) + Separator;
		Line += clsDateLibrary::CurrentTime() + Separator;
		Line += SourceClient.getAccountNumber() + Separator;
		Line += DestinationClient.getAccountNumber() + Separator;
		Line += to_string(Amount) + Separator;
		Line += to_string (SourceClient.AccountBalance) + Separator;
		Line += to_string(DestinationClient.AccountBalance) + Separator;
		Line += CuurrentUser.UserName;

		return Line;
	}

public:

	struct stTransferLogRecord
	{
		string Date;
		string Time;
		string DestinationClientAccountNumber;
		string SourceClientAccountNumber;
		double Amount;
		double DestinationClientBalance;
		double SourceClientBalance;
		string User;

	};

private:

	static stTransferLogRecord _ConvertTransferLogToRecord(string Line, string Separator = "#//#")
	{
		stTransferLogRecord TransferLog;

		vector <string> vStr = clsString::SplitFunction(Line, Separator);

		TransferLog.Date = vStr[0];
		TransferLog.Time = vStr[1];
		TransferLog.SourceClientAccountNumber = vStr[2];
		TransferLog.DestinationClientAccountNumber = vStr[3];
		TransferLog.Amount = stod(vStr[4]);
		TransferLog.SourceClientBalance = stod(vStr[5]);
		TransferLog.DestinationClientBalance = stod(vStr[6]);
		TransferLog.User = vStr[7];

		return TransferLog;

	}

public:
			
	clsBankClient(enMode Mode ,string FirstName, string LastName, string Email, string PhoneNumber, string AccountNumber, string PinCode, double AccountBalance)
		: clsPerson(FirstName, LastName, Email, PhoneNumber)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	string getAccountNumber()
	{
		return _AccountNumber;
	}

	void setPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	string getPinCode()
	{
		return _PinCode;
	}

	__declspec(property(get = getPinCode, put = setPinCode)) string PinCode;

	void setAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	double getAccountBalance()
	{
		return _AccountBalance;
	}

	__declspec(property(get = getAccountBalance, put = setAccountBalance)) double AccountBalance;

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	static clsBankClient Find(string AccountNumber)
	{
		fstream MyFile;

		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertOneLineToClientRecord(Line);

				if (Client._AccountNumber == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
			}
		}
		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber , string PinCode)
	{
		clsBankClient Client = clsBankClient::Find(AccountNumber);

		if (!Client.IsEmpty() && Client.PinCode == PinCode)
		{
			return Client;
		}
		return _GetEmptyClientObject();
	}
	
	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client = Find(AccountNumber);

		return (!Client.IsEmpty());
	}

	void Delete()
	{
		vector <clsBankClient> Vclient = _LoadClientDataFromFile();

		for (clsBankClient& C : Vclient)
		{
			if (C.getAccountNumber() == _AccountNumber)
			{
				C._MarkToDelete = true;
			}
		}
		_SaveClientDateToFile(Vclient);

		*this = _GetEmptyClientObject();
	}

	enum enSaveResult {SaveFailed = 0 , SaveSucceeded = 1 ,svFailedAccountNumberExist = 2 }; 

	enSaveResult Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
			return SaveFailed;
		case enMode::UpdateMode:
			_Update();
			return SaveSucceeded;
		case enMode::AddNewMode:
			if (IsClientExist(_AccountNumber))
			{
				return svFailedAccountNumberExist;
			}
			else
			{
				_AddNew();
				_Mode = enMode::UpdateMode;
				return SaveSucceeded;
			}
		}
		return SaveFailed;
	}

	static vector <clsBankClient> GetClientList()
	{
		return _LoadClientDataFromFile();
	}

	static double GetClientTotalBalance()
	{
		vector <clsBankClient> Vclient = _LoadClientDataFromFile();
		double TotalBalance = 0;
		for (clsBankClient& C : Vclient)
		{
			TotalBalance += C.AccountBalance;
		}
		return TotalBalance;
	}

	void Deposit(double Amount)
	{
		AccountBalance += Amount;
		Save();
	}

	void WithDraw(double Amount)
	{
		AccountBalance -= Amount;
		Save();
	}

	bool Transfer(clsBankClient& DestinationClient, double Amount)
	{
		if (Amount > AccountBalance)
		{
			return false;
		}

		WithDraw(Amount);
		DestinationClient.Deposit(Amount);
		_RegisterTransferLog(DestinationClient, Amount);
		return true;
	}

	static vector <stTransferLogRecord> GetTransferList()
	{
		vector <stTransferLogRecord> TransferLog;

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			stTransferLogRecord RegisterLine;
			while (getline(MyFile, Line))
			{
				RegisterLine = _ConvertTransferLogToRecord(Line);
				TransferLog.push_back(RegisterLine);
			}
		}

		MyFile.close();
		return TransferLog;
	}

};

