#include<iostream.h>
void main()
{
  double x1,x2,y1,y2,x,y;
  char ch;
  ch='y';
  cout<<"请输入两点:\n";
  cout<<"x1="; cin>>x1;
  cout<<"x2="; cin>>x2;
  cout<<"y1="; cin>>y1;
  cout<<"y2="; cin>>y2;
  while(ch=='y'||ch=='Y')
  { 
	cout<<"请输入两点之间的插值x\n";
    cout<<"x="; cin>>x;
	if(x>=x1&&x<=x2||x>=x2&&x<=x1)  
	{ y=((y2-y1)/(x2-x1))*(x-x1)+y1;
	  cout<<"y="<<y;
	}
	else
	cout<<"不能插值";
	cout<<"\n是否继续插值（y/n）?";
	cin>>ch;
	
  }
}
