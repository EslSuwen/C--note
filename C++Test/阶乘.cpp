#include<iostream.h>
int jiecheng(int);
void main()
{
  int n;
  cout<<"������һ��������";
  cout<<"n="; cin>>n;
  cout<<"�۳˽��Ϊ��"<<jiecheng(n)<<endl;
}
int jiecheng(int n)
{
  int i,j;
  for(i=1,j=1;i<=n;i++)
	  j*=i;
  return j;
}