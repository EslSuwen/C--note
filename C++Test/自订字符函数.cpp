#include<iostream.h>
const int N=100;
void strIn(char *);//����
void strCpy(char *,char *);//����
void strCat(char *,char *);//����
int strLen(char *);//����
void strCmp(char *,char *);//�Ƚ�
void main()
{
	char str1[N],str2[N],str3[2*N];
	cout<<"�����һ���ַ���(1-100):\n";
	strIn(str1);
	cout<<"�ַ��� "<<str1<<" �ĳ���Ϊ�� ";
	cout<<strLen(str1)<<endl;
	cout<<"����ڶ����ַ���(1-100):\n";
	strIn(str2);
	cout<<"�ַ��� "<<str2<<" �ĳ���Ϊ�� ";
	cout<<strLen(str2)<<endl;
	strCpy(str3,str1);
	cout<<"��������ַ���:\n";
	cout<<str3<<endl; 
	strCat(str3,str2);
	cout<<"���Ӻ���ַ���:\n";
	cout<<str3<<endl;
	cout<<"���Ӻ���ַ����ĳ���:\n";
	cout<<strLen(str3)<<endl;
	strCmp(str1,str2);
}
void strIn(char *str1)
{
	char ch;
	while((ch=cin.get())!='\n')
		*str1++=ch;
    *str1='\0';
}
void strCpy(char *str1,char *str2)//�ַ�����
{
	for(int i=0;*str2;i++)
	{
		*str1=*str2;str1++;str2++;
	}
	*str1='\0';
}
void strCat(char *str1,char *str2)//�ַ�����
{
	while(*str1)
		str1++;
	while(*str2)
	{
		*str1=*str2;str1++;str2++;
	}
	*str1='\0';
}
int strLen(char *s)//�ַ�����
{
	char *str1;
	str1=s;
	while(*str1)
		str1++;
	return str1-s;
}
void strCmp(char *str1,char *str2)//�ַ��Ƚ�
{
	int n;
	while(*str1&&*str2)
	{
		if(*str1!=*str2)
			break;
		str1++;str2++;
	}
	n=*str1-*str2;
	if(n==0)
		cout<<"���!\n";
	else if(n>0)
		cout<<"����!\n"<<endl;
	else cout<<"С��!\n"<<endl;
}