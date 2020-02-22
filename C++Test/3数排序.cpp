//��������������������
#include<iostream>
void main()
{
  double x,y,z,temp;
  cout<<"������������:\n";
  cout<<"x="; cin>>x;
  cout<<"y="; cin>>y;
  cout<<"z="; cin>>z;
  if(x<y)
  {temp=x;x=y;y=temp;}
  if(x<z)
  {temp=x;x=z;z=temp;}
  if(y<z)
  {temp=y;y=z;z=temp;}
  cout<<x<<" "<<y<<" "<<z<<endl;
}