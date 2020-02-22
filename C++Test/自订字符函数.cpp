#include<iostream.h>
const int N=100;
void strIn(char *);//输入
void strCpy(char *,char *);//拷贝
void strCat(char *,char *);//连接
int strLen(char *);//长度
void strCmp(char *,char *);//比较
void main()
{
	char str1[N],str2[N],str3[2*N];
	cout<<"输入第一个字符串(1-100):\n";
	strIn(str1);
	cout<<"字符串 "<<str1<<" 的长度为： ";
	cout<<strLen(str1)<<endl;
	cout<<"输入第二个字符串(1-100):\n";
	strIn(str2);
	cout<<"字符串 "<<str2<<" 的长度为： ";
	cout<<strLen(str2)<<endl;
	strCpy(str3,str1);
	cout<<"拷贝后的字符串:\n";
	cout<<str3<<endl; 
	strCat(str3,str2);
	cout<<"连接后的字符串:\n";
	cout<<str3<<endl;
	cout<<"连接后的字符串的长度:\n";
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
void strCpy(char *str1,char *str2)//字符拷贝
{
	for(int i=0;*str2;i++)
	{
		*str1=*str2;str1++;str2++;
	}
	*str1='\0';
}
void strCat(char *str1,char *str2)//字符连接
{
	while(*str1)
		str1++;
	while(*str2)
	{
		*str1=*str2;str1++;str2++;
	}
	*str1='\0';
}
int strLen(char *s)//字符长度
{
	char *str1;
	str1=s;
	while(*str1)
		str1++;
	return str1-s;
}
void strCmp(char *str1,char *str2)//字符比较
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
		cout<<"相等!\n";
	else if(n>0)
		cout<<"大于!\n"<<endl;
	else cout<<"小于!\n"<<endl;
}