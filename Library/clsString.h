#include <iostream>
#include <cctype>
#include <vector>
#pragma once

using namespace std;

class clsString
{
	string _Value;

public:

	clsString(string Value)
	{
		_Value = Value;
	}

	clsString()
	{
		_Value = "";
	}

	void setValue(string Value)
	{
		_Value = Value;
	}

	string getValue()
	{
		return _Value;
	}

	__declspec(property(get = getValue, put = setValue)) string Value;

	void Print()
	{
		cout << _Value << endl ;
	}

	static void FirstLetterOfEachWord(string S1)
	{
		bool IsFirstLetter = true;
		cout << "First Letter Of Each Word\n";
		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && IsFirstLetter)
			{
				cout << S1[i] << endl;
			}
			IsFirstLetter = (S1[i] == ' ' ? true : false);
		}
	}

	void FirstLetterOfEachWord()
	{
		FirstLetterOfEachWord(_Value);
	}

	static string UpperFirstLetterOfEachWord(string S1)
	{
		bool IsFirstLetter = true;
		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && IsFirstLetter)
			{
				S1[i] = toupper(S1[i]);
			}
			IsFirstLetter = (S1[i] == ' ' ? true : false);
		}
		return S1;
	}

	void UpperFirstLetterOfEachWord()
	{
		_Value =  UpperFirstLetterOfEachWord(_Value);
	}

	static string LowerFirstLetterOfEachWord(string S1)
	{
		bool IsFirstLetter = true;
		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && IsFirstLetter)
			{
				S1[i] = tolower(S1[i]);
			}
			IsFirstLetter = (S1[i] == ' ' ? true : false);
		}
		return S1;
	}

	void LowerFirstLetterOfEachWord()
	{
		_Value =  LowerFirstLetterOfEachWord(_Value);
	}

	static string UpperAllLetters(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ')
				S1[i] = toupper(S1[i]);
		}
		return S1;
	}

	void UpperAllLetters()
	{
		_Value = UpperAllLetters(_Value);
	}

	static string LowerAllLetters(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
			S1[i] = tolower(S1[i]);
		return S1;
	}

	void LowerAllLetters()
	{
		_Value =  LowerAllLetters(_Value);
	}

	static char InvertLetterCase(char S1)
	{
		return isupper(S1) ? tolower(S1) : toupper(S1);
	}

	static string InvertAllLettersCase(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
			S1[i] = InvertLetterCase(S1[i]);
		return S1;
	}

	void InvertAllLettersCase()
	{
		_Value =  InvertAllLettersCase(_Value);
	}

	enum enCountLetter {SmallLetter = 1 , CaptailLetter = 2 , All = 3}; 

	short CountLetter(string S1, enCountLetter WhatToCount = enCountLetter::All)
	{
		int Count = 0;
		for (int i = 0; i < S1.length(); i++)
		{
			if (WhatToCount == enCountLetter::All && isalpha(S1[i]))
				Count++;
			if (WhatToCount == enCountLetter::CaptailLetter && isupper(S1[i]))
				Count++;
			if (WhatToCount == enCountLetter::SmallLetter && islower(S1[i]))
				Count++;
		}
		return Count;
	}

	static int CountSmallLetter(string S1)
	{
		int Count = 0 ;
		for (int i = 0; i < S1.length(); i++)
			if (islower(S1[i]))
				Count++;
		return Count;
	}

	int CountSmallLetter()
	{
		return CountSmallLetter(_Value);
	}

	static int CountCapitalLetter(string S1)
	{
		int Count = 0;
		for (int i = 0; i < S1.length(); i++)
			if (isupper(S1[i]))
				Count++;
		return Count;
	}

	int CountCapitalLetter()
	{
		return CountCapitalLetter(_Value);
	}

	static void CountAllLetter(string S1)
	{
		cout << "Capital Char : " << CountCapitalLetter(S1) <<  endl;
		cout << "Small Char: " << CountSmallLetter(S1) <<  endl;
	}

	void CountAllLetter()
	{
		CountAllLetter(_Value);
	}

	static int CountLetter(string S1, char C1 , bool MatchCase = true)
	{
		int Count = 0;
		for (int i = 0; i < S1.length(); i++)
		{
			if (MatchCase)
			{
				if (S1[i] == C1)
					Count++;
			}
			else
			{
				if (tolower(S1[i]) == tolower(C1))
					Count++;
			}
		}
		return Count;
	}

	int CountLetter(char C)
	{
		return CountLetter(_Value,C);
	}

	static int CountWord(string S1)
	{
		bool IsFirstLetter = true;
		int Count = 0;
		for (int i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && IsFirstLetter)
				Count++;
			IsFirstLetter = S1[i] == ' ' ? true : false;
		}
		return Count;
	}

	int CountWord()
	{
		return CountWord(_Value);
	}

	static bool IsVowel(char C1)
	{
		C1 = tolower(C1);
		return ((C1 == 'a') || (C1 == 'e') || (C1 == 'i') || (C1 == 'o') || (C1 == 'u'));
	}

	static int NumberOfVowelLetter(string S1)
	{
		int Count = 0;
		for (int i = 0; i < S1.length(); i++)
			if (IsVowel(S1[i]))
				Count++;
		return Count;
	}

	int NumberOfVowelLetter()
	{
		return NumberOfVowelLetter(_Value);
	}
	
	static void PrintAllVowelLetter(string S1)
	{
		for (int i = 0; i < S1.length(); i++)
			if (IsVowel(S1[i]))
				cout << S1[i] << "\t";
	}

	void PrintAllVowelLetter()
	{
		PrintAllVowelLetter(_Value);
	}

	static void PrintEachWord(string S1)
	{
		int Pos = 0;
		string Delim = " ";
		string Sword = " ";
		while ((Pos = S1.find(Delim)) != std::string::npos)
		{
			Sword = S1.substr(0, Pos);
			if (!Sword.empty())
				cout << Sword << endl;
			S1.erase(0, Pos + Delim.length());
		}
		if (!S1.empty())
			cout << S1 << endl;
	}

	void PrintEachWord()
	{
		PrintEachWord(_Value);
	}

	static vector<string> SplitFunction(string S1, string Delim = " ")
	{
		vector <string>  Vstring ;
		int Pos = 0; 
		string Sword = "";
		while ((Pos = S1.find(Delim)) != std::string::npos)
		{
			Sword = S1.substr(0, Pos);
			if (!Sword.empty())
				Vstring.push_back(Sword);
			S1.erase(0, Pos + Delim.length());
		}
		if (!S1.empty())
			Vstring.push_back(S1);
		return Vstring;
	}

	vector<string> SplitBy(string Delim = " ")
	{
		return  SplitFunction(_Value,Delim);
	}

	static string TrimLeft(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
			if (S1[i] != ' ')
				return S1.erase(0, i);
		return S1;
	}

	void TrimLeft()
	{
		_Value =  TrimLeft(_Value);
	}

	static string TrimRight(string S1)
	{
		for (int i = S1.length() - 1; i >= 0; i--)
			if (S1[i] != ' ')
				return S1.erase(i + 1, S1.length());
		return S1;
	}

	void TrimRight()
	{
		_Value =  TrimRight(_Value);
	}

	static string JoinString(vector <string> Vstring , string Separator = " ")
	{
		string Join = "";
		for (int i = 0; i < Vstring.size(); i++)
		{
			Join += Vstring[i];
			if (i != Vstring.size() - 1)
				Join += Separator;
		}
		return Join;
	}

	static string ReverseWordInString(string S1)
	{
		string S2 = "";
		vector <string> Vstring = SplitFunction(S1, " ");
		vector <string>::iterator  itr = Vstring.end();
		while (itr != Vstring.begin())
		{
			--itr;
			S2 += *itr + " ";
		}
		S2 = S2.substr(0, S2.length() - 1);
		return S2;
	}

	void ReverseWordInString()
	{
		_Value = ReverseWordInString(_Value);
	}

	static string ReplaceWord(string S1, string Replace, string ReplaceTo)
	{
		short pos = S1.find(Replace);
		while (pos != std::string::npos)
		{
			S1 = S1.replace(pos, Replace.length(), ReplaceTo);
			pos = S1.find(Replace);
		}
		return S1;
	}

	void ReplaceWord(string Replace , string ReplaceWordTo)
	{
		_Value =  ReplaceWord(_Value, Replace, ReplaceWordTo);
	}

	static string RemovePunctuationsFromString(string S1)
	{
		string S2 = "";
		for (int i = 0; i < S1.length(); i++)
		{
			if (!ispunct(S1[i]))
				S2 += S1[i];
		}
		return S2;
	}

	void RemovePunctuationsFromString()
	{
		_Value =  RemovePunctuationsFromString(_Value);
	}
};
