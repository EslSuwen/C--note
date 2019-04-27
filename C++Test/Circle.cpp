//利用半径求圆的周长及面积的近似值
#include<iostream.h>
#include<math.h>
void main()
{
	double r,c,s,pi;
	cout<<"请输入圆的半径"<<endl;
	cin>>r;
	pi=3.1415926;
	c=2*r*pi;
	s=r*r*pi;
	cout<<"周长c="<<c<<endl;
	cout<<"面积s="<<s<<endl;
}
