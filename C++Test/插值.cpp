#include<iostream.h>
void main()
{
  double x1,x2,y1,y2,x,y;
  char ch;
  ch='y';
  cout<<"����������:\n";
  cout<<"x1="; cin>>x1;
  cout<<"x2="; cin>>x2;
  cout<<"y1="; cin>>y1;
  cout<<"y2="; cin>>y2;
  while(ch=='y'||ch=='Y')
  { 
	cout<<"����������֮��Ĳ�ֵx\n";
    cout<<"x="; cin>>x;
	if(x>=x1&&x<=x2||x>=x2&&x<=x1)  
	{ y=((y2-y1)/(x2-x1))*(x-x1)+y1;
	  cout<<"y="<<y;
	}
	else
	cout<<"���ܲ�ֵ";
	cout<<"\n�Ƿ������ֵ��y/n��?";
	cin>>ch;
	
  }
}
