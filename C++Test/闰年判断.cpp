#include<iostream.h>
int year(int);
int month(int,int);
void main()
{
  int x,y;
  cout<<"������һ����ݣ�";
  cin>>x;
  cout<<"������һ���·ݣ�";
  cin>>y;
  if(year(x)==1)
	  cout<<"����������\n";
  else
	  cout<<"���겻������\n";
  cout<<"�µ�������"<<month(x,y)<<endl;
}
int year(int x)
{
  int a;
  if(x%400==0||x%4==0&&x%100!=0)
	  a=1;
  return a;
}
int month(int x,int y)
{
	int n;
	switch(y)
	{ case 1:case 3:case 5:case 7:case 8:case 10:case 12: n=31;break;
	  case 4:case 6:case 9:case 11:n=30;break;
	  case 2:
		  if(year(x)==1)
			  n=29;
		  else
			  n=28;break;
	  default:  cout<<"�������ݲ���";n=0;break;
	}
	return n;
}
      
  