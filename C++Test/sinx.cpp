#include<iostream.h>
#include<math.h>
#define PI 3.1415926
double sinx(double);
void main()
{
	double a,x;
	cout<<"输入一个角度:";
	cin>>x;
	x=x/180*PI;
	a=sinx(x);
	cout<<"sinx="<<a<<endl;
}
double sinx(double x)
{
	double sin,m,z,n;
	sin=0;
	z=x;
	n=1;
	for(m=1;fabs(z/n)>=1.0e-7; m=m+2)
	{
		sin=sin+z/n;
		z=-z*x*x;
		n*=(m+1)*(m+2);
	}
	return sin;
}