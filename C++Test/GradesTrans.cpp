#include<iostream.h>
void main()
{
	int s;
	cout<<"�����뿼�Գɼ�:"<<endl;
	cin>>s;
	if(s>=0&&s<=100)
	{
		switch(s/10)
		{

		    case 10:cout<<"��\n";break;
            case 9:cout<<"��\n";break;
		    case 8:cout<<"��\n";break;
		    case 7:cout<<"��\n";break;
		    case 6:cout<<"����\n";break;
		    default:cout<<"������"<<endl;
		}
	}
	else
		cout<<"inter error!\n";
}