#include<iostream.h>
void sushu(int);
void main()
{
  int x;
  cout<<"������һ������1��������";
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
		cout<<"��������������"<<endl;
	  }
	  else if(x%a==0&&a==x)
	  {
		b=0;
		cout<<"����������"<<endl;
	  }
	  else
	  {
		b=1;
	  }
  }
}