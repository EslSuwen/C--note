#include <iostream.h>
int cd(int a,int b);
int cre(int a,int b);
void main()
{
  int a,b;
  cout<<"��������������:"<<endl;
  cout<<"a=";cin>>a;
  cout<<"b=";cin>>b;
  cout<<"���������Լ����:"<<cd(a,b)<<endl;
  cout<<"��������С��������:"<<cre(a,b)<<endl;
}
int cd(int m,int n)//cd��cre�ֱ������Լ������С��������
{ 
  int temp,i;
  if (m<n)
  {
    temp=m;m=n;n=temp;
  }
	for(i=m;i>=1;i--) 
	  if(m%i==0&&n%i==0)    
      break;
   return i;
}
int cre(int m,int n)
{ 
  int temp,i;
  if (m>n)
  {
    temp=m;m=n;n=temp;
  }
	for(i=m;i<=m*n;i++) 
	  if(i%m==0&&i%n==0)    
      break;
   return i;
}
