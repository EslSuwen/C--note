#include<iostream.h>
void sushu(int);
void main()
{
  int x;
  cout<<"请输入一个大于1的整数：";
  cout<<"x="; cin>>x;
  sushu(x);
}
void sushu(int x)
{
  int a,b;
  b=1;
  a=1;
  while(b==1)
  {   
      a++;
	  if(x%a==0&&a<x)
	  {
	    b=0;
		cout<<"该整数不是素数"<<endl;
	  }
	  else if(x%a==0&&a==x)
	  {
		b=0;
		cout<<"该数是素数"<<endl;
	  }
	  else
	  {
		b=1;
	  }
  }
}