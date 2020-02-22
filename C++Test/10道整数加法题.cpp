#include"iostream"
#include"stdlib.h"
#include"stdio.h"
using namespace std;
void main()
{
	char ch;
	ch='y';
	while(ch=='y'||ch=='Y')
	{
		int i,j,x,n,x1,x2,score=0;
		cout<<"Plesae enter any number:";
		cin>>n;
		for(i=1;i<=10;i++)
		{
			srand(n);
			x1=rand()%n;
			x2=rand()%n;
			for(j=1;j<=5;j++)
			{
				cout<<"µÚ"<<i<<"Ìâ:"<<endl;
				cout<<x1<<"+"<<x2<<"=";
				cin>>x;
				if(x==x1+x2&&j==1)
				{
					cout<<"Right!\n";
					score+=10;
					break;
				}
				else if(x==x1+x2)
				{
					cout<<"Right!\n";
					break;
				}
				else if(x!=x1+x2&&j==1)
				{
					cout<<"False!\n";
					score-=10;
				}
				else
					cout<<"False!\n";
			}
		}
		cout<<"score="<<score<<endl;
		cout<<"\nWhether to continue?£¨y/n£©?\n";
		cin>>ch;
	}
}