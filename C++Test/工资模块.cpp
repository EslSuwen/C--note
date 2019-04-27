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
	cout<<"\n            工资管理主模板 ";
	cout<<"\n           * 1.工资数据输出     *";
	cout<<"\n           * 2.工资数据修改     *";
	cout<<"\n           * 3.工资数据查询     *";
    cout<<"\n           * 4.工资数据统计输出 *";
	cout<<"\n           * 0.退出系统         *";
	cout<<"\n           ======================"  ;
	cout<<"\n          请输入你想选择的菜单项";
	cin>>choice;
	switch(choice)
	{
	  case 1: Sub_1();break;
	  case 2: Sub_2();break;
	  case 3: Sub_3();break;
	  case 4: Sub_4();break;
	  default:cout<<"\n无该选项,请重新输入:"<<'\n';
	}
  }
}
void Sub_1(void)
{
  cout<<"对不起，该模板暂未实现:";
  cin.get();
}
void Sub_2(void)
{
  cout<<"对不起，该模板暂未实现:";
  cin.get();
}
void Sub_3(void)
{
  cout<<"对不起，该模板暂未实现:";
  cin.get();
}
void Sub_4(void)
{
  cout<<"对不起，该模板暂未实现:";
  cin.get();
}
