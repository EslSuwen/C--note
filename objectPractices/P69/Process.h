#include <cstring>
#include <iostream>

using namespace std;
class process
{
  public:
    virtual void print() = 0;
};

class person : public process
{
  protected:
    char name[8];
    char sex[6];
    int age;

  public:
    person(const char *n, const char *s, int a)
    {
        strcpy(name, n);
        strcpy(sex, s);
        age = a;
    }
    void setPerson(char *n, char *s, int a)
    {
        strcpy(name, n);
        strcpy(sex, s);
        age = a;
    }
    char *getName()
    {
        return name;
    }
    char *getSex()
    {
        return sex;
    }
    int getAge()
    {
        return age;
    }
    void print()
    {
        cout << "Name: " << getName() << endl;
        cout << "Sex: " << getSex() << endl;
        cout << "age: " << getAge() << endl;
    }
};

class student : public person
{
  private:
    char college[10];
    char major[20];
    char No[11];

  public:
    student(const char *n, const char *s, int a, const char *c, const char *m, const char *N) : person(n, s, a)
    {
        strcpy(college, c);
        strcpy(major, m);
        strcpy(No, N);
    }
    void setstudent(char *c, char *m, char *N)
    {
        strcpy(college, c);
        strcpy(major, m);
        strcpy(No, N);
    }
    char *getCollege()
    {
        return college;
    }
    char *getMajor()
    {
        return major;
    }
    char *getNo()
    {
        return No;
    }
    void print()
    {
        cout << "Name: " << getName() << endl;
        cout << "Sex: " << getSex() << endl;
        cout << "age: " << getAge() << endl;
        cout << "college: " << getCollege() << endl;
        cout << "major: " << getMajor() << endl;
        cout << "No: " << getNo() << endl;
    }
};