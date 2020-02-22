#include<iostream.h>
#include<stdlib.h>
void main()
{
  int a,n,b,c;
  cout<<"输入一个四位数重置随机数:";
  cin>>a;
  srand(a);
  n=rand()%900+100;
  for(b=1;c=n;b++)
  {
    cout<<"输入一个数:";
	cin>>c;
	if(c!=n)
	{
	  cout<<"错误。"<<endl;
	  if(c>n)
		  cout<<"数大了！"<<endl;
	  else
		  cout<<"数小了！"<<endl;
	}
	else
	{
		cout<<"正确！"<<endl;break;
	}
  }
  switch(b)
  {
  case 1:case 2:case 3:cout<<"真棒！"<<endl;break;
  case 4:case 5:cout<<"不错！"<<endl;break;
  case 6:case 7:cout<<"还可以！"<<endl;break;
  case 8:case 9:cout<<"有点笨！"<<endl;break;
  default :cout<<"真笨！"<<endl;break;
  }
}