//����ֶκ���
#include<iostream.h>
void main()
{
  double x,y;
  int z;
  cout<<"������һ����С��0����:\n";
  cout<<"x="; cin>>x;
    if(x>0)
	  { z=1*(x>=0&&x<=50)+2*(x>50&&x<=100)+3*(x>100&&x<=200)+4*(x>200);
		switch(z)
		  {case 1: y=0.2*x; break;
           case 2: y=10.0+0.4*(x-50); break;
		   case 3: y=30.0+0.5*(x-100); break;
		   case 4: y=80.0+0.6*(x-200); break;
		  }
	    cout<<"y="<<y<<endl;
	  }
	else
		cout<<"�������С����0"<<endl;
}