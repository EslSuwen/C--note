#include<iostream>
using namespace std;
void main()
{
	int n, max, min, avg, sum, i=1;
	cin >> n;
	max=min=sum=avg=n;
	while (n >= 0)
	{
		cin >> n;
		i++;
		if(n<0)
			cout << "sum="<<sum <<"  max="<< max <<"  min=" << min << "  avg=" <<avg<< endl;
		if (n>max)
			max = n;
		if (n<min)
			min = n;
		sum = sum + n;
		avg = sum / i;	
	}
}