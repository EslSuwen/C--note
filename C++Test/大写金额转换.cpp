#include<iostream>  
#include<string>  
#include<cstring>  
#include<stdio.h>  
#include<memory.h>  
using namespace std;  
  
string uper1[10]={"��","Ҽ","��","��","��","��","½","��","��","��"};//��0��9ʮ�����ֵĴ�д   
string uper2[8]={"ʰ","��","Ǫ","��","ʰ��","����","Ǫ��","��"};//�����������Ĵ�д   
  
int main()  
{  
    char num[15];//�û����������   
    int i,j,p=0;//p��һ��ָ�룬��Ϊ����û���浽һ���ַ����У����Կ�����һ��string[]��ÿ��������һ���ַ���   
    string result[20];//�������ս��������   
    cin>>num;  
    int len=strlen(num);//��ȡ��������ֵĳ���   
    for(i=0;i<len;i++)//�������� ֱ�Ӱ�ÿһ�����ֱ�ʾ����������10200500��ֱ����� ҼǪ���㷡ʰ�������������  
    {                 //˵���˾���ֱ�����ÿ�����ֵ�ֵ������������ע�����һ��������0������Ҫ�������������   
        result[p++]=uper1[(int)(num[i]-'0')];  
        if(num[i]!='0'&&len-i-2>=0)  
        result[p++]=uper2[len-i-2];  
    }  
    len=p;//����Ԥ����֮��Ľ���ĳ���   
      
      
    for(i=0;i<len;i++)  
    {  
        cout<<result[i];  
    }  
    cout<<endl;  
    bool *flag=new bool[len];//��ÿһλ������һ����־λ��true�������false�Ͳ����  
      
       
    for(i=0;i<len;i++)//��ʼ��flag   
    flag[i]=true;  
      
      
      
    for(i=len-1;i>=0&&result[i]=="��";i--)//���1234000�������һλ��0���ҿ������������0���������ʱ��ֻ���Ӻ���ǰ��   
    flag[i]=false;                        //��һ����Ϊ0����������������������4ǧ   
      
    for(;i>0;i--)//��������һ����ֻ��ȥ����β�����������0������Ҫ����һ��ֹͣ�ĵط�������ɨ���Ƿ����������   
    {            //0�Ĵ��ڣ�����У�ֻ����һ��   
        if(result[i]=="��"&&result[i-1]=="��")  
        flag[i]=false;  
    }  
      
      
    if(num[4]!='0'||num[5]!='0'||num[6]!='0'||num[7]!='0')//�����λ��ʮ��λ������λ��ǧ��λ��һ������0����ô������ֿ϶�Ҫ��   
    {                                                     //���ԾʹӺ���ǰ����������һ�����֣�����Ķ�ɾ��   
        for(i=len-1;i>=0&&result[i]!="��";i--){}  
          
        for(i=i-1;i>=0;i--)  
        {  
            if(result[i]=="��")  
            flag[i]=false;  
            if(result[i]=="ʰ��")  
            result[i]="ʰ";  
            if(result[i]=="����")  
            result[i]="��";  
            if(result[i]=="Ǫ��")  
            result[i]="Ǫ";  
        }  
    }  
    else//�������Ҫ�����֣��ǾͰ����е����ֶ�ɾ��   
    {  
        for(i=len-1;i>=0;i--)  
        if(result[i]=="��")  
        flag[i]=false;  
        if(result[i]=="ʰ��")  
        result[i]="ʰ";  
        if(result[i]=="����")  
        result[i]="��";  
        if(result[i]=="Ǫ��")  
        result[i]="Ǫ";  
    }  
      
      
      
    for(i=0;i<len;i++)//���������   
    {  
        if(flag[i])  
        cout<<result[i];  
    }  
    cout<<endl;  
      
    return 0;  
}  