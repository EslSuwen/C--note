#include<iostream.h>
void main()
{  
	int i,x;
	double y,y1;
	x=1;
	y1=5*x+1;
	i=1;
	while(i<=4)
	{  
		y=5*y1/4+1;
		i++;
		y1=y;
		if(y!=int(y))
		{ 
			x++;
			i=1;
			y1=5*x+1;
		}
	}
	cout<<"椰子一共有:"<<y<<endl;
}