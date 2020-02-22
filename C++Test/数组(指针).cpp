#include<iostream.h>
#include<iomanip.h>
const int N=100;
void array_in(double *,int);
void array_out(double *,int);
double average(double *,int);
double max(double *,int);
double min(double *,int);
void inversion(double *,int);
void sort(double *,int);
void main()
{
 double x[N];
 int n;
 double aver,a,b;
 cout<<"请输入数组个数（1-100）";
 cin>>n;
 array_in(x,n);
 array_out(x,n);
 /*aver=average(x,n);
 cout<<"平均值="<<aver<<"\n";endl;
 a=max(x,n);
 cout<<"最大值="<<a<<endl;
 b=min(x,n);
 cout<<"最小值="<<b<<endl;
 cout<<"倒置后输出"<<endl;
 inversion(x,n);
 array_out(x,n);
 cout<<"排序后输出"<<endl;
 sort(x,n);
 array_out(x,n);
}*/
void array_in(double *array ,int n)
{
 int i;
 for(i=0;i<n;i++)
 {
  cout<<"array["<<i<<"]=";
  cin>>*array++;
 }
}
void array_out(double *array,int n)
{
 int i;
 for(i=0;i<n;i++)
 {
  if(i%5==0)
  cout<<endl;
  cout<<setw(5)<<*p++;
 }
 cout<<endl;
}
/*double average(double array[],int n)
{
 double sum,average;
 int i;
 sum=0;
 for(i=0;i<n;i++)
 sum+=array[i];
 average=sum/n;
 return average;
}
double max(double array[],int n)
{
 double max;
 int i;
 max=array[0];
 for(i=0;i<n;i++)
  if(max<array[i])
  max=array[i];
  return max;

}
double min(double array[],int n)
{
 double min;
 int i;
 min=array[0];
 for(i=0;i<n;i++)
 if(min>array[i])
  min=array[i];
 return min;*/
}
void inversion(double *array,int n)
{
 int i;
 double temp,*p1,*p2;
 p1=p1=array;
 for(i=0;i<n-1;i++)
    p2++;
 while(p2>p1)
 {
  temp=*p1;*p1=*p2;*p2=temp;
  pi++;p2--;
 }
void sort(double *array,int n)
{
  int i,j;
  double t,*p1,*p2;
  p1=array;
  for(i=0;i<n-1;i++)
  {
     p2=p1+1;
     for(j=i+1;j<n;j++)
	 {   
		 if(*p1<*p2)
		 {
		   t=*p1;*p1=*p2;*p2=t;
		 }
		 p2++;
	 }
	 p1==;
  }
} 
