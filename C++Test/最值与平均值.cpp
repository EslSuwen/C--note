#include<iostream.h>
void main()
{
	double max,min,n,i=1,sum=0,avg,m;
	max=-0x7FFFFFFF;
	min=0x7FFFFFFF;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>m;
		if(m>max)
			max=m;
		if(m<min)
			min=m;
		sum+=m;
	}
	avg=sum/n;
	cout<<"max="<<max<<"  min="<<min<<"  avg="<<avg<<endl;
}