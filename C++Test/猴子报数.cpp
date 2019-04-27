//一群猴子围坐一圈，编号依次为了，1，2，3，4...n，从1号猴子开始报数，
//报到m的猴子退出圈子，然后退出猴子的下一只开始依次从1报数，报到m再退出
//依此类推，直到圈中的猴子只剩一只为止。输入n和m，输出最后剩下的这只猴子的编号。
#include <iostream.h>
void main()
{
	int x[1000];
	int m,n,i;
	int count;
	cout<<"猴子数量为：";
	cin>>m;
	cout<<"报的数字为：";
	cin>>n;
	count=m;
	for(i=0;i<m;i++)
		x[i]=1;
	int k=0;
	i=0;
	while(count>1)
	{
		k=k+x[i];
		if(k==n)
		{
			x[i]=0;
			count--;
			k=0;
		}
		i=(i+1)%m;
	}
	for(i=0;i<m;i++)
	{
		if(x[i]==1)
			cout<<"最后剩下的猴子是第"<<i+1<<"只猴子"<<endl;
	}
}
