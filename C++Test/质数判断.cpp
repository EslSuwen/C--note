#include<iostream.h>
#include<math.h>
void main()
{
	int n,i;
    cout<<"������һ����������";
	cin>>n;
	i=2;
	if(i<=n-1)
	{
       while(n%i!=0)
	   {
		   i++;
	   }
	   if(i==n)
		   cout<<""<<n<<"������\n";
	   else
		   cout<<""<<n<<"��������\n";
	
	}
	else
		cout<<"input error!"<<endl;
}