#include<iostream.h>
void main()
{
	int s;
	cout<<"请输入考试成绩:"<<endl;
	cin>>s;
	if(s>=0&&s<=100)
	{
		switch(s/10)
		{

		    case 10:cout<<"优\n";break;
            case 9:cout<<"优\n";break;
		    case 8:cout<<"良\n";break;
		    case 7:cout<<"中\n";break;
		    case 6:cout<<"及格\n";break;
		    default:cout<<"不及格"<<endl;
		}
	}
	else
		cout<<"inter error!\n";
}