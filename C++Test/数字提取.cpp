#include<iostream.h>
void main()
{
	int x1,x2,x3;
	char ch;
	x1=x2=x3=0;
	cout<<"ÊäÈëÒ»¸ö×Ö·û´®£º";
	while((ch=cin.get())!='\n')
	{
		if(ch>='0'&&ch<='9')
			cout<<ch;
		else
			cout<<" ";
	}
}