//�������� Microsoft Visual Studio 2017 (v141) �±���ͨ��
//���ʱ��2018-1-31
//

#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
//�����ṹ��
struct college {               //ѧԺ�ṹ��
	int collegeNo;             //ѧԺ���
	char collegeName[21];      //ѧԺ����
	char deanName[11];         //Ժ������
	int collegeFlag;           //EndFlag
};
struct major {                  //רҵ�ṹ��
	int majorNo;                //רҵ���
	int collegeNo;              //רҵ����ѧԺ���
	int majorYear;            //רҵѧ��
	char majorName[21];         //רҵ����
	int majorFlag;            //EndFlag
};
struct student {               //ѧ���ṹ��
	int studNo;                //ѧ��
	int majorNo;               //רҵ���
	char Name[11];             //ѧ������
	char sex[3];               //ѧ���Ա�
	char phoneNumber[12];      //ѧ����ϵ�绰
	float avgGrade;            //ƽ���ɼ�
	int studentFlag;           //EndFlag
};
struct course {                //�γ̽ṹ��
	int No;                    //�γ̱��
	char name[21];             //�γ�����
	char type[21];             //�γ����ʣ����ޡ���ѡ����ѡ��
	float credit;              //�γ�ѧ��
	int sumPeriod;             //�γ���ѧʱ
	int thPeriod;              //�γ�����ѧʱ
	int expPeriod;             //�γ�ʵ��ѧʱ
	int courseFlag;            //EndFlag
};
struct cv {
	int studNo;                //ѧ��ѧ��
	int courseNo;              //�γ̱��
	float grade;               //�γ̳ɼ�
	int cvFlag;                //EndFlag
};
//��������
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
		cout << "���������ѡ��";
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
		cout << "���������ѡ��";
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
		cout << "���������ѡ��";
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
		cout << "���������ѡ��";
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
		cout << "���������ѡ��";
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
		cout << "���������ѡ��";
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
		cout << "���������ѡ��";
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
	cout << "ѧ��������Ϣ����" << endl;
	cout << "----------------" << endl;
	cout << "1. ѧԺ��Ϣ����" << endl;
	cout << "2. רҵ��Ϣ����" << endl;
	cout << "3. ѧ����Ϣ����" << endl;
	cout << "4. �γ���Ϣ����" << endl;
	cout << "5. ѡ����Ϣ����" << endl;
	cout << "6. ѧ���ɼ�����" << endl;
	cout << "0. �˳�ϵͳ" << endl;
	cout << "----------------" << endl;
}
void menu1()
{
	cout << "  ѧԺ��Ϣ����" << endl;
	cout << "----------------" << endl;
	cout << "1. ѧԺ��Ϣ����" << endl;
	cout << "2. ѧԺ��Ϣ��ʾ" << endl;
	cout << "3. ѧԺ��Ϣ��ѯ" << endl;
	cout << "4. ѧԺ��Ϣ�޸�" << endl;
	cout << "5. ѧԺ��Ϣɾ��" << endl;
	cout << "0. �˳�" << endl;
	cout << "----------------" << endl;
}
void menu2()
{
	cout << "  רҵ��Ϣ����" << endl;
	cout << "----------------" << endl;
	cout << "1. רҵ��Ϣ����" << endl;
	cout << "2. רҵ��Ϣ��ʾ" << endl;
	cout << "3. רҵ��Ϣ��ѯ" << endl;
	cout << "4. רҵ��Ϣ�޸�" << endl;
	cout << "5. רҵ��Ϣɾ��" << endl;
	cout << "0. �˳�" << endl;
	cout << "----------------" << endl;
}
void menu3()
{
	cout << "  ѧ����Ϣ����" << endl;
	cout << "----------------" << endl;
	cout << "1. ѧ����Ϣ����" << endl;
	cout << "2. ѧ����Ϣ��ʾ" << endl;
	cout << "3. ѧ����Ϣ��ѯ" << endl;
	cout << "4. ѧ����Ϣ�޸�" << endl;
	cout << "5. ѧ����Ϣɾ��" << endl;
	cout << "0. �˳�" << endl;
	cout << "----------------" << endl;
}
void menu4()
{
	cout << "��ѡ���ѯѧԺ�ķ�ʽ��" << endl;
	cout << "----------------" << endl;
	cout << "1. ѧԺ���Ʋ���" << endl;
	cout << "2. ѧԺԺ������" << endl;
	cout << "3. ѧԺ��Ų���" << endl;
	cout << "0. �˳�" << endl;
	cout << "----------------" << endl;
}
void menu5()
{
	cout << "��ѡ���ѯרҵ�ķ�ʽ��" << endl;
	cout << "----------------" << endl;
	cout << "1. רҵ���Ʋ���" << endl;
	cout << "2. ����ѧԺ����" << endl;
	cout << "3. רҵ��Ų���" << endl;
	cout << "0. �˳�" << endl;
	cout << "----------------" << endl;
}
void menu6()
{
	cout << "��ѡ���ѯѧ���ķ�ʽ��" << endl;
	cout << "----------------" << endl;
	cout << "1. ѧ�����Ʋ���" << endl;
	cout << "2. ѧ��ѧ�Ų���" << endl;
	cout << "0. �˳�" << endl;
	cout << "----------------" << endl;
}
void menu7()
{
	cout << "  �γ���Ϣ����" << endl;
	cout << "----------------" << endl;
	cout << "1. �γ���Ϣ����" << endl;
	cout << "2. �γ���Ϣ��ʾ" << endl;
	cout << "3. �γ���Ϣ��ѯ" << endl;
	cout << "4. �γ���Ϣ�޸�" << endl;
	cout << "5. �γ���Ϣɾ��" << endl;
	cout << "0. �˳�" << endl;
	cout << "----------------" << endl;
}
void menu8()
{
	cout << "��ѡ���ѯ�γ̵ķ�ʽ��" << endl;
	cout << "----------------" << endl;
	cout << "1. �γ����Ʋ���" << endl;
	cout << "2. �γ̱�Ų���" << endl;
	cout << "0. �˳�" << endl;
	cout << "----------------" << endl;
}
void menu9()
{
	cout << "  ѡ����Ϣ����" << endl;
	cout << "----------------" << endl;
	cout << "1. ѡ����Ϣ����" << endl;
	cout << "2. ѡ����Ϣ��ʾ" << endl;
	cout << "3. ѡ����Ϣ��ѯ" << endl;
	cout << "4. ѡ����Ϣɾ��" << endl;
	cout << "0. �˳�" << endl;
	cout << "----------------" << endl;
}
void menu10()
{
	cout << "  ѡ����Ϣ��ѯ" << endl;
	cout << "----------------" << endl;
	cout << "1. �γ�ѡ�β�ѯ" << endl;
	cout << "2. ѧ��ѡ�β�ѯ" << endl;
	cout << "0. �˳�" << endl;
	cout << "----------------" << endl;
}
void menu11()
{
	cout << "  ѧ���ɼ�����" << endl;
	cout << "----------------" << endl;
	cout << "1. ѧ���ɼ�����" << endl;
	cout << "2. �γ̳ɼ����" << endl;
	cout << "3. ѧ���ɼ����" << endl;
	cout << "4. �ɼ��������" << endl;
	cout << "0. �˳�" << endl;
	cout << "----------------" << endl;
}
void menu12()
{
	cout << "  �ɼ�����ʽ" << endl;
	cout << "----------------" << endl;
	cout << "1.   Ĭ������" << endl;
	cout << "2. �ɼ��ɸߵ���" << endl;
	cout << "3. ѧ���ɵ͵���" << endl;
	cout << "0. �˳�" << endl;
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
		cout << "ѧԺ��ţ�"; cin >> c1[i].collegeNo;
		c1[i].collegeFlag = c1[i].collegeNo;
		cout << "ѧԺ���ƣ�"; cin >> c1[i].collegeName;
		cout << "ѧԺԺ����"; cin >> c1[i].deanName;
		cout << "�Ƿ�������룿��Y/N��";
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
		cout << "רҵ��ţ�"; cin >> c1[i].majorNo;
		c1[i].majorFlag = c1[i].majorNo;
		cout << "����ѧԺ��ţ�"; cin >> c1[i].collegeNo;
		cout << "רҵ���ƣ�"; cin >> c1[i].majorName;
		cout << "רҵѧ�ƣ�"; cin >> c1[i].majorYear;
		cout << "�Ƿ�������룿��Y/N��";
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
		cout << "ѧ�ţ�"; cin >> s[i].studNo;
		s[i].studentFlag = s[i].studNo;
		cout << "������"; cin >> s[i].Name;
		cout << "�Ա�"; cin >> s[i].sex;
		cout << "����רҵ��ţ�"; cin >> s[i].majorNo;
		cout << "��ϵ�绰��"; cin >> s[i].phoneNumber;
		cout << "�Ƿ�������룿��Y/N��";
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
		cout << "�γ̱�ţ�"; cin >> c3[i].No;
		c3[i].courseFlag = c3[i].No;
		cout << "�γ����ƣ�"; cin >> c3[i].name;
		cout << "�γ����ʣ�"; cin >> c3[i].type;
		cout << "�γ�ѧ�֣�"; cin >> c3[i].credit;
		cout << "�γ���ѧʱ��"; cin >> c3[i].sumPeriod;
		cout << "�γ�����ѧʱ��"; cin >> c3[i].thPeriod;
		cout << "�γ�ʵ��ѧʱ��"; cin >> c3[i].expPeriod;
		cout << "�Ƿ�������룿��Y/N��";
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
		cout << "ѧ��ѧ�ţ�"; cin >> cu[i].studNo;
		cu[i].cvFlag = cu[i].courseNo;
		cout << "�γ̱�ţ�"; cin >> cu[i].courseNo;
		cout << "�γ̳ɼ���"; cin >> cu[i].grade;
		cout << "�Ƿ�������룿��Y/N��";
		cin >> ch;
		i++;
	}
}
void gradeIn(student s[], course c3[], cv cu[])
{
	int i = 0, flag = 0, bh;
	cout << "������γ̱�ţ�";
	cin >> bh;
	while (c3[i].courseFlag != 0)
	{
		if (bh == c3[i].No)
		{
			cout << "                                �γ��б�" << endl;
			cout << "------------------------------------------------------------------------" << endl;
			cout << " ���    ����         ����    ѧ��        ��ѧʱ    ����ѧʱ    ʵ��ѧʱ" << endl;
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
			cout << "ѧ������: " << findStudName(s, cu[i].studNo);
			cout << "ѧ��: " << cu[i].studNo;
			cout << "�ɼ�: ";
			cin >> cu[i].grade;
			cout << endl;
			flag = 2;
		}
		i++;
	}
	if (flag == 0)
		cout << "û�ҵ��ÿγ̣�";
	if (flag == 1)
		cout << "�ÿγ���ѧ��ѡ�Σ�";

}

void collegeOut(college c1[])
{
	int i = 0;
	cout << "              ѧԺ��Ϣ�б�" << endl;
	cout << "----------------------------------------------" << endl;
	cout << "ѧԺ���                ѧԺ����         Ժ��" << endl;
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
	cout << "                             רҵ�б�" << endl;
	cout << "---------------------------------------------------------------------" << endl;
	cout << "רҵ���          רҵ����                       ѧ��        ����ѧԺ" << endl;
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
	cout << "                                ѧ���б�" << endl;
	cout << "------------------------------------------------------------------------" << endl;
	cout << " ѧ��    ����    �Ա�       רҵ                ѧԺ          ��ϵ��ʽ" << endl;
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
	cout << "                                �γ��б�" << endl;
	cout << "------------------------------------------------------------------------" << endl;
	cout << " ���    ����         ����       ѧ��     ��ѧʱ    ����ѧʱ    ʵ��ѧʱ" << endl;
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
	cout << "                                ѡ���б�" << endl;
	cout << "------------------------------------------------------------------------" << endl;
	cout << "ѧ������   ѧ��ѧ��   �γ̱��   �γ�����  �γ̳ɼ�     ���� ѧ�� ��ѧʱ" << endl;
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
	cout << "������γ̱�ţ� ";
	cin >> bh;
	cout << "                                �γ���Ϣ" << endl;
	cout << "------------------------------------------------------------------------" << endl;
	cout << " ���    ����         ����       ѧ��     ��ѧʱ    ����ѧʱ    ʵ��ѧʱ" << endl;
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
	cout << "                              ѧ���ɼ��б�" << endl;
	cout << "------------------------------------------------------------------------" << endl;
	cout << "ѧ������   ѧ��ѧ��   רҵ   �γ̱��   �γ�����  �γ̳ɼ�    ����  ѧ�� " << endl;
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
	cout << "������ѧ��ѧ�ţ� ";
	cin >> bh;
	cout << "                              ѧ���ɼ��б�" << endl;
	cout << "------------------------------------------------------------------------" << endl;
	cout << "ѧ������   ѧ��ѧ��  רҵ  �γ̱��   �γ�����  �γ̳ɼ�     ����   ѧ��" << endl;
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
		cout << "û���ҵ���ѧ����";
}
void rankGradeOut(major c2[], student s[], course c3[], cv cu[])
{
	int i = 0, j;
	char str1[] = "����";
	char str2[] = "��ѡ";
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
	cout << "        ѧ���ɼ��б�" << endl;
	cout << "---------------------------------------" << endl;
	cout << "ѧ������               ƽ���ɼ�" << endl;

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
		cout << "���������ѡ��";
		cin >> sel;
		if (sel == 1)
		{
			char bh[21];
			int i = 0, flag = 0;
			cout << "������ѧԺ���ƣ�";
			cin >> bh;
			while (c1[i].collegeFlag != 0)
			{
				if (strcmp(bh, c1[i].collegeName) == 0)
				{
					cout << "----------------------------------------------" << endl;
					cout << "ѧԺ���      ѧԺ����                 Ժ��" << endl;
					cout << setw(8) << c1[i].collegeNo << setw(30) << c1[i].collegeName << setw(8) << c1[i].deanName << endl;
					cout << "----------------------------------------------" << endl;
					flag = 1;
				}
				i++;
			}
			if (flag == 0)
				cout << "û�ҵ���ѧԺ��";
		}
		if (sel == 2)
		{
			char bh[21];
			int i = 0, flag = 0;
			cout << "������Ժ��������";
			cin >> bh;
			while (c1[i].collegeFlag != 0)
			{
				if (strcmp(bh, c1[i].deanName) == 0)
				{
					cout << "----------------------------------------------" << endl;
					cout << "ѧԺ���      ѧԺ����                 Ժ��" << endl;
					cout << setw(8) << c1[i].collegeNo << setw(30) << c1[i].collegeName << setw(8) << c1[i].deanName << endl;
					cout << "----------------------------------------------" << endl;
					flag = 1;
				}
				i++;
			}
			if (flag == 0)
				cout << "û�ҵ���ѧԺ��";
		}
		if (sel == 3)
		{
			int bh, i = 0;
			char *p;
			cout << "������ѧԺ��ţ�";
			cin >> bh;
			p = findCollegeName(c1, bh);
			if (bh != NULL)
			{
				while (c1[i].collegeFlag != 0)
				{
					if (p == c1[i].collegeName)
					{
						cout << "----------------------------------------------" << endl;
						cout << "ѧԺ���      ѧԺ����                 Ժ��" << endl;
						cout << setw(8) << c1[i].collegeNo << setw(30) << c1[i].collegeName << setw(8) << c1[i].deanName << endl;
						cout << "----------------------------------------------" << endl;
					}
					i++;
				}

			}
			else
				cout << "û�ҵ���ѧԺ��";
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
		cout << "���������ѡ��";
		cin >> sel;
		if (sel == 1)
		{
			char bh[21];
			int i = 0, flag = 0;
			cout << "������רҵ���ƣ�";
			cin >> bh;
			while (c2[i].majorFlag != 0)
			{
				if (strcmp(bh, c2[i].majorName) == 0)
				{
					cout << "                             רҵ�б�" << endl;
					cout << "---------------------------------------------------------------------" << endl;
					cout << "רҵ���          רҵ����                       ѧ��        ����ѧԺ" << endl;
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
				cout << "û�ҵ���רҵ��";
		}
		if (sel == 2)
		{
			int bh;
			int i = 0, flag = 0;
			cout << "����������ѧԺ��ţ�";
			cin >> bh;
			while (c2[i].majorFlag != 0)
			{
				if (bh == c2[i].collegeNo)
				{
					cout << "                             רҵ�б�" << endl;
					cout << "---------------------------------------------------------------------" << endl;
					cout << "רҵ���          רҵ����                       ѧ��        ����ѧԺ" << endl;
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
				cout << "û�ҵ���רҵ��";

		}
		if (sel == 3)
		{
			int i = 0, flag = 0, bh;
			cout << "������רҵ��ţ�";
			cin >> bh;
			while (c2[i].majorFlag != 0)
			{
				if (bh == c2[i].majorNo)
				{
					cout << "                             רҵ�б�" << endl;
					cout << "---------------------------------------------------------------------" << endl;
					cout << "רҵ���          רҵ����                       ѧ��        ����ѧԺ" << endl;
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
				cout << "û�ҵ���רҵ��";
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
		cout << "���������ѡ��";
		cin >> sel;
		if (sel == 1)
		{
			char bh[21];
			int i = 0, flag = 0;
			cout << "������ѧ��������";
			cin >> bh;
			while (s[i].studentFlag != 0)
			{
				if (strcmp(bh, s[i].Name) == 0)
				{
					cout << "                                ѧ���б�" << endl;
					cout << "------------------------------------------------------------------------" << endl;
					cout << " ѧ��    ����   �Ա�        רҵ                ѧԺ          ��ϵ��ʽ" << endl;
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
				cout << "û�ҵ���ѧ����";
		}
		if (sel == 2)
		{
			int i = 0, flag = 0, bh;
			cout << "������ѧ��ѧ�ţ�";
			cin >> bh;
			while (s[i].studentFlag != 0)
			{
				if (bh == s[i].studNo)
				{
					cout << "                                ѧ���б�" << endl;
					cout << "------------------------------------------------------------------------" << endl;
					cout << " ѧ��    ����   �Ա�        רҵ                ѧԺ          ��ϵ��ʽ" << endl;
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
				cout << "û�ҵ���ѧ����";
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
		cout << "���������ѡ��";
		cin >> sel;
		if (sel == 1)
		{
			char bh[21];
			int i = 0, flag = 0;
			cout << "������γ����ƣ�";
			cin >> bh;
			while (c3[i].courseFlag != 0)
			{
				if (strcmp(bh, c3[i].name) == 0)
				{
					cout << "                                �γ��б�" << endl;
					cout << "------------------------------------------------------------------------" << endl;
					cout << " ���    ����         ����    ѧ��        ��ѧʱ    ����ѧʱ    ʵ��ѧʱ" << endl;
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
				cout << "û�ҵ��ÿγ̣�";
		}
		if (sel == 2)
		{
			int i = 0, flag = 0, bh;
			cout << "������γ̱�ţ�";
			cin >> bh;
			while (c3[i].courseFlag != 0)
			{
				if (bh == c3[i].No)
				{
					cout << "                                �γ��б�" << endl;
					cout << "------------------------------------------------------------------------" << endl;
					cout << " ���    ����         ����    ѧ��        ��ѧʱ    ����ѧʱ    ʵ��ѧʱ" << endl;
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
				cout << "û�ҵ��ÿγ̣�";
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
		cout << "���������ѡ��";
		cin >> sel;
		if (sel == 1)
		{
			int i = 0, flag = 0, bh;
			cout << "������γ̱�ţ�";
			cin >> bh;
			while (c3[i].courseFlag)
			{
				if (bh == c3[i].No)
				{
					cout << "                                �γ���Ϣ" << endl;
					cout << "------------------------------------------------------------------------" << endl;
					cout << " ���    ����         ����    ѧ��        ��ѧʱ    ����ѧʱ    ʵ��ѧʱ" << endl;
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
					cout << "                                ѧ���б�" << endl;
					cout << "------------------------------------------------------------------------" << endl;
					cout << " ѧ��    ����   �Ա�        רҵ                ѧԺ          ��ϵ��ʽ" << endl;
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
				cout << "û�ҵ��ÿγ̣�";
		}
		if (sel == 2)
		{
			int i = 0, flag = 0, bh;
			cout << "������ѧ��ѧ�ţ�";
			cin >> bh;
			cout << "                                ѡ���б�" << endl;
			cout << "------------------------------------------------------------------------" << endl;
			cout << "ѧ������   ѧ��ѧ��   �γ̱��   �γ�����  �γ̳ɼ�     ���� ѧ�� ��ѧʱ" << endl;
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
				cout << "û�ҵ��ÿγ̣�";
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
	cout << "������ѧԺ��ţ�";
	cin >> bh;
	while (c[i].collegeFlag != 0)
	{
		if (bh == c[i].collegeNo)
		{
			cout << "----------------------------------------------" << endl;
			cout << "ѧԺ���      ѧԺ����                 Ժ��" << endl;
			cout << setw(8) << c[i].collegeNo << setw(30) << c[i].collegeName << setw(8) << c[i].deanName << endl;
			cout << "----------------------------------------------" << endl;
			flag = i;
		}
		i++;
	}
	if (flag)
	{
		cout << "�������µ�ѧԺ���ƣ� "; cin >> c[flag].collegeName;
		cout << "�������µ�Ժ�������� "; cin >> c[flag].deanName;
	}
	else
		cout << "û�ҵ���ѧԺ��";

}
void modifyMajor(college c1[], major c2[])
{
	int i = 0, flag = 0, bh;
	cout << "������רҵ��ţ�";
	cin >> bh;
	while (c2[i].majorFlag != 0)
	{
		if (bh == c2[i].majorNo)
		{
			cout << "                             רҵ�б�" << endl;
			cout << "---------------------------------------------------------------------" << endl;
			cout << "רҵ���          רҵ����                       ѧ��        ����ѧԺ" << endl;
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
		cout << "����ѧԺ��ţ�"; cin >> c2[flag].collegeNo;
		cout << "רҵ���ƣ�"; cin >> c2[flag].majorName;
		cout << "רҵѧ�ƣ�"; cin >> c2[flag].majorYear;
	}
	else
		cout << "û�ҵ���רҵ��";
}
void modifyStudent(college c[], major c1[], student s[])
{
	int i = 0, flag = 0, bh;
	cout << "������ѧ��ѧ�ţ�";
	cin >> bh;
	while (s[i].studentFlag != 0)
	{
		if (bh == s[i].studNo)
		{
			cout << "                                ѧ���б�" << endl;
			cout << "------------------------------------------------------------------------" << endl;
			cout << " ѧ��    ����   �Ա�        רҵ                ѧԺ          ��ϵ��ʽ" << endl;
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
		cout << "������"; cin >> s[flag].Name;
		cout << "�Ա�"; cin >> s[flag].sex;
		cout << "����רҵ��ţ�"; cin >> s[flag].majorNo;
		cout << "��ϵ�绰��"; cin >> s[flag].phoneNumber;
	}
	else
		cout << "û�ҵ���ѧ����";

}
void modifyCourse(course c3[])
{
	int i = 0, flag = 0, bh;
	cout << "������γ̱�ţ�";
	cin >> bh;
	while (c3[i].courseFlag != 0)
	{
		if (bh == c3[i].No)
		{
			cout << "                                �γ��б�" << endl;
			cout << "------------------------------------------------------------------------" << endl;
			cout << " ���    ����         ����    ѧ��        ��ѧʱ    ����ѧʱ    ʵ��ѧʱ" << endl;
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
		cout << "�γ����ƣ�"; cin >> c3[flag].name;
		cout << "�γ����ʣ�"; cin >> c3[flag].type;
		cout << "�γ�ѧ�֣�"; cin >> c3[flag].credit;
		cout << "�γ���ѧʱ��"; cin >> c3[flag].sumPeriod;
		cout << "�γ�����ѧʱ��"; cin >> c3[flag].thPeriod;
		cout << "�γ�ʵ��ѧʱ��"; cin >> c3[flag].expPeriod;
	}
	else
		cout << "û�ҵ��ÿγ̣�";
}

void deleteCv(cv cu[])
{
	int bh, zh;
	cout << "������ѧ�ţ�"; cin >> bh;
	cout << "������γ̱�ţ�"; cin >> zh;
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
		cout << "δ�ҵ���ѡ����Ϣ��";

}
void deleteCourse(course c3[], cv cu[])
{
	int bh, flag = 0, i = 0;
	cout << "������γ̱�ţ�"; cin >> bh;
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
			cout << "û�ҵ��ÿγ̣�";
	}
	else
	{
		cout << "�ÿγ���ѧ��ѡ�Σ��޷�ɾ����";
	}
}
void deleteStudent(student s[], cv cu[])
{
	int bh, flag = 0, i = 0;
	cout << "������ѧ��ѧ�ţ�"; cin >> bh;
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
			cout << "û�ҵ���ѧ����";
	}
	else
	{
		cout << "��ѧ����ѡ�Σ��޷�ɾ����";
	}
}
void deleteMajor(major c2[], student s[])
{
	int bh, flag = 0, i = 0;
	cout << "������רҵ��ţ�"; cin >> bh;
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
			cout << "û�ҵ���רҵ��";
	}
	else
	{
		cout << "��רҵ��ѧ�����޷�ɾ����";
	}
}
void deleteCollege(college c1[], major c2[])
{
	int bh, flag = 0, i = 0;
	cout << "������ѧԺ��ţ�"; cin >> bh;
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
			cout << "û�ҵ���ѧԺ��";
	}
	else
	{
		cout << "��ѧԺ��רҵ���޷�ɾ����";
	}
}
