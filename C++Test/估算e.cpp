#include<iostream.h>
#include<math.h>
double suane(double);
void main()
{
  int e;
  e=1;
  cout<<"eµÄÖµÎª£º";
  cout<<"e="<<suane(e)<<endl;
}
double suane(double e)   
{
	double m,z,j;
	m=1; z=e;
	j=1;
	for(m=1;fabs(z/m)>1.0e-7;m++)
	{ 
	  m*=m;
	  j+=z/m;
	}
	return j;
}