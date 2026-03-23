#pragma once
#pragma warning (disable:4996 )
#include <iostream>
#include <ctime>
#include <string>
#include "clsString.h"

using namespace std;

class clsDateLibrary
{
	short _Year;
	short _Month;
	short _Day;

public:

	clsDateLibrary()
	{
		time_t t = time(0);
		tm* now = localtime(&t);

		_Year = now->tm_year + 1900;
		_Month = now->tm_mon + 1;
		_Day = now->tm_mday;
	}

	clsDateLibrary(short Day, short Month, short Year)
	{
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}

	clsDateLibrary(string Date)
	{
		vector <string> Vstring = clsString::SplitFunction(Date, "/");

		_Day = stoi(Vstring[0]);
		_Month = stoi(Vstring[1]);
		_Year = stoi(Vstring[2]);
	}

	clsDateLibrary(short DayOrder, short Year)
	{
		clsDateLibrary Date = GetDateFromDayOrder(DayOrder, Year);
		_Year = Date.Year;
		_Month = Date.Month;
		_Day = Date.Day;
	}

	void setYear(short Year)
	{
		_Year = Year;
	}

	short getYear()
	{
		return _Year;
	}

	__declspec(property(get = getYear, put = setYear)) short Year;

	void setMonth(short Month)
	{
		_Month = Month;
	}

	short getMonth()
	{
		return _Month;
	}

	__declspec(property(get = getMonth, put = setMonth)) short Month;

	void setDay(short Day)
	{
		_Day = Day;
	}

	short getDay()
	{
		return _Day;
	}

	__declspec(property(get = getDay, put = setDay)) short Day;

	void Print()
	{
		cout << DateToString();
	}

	static string DateToString(clsDateLibrary Date)
	{
		return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
	}

	static clsDateLibrary GetSystemDate()
	{
		return clsDateLibrary();
	}

	string DateToString()
	{
		return DateToString(*this);
	}

	static bool IsLeapYear(short Year)
	{
		return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
	}

	bool IsLeapYear()
	{
		return IsLeapYear(_Year);
	}

	static short NumberOfDaysInYear(short Year)
	{
		return (IsLeapYear(Year)) ? 366 : 365;
	}

	short NumberOfDaysInYear()
	{
		return NumberOfDaysInYear(_Year);
	}

	static short NumberOfHours(short Year)
	{
		return NumberOfDaysInYear(Year) * 24;
	}

	short NumberOfHours()
	{
		return NumberOfHours(_Year);
	}

	static short NumberOfMinute(short Year)
	{
		return NumberOfHours(Year) * 60;
	}

	short NumberOfMinute()
	{
		return NumberOfMinute(_Year);
	}

	static short NumberOfSeconds(short Year)
	{
		return NumberOfMinute(Year) * 60;
	}

	short NumberOfSeconds()
	{
		return NumberOfSeconds(_Year);
	}

	static short NumberOfDaysInMonth(short Year, short Month)
	{
		if (Month < 1 || Month > 12)
			return 0;

		short NumberOfDays[] = { 31,28,31,30,31,30,31,31,30,31,30,31};

		return (Month == 2) ? (IsLeapYear(Year)) ? 29 : 28 : NumberOfDays[Month - 1];
	}

	short NumberOfDaysInMonth()
	{
		return NumberOfDaysInMonth(_Year, _Month);
	}

	static short NumberOfHoursInMonth(short Year, short Month)
	{
		return NumberOfDaysInMonth(Year, Month) * 24;
	}

	short NumberOfHoursInMonth()
	{
		return NumberOfHoursInMonth(_Year, _Month);
	}

	static short NumberOfMinuteInMonth(short Year, short Month)
	{
		return NumberOfHoursInMonth(Year, Month) * 60;
	}

	short NumberOfMinuteInMonth()
	{
		return NumberOfMinuteInMonth(_Year, Month);
	}

	static short NumberOfSecondsInMonth(short Year, short Month)
	{
		return NumberOfMinuteInMonth(Year, Month) * 60;
	}

	short NumberOfSecondsInMonth()
	{
		return NumberOfSecondsInMonth(_Year, _Month);
	}

	static short DayOfWeekOrder(clsDateLibrary Date)
	{
		short a = ((14 - Date.Month) / 12);
		short y = Date.Year - a;
		short m = Date.Month + 12 * a - 2;

		short d = (Date.Day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;

		return d;
	}

	short DayOfWeekOrder()
	{
		 return DayOfWeekOrder(*this);
	}

	static string DayName(short DayOrder)
	{
		string Days[] = { "Sun" , "Mon" , "Tues" , "Wed" , "Thurs" , "Fri" , "Sat" };

		return Days[DayOrder];
	}

	string DayName()
	{
		return DayName(DayOfWeekOrder(*this));
	}

	static string MonthName(short Month)
	{
		string MonthArr[] = { "Jan", "Feb", "Mar","Apr", "May", "Jun","Jul", "Aug", "Sep","Oct", "Nov", "Dec" };

		return MonthArr[Month-1];
	}

	static void PrintMonthCalendar(short Year , short Month)
	{
		clsDateLibrary Date(Year,Month,1);
		short current = DayOfWeekOrder(Date);
		short Days = NumberOfDaysInMonth(Year,Month);

		printf("----------------------%s-------------------\n\n", MonthName(Month).c_str());
		printf("  Sun   Mon  Tue  Wed  Thu  Fri  Sat\n");

		short i;
		for (i = 0; i < current; i++)
			printf("     ");
		for (short j = 1; j <= Days; j++)
		{
			printf("%5d", j);
			if (++i == 7)
			{
				i = 0;
				printf("\n");
				
			}
		}
		printf("\n _________________________________\n");
	}

	void PrintMonthCalendar()
	{
		PrintMonthCalendar(_Year,_Month);
	}

	static void PrintYearCalendar(short Year)
	{
		printf("\n _________________________________\n\n");
		printf(" Calendar - %d\n",Year);
		printf(" _________________________________\n");

		for (short i = 1; i <= 12; i++)
		{
			PrintMonthCalendar(Year , i);
		}
	}

	void PrintYearCalendar()
	{
		PrintYearCalendar(_Year);
	}

	static short DaysFromBeginningTheYear(clsDateLibrary Date)
	{
		short NumberOfDays = 0;

		for (short i = 1; i < Date.Month; i++)
		{
			NumberOfDays += NumberOfDaysInMonth(Date.Year, i);
		}
		return NumberOfDays + Date.Day;
	}

	short DaysFromBeginningTheYear()
	{
		 return DaysFromBeginningTheYear(*this);
	}

	static clsDateLibrary GetDateFromDayOrder(short Year , short DayOrder)
	{
		clsDateLibrary Date;
		Date.Month = 1;
		Date.Year = Year;

		if (DayOrder > NumberOfDaysInYear(Year) || DayOrder < 1)
			return {};

		while (DayOrder > NumberOfDaysInMonth(Year,Date.Month))
		{
			DayOrder -= NumberOfDaysInMonth(Year, Date.Month);
			Date.Month++;
		}
		Date.Day = DayOrder;
		return Date;
	}

	 void GetDateFromDayOrder(short DayOrder)
	{
		 clsDateLibrary Date = clsDateLibrary::GetDateFromDayOrder(_Year, DayOrder);

		 _Year = Date.Year;
		 _Month = Date.Month;
		 _Day = Date.Day;
	}

	 static clsDateLibrary AddDayToDate(clsDateLibrary Date , int AddDay)
	 {
		 int ReminingDay = AddDay + DaysFromBeginningTheYear(Date);
		 short MonthDay = 0;
		 Date.Month = 1;
		 while (true)
		 {
			 MonthDay = NumberOfDaysInMonth(Date.Year, Date.Month);
			 if (ReminingDay > MonthDay)
			 {
				 ReminingDay -= MonthDay;
				 Date.Month++;
				 if (Date.Month > 12)
				 {
					 Date.Year++;
					 Date.Month = 1;
				 }
			 }
			 else
			 {
				 Date.Day = ReminingDay;
				 break;
			 }
		 }
		 return Date;
	 }

	 void AddDayToDate(int AddDay)
	 {
		*this =  AddDayToDate(*this, AddDay);
	 }

	 static bool IsDate1BeforeDate2(clsDateLibrary Date1, clsDateLibrary Date2)
	 {
		 return  (Date1.Year < Date2.Year) ? true :
			 (Date1.Year > Date2.Year) ? false :
			 (Date1.Month < Date2.Month) ? true :
			 (Date1.Month > Date2.Month) ? false :
			 (Date1.Day < Date2.Day);
		 
	 }

	 bool IsDate1BeforeDate2(clsDateLibrary Date)
	 {
		 return IsDate1BeforeDate2(*this, Date);
	 }

	 static bool IsDate1EqualDate2(clsDateLibrary Date1, clsDateLibrary Date2)
	 {
		 return (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day == Date2.Day);
	 }

	 bool IsDate1EqualDate2(clsDateLibrary Date)
	 {
		 return IsDate1EqualDate2(*this, Date);
	 }

	 static bool IsLastMonthInTheYear(short Month)
	 {
		 return Month == 12;
	 }

	 bool IsLastMonthInYear()
	 {
		 return IsLastMonthInTheYear(_Month);
	 }

	 static bool IsLastDayInTheMonth(clsDateLibrary Date)
	 {
		 return Date.Day == NumberOfDaysInMonth(Date.Year, Date.Month);
	 }

	 bool IsLastDayInTheMonth()
	 {
		 return IsLastDayInTheMonth(*this);
	 }

	 static void IncreaseDateByOneDay(clsDateLibrary &Date)
	 {
		 if (IsLastDayInTheMonth(Date))
		 {
			 Date.Day = 1;
			 if (IsLastMonthInTheYear(Date.Month))
			 {
				 Date.Year++;
				 Date.Month = 1;
			 }
			 else
			 {
				 Date.Month++;
			 }
		 }
		 else
		 {
			 Date.Day++;
		 }
	 }

	 void IncreaseDateByOneDay()
	 {
		  IncreaseDateByOneDay(*this);
	 }

	 static void SwapDate(clsDateLibrary &Date1, clsDateLibrary &Date2)
	 {
		 clsDateLibrary TempDate;

		 TempDate.Year = Date1.Year;
		 TempDate.Month = Date1.Month;
		 TempDate.Day = Date1.Day;

		 Date1.Year = Date2.Year;
		 Date1.Month = Date2.Month;
		 Date1.Day = Date2.Day;

		 Date2.Year = TempDate.Year;
		 Date2.Month = TempDate.Month;
		 Date2.Day = TempDate.Day;
	 }

	 static int DiffBetweenDate1AndDate2(clsDateLibrary Date1, clsDateLibrary Date2, bool IncludeLastDay = false)
	 {
		 int DiffDay = 0;
		 int SwapFlag = 1;

		 if (!IsDate1BeforeDate2(Date1, Date2))
		 {
			 SwapDate(Date1, Date2);
			 SwapFlag = -1;
		 }
		 while (IsDate1BeforeDate2(Date1, Date2))
		 {
			 DiffDay++;
			 IncreaseDateByOneDay(Date1);
		 }
		return  IncludeLastDay ? ++DiffDay * SwapFlag : DiffDay * SwapFlag;
	 }

	 int DiffBetweenDate1AndDate2(clsDateLibrary Date, bool IncludeLastDay = false)
	 {
		 return DiffBetweenDate1AndDate2(*this, Date , IncludeLastDay);
	 }

	 static int AgeInDay(clsDateLibrary Date)
	 {
		 clsDateLibrary Date1;
		 Date1 = GetSystemDate();

		 return DiffBetweenDate1AndDate2(Date, Date1);
	 }

	 int AgeInDay()
	 {
		 return AgeInDay(*this);
	 }

	 static clsDateLibrary FixDayInMonth(clsDateLibrary& Date)
	 {
		 short MaxDays = NumberOfDaysInMonth(Date.Year, Date.Month);

		 if (Date.Day > MaxDays)
		 {
			 Date.Day = MaxDays;
		 }

		 return Date;
	 }

	 static clsDateLibrary IncreaseDateByX_Day(clsDateLibrary &Date, short Days)
	 {
		 for (short i = 1; i <= Days; i++)
		 {
			  IncreaseDateByOneDay(Date);
		 }
		 return Date;
	 }

	 clsDateLibrary IncreaseDateByX_Day(short Day)
	 {
		 return IncreaseDateByX_Day(*this,Day);
	 }

	 static clsDateLibrary IncreaseDateByOneWeek(clsDateLibrary& Date )
	 {
		 return IncreaseDateByX_Day(Date, 7);
	 }

	 clsDateLibrary IncreaseDateByOneWeek()
	 {
		 return IncreaseDateByOneWeek(*this);
	 }

	 static clsDateLibrary IncreaseDateByX_Weeks(clsDateLibrary& Date, short Weeks)
	 {
		 for (short i = 1; i <= Weeks; i++)
		 {
			 Date = IncreaseDateByOneWeek(Date);
		 }
		 return Date;
	 }

	 clsDateLibrary IncreaseDateByX_Weeks(short Weeks)
	 {
		 return  IncreaseDateByX_Weeks(*this, Weeks);
	 }

	 static clsDateLibrary IncreaseDateByOneMonth(clsDateLibrary& Date)
	 {
		 if (IsLastMonthInTheYear(Date.Month))
		 {
			 Date.Year++;
			 Date.Month = 1;
		 }
		 else
		 {
			 Date.Month++;
		 }

		 Date = FixDayInMonth(Date);

		 return Date;
	 }

	 clsDateLibrary IncreaseDateByOneMonth()
	 {
		 return IncreaseDateByOneMonth(*this);
	 }

	 static clsDateLibrary IncreaseDataByX_Months(clsDateLibrary& Date, short Months)
	 {
		 for (int i = 1; i <= Months; i++)
		 {
			 Date = IncreaseDateByOneMonth(Date);
		 }
		 return Date;
	 }

	 clsDateLibrary IncreaseDataByX_Months(short Months)
	 {
		 return IncreaseDataByX_Months(*this, Months);
	 }

	 static clsDateLibrary IncreaseDateByOneYear(clsDateLibrary& Date )
	 {
		 Date.Year++;
		 Date = FixDayInMonth(Date);
		 return Date;
	 }

	 clsDateLibrary IncreaseDateByOneYear()
	 {
		 return IncreaseDateByOneYear(*this);
	 }

	 static clsDateLibrary IncreaseDateByX_Year(clsDateLibrary& Date, short Years)
	 {
		 for (int i = 1; i <= Years; i++)
		 {
			 Date = IncreaseDateByOneYear(Date);
		 }
		 return Date;
	 }

	 clsDateLibrary IncreaseDateByX_Year(short Years)
	 {
		 return IncreaseDateByX_Year(*this, Years);
	 }

	 static clsDateLibrary IncreaseDateByX_YearFaster(clsDateLibrary& Date, short Years)
	 {
		 Date.Year += Years;
		 Date = FixDayInMonth(Date);
		 return Date;
	 }

	 clsDateLibrary IncreaseDateByX_YearFaster(short Years)
	 {
		 return IncreaseDateByX_YearFaster(*this, Years);
	 }

	 static clsDateLibrary IncreaseDateByOneDecade(clsDateLibrary& Date)
	 {
		 return IncreaseDateByX_YearFaster(Date, 10);
	 }

	 clsDateLibrary IncreaseDateByOneDecade()
	 {
		 return IncreaseDateByOneDecade(*this);
	 }

	 static clsDateLibrary IncreaseDateByX_Decade(clsDateLibrary& Date, short Decade)
	 {
		 for (int i = 1; i <= Decade; i++)
		 {
			 Date = IncreaseDateByOneDecade(Date);
		 }
		 return Date;
	 }

	 clsDateLibrary IncreaseDateByX_Decade(short Decade)
	 {
		 return IncreaseDateByX_Decade(*this, Decade);
	 }

	 static clsDateLibrary IncreaseDateByX_DecadeFaster(clsDateLibrary& Date, short Decade)
	 {
		 Date.Year += 10 * Decade;
		 Date = FixDayInMonth(Date);
		 return Date;
	 }

	 clsDateLibrary IncreaseDateByX_DecadeFaster(short Decade)
	 {
		 return IncreaseDateByX_DecadeFaster(*this, Decade);
	 }

	 static clsDateLibrary IncreaseDateByOneCentury(clsDateLibrary &Date)
	 {
		 return IncreaseDateByX_DecadeFaster(Date, 10);

	 }

	 clsDateLibrary IncreaseDateByOneCentury()
	 {
		 return IncreaseDateByOneCentury(*this);
	 }

	 static clsDateLibrary IncreaseDateByOneMillennium(clsDateLibrary& Date)
	 {
		 Date.Year += 1000;
		 Date = FixDayInMonth(Date);
		 return Date;
	 }

	 clsDateLibrary IncreaseDateByOneMillennium()
	 {
		 return IncreaseDateByOneMillennium(*this);
	 }

	 static clsDateLibrary DecreaseDateByOneDay(clsDateLibrary& Date)
	 {
		 if (Date.Day == 1)
		 {
			 Date.Month--;
			 if (Date.Month == 0)
			 {
				 Date.Year--;
				 Date.Month = 12;
			 }
			 Date.Day = NumberOfDaysInMonth(Date.Year, Date.Month);
		 }
		 else
		 {
			 Date.Day--;
		 }
		 return Date;

	 }

	 clsDateLibrary DecreaseDateByOneDay()
	 {
		 return DecreaseDateByOneDay(*this);
	 }

	 static clsDateLibrary DecreaseDateByX_Days(clsDateLibrary &Date, short Days)
	 {
		 for (short i = 1; i <= Days; i++)
		 {
			 Date = DecreaseDateByOneDay(Date);
		 }
		 return Date;
	 }

	 clsDateLibrary DecreaseDateByX_Days(short Days)
	 {
		 return DecreaseDateByX_Days(*this, Days);
	 }

	 static clsDateLibrary DecreaseDateByOneWeek(clsDateLibrary& Date)
	 {
		 return DecreaseDateByX_Days(Date, 7);
	 }

	 clsDateLibrary DecreaseDateByOneWeek()
	 {
		 return DecreaseDateByOneWeek(*this);
	 }

	 static clsDateLibrary DecreaseDateByX_Weeks(clsDateLibrary& Date, short Weeks)
	 {
		 for (short i = 1; i <= Weeks; i++)
		 {
			 Date = DecreaseDateByOneWeek(Date);
		 }
		 return Date;
	 }

	 clsDateLibrary DecreaseDateByX_Weeks(short Weeks)
	 {
		 return DecreaseDateByX_Weeks(*this, Weeks);
	 }

	 static clsDateLibrary DecreaseDateByOneMonth(clsDateLibrary& Date)
	 {
		 if (Date.Month == 1)
		 {
			 Date.Year--;
			 Date.Month = 12;
			 Date = FixDayInMonth(Date);
		 }
		 else
		 {
			 Date.Month--;
			 Date = FixDayInMonth(Date);
		 }
		 return Date;
	 }

	 clsDateLibrary DecreaseDateByOneMonth()
	 {
		 return DecreaseDateByOneMonth(*this);
	 }

	 static clsDateLibrary DecreaseDateByX_Months(clsDateLibrary& Date, short Months)
	 {
		 for (short i = 1; i <= Months; i++)
		 {
			 Date = DecreaseDateByOneMonth(Date);
		 }
		 return Date;
	 }

	 clsDateLibrary DecreaseDateByX_Months(short Months)
	 {
		 return DecreaseDateByX_Months(*this, Months);
	 }

	 static clsDateLibrary DecreaseDateByOneYear(clsDateLibrary &Date)
	 {
		 Date.Year--;
		 Date = FixDayInMonth(Date);
		 return Date;
	 }

	 clsDateLibrary DecreaseDateByOneYear()
	 {
		 return DecreaseDateByOneYear(*this);
	 }

	 static clsDateLibrary DecreaseDateByX_Years(clsDateLibrary &Date, short Years)
	 {
		 for (short i = 1; i <= Years; i++)
		 {
			 Date = DecreaseDateByOneYear(Date);
		 }
		 return Date;
	 }

	 clsDateLibrary DecreaseDateByX_Years(short Years)
	 {
		 return DecreaseDateByX_Years(*this, Years);
	 }

	 static clsDateLibrary DecreaseDateByX_YearsFaster(clsDateLibrary &Date, short Years)
	 {
		 Date.Year -= Years;
		 Date = FixDayInMonth(Date);
		 return Date;
	 }

	 clsDateLibrary DecreaseDateByX_YearsFaster(short Years)
	 {
		 return DecreaseDateByX_YearsFaster(*this, Years);
	 }

	 static clsDateLibrary DecreaseDateByOneDecade(clsDateLibrary& Date)
	 {
		 Date.Year -= 10;
		 Date = FixDayInMonth(Date);
		 return Date;
	 }

	 clsDateLibrary DecreaseDateByOneDecade()
	 {
		 return DecreaseDateByOneDecade(*this);
	 }

	 static clsDateLibrary DecreaseDateByX_Decades(clsDateLibrary &Date, short Decades)
	 {
		 for (short i = 1; i <= Decades; i++)
		 {
			 Date = DecreaseDateByOneDecade(Date);
		 }
		 return Date;
	 }

	 clsDateLibrary DecreaseDateByX_Decades(short Decades)
	 {
		 return DecreaseDateByX_Decades(*this, Decades);
	 }

	 static clsDateLibrary DecreaseDateByX_DecadesFaster(clsDateLibrary& Date, short Decades)
	 {
		 Date.Year -= Decades * 10;
		 Date = FixDayInMonth(Date);
		 return Date;
	 }

	 clsDateLibrary DecreaseDateByX_DecadesFaster(short Decades)
	 {
		 return DecreaseDateByX_DecadesFaster(*this, Decades);
	 }

	 static clsDateLibrary DecreaseDateByOneCentury(clsDateLibrary& Date)
	 {
		 Date.Year -= 100;
		 Date = FixDayInMonth(Date);
		 return Date;
	 }

	 clsDateLibrary DecreaseDateByOneCentury()
	 {
		 return DecreaseDateByOneCentury(*this);
	 }

	 static clsDateLibrary DecreaseDateByOneMilleniumYear(clsDateLibrary& Date)
	 {
		 Date.Year -= 1000;
		 Date = FixDayInMonth(Date);
		 return Date;
	 }

	 clsDateLibrary DecreaseDateByOneMilleniumYear()
	 {
		 return DecreaseDateByOneMilleniumYear(*this);
	 }

	 static bool IsEndOfWeek(clsDateLibrary Date)
	 {
		 return (DayOfWeekOrder(Date) == 5 || DayOfWeekOrder(Date) == 6);
	 }

	 bool IsEndOfWeek()
	 {
		 return IsEndOfWeek(*this);
	 }

	 static bool IsWeekEnd(clsDateLibrary Date)
	 {
		 return (DayOfWeekOrder(Date) == 5 || DayOfWeekOrder(Date) == 6);
	 }

	 bool IsWeekEnd()
	 {
		 return IsWeekEnd(*this);
	 }

	 static bool IsBusinessDay(clsDateLibrary Date)
	 {
		 return (!IsWeekEnd(Date));
	 }

	 bool IsBusinessDay()
	 {
		 return IsBusinessDay(*this);
	 }

	 static short DaysUntilEndWeek(clsDateLibrary Date)
	 {
		 short UntilDays = 0;

		 for (short i = 0; i < 6; i++)
		 {
			 if (!IsEndOfWeek(Date))
			 {
				 UntilDays++;
				 IncreaseDateByOneDay(Date);
			 }
		 }
		 return UntilDays;
	 }

	 short DaysUntilEndWeek()
	 {
		 return DaysUntilEndWeek(*this);
	 }

	 static short DaysUntilEndMonth(clsDateLibrary Date)
	 {
		 return NumberOfDaysInMonth(Date.Year, Date.Month) - Date.Day;
	 }

	 short DaysUntilEndMonth()
	 {
		 return DaysUntilEndMonth(*this);
	 }

	 static short DaysUntilEndYear(clsDateLibrary Date)
	 {
		 return NumberOfDaysInYear(Date.Year) - DaysFromBeginningTheYear(Date);
	 }
	
	 short DaysUntilEndYear()
	 {
		 return DaysUntilEndYear(*this);
	 }

	 static short CalculateVacationDays(clsDateLibrary Date1, clsDateLibrary Date2)
	 {
		 short VacationDays = 0;

		 while (IsDate1BeforeDate2(Date1, Date2))
		 {
			 if (IsBusinessDay(Date1))
				 VacationDays++;
			 IncreaseDateByOneDay(Date1);
		 }
		 return VacationDays;
	 }

	 short CalculateVacationDays(clsDateLibrary Date)
	 {
		 return	CalculateVacationDays(*this, Date);
	 }

	 clsDateLibrary GetVacationReturnedDate(clsDateLibrary Date, short VacationDays)
	 {
		 short WeekEndCounter = 0;
		
		 while (IsWeekEnd(Date))
		 {
			 IncreaseDateByOneDay(Date);
		 }

		 for (short i = 0; i < VacationDays + WeekEndCounter; i++)
		 {
			 if (IsWeekEnd(Date))
				 WeekEndCounter++;
			 IncreaseDateByOneDay(Date);
		 }

		 while (IsWeekEnd(Date))
			 IncreaseDateByOneDay(Date);

		 return Date;
	 }

	 clsDateLibrary GetVacationReturnedDate(short VacationDays)
	 {
		 return GetVacationReturnedDate(*this, VacationDays);
	 }

	 static bool IsDate1AfterDate2(clsDateLibrary Date1, clsDateLibrary Date2)
	 {
		 return !(IsDate1BeforeDate2(Date1, Date2) && IsDate1EqualDate2(Date1, Date2));
	 }

	 bool IsDate1AfterDate2(clsDateLibrary Date)
	 {
		 return IsDate1AfterDate2(*this, Date);
	 }

	 static int CompareDate(clsDateLibrary Date1, clsDateLibrary Date2)
	 {
		 if (IsDate1BeforeDate2(Date1, Date2))
			 return 1;
		 if (IsDate1EqualDate2(Date1, Date2))
			 return 0;
		 if (IsDate1AfterDate2(Date1, Date2))
			 return -1;
	 }

	 int CompareDate(clsDateLibrary Date)
	 {
		 return CompareDate(*this, Date);
	 }

	 static int PeriodDays(clsDateLibrary Date1Start, clsDateLibrary Date1End, clsDateLibrary Date2Start, clsDateLibrary Date2End)
	 {
		 clsDateLibrary IntersectStart = IsDate1BeforeDate2(Date1Start, Date2Start) ? Date1Start : Date2Start;
		 clsDateLibrary IntersectEnd = IsDate1BeforeDate2(Date1End, Date2End) ? Date1End : Date2End;

		 return DiffBetweenDate1AndDate2(IntersectStart, IntersectEnd, true);
	 }

	 int PeriodDays(clsDateLibrary Date1End, clsDateLibrary Date2Start, clsDateLibrary Date2End)
	 {
		 return PeriodDays(*this, Date1End, Date2Start, Date2End);
	 }

	 static bool IsDateWithinPeriod(clsDateLibrary Date, clsDateLibrary PeriodStart, clsDateLibrary PeriodEnd)
	 {
		 return !(CompareDate(Date, PeriodStart) == 1 || CompareDate(PeriodEnd, Date) == 1);
	 }

	 bool IsDateWithinPeriod(clsDateLibrary PeriodStart, clsDateLibrary PeriodEnd)
	 {
		 return IsDateWithinPeriod(*this, PeriodStart, PeriodEnd);
	 }

	 static bool IsValidDate(clsDateLibrary Date)
	 {
		 if (Date.Year <= 0)
			 return false;
		 if (Date.Month <= 0 || Date.Month > 12)
			 return false;
		 if (Date.Day <= 0 || Date.Day > NumberOfDaysInMonth(Date.Year, Date.Month))
			 return false;

		 return true;
	 }

	 bool IsValidDate()
	 {
		 return IsValidDate(*this);
	 }

	 static string FormatDate(clsDateLibrary Date, string DateFormat = "dd/mm/yy")
	 {
		 string FormatDateToString = "";

		 FormatDateToString = clsString::ReplaceWord(DateFormat, "dd", to_string(Date.Day));
		 FormatDateToString = clsString::ReplaceWord(FormatDateToString, "mm", to_string(Date.Month));
		 FormatDateToString = clsString::ReplaceWord(FormatDateToString, "yy", to_string(Date.Year));

		 return FormatDateToString;
	 }

	 string FormatDate(string DateFormat = "dd/mm/yy")
	 {
		 return FormatDate(*this, DateFormat);
	 }

	 static string CurrentTime()
	 {
		 time_t t = time(0);
		 tm* now = localtime(&t);

		 return to_string(now->tm_hour) + ":" + to_string(now->tm_min) + ":" + to_string(now->tm_sec);
	 }
};

