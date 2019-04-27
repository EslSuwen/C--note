#include<iostream.h>
#include<math.h>
void main()
{
  double a,b,c,d,x1,x2;
  cout<<"请输入三个系数，用空格隔开:\n";
  cout<<"a="; cin>>a;
  cout<<"b="; cin>>b;
  cout<<"c="; cin>>c;
  d=b*b-4*a*c;
  if(d>0)
  {
    x1=(-b+sqrt(d)/a/2);
	x2=(-b-sqrt(d)/a/2);
	cout<<"函数a*x^2+b*x+c=0有两个实根";
	cout<<"x1="<<x1<<"x2="<<x2<<endl;
  }
  else if(d==0)
  {
	x1=(-b+sqrt(d)/a/2);
	cout<<"函数a*x^2+b*x+c=0有一个实根";
	cout<<"x1="<<"x2="<<x1<<endl;
  }
  else
  {
    cout<<"函数无实根"<<endl;
  }
}