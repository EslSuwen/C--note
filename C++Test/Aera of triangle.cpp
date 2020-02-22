//利用三角形三边求三角形面积
#include<iostream.h>
#include<math.h>
void main()
{
	double a,b,c,p,s;
	cout<<"请输入三角形三边"<<endl;
	cin>>a>>b>>c;
	p=(a+b+c)/2;
	s=sqrt(p*(p-a)*(p-b)*(p-c));
	if(a+b>c&&b+c>a&&a+c>b)
		cout<<"面积s="<<s<<endl; 
	else
		cout<<"请输入正确三角形三边"<<endl;
}