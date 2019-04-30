#include "Student.h"
#include <fstream>

class StudentSet
{
private:
  Student sData[100];
  int num;

public:
  StudentSet()
  {
    num = 0;
    ifstream f2;                             //定义一个输出流文件对象，即文件流变量
    f2.open("StudentData.dat", ios::binary); //打开一个文件，如果文件不存在，则有出错信息
    if (!f2)
    {
      return;
    }
    while (1)
    {
      f2.read((char *)&sData[num], sizeof(Student)); // 将数组中的数据元素一个一个地写入文件
      if (f2.eof())
        break;
      num++;
    }
    f2.close(); //关闭文件，断开 f2与具体文件的关联
  }
  ~StudentSet()
  {
    ofstream f2;                             //定义一个输出流文件对象，即文件流变量
    f2.open("StudentData.dat", ios::binary); //打开一个文件，如果文件不存在，则有出错信息
    if (!f2)
    {
      cout << "Save Data Error!" << endl;
      return;
    }
    for (int i = 0; i < num; i++)
    {
      f2.write((char *)&sData[i], sizeof(Student)); // 将数组中的数据元素一个一个地写入文件
    }
    f2.close(); //关闭文件，断开 f2与具体文件的关联
  }
  void process()
  {
    while (1)
    {
      cout << "\n\t\t\t   Student Information\n";
      cout << "\t\t\t------------------------" << endl;
      cout << "\t\t\t  1. Information input" << endl;
      cout << "\t\t\t  2. Information output" << endl;
      cout << "\t\t\t  3. Information find" << endl;
      cout << "\t\t\t  0.      exit" << endl;
      cout << "\t\t\t------------------------" << endl;
      int sel;
      cout << "Please input your choice :";
      cin >> sel;

      switch (sel)
      {
      case 1:
        input();
        break;
      case 2:
        print();
        break;
      case 3:
        findStudent();
        break;

      default:
        break;
      }
      if (sel == 0)
        break;
    }
  }
  void input()
  {
    int bh;               //学号
    char major[21];       //专业
    char name[31];        //学生姓名
    char sex[8];          //学生性别
    char phoneNumber[31]; //学生联系电话
    char sel = 'y';
    while (sel == 'y' || sel == 'Y')
    {
      cout << "Student No is :";
      cin >> bh;
      if (findBH(bh)) //检查输入编号是否被占用
      {
        cout << " This No has been used !" << endl;
        continue; //编号被占用从新输入
      }
      cout << "Student name is :";
      cin >> name;
      cout << "Student major is :";
      cin >> major;
      cout << "Student sex is :";
      cin >> sex;
      cout << "Student phone number is :";
      cin >> phoneNumber;
      sData[num].initStudent(bh, major, name, sex, phoneNumber);
      num++;
      cout << "Whether continue ? (Y/N) " << endl;
      cin >> sel;
    }
  }
  int findBH(int bh)
  {
    for (int i = 0; i < num; i++)
      if (bh == sData[i].getStudNo())
        return 1;
    return 0;
  }
  void print()
  {
    cout << "\n\n\t\t                              STUDENT INFORMATION" << endl;
    cout << "\t\t   ---------------------------------------------------------------------------------" << endl;
    cout << "\t\t        No                Major           Name             sex           Tel " << endl;
    cout << "\t\t   ---------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < num; i++)
    {
      sData[i].print();
    }
    cout << "\t\t   ---------------------------------------------------------------------------------\n\n"
         << endl;
  }
  void findStudent()
  {
    int sel;
    while (1)
    {
      cout << "\n\t\t\t Select the way to find\n"
           << endl;
      cout << "\t\t\t------------------------" << endl;
      cout << "\t\t\t  1. By student name" << endl;
      cout << "\t\t\t  2. By student No" << endl;
      cout << "\t\t\t  0.    exit" << endl;
      cout << "\t\t\t------------------------" << endl;

      cout << "Please input your choice :";
      cin >> sel;
      if (sel == 1)
      {
        char bh[31];
        int flag = 0;
        cout << "Please input student name :";
        cin >> bh;
        for (int i = 0; i < num; i++)
        {
          if (!strcmp(bh, sData[i].getStudName()))
          {
            cout << "\t\t   ---------------------------------------------------------------------------------" << endl;
            cout << "\t\t        No                Major           Name             sex           Tel " << endl;
            sData[i].print();
            cout << "\t\t   ---------------------------------------------------------------------------------" << endl;
            flag = 1;
          }
        }
        if (flag == 0)
          cout << "Not be found !" << endl;
      }
      if (sel == 2)
      {
        int bh, flag = 0;
        cout << "Please input student No :";
        cin >> bh;
        for (int i = 0; i < num; i++)
        {
          if (bh == sData[i].getStudNo())
          {
            cout << "\t\t   ---------------------------------------------------------------------------------" << endl;
            cout << "\t\t        No                Major           Name             sex           Tel " << endl;
            sData[i].print();
            cout << "\t\t   ---------------------------------------------------------------------------------" << endl;
            flag = 1;
          }
        }
        if (flag == 0)
          cout << "Not be found !" << endl;
      }
      if (sel == 0)
        break;
    }
  }
};