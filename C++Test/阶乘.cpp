#include<iostream.h>
int jiecheng(int);
void main()
{
  int n;
  cout<<"请输入一个正数：";
  cout<<"n="; cin>>n;
  cout<<"累乘结果为："<<jiecheng(n)<<endl;
}
int jiecheng(int n)
{
  int i,j;
  for(i=1,j=1;i<=n;i++)
	  j*=i;
  return j;
}