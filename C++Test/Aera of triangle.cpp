//�������������������������
#include<iostream.h>
#include<math.h>
void main()
{
	double a,b,c,p,s;
	cout<<"����������������"<<endl;
	cin>>a>>b>>c;
	p=(a+b+c)/2;
	s=sqrt(p*(p-a)*(p-b)*(p-c));
	if(a+b>c&&b+c>a&&a+c>b)
		cout<<"���s="<<s<<endl; 
	else
		cout<<"��������ȷ����������"<<endl;
}