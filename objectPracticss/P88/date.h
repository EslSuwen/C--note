#include <iostream>
using namespace std;
class Date
{
  private:
    int year;
    int month;
    int day;

  public:
    Date(int y = 0, int m = 0, int d = 0) : year(y), month(m), day(d)
    {
    }
    int getYear()
    {
        return year;
    }
    int getMonth()
    {
        return month;
    }
    int getDay()
    {
        return day;
    }
    void setYear(int y)
    {
        year = y;
    }
    void setMonth(int m)
    {
        month = m;
    }
    void setDay(int d)
    {
        day = d;
    }
    int leapYear(Date d)
    {
        return (d.getYear() % 400 == 0 || (d.getYear() % 4 == 0 && d.getYear() % 100 != 0)) ? 1 : 0;
    }
    int leapYear()
    {
        return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) ? 1 : 0;
    }
    void print()
    {
        cout << "Date: " << year << " : " << month << " : " << day;
    }
    friend ostream &operator<<(ostream &os, Date &date);
    friend istream &operator>>(istream &is, Date &date);
};
ostream &operator<<(ostream &os, Date &date)
{
    os << "Date: " << date.getYear() << " : " << date.getMonth() << " : " << date.getDay();
    return os;
}
istream &operator>>(istream &is, Date &date)
{
    int year, month, day;
    is >> year >> month >> day;
    date.setYear(year);
    date.setMonth(month);
    date.setDay(day);
    return is;
}
