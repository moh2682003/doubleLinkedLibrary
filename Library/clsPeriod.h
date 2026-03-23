#pragma once
#include "clsDateLibrary.h"

class clsPeriod
{
public:

    clsDateLibrary StartDate;
    clsDateLibrary EndDate;

    clsPeriod(clsDateLibrary StartDate, clsDateLibrary DateTo)
    {
        this->StartDate = StartDate;
        this->EndDate = EndDate;

    }

    static bool IsOverlapPeriods(clsPeriod Period1, clsPeriod Period2)
    {

        if (
            clsDateLibrary::CompareDate(Period2.EndDate, Period1.StartDate) == clsDateLibrary::enCompareDate::Before
            ||
            clsDateLibrary::CompareDate(Period2.StartDate, Period1.EndDate) == clsDateLibrary::enCompareDate::After
            )
            return false;
        else
            return true;

    }

    bool IsOverLapWith(clsPeriod Period2)
    {
        return IsOverlapPeriods(*this, Period2);
    }

    void Print()
    {
        cout << "Period Start: ";
        StartDate.Print();


        cout << "Period End: ";
        EndDate.Print();


    }

};
