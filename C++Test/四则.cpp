#include<iostream.h>
void main()
{
  double x,y;
  char opt,ch;
  ch='y';
  while(ch=='y'||ch=='Y')
  {
	cout<<"请输入一个四则运算:\n";
    cin>>x>>opt>>y;
    cout<<x<<opt<<y<<"=";
    switch(opt)
	{case '+':cout<<x+y;break;
	 case '-':cout<<x-y;break;
	 case '*':cout<<x*y;break;
	 case '/':
		 if(y==0)
			 cout<<"\n分母为零，不能计算！";
		 else
			 cout<<x/y;break;
	 default:cout<<"运算符号错误";
	}
	cout<<"\n是否继续（y/n）?";
	cin>>ch;
  }
}
  