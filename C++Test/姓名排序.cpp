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
	cout<<"������ѧ������������1-100��\n";
	cin>>n;
	strIn(str,n);
	strSort(str,n);
}
void strIn(char str[][M],int n)
{
	for (int i=0;i<n;i++)
	{
		cout<<"�������"<<i+1<<"��ѧ��������"<<endl;
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
	cout<<"��������ƴ������ĸ˳�������\n";
	for(int i=0;i<n-1;i++) 
		for (int j=i+1;j<n;j++)
			if (strcmp(str[i],str[j])>0)
			{
				strcpy(c,str[i]);
				strcpy(str[i],str[j]);
				strcpy(str[j],c) ;
			}
	strOut(str,n);
	cout<<"�������ַ����Ӷ̵��������\n";
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
