#include<iostream.h>
void main()
{
  char ch;
  int n1,n2,n3;
  n1=n2=n3=0;
  cout<<"ÇëÊäÈëÒ»´®×Ö·û£¬#½áÊø! \n";
  while(1)
  {
	ch=cin.get();
	if(ch=='#')
		break;
	if(ch>='A'&&ch<='Z'||ch>'a'&&ch<='z')
		n1++;
	else if(ch>='0'&&ch<='9')
		n2++;
	else
	    n3++;
  }
  cout<<"×ÖÄ¸:"<<n1<<"Êý×Ö£º"<<n2<<" ÆäËû·ûºÅ£º"<<n3<<endl;
}
