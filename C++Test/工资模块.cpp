#include <iostream.h>
void Sub_1(void);
void Sub_2(void);
void Sub_3(void);
void Sub_4(void);
void main()
{
  int choice=1;
  while(choice>0)
  {
    cout<<"\n           ======================";
	cout<<"\n            ���ʹ�����ģ�� ";
	cout<<"\n           * 1.�����������     *";
	cout<<"\n           * 2.���������޸�     *";
	cout<<"\n           * 3.�������ݲ�ѯ     *";
    cout<<"\n           * 4.��������ͳ����� *";
	cout<<"\n           * 0.�˳�ϵͳ         *";
	cout<<"\n           ======================"  ;
	cout<<"\n          ����������ѡ��Ĳ˵���";
	cin>>choice;
	switch(choice)
	{
	  case 1: Sub_1();break;
	  case 2: Sub_2();break;
	  case 3: Sub_3();break;
	  case 4: Sub_4();break;
	  default:cout<<"\n�޸�ѡ��,����������:"<<'\n';
	}
  }
}
void Sub_1(void)
{
  cout<<"�Բ��𣬸�ģ����δʵ��:";
  cin.get();
}
void Sub_2(void)
{
  cout<<"�Բ��𣬸�ģ����δʵ��:";
  cin.get();
}
void Sub_3(void)
{
  cout<<"�Բ��𣬸�ģ����δʵ��:";
  cin.get();
}
void Sub_4(void)
{
  cout<<"�Բ��𣬸�ģ����δʵ��:";
  cin.get();
}
