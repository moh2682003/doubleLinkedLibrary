#pragma once 
#include <iostream>

using namespace std;

class clsPerson
{
	string _FirstName;
	string _LastName;
	string _email;
	string _Phone;

public:

	clsPerson(string FirstName, string LastName, string Email, string Phone)
	{
		_FirstName = FirstName;
		_LastName = LastName;
		_email = Email;
		_Phone = Phone;
	}

	void setFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}

	string getFirstName()
	{
		return _FirstName;
	}

	__declspec(property(get = getFirstName, put = setFirstName)) string FirstName;

	void setLastName(string LastName)
	{
		_LastName = LastName;
	}

	string getLastName()
	{
		return _LastName;
	}

	__declspec(property(get = getLastName, put = setLastName)) string LastName;


	string FullName()
	{
		return _FirstName + " " + _LastName;
	}

	void setEmail(string Email)
	{
		_email = Email;
	}

	string getEmail()
	{
		return _email;
	}
	__declspec(property(get = getEmail, put = setEmail)) string Email;


	void setPhoneNumber(string Phone)
	{
		_Phone = Phone;
	}

	string getPhone()
	{
		return _Phone;
	}

	__declspec(property (get = getPhone, put = setPhoneNumber)) string PhoneNumber;

	void SendEmail(string Subject, string Body)
	{
		cout << "Your Following Successfully Send to: " << _email << endl;
		cout << "Subject: " << Subject << endl;
		cout << "Body: " << Body << endl;
		cout << "\n";
	}

	void sendMassage(string Massage)
	{
		cout << "Your Following Successfully Send to: " << _Phone << endl;
		cout << "Massage: " << Massage << endl;
		cout << "\n";
	}

};
