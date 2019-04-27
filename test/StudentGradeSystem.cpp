//本程序在 Microsoft Visual Studio 2017 (v141) 下编译通过
//完成时间2018-1-31
//

#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
//创建结构体
struct college {               //学院结构体
	int collegeNo;             //学院编号
	char collegeName[21];      //学院名称
	char deanName[11];         //院长姓名
	int collegeFlag;           //EndFlag
};
struct major {                  //专业结构体
	int majorNo;                //专业编号
	int collegeNo;              //专业所属学院编号
	int majorYear;            //专业学制
	char majorName[21];         //专业名称
	int majorFlag;            //EndFlag
};
struct student {               //学生结构体
	int studNo;                //学号
	int majorNo;               //专业编号
	char Name[11];             //学生姓名
	char sex[3];               //学生性别
	char phoneNumber[12];      //学生联系电话
	float avgGrade;            //平均成绩
	int studentFlag;           //EndFlag
};
struct course {                //课程结构体
	int No;                    //课程编号
	char name[21];             //课程名称
	char type[21];             //课程性质（必修、限选、任选）
	float credit;              //课程学分
	int sumPeriod;             //课程总学时
	int thPeriod;              //课程理论学时
	int expPeriod;             //课程实验学时
	int courseFlag;            //EndFlag
};
struct cv {
	int studNo;                //学生学号
	int courseNo;              //课程编号
	float grade;               //课程成绩
	int cvFlag;                //EndFlag
};
//函数声明
void collegeManage(college[], major[], student[]);
void majorManage(college[], major[], student[]);
void studentManage(college[], major[], student[], cv[]);
void courseManage(college[], major[], student[], course[], cv[]);
void cvManage(college[], major[], student[], course[], cv[]);
void gradeManage(major[], student[], course[], cv[]);
void menu();
void menu1();
void menu2();
void menu3();
void menu4();
void menu5();
void menu6();
void menu7();
void menu8();
void menu9();
void menu10();
void menu11();
void menu12();

void flagIn(college[], int, major[], int, student[], int, course[], int, cv[], int);
void collegeIn(college c1[]);
void majorIn(major c1[]);
void studIn(student s[]);
void cvIn(cv[]);
void gradeIn(student s[], course c3[], cv cu[]);

void collegeOut(college c1[]);
void majorOut(major c1[], college s1[]);
void studentOut(student s[], major c1[], college c2[]);
void courseIn(course c3[]);
void courseOut(course c3[]);
void cvOut(cv[], student[], course[]);
char *findCollegeName(college c1[], int bh);
char *findCollegeDeanName(college c1[], int bh);
int findCollegeNo(major c1[], int majorbh);
char *findMajorName(major c1[], int majorbh);
char *findStudName(student s[], int namebh);
char *findCourseName(course c3[], int namebh);
char *findCourseType(course c3[], int namebh);
float findCourseCredit(course c3[], int namebh);
int findCoursePeriod(course c3[], int namebh);
void studentFind(college c[], major c1[], student s[], course c3[], cv cu[], int bh);
void courseGradeOut(major[], student[], course[], cv[]);
void gradeSort(cv[]);
void studentGradeOut(major c2[], student s[], course c3[], cv cu[]);
void rankGradeOut(major c2[], student s[], course c3[], cv cu[]);

void findCollege(college c1[]);
void findMajor(college c1[], major c2[]);
void findStudent(college c1[], major c2[], student s[]);
void findCourse(course[]);
void findCv(college c[], major c1[], student s[], course c3[], cv cu[]);

void modifyCollege(college[]);
void modifyMajor(college c1[], major c2[]);
void modifyStudent(college c[], major c1[], student s[]);
void modifyCourse(course[]);

void deleteCv(cv cu[]);
void deleteCourse(course c3[], cv cu[]);
void deleteStudent(student s[], cv cu[]);
void deleteMajor(major c2[], student s[]);
void deleteCollege(college c1[], major c2[]);

int main(void)
{
	college c[100];
	int cNumber = 100;
	major c2[100];
	int mNumber = 100;
	student s[100];
	int sNumber = 100;
	course c3[100];
	int c3Number = 100;
	cv cu[100];
	int cuNumber = 100;
	flagIn(c, cNumber, c2, mNumber, s, sNumber, c3, c3Number, cu, cuNumber);
	int sel;
	while (1)
	{
		menu();
		cout << "请输入你的选择：";
		cin >> sel;
		switch (sel)
		{
		case 1:collegeManage(c, c2, s);   break;
		case 2:majorManage(c, c2, s);     break;
		case 3:studentManage(c, c2, s, cu);   break;
		case 4:courseManage(c, c2, s, c3, cu);   break;
		case 5:cvManage(c, c2, s, c3, cu);   break;
		case 6:gradeManage(c2, s, c3, cu); break;
		}
		if (sel == 0)
			break;
	}
	return 0;
}

void collegeManage(college c[], major c1[], student s[])
{
	int sel;

	while (1)
	{
		menu1();
		cout << "请输入你的选择：";
		cin >> sel;
		switch (sel)
		{
		case 1: collegeIn(c); break;
		case 2: collegeOut(c); break;
		case 3: findCollege(c); break;
		case 4: modifyCollege(c); break;
		case 5: deleteCollege(c, c1); break;
		}
		if (sel == 0)
			break;
	}
}
void majorManage(college c[], major c1[], student s[])
{
	int sel;

	while (1)
	{
		menu2();
		cout << "请输入你的选择：";
		cin >> sel;
		switch (sel)
		{
		case 1: majorIn(c1); break;
		case 2: majorOut(c1, c); break;
		case 3: findMajor(c, c1); break;
		case 4: modifyMajor(c, c1); break;
		case 5: deleteMajor(c1, s); break;
		}
		if (sel == 0)
			break;
	}
}
void studentManage(college c[], major c1[], student s[], cv cu[])
{
	int sel;
	while (1)
	{
		menu3();
		cout << "请输入你的选择：";
		cin >> sel;
		switch (sel)
		{
		case 1: studIn(s); break;
		case 2: studentOut(s, c1, c); break;
		case 3: findStudent(c, c1, s); break;
		case 4: modifyStudent(c, c1, s); break;
		case 5: deleteStudent(s, cu); break;
		}
		if (sel == 0)
			break;
	}
}
void courseManage(college c[], major c1[], student s[], course c3[], cv cu[])
{
	int sel;
	while (1)
	{
		menu7();
		cout << "请输入你的选择：";
		cin >> sel;
		switch (sel)
		{
		case 1: courseIn(c3); break;
		case 2: courseOut(c3); break;
		case 3: findCourse(c3); break;
		case 4: modifyCourse(c3); break;
		case 5: deleteCourse(c3, cu); break;
		}
		if (sel == 0)
			break;
	}
}
void cvManage(college c[], major c1[], student s[], course c3[], cv cu[])
{
	int sel;
	while (1)
	{
		menu9();
		cout << "请输入你的选择：";
		cin >> sel;
		switch (sel)
		{
		case 1: cvIn(cu); break;
		case 2: cvOut(cu, s, c3); break;
		case 3: findCv(c, c1, s, c3, cu); break;
		case 4: deleteCv(cu); break;
		}
		if (sel == 0)
			break;
	}
}
void gradeManage(major c2[], student s[], course c3[], cv cu[])
{
	int sel;
	while (1)
	{
		menu11();
		cout << "请输入你的选择：";
		cin >> sel;
		switch (sel)
		{
		case 1: gradeIn(s, c3, cu); break;
		case 2: courseGradeOut(c2, s, c3, cu); break;
		case 3: studentGradeOut(c2, s, c3, cu); break;
		case 4: rankGradeOut(c2, s, c3, cu); break;
		}
		if (sel == 0)
			break;
	}
}

void menu()
{
	cout << "学生基本信息管理" << endl;
	cout << "----------------" << endl;
	cout << "1. 学院信息管理" << endl;
	cout << "2. 专业信息管理" << endl;
	cout << "3. 学生信息管理" << endl;
	cout << "4. 课程信息管理" << endl;
	cout << "5. 选课信息管理" << endl;
	cout << "6. 学生成绩管理" << endl;
	cout << "0. 退出系统" << endl;
	cout << "----------------" << endl;
}
void menu1()
{
	cout << "  学院信息管理" << endl;
	cout << "----------------" << endl;
	cout << "1. 学院信息输入" << endl;
	cout << "2. 学院信息显示" << endl;
	cout << "3. 学院信息查询" << endl;
	cout << "4. 学院信息修改" << endl;
	cout << "5. 学院信息删除" << endl;
	cout << "0. 退出" << endl;
	cout << "----------------" << endl;
}
void menu2()
{
	cout << "  专业信息管理" << endl;
	cout << "----------------" << endl;
	cout << "1. 专业信息输入" << endl;
	cout << "2. 专业信息显示" << endl;
	cout << "3. 专业信息查询" << endl;
	cout << "4. 专业信息修改" << endl;
	cout << "5. 专业信息删除" << endl;
	cout << "0. 退出" << endl;
	cout << "----------------" << endl;
}
void menu3()
{
	cout << "  学生信息管理" << endl;
	cout << "----------------" << endl;
	cout << "1. 学生信息输入" << endl;
	cout << "2. 学生信息显示" << endl;
	cout << "3. 学生信息查询" << endl;
	cout << "4. 学生信息修改" << endl;
	cout << "5. 学生信息删除" << endl;
	cout << "0. 退出" << endl;
	cout << "----------------" << endl;
}
void menu4()
{
	cout << "请选择查询学院的方式：" << endl;
	cout << "----------------" << endl;
	cout << "1. 学院名称查找" << endl;
	cout << "2. 学院院长查找" << endl;
	cout << "3. 学院编号查找" << endl;
	cout << "0. 退出" << endl;
	cout << "----------------" << endl;
}
void menu5()
{
	cout << "请选择查询专业的方式：" << endl;
	cout << "----------------" << endl;
	cout << "1. 专业名称查找" << endl;
	cout << "2. 所属学院查找" << endl;
	cout << "3. 专业编号查找" << endl;
	cout << "0. 退出" << endl;
	cout << "----------------" << endl;
}
void menu6()
{
	cout << "请选择查询学生的方式：" << endl;
	cout << "----------------" << endl;
	cout << "1. 学生名称查找" << endl;
	cout << "2. 学生学号查找" << endl;
	cout << "0. 退出" << endl;
	cout << "----------------" << endl;
}
void menu7()
{
	cout << "  课程信息管理" << endl;
	cout << "----------------" << endl;
	cout << "1. 课程信息输入" << endl;
	cout << "2. 课程信息显示" << endl;
	cout << "3. 课程信息查询" << endl;
	cout << "4. 课程信息修改" << endl;
	cout << "5. 课程信息删除" << endl;
	cout << "0. 退出" << endl;
	cout << "----------------" << endl;
}
void menu8()
{
	cout << "请选择查询课程的方式：" << endl;
	cout << "----------------" << endl;
	cout << "1. 课程名称查找" << endl;
	cout << "2. 课程编号查找" << endl;
	cout << "0. 退出" << endl;
	cout << "----------------" << endl;
}
void menu9()
{
	cout << "  选课信息管理" << endl;
	cout << "----------------" << endl;
	cout << "1. 选课信息输入" << endl;
	cout << "2. 选课信息显示" << endl;
	cout << "3. 选课信息查询" << endl;
	cout << "4. 选课信息删除" << endl;
	cout << "0. 退出" << endl;
	cout << "----------------" << endl;
}
void menu10()
{
	cout << "  选课信息查询" << endl;
	cout << "----------------" << endl;
	cout << "1. 课程选课查询" << endl;
	cout << "2. 学生选课查询" << endl;
	cout << "0. 退出" << endl;
	cout << "----------------" << endl;
}
void menu11()
{
	cout << "  学生成绩管理" << endl;
	cout << "----------------" << endl;
	cout << "1. 学生成绩输入" << endl;
	cout << "2. 课程成绩输出" << endl;
	cout << "3. 学生成绩输出" << endl;
	cout << "4. 成绩排名输出" << endl;
	cout << "0. 退出" << endl;
	cout << "----------------" << endl;
}
void menu12()
{
	cout << "  成绩排序方式" << endl;
	cout << "----------------" << endl;
	cout << "1.   默认排序" << endl;
	cout << "2. 成绩由高到低" << endl;
	cout << "3. 学号由低到高" << endl;
	cout << "0. 退出" << endl;
	cout << "----------------" << endl;
}

void flagIn(college c1[], int collegeFlag, major c2[], int majorFlag, student s[], int studentFlag, course c3[], int c3Number, cv cu[], int cuNumber)
{
	for (int i = 0; i < collegeFlag; i++)
		c1[i].collegeFlag = 0;
	for (i = 0; i < majorFlag; i++)
		c2[i].majorFlag = 0;
	for (i = 0; i < collegeFlag; i++)
	{
		s[i].studentFlag = 0;
		s[i].avgGrade = 0;
	}
	for (i = 0; i < c3Number; i++)
		c3[i].courseFlag = 0;
}
void collegeIn(college c1[])
{
	int i = 0;
	while (c1[i].collegeFlag != 0)
		i++;
	char ch;
	ch = 'y';
	while (ch == 'y' || ch == 'Y')
	{
		cout << "学院编号："; cin >> c1[i].collegeNo;
		c1[i].collegeFlag = c1[i].collegeNo;
		cout << "学院名称："; cin >> c1[i].collegeName;
		cout << "学院院长："; cin >> c1[i].deanName;
		cout << "是否继续输入？（Y/N）";
		cin >> ch;
		i++;
	}
}
void majorIn(major c1[])
{
	int i = 0;
	while (c1[i].majorFlag != 0)
		i++;
	char ch;
	ch = 'y';
	while (ch == 'y' || ch == 'Y')
	{
		cout << "专业编号："; cin >> c1[i].majorNo;
		c1[i].majorFlag = c1[i].majorNo;
		cout << "所属学院编号："; cin >> c1[i].collegeNo;
		cout << "专业名称："; cin >> c1[i].majorName;
		cout << "专业学制："; cin >> c1[i].majorYear;
		cout << "是否继续输入？（Y/N）";
		cin >> ch;
		i++;
	}
}
void studIn(student s[])
{
	int i = 0;
	while (s[i].studentFlag != 0)
		i++;
	char ch;
	ch = 'y';
	while (ch == 'y' || ch == 'Y')
	{
		cout << "学号："; cin >> s[i].studNo;
		s[i].studentFlag = s[i].studNo;
		cout << "姓名："; cin >> s[i].Name;
		cout << "性别："; cin >> s[i].sex;
		cout << "所属专业编号："; cin >> s[i].majorNo;
		cout << "联系电话："; cin >> s[i].phoneNumber;
		cout << "是否继续输入？（Y/N）";
		cin >> ch;
		i++;
	}
}
void courseIn(course c3[])
{
	int i = 0;
	while (c3[i].courseFlag != 0)
		i++;
	char ch;
	ch = 'y';
	while (ch == 'y' || ch == 'Y')
	{
		cout << "课程编号："; cin >> c3[i].No;
		c3[i].courseFlag = c3[i].No;
		cout << "课程名称："; cin >> c3[i].name;
		cout << "课程性质："; cin >> c3[i].type;
		cout << "课程学分："; cin >> c3[i].credit;
		cout << "课程总学时："; cin >> c3[i].sumPeriod;
		cout << "课程理论学时："; cin >> c3[i].thPeriod;
		cout << "课程实验学时："; cin >> c3[i].expPeriod;
		cout << "是否继续输入？（Y/N）";
		cin >> ch;
		i++;
	}
}
void cvIn(cv cu[])
{
	int i = 0;
	while (cu[i].cvFlag != 0)
		i++;
	char ch;
	ch = 'y';
	while (ch == 'y' || ch == 'Y')
	{
		cout << "学生学号："; cin >> cu[i].studNo;
		cu[i].cvFlag = cu[i].courseNo;
		cout << "课程编号："; cin >> cu[i].courseNo;
		cout << "课程成绩："; cin >> cu[i].grade;
		cout << "是否继续输入？（Y/N）";
		cin >> ch;
		i++;
	}
}
void gradeIn(student s[], course c3[], cv cu[])
{
	int i = 0, flag = 0, bh;
	cout << "请输入课程编号：";
	cin >> bh;
	while (c3[i].courseFlag != 0)
	{
		if (bh == c3[i].No)
		{
			cout << "                                课程列表" << endl;
			cout << "------------------------------------------------------------------------" << endl;
			cout << " 编号    名称         性质    学分        总学时    理论学时    实验学时" << endl;
			cout << "------------------------------------------------------------------------" << endl;
			cout << setw(6) << c3[i].No;
			cout << setw(6) << c3[i].name;
			cout << setw(4) << c3[i].type;
			cout << setw(8) << c3[i].credit;
			cout << setw(8) << c3[i].sumPeriod;
			cout << setw(8) << c3[i].thPeriod;
			cout << setw(8) << c3[i].expPeriod;
			cout << "------------------------------------------------------------------------" << endl;
			cout << endl;
			flag = 1;
		}
		i++;
	}
	i = 0;
	while (cu[i].cvFlag != 0)
	{
		if (cu[i].courseNo == bh)
		{
			cout << "学生姓名: " << findStudName(s, cu[i].studNo);
			cout << "学号: " << cu[i].studNo;
			cout << "成绩: ";
			cin >> cu[i].grade;
			cout << endl;
			flag = 2;
		}
		i++;
	}
	if (flag == 0)
		cout << "没找到该课程！";
	if (flag == 1)
		cout << "该课程无学生选课！";

}

void collegeOut(college c1[])
{
	int i = 0;
	cout << "              学院信息列表" << endl;
	cout << "----------------------------------------------" << endl;
	cout << "学院编号                学院名称         院长" << endl;
	cout << "----------------------------------------------" << endl;
	while (c1[i].collegeFlag != 0)
	{
		cout << setw(5) << c1[i].collegeNo << setw(20) << c1[i].collegeName << setw(10) << c1[i].deanName << endl;
		i++;
	}
	cout << "----------------------------------------------" << endl;
}
void majorOut(major c1[], college s1[])
{
	int i = 0;
	cout << "                             专业列表" << endl;
	cout << "---------------------------------------------------------------------" << endl;
	cout << "专业编号          专业名称                       学制        所属学院" << endl;
	cout << "---------------------------------------------------------------------" << endl;
	while (c1[i].majorFlag != 0)
	{
		cout << setw(8) << c1[i].majorNo;
		cout << setw(20) << c1[i].majorName;
		cout << setw(20) << c1[i].majorYear;
		cout << setw(20) << findCollegeName(s1, c1[i].collegeNo);
		cout << endl;
		i++;
	}
	cout << "--------------------------------------------------------------------" << endl;
}
void studentOut(student s[], major c1[], college c2[])
{
	int i = 0;
	cout << "                                学生列表" << endl;
	cout << "------------------------------------------------------------------------" << endl;
	cout << " 学号    姓名    性别       专业                学院          联系方式" << endl;
	cout << "------------------------------------------------------------------------" << endl;
	while (s[i].studentFlag != 0)
	{
		cout << setw(6) << s[i].studNo;
		cout << setw(10) << s[i].Name;
		cout << setw(4) << s[i].sex;
		cout << setw(15) << findMajorName(c1, s[i].majorNo);
		cout << setw(20) << findCollegeName(c2, findCollegeNo(c1, s[i].majorNo));
		cout << setw(18) << s[i].phoneNumber;
		cout << endl;
		i++;
	}
	cout << "------------------------------------------------------------------------" << endl;
}
void courseOut(course c3[])
{
	int i = 0;
	cout << "                                课程列表" << endl;
	cout << "------------------------------------------------------------------------" << endl;
	cout << " 编号    名称         性质       学分     总学时    理论学时    实验学时" << endl;
	cout << "------------------------------------------------------------------------" << endl;
	while (c3[i].courseFlag != 0)
	{
		cout << setw(6) << c3[i].No;
		cout << setw(6) << c3[i].name;
		cout << setw(15) << c3[i].type;
		cout << setw(10) << c3[i].credit;
		cout << setw(8) << c3[i].sumPeriod;
		cout << setw(8) << c3[i].thPeriod;
		cout << setw(8) << c3[i].expPeriod;
		cout << endl;
		i++;
	}
	cout << "------------------------------------------------------------------------" << endl;
}
void cvOut(cv cu[], student s[], course c3[])
{
	int i = 0;
	cout << "                                选课列表" << endl;
	cout << "------------------------------------------------------------------------" << endl;
	cout << "学生姓名   学生学号   课程编号   课程名称  课程成绩     性质 学分 总学时" << endl;
	cout << "------------------------------------------------------------------------" << endl;
	while (cu[i].cvFlag != 0)
	{
		cout << setw(6) << findStudName(s, cu[i].studNo);
		cout << setw(6) << cu[i].studNo;
		cout << setw(4) << cu[i].courseNo;
		cout << setw(6) << findCourseName(c3, cu[i].courseNo);
		cout << setw(6) << cu[i].grade;
		cout << setw(4) << findCourseType(c3, cu[i].courseNo);
		cout << setw(8) << findCourseCredit(c3, cu[i].courseNo);
		cout << setw(8) << findCoursePeriod(c3, cu[i].courseNo);
		cout << endl;
		i++;
	}
	cout << "------------------------------------------------------------------------" << endl;
}
void courseGradeOut(major c2[], student s[], course c3[], cv cu[])
{
	int i = 0, bh;
	cout << "请输入课程编号： ";
	cin >> bh;
	cout << "                                课程信息" << endl;
	cout << "------------------------------------------------------------------------" << endl;
	cout << " 编号    名称         性质       学分     总学时    理论学时    实验学时" << endl;
	cout << "------------------------------------------------------------------------" << endl;
	while (c3[i].courseFlag != 0)
	{
		if (bh == c3[i].No)
		{
			cout << setw(6) << c3[i].No;
			cout << setw(6) << c3[i].name;
			cout << setw(15) << c3[i].type;
			cout << setw(10) << c3[i].credit;
			cout << setw(8) << c3[i].sumPeriod;
			cout << setw(8) << c3[i].thPeriod;
			cout << setw(8) << c3[i].expPeriod;
		}
		cout << endl;
		i++;
	}
	cout << "------------------------------------------------------------------------" << endl;
	i = 0;
	gradeSort(cu);
	cout << "                              学生成绩列表" << endl;
	cout << "------------------------------------------------------------------------" << endl;
	cout << "学生姓名   学生学号   专业   课程编号   课程名称  课程成绩    性质  学分 " << endl;
	cout << "------------------------------------------------------------------------" << endl;
	while (cu[i].cvFlag != 0)
	{
		if (bh == cu[i].courseNo)
		{
			cout << setw(6) << findStudName(s, cu[i].studNo);
			cout << setw(5) << cu[i].studNo;
			cout << setw(5) << findMajorName(c2, cu[i].studNo);
			cout << setw(4) << cu[i].courseNo;
			cout << setw(6) << findCourseName(c3, cu[i].courseNo);
			cout << setw(6) << cu[i].grade;
			cout << setw(4) << findCourseType(c3, cu[i].courseNo);
			cout << setw(8) << findCourseCredit(c3, cu[i].courseNo);
			cout << endl;
			i++;
		}
	}
	cout << "------------------------------------------------------------------------" << endl;
}
void studentGradeOut(major c2[], student s[], course c3[], cv cu[])
{
	int bh, i = 0, flag = 0;
	cout << "请输入学生学号： ";
	cin >> bh;
	cout << "                              学生成绩列表" << endl;
	cout << "------------------------------------------------------------------------" << endl;
	cout << "学生姓名   学生学号  专业  课程编号   课程名称  课程成绩     性质   学分" << endl;
	cout << "------------------------------------------------------------------------" << endl;
	while (cu[i].cvFlag != 0)
	{
		if (bh == cu[i].studNo)
		{
			cout << setw(6) << findStudName(s, cu[i].studNo);
			cout << setw(5) << cu[i].studNo;
			cout << setw(5) << findMajorName(c2, cu[i].studNo);
			cout << setw(4) << cu[i].courseNo;
			cout << setw(6) << findCourseName(c3, cu[i].courseNo);
			cout << setw(6) << cu[i].grade;
			cout << setw(4) << findCourseType(c3, cu[i].courseNo);
			cout << setw(8) << findCourseCredit(c3, cu[i].courseNo);
			cout << endl;

			flag = 1;
		}
		i++;
	}
	if (flag == 0)
		cout << "没有找到该学生！";
}
void rankGradeOut(major c2[], student s[], course c3[], cv cu[])
{
	int i = 0, j;
	char str1[] = "必修";
	char str2[] = "限选";
	while (cu[i].cvFlag != 0)
	{
		if ((strcmp((findCourseType(c3, cu[i].courseNo)), str1) == 0) || (strcmp((findCourseType(c3, cu[i].courseNo)), str2)) == 0)
		{
			int j = 0;
			while (s[j].studentFlag != 0)
			{
				if (s[j].studNo == cu[i].studNo)
				{
					s[j].avgGrade += (cu[i].grade)*(findCourseCredit(c3, cu[i].courseNo));
				}
				j++;
			}
		}
		i++;
	}
	cout << "        学生成绩列表" << endl;
	cout << "---------------------------------------" << endl;
	cout << "学生姓名               平均成绩" << endl;

	while (s[i].studentFlag != 0)
	{
		j = i + 1;
		while (s[j].studentFlag != 0)
		{
			if ((s[i].avgGrade) < s[j].avgGrade)
			{
				i = j;
			}
			j++;
		}
		if (s[j].studentFlag == 0)
			break;
		cout << setw(5) << s[i].Name << setw(8) << s[i].avgGrade << endl;
		i++;
	}
	cout << "-----------------------------------------" << endl;
}

void findCollege(college c1[])
{
	char ch;
	int sel;
	ch = 'y';
	while (ch == 'y' || ch == 'Y')
	{
		menu4();
		cout << "请输入你的选择：";
		cin >> sel;
		if (sel == 1)
		{
			char bh[21];
			int i = 0, flag = 0;
			cout << "请输入学院名称：";
			cin >> bh;
			while (c1[i].collegeFlag != 0)
			{
				if (strcmp(bh, c1[i].collegeName) == 0)
				{
					cout << "----------------------------------------------" << endl;
					cout << "学院编号      学院名称                 院长" << endl;
					cout << setw(8) << c1[i].collegeNo << setw(30) << c1[i].collegeName << setw(8) << c1[i].deanName << endl;
					cout << "----------------------------------------------" << endl;
					flag = 1;
				}
				i++;
			}
			if (flag == 0)
				cout << "没找到该学院！";
		}
		if (sel == 2)
		{
			char bh[21];
			int i = 0, flag = 0;
			cout << "请输入院长姓名：";
			cin >> bh;
			while (c1[i].collegeFlag != 0)
			{
				if (strcmp(bh, c1[i].deanName) == 0)
				{
					cout << "----------------------------------------------" << endl;
					cout << "学院编号      学院名称                 院长" << endl;
					cout << setw(8) << c1[i].collegeNo << setw(30) << c1[i].collegeName << setw(8) << c1[i].deanName << endl;
					cout << "----------------------------------------------" << endl;
					flag = 1;
				}
				i++;
			}
			if (flag == 0)
				cout << "没找到该学院！";
		}
		if (sel == 3)
		{
			int bh, i = 0;
			char *p;
			cout << "请输入学院编号：";
			cin >> bh;
			p = findCollegeName(c1, bh);
			if (bh != NULL)
			{
				while (c1[i].collegeFlag != 0)
				{
					if (p == c1[i].collegeName)
					{
						cout << "----------------------------------------------" << endl;
						cout << "学院编号      学院名称                 院长" << endl;
						cout << setw(8) << c1[i].collegeNo << setw(30) << c1[i].collegeName << setw(8) << c1[i].deanName << endl;
						cout << "----------------------------------------------" << endl;
					}
					i++;
				}

			}
			else
				cout << "没找到该学院！";
		}

		if (sel == 0)
			break;

	}
}
void findMajor(college c1[], major c2[])
{
	char ch;
	int sel;
	ch = 'y';
	while (ch == 'y' || ch == 'Y')
	{
		menu5();
		cout << "请输入你的选择：";
		cin >> sel;
		if (sel == 1)
		{
			char bh[21];
			int i = 0, flag = 0;
			cout << "请输入专业名称：";
			cin >> bh;
			while (c2[i].majorFlag != 0)
			{
				if (strcmp(bh, c2[i].majorName) == 0)
				{
					cout << "                             专业列表" << endl;
					cout << "---------------------------------------------------------------------" << endl;
					cout << "专业编号          专业名称                       学制        所属学院" << endl;
					cout << "---------------------------------------------------------------------" << endl;
					cout << setw(8) << c2[i].majorNo;
					cout << setw(30) << c2[i].majorName;
					cout << setw(8) << c2[i].majorYear;
					cout << setw(30) << findCollegeName(c1, c1[i].collegeNo);
					cout << endl;
					cout << "---------------------------------------------------------------------" << endl;
					cout << endl;
					flag = 1;
				}
				i++;
			}
			if (flag == 0)
				cout << "没找到该专业！";
		}
		if (sel == 2)
		{
			int bh;
			int i = 0, flag = 0;
			cout << "请输入所属学院编号：";
			cin >> bh;
			while (c2[i].majorFlag != 0)
			{
				if (bh == c2[i].collegeNo)
				{
					cout << "                             专业列表" << endl;
					cout << "---------------------------------------------------------------------" << endl;
					cout << "专业编号          专业名称                       学制        所属学院" << endl;
					cout << "---------------------------------------------------------------------" << endl;
					cout << setw(8) << c2[i].majorNo;
					cout << setw(30) << c2[i].majorName;
					cout << setw(8) << c2[i].majorYear;
					cout << setw(30) << findCollegeName(c1, c2[i].collegeNo);
					cout << endl;
					cout << "---------------------------------------------------------------------" << endl;
					cout << endl;
					flag = 1;
				}
				i++;
			}
			if (flag == 0)
				cout << "没找到该专业！";

		}
		if (sel == 3)
		{
			int i = 0, flag = 0, bh;
			cout << "请输入专业编号：";
			cin >> bh;
			while (c2[i].majorFlag != 0)
			{
				if (bh == c2[i].majorNo)
				{
					cout << "                             专业列表" << endl;
					cout << "---------------------------------------------------------------------" << endl;
					cout << "专业编号          专业名称                       学制        所属学院" << endl;
					cout << "---------------------------------------------------------------------" << endl;
					cout << setw(8) << c2[i].majorNo;
					cout << setw(30) << c2[i].majorName;
					cout << setw(8) << c2[i].majorYear;
					cout << setw(30) << findCollegeName(c1, c1[i].collegeNo);
					cout << endl;
					cout << "---------------------------------------------------------------------" << endl;
					cout << endl;
					flag = 1;
				}
				i++;
			}
			if (flag == 0)
				cout << "没找到该专业！";
		}
		if (sel == 0)
			break;

	}
}
void findStudent(college c1[], major c2[], student s[])
{
	char ch;
	int sel;
	ch = 'y';
	while (ch == 'y' || ch == 'Y')
	{
		menu6();
		cout << "请输入你的选择：";
		cin >> sel;
		if (sel == 1)
		{
			char bh[21];
			int i = 0, flag = 0;
			cout << "请输入学生姓名：";
			cin >> bh;
			while (s[i].studentFlag != 0)
			{
				if (strcmp(bh, s[i].Name) == 0)
				{
					cout << "                                学生列表" << endl;
					cout << "------------------------------------------------------------------------" << endl;
					cout << " 学号    姓名   性别        专业                学院          联系方式" << endl;
					cout << "------------------------------------------------------------------------" << endl;
					cout << setw(6) << s[i].studNo;
					cout << setw(10) << s[i].Name;
					cout << setw(4) << s[i].sex;
					cout << setw(20) << findMajorName(c2, s[i].majorNo);
					cout << setw(20) << findCollegeName(c1, findCollegeNo(c2, s[i].majorNo));
					cout << setw(12) << s[i].phoneNumber;
					cout << endl;
					cout << "------------------------------------------------------------------------" << endl;
					flag = 1;
				}
				i++;
			}
			if (flag == 0)
				cout << "没找到该学生！";
		}
		if (sel == 2)
		{
			int i = 0, flag = 0, bh;
			cout << "请输入学生学号：";
			cin >> bh;
			while (s[i].studentFlag != 0)
			{
				if (bh == s[i].studNo)
				{
					cout << "                                学生列表" << endl;
					cout << "------------------------------------------------------------------------" << endl;
					cout << " 学号    姓名   性别        专业                学院          联系方式" << endl;
					cout << "------------------------------------------------------------------------" << endl;
					cout << setw(6) << s[i].studNo;
					cout << setw(10) << s[i].Name;
					cout << setw(4) << s[i].sex;
					cout << setw(20) << findMajorName(c2, s[i].majorNo);
					cout << setw(20) << findCollegeName(c1, findCollegeNo(c2, s[i].majorNo));
					cout << setw(12) << s[i].phoneNumber;
					cout << endl;
					cout << "------------------------------------------------------------------------" << endl;
					flag = 1;
				}
				i++;
			}
			if (flag == 0)
				cout << "没找到该学生！";
		}
		if (sel == 0)
			break;

	}

}
void findCourse(course c3[])
{

	char ch;
	int sel;
	ch = 'y';
	while (ch == 'y' || ch == 'Y')
	{
		menu8();
		cout << "请输入你的选择：";
		cin >> sel;
		if (sel == 1)
		{
			char bh[21];
			int i = 0, flag = 0;
			cout << "请输入课程名称：";
			cin >> bh;
			while (c3[i].courseFlag != 0)
			{
				if (strcmp(bh, c3[i].name) == 0)
				{
					cout << "                                课程列表" << endl;
					cout << "------------------------------------------------------------------------" << endl;
					cout << " 编号    名称         性质    学分        总学时    理论学时    实验学时" << endl;
					cout << "------------------------------------------------------------------------" << endl;
					cout << setw(6) << c3[i].No;
					cout << setw(6) << c3[i].name;
					cout << setw(4) << c3[i].type;
					cout << setw(8) << c3[i].credit;
					cout << setw(8) << c3[i].sumPeriod;
					cout << setw(8) << c3[i].thPeriod;
					cout << setw(8) << c3[i].expPeriod;
					cout << endl;
					cout << "------------------------------------------------------------------------" << endl;
					flag = 1;
				}
				i++;
			}
			if (flag == 0)
				cout << "没找到该课程！";
		}
		if (sel == 2)
		{
			int i = 0, flag = 0, bh;
			cout << "请输入课程编号：";
			cin >> bh;
			while (c3[i].courseFlag != 0)
			{
				if (bh == c3[i].No)
				{
					cout << "                                课程列表" << endl;
					cout << "------------------------------------------------------------------------" << endl;
					cout << " 编号    名称         性质    学分        总学时    理论学时    实验学时" << endl;
					cout << "------------------------------------------------------------------------" << endl;
					cout << setw(6) << c3[i].No;
					cout << setw(6) << c3[i].name;
					cout << setw(4) << c3[i].type;
					cout << setw(8) << c3[i].credit;
					cout << setw(8) << c3[i].sumPeriod;
					cout << setw(8) << c3[i].thPeriod;
					cout << setw(8) << c3[i].expPeriod;
					cout << endl;
					flag = 1;
				}
				i++;
			}
			if (flag == 0)
				cout << "没找到该课程！";
		}
		if (sel == 0)
			break;
	}
}
void findCv(college c[], major c1[], student s[], course c3[], cv cu[])
{
	char ch;
	int sel;
	ch = 'y';
	while (ch == 'y' || ch == 'Y')
	{
		menu10();
		cout << "请输入你的选择：";
		cin >> sel;
		if (sel == 1)
		{
			int i = 0, flag = 0, bh;
			cout << "请输入课程编号：";
			cin >> bh;
			while (c3[i].courseFlag)
			{
				if (bh == c3[i].No)
				{
					cout << "                                课程信息" << endl;
					cout << "------------------------------------------------------------------------" << endl;
					cout << " 编号    名称         性质    学分        总学时    理论学时    实验学时" << endl;
					cout << "------------------------------------------------------------------------" << endl;
					cout << setw(6) << c3[i].No;
					cout << setw(6) << c3[i].name;
					cout << setw(4) << c3[i].type;
					cout << setw(8) << c3[i].credit;
					cout << setw(8) << c3[i].sumPeriod;
					cout << setw(8) << c3[i].thPeriod;
					cout << setw(8) << c3[i].expPeriod;
					cout << endl;



					cout << "------------------------------------------------------------------------" << endl;
					cout << "                                学生列表" << endl;
					cout << "------------------------------------------------------------------------" << endl;
					cout << " 学号    姓名   性别        专业                学院          联系方式" << endl;
					cout << "------------------------------------------------------------------------" << endl;
					while (cu[i].studNo != 0)
					{
						if (cu[i].courseNo == bh)
							studentFind(c, c1, s, c3, cu, cu[i].studNo);
						i++;
					}
					cout << "------------------------------------------------------------------------" << endl;
					flag = 1;
				}

				i++;
			}
			if (flag == 0)
				cout << "没找到该课程！";
		}
		if (sel == 2)
		{
			int i = 0, flag = 0, bh;
			cout << "请输入学生学号：";
			cin >> bh;
			cout << "                                选课列表" << endl;
			cout << "------------------------------------------------------------------------" << endl;
			cout << "学生姓名   学生学号   课程编号   课程名称  课程成绩     性质 学分 总学时" << endl;
			cout << "------------------------------------------------------------------------" << endl;
			while (cu[i].cvFlag != 0)
			{
				if (bh == cu[i].studNo)
				{
					cout << setw(6) << findStudName(s, cu[i].studNo);
					cout << setw(6) << cu[i].studNo;
					cout << setw(4) << cu[i].courseNo;
					cout << setw(6) << findCourseName(c3, cu[i].courseNo);
					cout << setw(6) << cu[i].grade;
					cout << setw(4) << findCourseType(c3, cu[i].courseNo);
					cout << setw(8) << findCourseCredit(c3, cu[i].courseNo);
					cout << setw(8) << findCoursePeriod(c3, cu[i].courseNo);
					cout << endl;
					i++;
					flag = 1;
				}
				i++;
			}
			cout << "------------------------------------------------------------------------" << endl;
			if (flag == 0)
				cout << "没找到该课程！";
		}
		if (sel == 0)
			break;
	}
}

char *findCollegeName(college c1[], int bh)
{
	int i = 0;
	while (c1[i].collegeFlag != 0)
	{
		if (c1[i].collegeNo == bh)
			return c1[i].collegeName;
		i++;
	}
	return NULL;
}
char *findCollegeDeanName(college c1[], int bh)
{
	int i = 0;
	while (c1[i].collegeFlag != 0)
	{
		if (c1[i].collegeNo == bh)
			return c1[i].deanName;
		i++;
	}
	return NULL;
}
int findCollegeNo(major c1[], int majorbh)
{
	int i = 0;
	while (c1[i].majorFlag != 0)
	{
		if (c1[i].majorNo == majorbh)
			return c1[i].collegeNo;
		i++;
	}
	return -1;
}
char *findMajorName(major c1[], int majorbh)
{
	int i = 0;
	while (c1[i].majorFlag != 0)
	{
		if (c1[i].majorNo == majorbh)
			return c1[i].majorName;
		i++;
	}
	return NULL;
}
char *findStudName(student s[], int namebh)
{
	int i = 0;
	while (s[i].studentFlag != 0)
	{
		if (s[i].studNo == namebh)
			return s[i].Name;
		i++;
	}
	return NULL;
}
char *findCourseName(course c3[], int namebh)
{
	int i = 0;
	while (c3[i].courseFlag != 0)
	{
		if (c3[i].No == namebh)
			return c3[i].name;
		i++;
	}
	return NULL;
}
char *findCourseType(course c3[], int namebh)
{
	int i = 0;
	while (c3[i].courseFlag != 0)
	{
		if (c3[i].No == namebh)
			return c3[i].type;
		i++;
	}
	return NULL;
}
float findCourseCredit(course c3[], int namebh)
{
	int i = 0;
	while (c3[i].courseFlag != 0)
	{
		if (c3[i].No == namebh)
			return c3[i].credit;
		i++;
	}
	return NULL;
}
int findCoursePeriod(course c3[], int namebh)
{
	int i = 0;
	while (c3[i].courseFlag != 0)
	{
		if (c3[i].No == namebh)
			return c3[i].sumPeriod;
		i++;
	}
	return NULL;
}
void studentFind(college c[], major c1[], student s[], course c3[], cv cu[], int bh)
{
	int i = 0;
	while (s[i].studentFlag != 0)
	{
		if (bh == s[i].studNo)
		{
			cout << setw(6) << s[i].studNo;
			cout << setw(10) << s[i].Name;
			cout << setw(4) << s[i].sex;
			cout << setw(15) << findMajorName(c1, s[i].majorNo);
			cout << setw(20) << findCollegeName(c, findCollegeNo(c1, s[i].majorNo));
			cout << setw(18) << s[i].phoneNumber;
			cout << endl;
		}
		i++;
	}
}

void gradeSort(cv cu[])
{
	int i = 0, j = 1, t, sel;
	float T;
	void menu12();
	cin >> sel;
	if (sel == 1)
	{
	}
	if (sel == 2) {
		while (cu[i].cvFlag != 0)
		{
			while (cu[j].cvFlag != 0)
			{
				if ((cu[i].grade) < cu[j].grade)
				{
					T = cu[i].grade;
					cu[i].grade = cu[j].grade;
					cu[j].grade = T;
					t = cu[i].studNo;
					cu[i].studNo = cu[j].studNo;
					cu[j].studNo = t;
					t = cu[i].courseNo;
					cu[i].courseNo = cu[j].courseNo;
					cu[j].courseNo = t;
				}
				j++;
			}
			i++;
		}
	}
	if (sel == 3)
	{
		while (cu[i].cvFlag != 0)
		{
			while (cu[j].cvFlag != 0)
			{
				if ((cu[i].studNo) > cu[j].studNo)
				{
					T = cu[i].grade;
					cu[i].grade = cu[j].grade;
					cu[j].grade = T;
					t = cu[i].studNo;
					cu[i].studNo = cu[j].studNo;
					cu[j].studNo = t;
					t = cu[i].courseNo;
					cu[i].courseNo = cu[j].courseNo;
					cu[j].courseNo = t;
				}
				j++;
			}
			i++;
		}

	}
}

void modifyCollege(college c[])
{
	int i = 0, flag = 0, bh;
	cout << "请输入学院编号：";
	cin >> bh;
	while (c[i].collegeFlag != 0)
	{
		if (bh == c[i].collegeNo)
		{
			cout << "----------------------------------------------" << endl;
			cout << "学院编号      学院名称                 院长" << endl;
			cout << setw(8) << c[i].collegeNo << setw(30) << c[i].collegeName << setw(8) << c[i].deanName << endl;
			cout << "----------------------------------------------" << endl;
			flag = i;
		}
		i++;
	}
	if (flag)
	{
		cout << "请输入新的学院名称： "; cin >> c[flag].collegeName;
		cout << "请输入新的院长姓名： "; cin >> c[flag].deanName;
	}
	else
		cout << "没找到该学院！";

}
void modifyMajor(college c1[], major c2[])
{
	int i = 0, flag = 0, bh;
	cout << "请输入专业编号：";
	cin >> bh;
	while (c2[i].majorFlag != 0)
	{
		if (bh == c2[i].majorNo)
		{
			cout << "                             专业列表" << endl;
			cout << "---------------------------------------------------------------------" << endl;
			cout << "专业编号          专业名称                       学制        所属学院" << endl;
			cout << "---------------------------------------------------------------------" << endl;
			cout << setw(8) << c2[i].majorNo;
			cout << setw(30) << c2[i].majorName;
			cout << setw(8) << c2[i].majorYear;
			cout << setw(30) << findCollegeName(c1, c1[i].collegeNo);
			cout << endl;
			cout << "---------------------------------------------------------------------" << endl;
			cout << endl;
			flag = i;
		}
		i++;
	}
	if (flag)
	{
		cout << "所属学院编号："; cin >> c2[flag].collegeNo;
		cout << "专业名称："; cin >> c2[flag].majorName;
		cout << "专业学制："; cin >> c2[flag].majorYear;
	}
	else
		cout << "没找到该专业！";
}
void modifyStudent(college c[], major c1[], student s[])
{
	int i = 0, flag = 0, bh;
	cout << "请输入学生学号：";
	cin >> bh;
	while (s[i].studentFlag != 0)
	{
		if (bh == s[i].studNo)
		{
			cout << "                                学生列表" << endl;
			cout << "------------------------------------------------------------------------" << endl;
			cout << " 学号    姓名   性别        专业                学院          联系方式" << endl;
			cout << "------------------------------------------------------------------------" << endl;
			cout << setw(6) << s[i].studNo;
			cout << setw(10) << s[i].Name;
			cout << setw(4) << s[i].sex;
			cout << setw(20) << findMajorName(c1, s[i].majorNo);
			cout << setw(20) << findCollegeName(c, findCollegeNo(c1, s[i].majorNo));
			cout << setw(12) << s[i].phoneNumber;
			cout << endl;
			cout << "------------------------------------------------------------------------" << endl;
			flag = i;
		}
		i++;
	}
	if (flag)
	{
		cout << "姓名："; cin >> s[flag].Name;
		cout << "性别："; cin >> s[flag].sex;
		cout << "所属专业编号："; cin >> s[flag].majorNo;
		cout << "联系电话："; cin >> s[flag].phoneNumber;
	}
	else
		cout << "没找到该学生！";

}
void modifyCourse(course c3[])
{
	int i = 0, flag = 0, bh;
	cout << "请输入课程编号：";
	cin >> bh;
	while (c3[i].courseFlag != 0)
	{
		if (bh == c3[i].No)
		{
			cout << "                                课程列表" << endl;
			cout << "------------------------------------------------------------------------" << endl;
			cout << " 编号    名称         性质    学分        总学时    理论学时    实验学时" << endl;
			cout << "------------------------------------------------------------------------" << endl;
			cout << setw(6) << c3[i].No;
			cout << setw(6) << c3[i].name;
			cout << setw(4) << c3[i].type;
			cout << setw(8) << c3[i].credit;
			cout << setw(8) << c3[i].sumPeriod;
			cout << setw(8) << c3[i].thPeriod;
			cout << setw(8) << c3[i].expPeriod;
			cout << endl;
			flag = i;
		}
		i++;
	}
	if (flag)
	{
		cout << "课程名称："; cin >> c3[flag].name;
		cout << "课程性质："; cin >> c3[flag].type;
		cout << "课程学分："; cin >> c3[flag].credit;
		cout << "课程总学时："; cin >> c3[flag].sumPeriod;
		cout << "课程理论学时："; cin >> c3[flag].thPeriod;
		cout << "课程实验学时："; cin >> c3[flag].expPeriod;
	}
	else
		cout << "没找到该课程！";
}

void deleteCv(cv cu[])
{
	int bh, zh;
	cout << "请输入学号："; cin >> bh;
	cout << "请输入课程编号："; cin >> zh;
	int i = 0, flag = 0;
	while (cu[i].cvFlag)
	{
		if ((bh == cu[i].studNo) && (zh == cu[i].courseNo))
			flag = i;
		if (flag)
			break;
		i++;
	}
	if (flag)
	{
		i = 0;
		while (cu[i].cvFlag)
		{
			cu[i].courseNo = cu[i + 1].courseNo;
			cu[i].grade = cu[i + 1].grade;
			cu[i].studNo = cu[i + 1].studNo;
			i++;
		}
		cu[i - 1].cvFlag = 0;
	}
	else
		cout << "未找到该选课信息！";

}
void deleteCourse(course c3[], cv cu[])
{
	int bh, flag = 0, i = 0;
	cout << "请输入课程编号："; cin >> bh;
	while (cu[i].cvFlag != 0)
	{
		if (bh == cu[i].courseNo)
			flag = i;
		if (flag != 0)
			break;
		i++;
	}
	if (flag == 0)
	{
		i = 0;
		while (c3[i].courseFlag)
		{
			if (bh == c3[i].No)
			{
				flag = i;
			}
			i++;
		}
		if (flag)
		{
			while (c3[i].courseFlag)
			{
				c3[i].No = c3[i + 1].No;
				strcpy(c3[i].name, c3[i + 1].name);
				strcpy(c3[i].type, c3[i + 1].type);
				c3[i].credit = c3[i + 1].credit;
				c3[i].sumPeriod = c3[i + 1].sumPeriod;
				c3[i].thPeriod = c3[i + 1].thPeriod;
				c3[i].expPeriod = c3[i + 1].expPeriod;
				i++;
			}
			c3[i - 1].courseFlag = 0;
		}
		if (flag == 0)
			cout << "没找到该课程！";
	}
	else
	{
		cout << "该课程有学生选课，无法删除！";
	}
}
void deleteStudent(student s[], cv cu[])
{
	int bh, flag = 0, i = 0;
	cout << "请输入学生学号："; cin >> bh;
	while (cu[i].cvFlag)
	{
		if (bh == cu[i].studNo)
			flag = i;
		if (flag)
			break;
		i++;
	}
	if (flag == 0)
	{
		i = 0;
		while (s[i].studentFlag)
		{
			if (bh == s[i].studNo)
			{
				flag = i;
				if (flag)
					break;
			}
			i++;
		}
		if (flag)
		{
			while (s[i].studentFlag)
			{
				s[i].studNo = s[i + 1].studNo;
				strcpy(s[i].sex, s[i + 1].sex);
				s[i].majorNo = s[i + 1].majorNo;
				strcpy(s[i].phoneNumber, s[i + 1].phoneNumber);
				i++;
			}
			s[i - 1].studentFlag = 0;
		}
		if (flag == 0)
			cout << "没找到该学生！";
	}
	else
	{
		cout << "该学生有选课，无法删除！";
	}
}
void deleteMajor(major c2[], student s[])
{
	int bh, flag = 0, i = 0;
	cout << "请输入专业编号："; cin >> bh;
	while (s[i].studentFlag)
	{
		if (bh == s[i].majorNo)
			flag = i;
		if (flag)
			break;
		i++;
	}
	if (flag == 0)
	{
		i = 0;
		while (c2[i].majorFlag)
		{
			if (bh == c2[i].majorNo)
			{
				flag = i;
				if (flag)
					break;
			}
			i++;
		}
		if (flag)
		{
			while (c2[i].majorFlag)
			{
				c2[i].majorNo = c2[i + 1].majorNo;
				c2[i].collegeNo = c2[i + 1].collegeNo;
				strcpy(c2[i].majorName, c2[i + 1].majorName);
				c2[i].majorYear = c2[i + 1].majorYear;
				i++;
			}
			c2[i - 1].majorFlag = 0;
		}
		if (flag == 0)
			cout << "没找到该专业！";
	}
	else
	{
		cout << "该专业有学生，无法删除！";
	}
}
void deleteCollege(college c1[], major c2[])
{
	int bh, flag = 0, i = 0;
	cout << "请输入学院编号："; cin >> bh;
	while (c2[i].majorFlag)
	{
		if (bh == c2[i].collegeNo)
			flag = i;
		if (flag)
			break;
		i++;
	}
	if (flag == 0)
	{
		i = 0;
		while (c1[i].collegeFlag)
		{
			if (bh == c1[i].collegeNo)
			{
				flag = i;
				if (flag)
					break;
			}
			i++;
		}
		if (flag)
		{
			while (c1[i].collegeFlag)
			{
				c1[i].collegeNo = c1[i + 1].collegeNo;
				strcpy(c1[i].collegeName, c1[i + 1].collegeName);
				strcpy(c1[i].deanName, c1[i + 1].deanName);
				i++;
			}
			c1[i - 1].collegeFlag = 0;
		}
		if (flag == 0)
			cout << "没找到该学院！";
	}
	else
	{
		cout << "该学院有专业，无法删除！";
	}
}
