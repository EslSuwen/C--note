#include<iostream.h>
#include<math.h>
double ex(double x);
void main()
{
	double x;
	cout<<"请输入想要的e的次方数:\n";
	cout<<"x="; cin>>x;
	cout<<"e^"<<x<<"="<<ex(x)<<endl;
}
double ex(double x)
{
	double t=x,sum=1,i=1;

	while (fabs(t)>1.0e-8)
	{  
	sum+=t;
	t=t*x/i;
	i++;
	}
	return sum;
}