#include<iostream.h>
#include<math.h>
void main()
{
	double x,y;
	int p;
	cin>>x;
	p=1*(x<0)+2*(x>=0&&x<16)+3*(x>=16);
	switch(p)
	{
		case 1:y=x-sqrt(-x);break;
		case 2:y=-x+sqrt(x);break;
		case 3:y=8+sqrt(x);break;
	}

    cout<<"y="<<y<<endl;
}