//迭代问题就是一个值一个值的试算！
#include<iostream.h>
void main()
{  int i,x;//x为最后分得的椰子值
   double y,y1;//y，y1分别表示上一个水手看到的椰子数、某水手.......
   x=1;
   y1=5*x+1;
   i=1;
   while(i<=5)
   {  
	   y=5*y1/4+1;
	   i++;
	   y1=y;
	   if(y!=int(y))//如果不满足就重算，x加一
	   { 
		 x++;
	     i=1;
         y1=5*x+1;
	   }
   }
cout<<"椰子一共有"<<y<<endl;
}