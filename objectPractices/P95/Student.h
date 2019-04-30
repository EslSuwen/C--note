#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;

class Student
{
  private:
	int studNo;			  //学号
	char major[21];		  //专业
	char name[31];		  //学生姓名
	char sex[8];		  //学生性别
	char phoneNumber[31]; //学生联系电话

  public:
	void initStudent(int sn, const char *m, const char *n, const char *s, const char *pn)
	{
		studNo = sn;
		strcpy(major, m);
		strcpy(name, n);
		strcpy(sex, s);
		strcpy(phoneNumber, pn);
	}
	int getStudNo()
	{
		return studNo;
	}
	char *getMajor()
	{
		return major;
	}
	char *getStudName()
	{
		return name;
	}
	char *getSex()
	{
		return sex;
	}
	char *getPhoneNumber()
	{
		return phoneNumber;
	}
	void print()
	{
		cout << "\t\t " << setw(10) << studNo;
		cout << setw(24) << major;
		cout << setw(12) << name;
		cout << setw(16) << sex;
		cout << setw(20) << phoneNumber;
		cout << endl;
	}
	friend ostream &operator<<(ostream &os, Student &student);
	friend istream &operator>>(istream &is, Student &student);
};
ostream &operator<<(ostream &os, Student &student)
{
	student.print();
	return os;
}
istream &operator>>(istream &is, Student &student)
{
	int sn;
	char m[21], n[31], s[8], pn[31];
	is >> sn >> m >> n >> s >> pn;
	student.initStudent(sn, m, n, s, pn);
	return is;
}
