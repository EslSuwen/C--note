#include<iostream.h>
#include<stdlib.h>
void main()
{
  int a,n,b,c;
  cout<<"����һ����λ�����������:";
  cin>>a;
  srand(a);
  n=rand()%900+100;
  for(b=1;c=n;b++)
  {
    cout<<"����һ����:";
	cin>>c;
	if(c!=n)
	{
	  cout<<"����"<<endl;
	  if(c>n)
		  cout<<"�����ˣ�"<<endl;
	  else
		  cout<<"��С�ˣ�"<<endl;
	}
	else
	{
		cout<<"��ȷ��"<<endl;break;
	}
  }
  switch(b)
  {
  case 1:case 2:case 3:cout<<"�����"<<endl;break;
  case 4:case 5:cout<<"����"<<endl;break;
  case 6:case 7:cout<<"�����ԣ�"<<endl;break;
  case 8:case 9:cout<<"�е㱿��"<<endl;break;
  default :cout<<"�汿��"<<endl;break;
  }
}