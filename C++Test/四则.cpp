#include<iostream.h>
void main()
{
  double x,y;
  char opt,ch;
  ch='y';
  while(ch=='y'||ch=='Y')
  {
	cout<<"������һ����������:\n";
    cin>>x>>opt>>y;
    cout<<x<<opt<<y<<"=";
    switch(opt)
	{case '+':cout<<x+y;break;
	 case '-':cout<<x-y;break;
	 case '*':cout<<x*y;break;
	 case '/':
		 if(y==0)
			 cout<<"\n��ĸΪ�㣬���ܼ��㣡";
		 else
			 cout<<x/y;break;
	 default:cout<<"������Ŵ���";
	}
	cout<<"\n�Ƿ������y/n��?";
	cin>>ch;
  }
}
  