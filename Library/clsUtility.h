#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include "clsString.h"

using namespace std;

class clsUtility
{
public:

	static bool IsEvenNumber(int Number)
	{
		return Number % 2 == 0;
	}

	static void Swap(int& Num1, int& Num2)
	{
		int Temp;

		Temp = Num1;
		Num1 = Num2;
		Num2 = Temp;
	}

	static bool IsPrime(int N)
	{
		vector <int> AllPrime;

		int m = round(N / 2);

		for (int Counter = 2; Counter <= m; Counter++)
		{

			if (N % Counter == 0)
				return false;
		}

		return true;
	}

	static vector <int> GetPrimeNumber(int N)
	{
		vector <int> AllPrime;
		for (int i = 3; i < N; i++)
		{
			if (IsPrime(i))
				AllPrime.push_back(i);
		}
		return AllPrime;
	}

	static bool IsPrefectNumber(int Number)
	{
		if (IsPrime(Number))
			return false;
		int Count = 1;
		for (int i = 1; i <= sqrt(Number); i++)
			if (Number % i == 0)
				Count += i;
		return Count == Number;
	}

	static vector <int> GetPrefectNumberToN(int Number)
	{
		vector <int> AllPrefect;
		for (int i = 1; i <= Number; i++)
			if (IsPrefectNumber(i))
				AllPrefect.push_back(i);

		return AllPrefect;
	}

	static vector <int> ReverseOrder(int Number)
	{
		vector <int> AllReverse;
		int Reminder = 0;

		while (Number != 0)
		{
			Reminder = Number % 10;
			AllReverse.push_back(Reminder);
			Number = Number / 10;
		}
		return AllReverse;
	}

	static int SumOfDigits(int Number)
	{
		int Sum = 0;
		vector <int> VSum = ReverseOrder(Number);

		for (int i = 0; i < VSum.size(); i++)
		{
			Sum += VSum[i];
		}
		return Sum;
	}

	static int ReverseNumber(int Number)
	{
		int Remainder = 0;
		int Number2 = 0;

		while (Number > 0)
		{
			Remainder = Number % 10;
			Number = Number / 10;
			Number2 = Number2 * 10 + Remainder;
		}

		return Number2;
	}

	static int CountDigitFrequency(short DigitToCheck, int Number)
	{
		int FreqCount = 0;
		vector <int> VNumber = ReverseOrder(Number);

		for (int i = 0; i < VNumber.size(); i++)
			if (DigitToCheck == VNumber[i])
				FreqCount++;
		return FreqCount;
	}

	static short CountLetterFrequency(string S1, char C, bool MatchCase = true)
	{
		return clsString::CountLetter(S1, C, MatchCase);
	}

	static bool isPalindromeNumber(int Number)
	{
		return ReverseNumber(Number) == Number;
	}

	static string EncryptText(string text, short Key)
	{
		for (int i = 0; i < text.length(); i++)
			text[i] = text[i] + Key;
		return text;
	}

	static string DecryptText(string text, short Key)
	{
		for (int i = 0; i < text.length(); i++)
			text[i] = text[i] - Key;
		return text;
	}

	static int RandomNumber(int From, int To)
	{
		return rand() % (To - From + 1) + From;
	}

	enum enCharType { SmallLetter = 1, CaptialLetter = 2, Digit = 3 ,SpicalCharcter = 4, MixChar = 5 };

	static char RandomCharacters(enCharType C)
	{

		if (C == MixChar)
			C = enCharType((RandomNumber(1, 3)));
		switch (C)
		{
		case enCharType::SmallLetter:
			return char(RandomNumber(97, 122));
		case enCharType::CaptialLetter:
			return char(RandomNumber(65, 90));
		case enCharType::SpicalCharcter:
			return char(RandomNumber(33, 47));
		case enCharType::Digit:
			return char(RandomNumber(48, 57));
		default:
			return C;
		}
	}

	static void RandomArrArr(int arr[], int length)
	{

		for (int i = 0; i < length; i++)
		{
			arr[i] = RandomNumber(1, 100);
		}
	}

	static vector <int> RandomArrVector(int length)
	{
		vector <int> Varr(length);
		for (int i = 0; i < length; i++)
			Varr[i] = (RandomNumber(1, 100));
		return Varr;
	}

	static int MaxNumberInArr(const vector <int>& Varr)
	{
		int MaxNumber = Varr[0];

		for (int i = 1; i < Varr.size(); i++)
			if (Varr[i] > MaxNumber)
				MaxNumber = Varr[i];
		return MaxNumber;
	}

	static int MinNumberInArr(const vector <int>& Varr)
	{
		int MinNumber = Varr[0];

		for (int i = 1; i < Varr.size(); i++)
			if (Varr[i] < MinNumber)
				MinNumber = Varr[i];
		return MinNumber;
	}

	static int SumNumberInArr(const vector <int>& Varr)
	{
		int Sum = 0;
		for (int i = 0; i < Varr.size(); i++)
			Sum += Varr[i];
		return Sum;
	}

	static double AverageNumberInArr(const vector <int>& Varr)
	{
		if (Varr.empty())
			return 0;
		double Sum = SumNumberInArr(Varr);
		return Sum / Varr.size();
	}

	static vector <int> CopyArr(const vector <int>& Varr)
	{
		vector <int> CVarr = Varr;
		return CVarr;
	}

	static vector <int> CopyOnlyPrimeNumberInArr(const vector <int>& Varr)
	{
		vector <int> CVarr;

		for (int i = 0; i < Varr.size(); i++)
			if (IsPrime(Varr[i]))
				CVarr.push_back(Varr[i]);
		return CVarr;

	}

	static vector <int> Sum2ArrWithSameLength(const vector <int>& Varr1, const vector <int>& Varr2)
	{
		vector <int> SumArr;

		if (Varr1.size() == Varr2.size())
		{
			for (int i = 0; i < Varr1.size(); i++)
				SumArr.push_back(Varr1[i] + Varr2[i]);
			return SumArr;
		}
		return SumArr;
	}

	static vector <int> GetOrderArr(int length)
	{
		vector <int> OVarr;

		for (int i = 1; i <= length; i++)
			OVarr.push_back(i);
		return OVarr;
	}

	static int CountElementFrequency(const vector <int>& Varr, short Number)
	{
		short Count = 0;
		for (int i = 0; i < Varr.size(); i++)
			if (Number == Varr[i]) Count++;
		return Count;
	}

	static vector <int> ShuffledArr(const vector <int>& Varr)
	{
		vector <int> ShuffledArr = Varr;

		for (int i = 0; i < ShuffledArr.size(); i++)
		{
			int j = RandomNumber(0, ShuffledArr.size() - 1);

			Swap(ShuffledArr[j], ShuffledArr[i]);
		}
		return ShuffledArr;

	}

	static vector <int> CopyArrInReverseOrder(const vector <int>& Varr)
	{
		vector <int> CVarr;

		for (int i = 0; i < Varr.size(); i++)
			CVarr.push_back(Varr[Varr.size() - 1 - i]);
		return CVarr;
	}

	static string GenerateWord(int GWordlength = 4)
	{
		string GWord = "";

		for (int i = 0; i < GWordlength; i++)
		{
			GWord += RandomCharacters(enCharType::CaptialLetter);
		}

		return GWord;
	}

	static string GenerateKey(int GWordLength = 4)
	{
		string Key = GenerateWord(GWordLength);

		for (int i = 1; i < GWordLength; i++)
		{
			Key += "-" + GenerateWord(GWordLength);
		}

		return Key;
	}

	static int SearchNumberInArr(const vector <int>& Varr, int SearchNumber)
	{
		for (int i = 0; i < Varr.size(); i++)
			if (Varr[i] == SearchNumber)
				return i;
		return -1;
	}

	static vector <int> CopyOnlyOddNumberInArr(const vector <int>& Varr)
	{
		vector <int> CVarr;
		for (int i = 0; i < Varr.size(); i++)
			if (!IsEvenNumber(Varr[i]))
				CVarr.push_back(Varr[i]);
		return CVarr;

	}

	static vector <int> Distinct(const vector<int>& Varr)
	{
		vector <int> CVarr;

		for (int i = 0; i < Varr.size(); i++)
		{
			bool Found = false;

			for (int j = 0; j < CVarr.size(); j++)
			{
				if (Varr[i] == CVarr[j])
				{
					Found = true;
					break;
				}
			}
			if (!Found)
				CVarr.push_back(Varr[i]);
		}
		return CVarr;
	}

	static bool IsPlinderArr(const vector <int>& Varr)
	{
		int start = 0;
		int end = Varr.size() - 1;

		while (start < end)
		{
			if (Varr[start] != Varr[end])
				return false;
			start++;
			end--;
		}
		return true;
	}

	static short CountOddNumberInArr(const vector <int>& Varr)
	{
		short Count = 0;

		for (int i = 0; i < Varr.size(); i++)
			if (!IsEvenNumber(Varr[i]))
				Count++;
		return Count;
	}

	static short CountEvenNumberInArr(const vector <int>& Varr)
	{
		return Varr.size() - CountOddNumberInArr(Varr);
	}

	static short CountPostiveNumbersInArr(const vector <int>& Varr)
	{
		int Count = 0;

		for (int i = 0; i < Varr.size(); i++)
			if (Varr[i] > 0)
				Count++;
		return Count;
	}

	static short CountNegitiveNumberInArr(const vector <int>& Varr)
	{
		int Count;
		for (int i = 0; i < Varr.size(); i++)
			if (Varr[i] < 0)
				Count++;
		return Count;
	}

	static string ConvertNumberToText(long long  Number)
	{
		if (Number == 0)
		{
			return "";
		}
		if (Number >= 1 && Number <= 19)
		{
			string Arr[] = { "" , "One" , "Tow" , "Three" , "Four" , "Five" , "Six" , "Seven" , "Eight" , "Nine" , "Ten",
			"Eleven", "Twelve" , "Thirteen" , "Fourteen" ,"Fifteen" , "Sixteen" , "Seventeen" , "Eighteen" , "Nineteen" };

			return Arr[Number];
		}
		if (Number >= 20 && Number <= 99)
		{
			string Arr1[] = { "" , "" , "Twenty" , "Thirty" , "Forty" , "Fifty" , "Sixty" , "Seventy" , "Eighty", "Ninty" };
			return Arr1[Number / 10] + " " + ConvertNumberToText(Number % 10);
		}
		if (Number >= 100 && Number <= 199)
		{
			return "OneHundred " + ConvertNumberToText(Number % 100);
		}
		if (Number >= 200 && Number <= 999)
		{
			return ConvertNumberToText(Number / 100) + "Hundred " + ConvertNumberToText(Number % 100);
		}
		if (Number >= 1000 && Number <= 1999)
		{
			return "OneThousand " + ConvertNumberToText(Number % 1000);
		}
		if (Number >= 2000 && Number <= 999999)
		{
			return ConvertNumberToText(Number / 1000) + "Thousands " + ConvertNumberToText(Number % 1000);
		}
		if (Number >= 1000000 && Number <= 1999999)
		{
			return "OneMillion " + ConvertNumberToText(Number % 1000000);
		}
		if (Number >= 2000000 && Number <= 999999999)
		{
			return ConvertNumberToText(Number / 1000000) + "Million " + ConvertNumberToText(Number % 1000000);
		}
		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return "OneBillion" + ConvertNumberToText(Number % 1000000000);
		}
		if (Number >= 2000000000 && Number <= 999999999999)
		{
			return ConvertNumberToText(Number / 1000000000) + "Billion " + ConvertNumberToText(Number % 1000000000);
		}

	}


};

