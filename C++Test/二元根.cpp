#include<iostream.h>
#include<math.h>
void main()
{
  double a,b,c,d,x1,x2;
  cout<<"����������ϵ�����ÿո����:\n";
  cout<<"a="; cin>>a;
  cout<<"b="; cin>>b;
  cout<<"c="; cin>>c;
  d=b*b-4*a*c;
  if(d>0)
  {
    x1=(-b+sqrt(d)/a/2);
	x2=(-b-sqrt(d)/a/2);
	cout<<"����a*x^2+b*x+c=0������ʵ��";
	cout<<"x1="<<x1<<"x2="<<x2<<endl;
  }
  else if(d==0)
  {
	x1=(-b+sqrt(d)/a/2);
	cout<<"����a*x^2+b*x+c=0��һ��ʵ��";
	cout<<"x1="<<"x2="<<x1<<endl;
  }
  else
  {
    cout<<"������ʵ��"<<endl;
  }
}