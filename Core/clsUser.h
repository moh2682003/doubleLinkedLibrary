#pragma once
#include "clsPerson.h"
#include <vector>
#include <fstream>
#include <string>
#include "clsString.h"
#include "clsDateLibrary.h"
#include "clsUtility.h"


class clsUser : public clsPerson
{
public :
	struct stLoginRegisterRecord
	{
		string Date;
		string Time;
		string UserName;
		string Password;
		int Permission;
	};
private:

	enum enMode {EmptyMode = 1 , AddNew = 2 , UpDate = 3  };

	string _UserName;
	string _PassWord;
	int _Permission;
	bool _MarkToDelete = false;
	enMode _Mode;

	static clsUser _ConvertLineToUserObject(string Line)
	{
		vector <string> vString = clsString::SplitFunction(Line, "#//#");

		return clsUser(enMode::UpDate, vString[0], vString[1], vString[2], vString[3], vString[4],clsUtility::DecryptText (vString[5],10), stoi(vString[6]));
	}

	static vector <clsUser> _LoadUserDateFromFile()
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		vector <clsUser> vUser;

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				vUser.push_back(User);
			}
		}
		MyFile.close();
		return vUser;
	}

	static clsUser _GetEmptyUserObject()
	{
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static string _ConvertRecordToLine(clsUser User, string Separator = "#//#")
	{
		string UserRecord = "";

		return UserRecord = User.FirstName + Separator +
			User.LastName + Separator +
			User.Email + Separator +
			User.PhoneNumber + Separator +
			User.UserName + Separator +
			clsUtility::EncryptText(User.PassWord,10)+ Separator +
			to_string(User.Permission);
	}

	static void _SaveUserDateToFile(vector <clsUser> vUser)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out);

		if (MyFile.is_open())
		{
			string Line;
			for (clsUser& U : vUser)
			{
				if (U._MarkToDelete == false)
				{
					Line = _ConvertRecordToLine(U);
					MyFile << Line << endl;
				}
			}
			
		}
		MyFile.close();
	}

	static void _AddNewLineToFile(string DateLine)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::app);


		if (MyFile.is_open())
		{
			MyFile << DateLine << endl;
		}
		
		MyFile.close();
	}

	void _AddNew()
	{
		_AddNewLineToFile(_ConvertRecordToLine(*this));
	}

	void _UpDate()
	{
		vector <clsUser> vUser = _LoadUserDateFromFile();

		for (clsUser& U : vUser)
		{
			if (U.UserName == _UserName)
			{
				U = *this;
				break;
			}
		}
		_SaveUserDateToFile(vUser);
	}

	string _PrepareLogInline(string Separator = "#//#")
	{
		string Line = "";
		Line = clsDateLibrary::DateToString(clsDateLibrary()) + Separator
			+ clsDateLibrary::CurrentTime() + Separator +
			UserName + Separator + clsUtility::EncryptText (PassWord,10) +Separator +  to_string(Permission);

		return Line;
	}
	
	static stLoginRegisterRecord _ConvertRegisterLoginLineToRecord(string S1, string Separator = "#//#")
	{
		stLoginRegisterRecord LoginRegister;
		vector <string> vString = clsString::SplitFunction(S1, Separator);

		
		LoginRegister.Date = vString[0];
		LoginRegister.Time = vString[1];
		LoginRegister.UserName = vString[2];
		LoginRegister.Password = clsUtility::DecryptText (vString[3],10);
		LoginRegister.Permission = stoi(vString[4]);

		return LoginRegister;
	}


public:


	enum enSaveResult { SaveFailed = 0, SaveSucceeded = 1, svFailedUserNameExist = 2 };

	enum enPermissions { eAll = -1 , pShowAllClient = 1 , pAddNewClient = 2 , pDeleteClient = 4,pUpDateClient = 8 , pFindClient = 16 ,
		pTransactionMainMenu = 32 , pManageUserMainMenu = 64 , pRegisterLogin = 128 };

	clsUser(enMode Mode ,string FirstName, string LastName, string Email, string Phone, string UserName, string PassWord, int Permission)
		: clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_PassWord = PassWord;
		_Permission = Permission;
	}

	void setUserName(string UserName)
	{
		_UserName = UserName;
	}

	string getUserName()
	{
		return _UserName;
	}

	__declspec(property (get = getUserName, put = setUserName)) string UserName;

	void setPassWord(string PassWord)
	{
		_PassWord = PassWord;
	}

	string getPassWord()
	{
		return _PassWord;
	}

	__declspec(property(get = getPassWord, put = setPassWord)) string PassWord;

	void setPermission(int Permission)
	{
		_Permission = Permission;
	}

	int getPermission()
	{
		return _Permission;
	}

	__declspec(property(get = getPermission, put = setPermission)) int Permission;

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	static clsUser Find(string UserName)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = clsUser::_ConvertLineToUserObject(Line);
				if (User.UserName == UserName)
				{
					MyFile.close();
					return User;
				}
			}
		}
		MyFile.close();
		return _GetEmptyUserObject();
	}

	static clsUser Find(string UserName, string PassWord)
	{
		clsUser User = clsUser::Find(UserName);

		if (!User.IsEmpty() && User.PassWord == PassWord)
		{
			return User;
		}
		return _GetEmptyUserObject();
	}

	static bool IsUserExist(string UserName)
	{
		clsUser User = clsUser::Find(UserName);

		return (!User.IsEmpty());
	}
	
	void Delete()
	{
		vector <clsUser> vUser = _LoadUserDateFromFile();

		for (clsUser& U : vUser)
		{
			if (U.UserName == _UserName)
			{
				 U._MarkToDelete = true;
				break;
			}
		}

		_SaveUserDateToFile(vUser);
		*this = _GetEmptyUserObject();
	}

	enSaveResult Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
			if (IsEmpty())
			{
				return enSaveResult::SaveFailed;
			}
			
		case enMode::UpDate:
			_UpDate();
			return enSaveResult::SaveSucceeded;
			break;
		case enMode::AddNew:
			if (clsUser::IsUserExist(_UserName))
			{
				return enSaveResult::svFailedUserNameExist;
			}
			else
			{
				_AddNew();
				_Mode = enMode::UpDate;
				return enSaveResult::SaveSucceeded;
			}
		}
		return enSaveResult::SaveFailed;
	}

	static vector <clsUser> GetUserList()
	{
		return _LoadUserDateFromFile();
	}

	static clsUser GetNewUserObject(string UserName)
	{
		return clsUser(enMode::AddNew, "", "", "", "", UserName, "", 0);
	}

	bool CheckAccessPermissions(enPermissions Permission)
	{
		if (this->Permission == enPermissions::eAll)
			return true;
		if ((this->Permission & Permission) == Permission)
			return true;
		else
			return false;
	}

	void RegisterLogIn()
	{
		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::out | ios::app);

		string Line = _PrepareLogInline();

		if (MyFile.is_open())
		{
			MyFile << Line << endl;
		}
		MyFile.close();
	}

	static vector <stLoginRegisterRecord> GetLoginRegisterList()
	{
		vector <stLoginRegisterRecord> vStr;

		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			stLoginRegisterRecord Login;
			while (getline(MyFile, Line))
			{
				Login = _ConvertRegisterLoginLineToRecord(Line);
				vStr.push_back(Login);
			}
		}
		MyFile.close();
		return vStr;
	}

};

