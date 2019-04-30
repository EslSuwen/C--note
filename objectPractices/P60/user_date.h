#include <iostream>
using namespace std;
class date
{
  private:
    int year;
    int month;
    int day;

  public:
    date(int y, int m, int d)
    {
        year = y;
        month = m;
        day = d;
    }
    void print()
    {
        cout << year << "/" << month << "/" << day << endl;
    }
    int operator==(date d1)
    {
        return (year == d1.year && month == d1.month && day == d1.day) ? 1 : 0;
    }
    int operator>(date d1)
    {
        if (year > d1.year)
            return 1;
        else if (year == d1.year && month > d1.month)
            return 1;
        else if (year == d1.year && month == d1.month && day > d1.day)
            return 1;
        else
            return 0;
    }
    int operator<(date d1)
    {
        if (year < d1.year)
            return 1;
        else if (year == d1.year && month < d1.month)
            return 1;
        else if (year == d1.year && month == d1.month && day < d1.day)
            return 1;
        else
            return 0;
    }
    int operator>=(date d1)
    {
        return operator==(d1) || operator>(d1) ? 1 : 0;
    }
    int operator<=(date d1)
    {
        return operator==(d1) || operator<(d1) ? 1 : 0;
    }
    int operator!=(date d1)
    {
        return operator==(d1) ? 0 : 1;
    }
    int leapYear(int year)
    {
        return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0) ? 1 : 0;
    }
    int operator-(date d1)
    {
        /*if (d1.operator<(d2))
        {
            date t = d2;
            d2 = d1;
            d1 = t;
        }*/
        int sum = 0;
        int m[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for (; year <= d1.year; month++)
        {
            if (month == 13)
            {
                year++;
                month = 1;
                continue;
            }
            sum += m[month - 1];
            if (month == 2)
            {
                if (leapYear(year))
                    sum++;
            }
        }
        return sum;
    }
};
