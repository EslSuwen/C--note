#include<iostream.h>
#include<string.h>
const int N=100;
const int M=20;
void strIn(char str[][M],int n);
void strOut(char str[][M],int n);
void strSort(char str[][M],int n);
void main()
{
	char str[N][M];
	int n;
	cout<<"请输入学生的数量：（1-100）\n";
	cin>>n;
	strIn(str,n);
	strSort(str,n);
}
void strIn(char str[][M],int n)
{
	for (int i=0;i<n;i++)
	{
		cout<<"请输入第"<<i+1<<"个学生的名字"<<endl;
        cin>>str[i] ;		
	}
}
void strOut(char str[][M],int n)
{
	for(int i=0;i<n;i++)
		cout<<str[i]<<"  ";
	cout<<endl;
}
void strSort(char str[][M],int n)
{
	char c[20];
	cout<<"按姓名（拼音）字母顺序输出：\n";
	for(int i=0;i<n-1;i++) 
		for (int j=i+1;j<n;j++)
			if (strcmp(str[i],str[j])>0)
			{
				strcpy(c,str[i]);
				strcpy(str[i],str[j]);
				strcpy(str[j],c) ;
			}
	strOut(str,n);
	cout<<"按姓名字符串从短到长输出：\n";
	for(i=0;i<n-1;i++) 
		for (int j=i+1;j<n;j++)
			if (strlen(str[i])>strlen(str[j]))
			{
				strcpy(c,str[i]);
				strcpy(str[i],str[j]);
				strcpy(str[j],c);
			}
    strOut(str,n);	
}		
