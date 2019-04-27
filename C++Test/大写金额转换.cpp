#include<iostream>  
#include<string>  
#include<cstring>  
#include<stdio.h>  
#include<memory.h>  
using namespace std;  
  
string uper1[10]={"零","壹","贰","叁","肆","伍","陆","柒","捌","玖"};//从0到9十个数字的大写   
string uper2[8]={"拾","佰","仟","万","拾万","佰万","仟万","亿"};//各种数量级的大写   
  
int main()  
{  
    char num[15];//用户输入的数据   
    int i,j,p=0;//p是一个指针，因为汉字没法存到一个字符当中，所以开辟了一个string[]，每个汉字是一个字符串   
    string result[20];//保存最终结果的数组   
    cin>>num;  
    int len=strlen(num);//获取输入的数字的长度   
    for(i=0;i<len;i++)//初步处理， 直接把每一个数字表示出来，比如10200500，直接输出 壹仟万零贰拾万零零伍佰零零  
    {                 //说白了就是直接输出每个数字的值加上数量级，注意如果一个数字是0，不需要输出它的数量级   
        result[p++]=uper1[(int)(num[i]-'0')];  
        if(num[i]!='0'&&len-i-2>=0)  
        result[p++]=uper2[len-i-2];  
    }  
    len=p;//保存预处理之后的结果的长度   
      
      
    for(i=0;i<len;i++)  
    {  
        cout<<result[i];  
    }  
    cout<<endl;  
    bool *flag=new bool[len];//给每一位数定义一个标志位，true就输出，false就不输出  
      
       
    for(i=0;i<len;i++)//初始化flag   
    flag[i]=true;  
      
      
      
    for(i=len-1;i>=0&&result[i]=="零";i--)//针对1234000这种最后一位是0并且可能有连续多个0的情况，这时候只读从后往前数   
    flag[i]=false;                        //第一个不为0的数和它的数量级，就是4千   
      
    for(;i>0;i--)//经过了上一步后，只是去除了尾部的连续多个0，现在要从上一步停止的地方继续，扫描是否有连续多个   
    {            //0的存在，如果有，只保留一个   
        if(result[i]=="零"&&result[i-1]=="零")  
        flag[i]=false;  
    }  
      
      
    if(num[4]!='0'||num[5]!='0'||num[6]!='0'||num[7]!='0')//如果万位，十万位，百万位，千万位有一个不是0，那么这个万字肯定要读   
    {                                                     //所以就从后往前数，保留第一个万字，其余的都删掉   
        for(i=len-1;i>=0&&result[i]!="万";i--){}  
          
        for(i=i-1;i>=0;i--)  
        {  
            if(result[i]=="万")  
            flag[i]=false;  
            if(result[i]=="拾万")  
            result[i]="拾";  
            if(result[i]=="佰万")  
            result[i]="佰";  
            if(result[i]=="仟万")  
            result[i]="仟";  
        }  
    }  
    else//如果不需要读万字，那就把所有的万字都删掉   
    {  
        for(i=len-1;i>=0;i--)  
        if(result[i]=="万")  
        flag[i]=false;  
        if(result[i]=="拾万")  
        result[i]="拾";  
        if(result[i]=="佰万")  
        result[i]="佰";  
        if(result[i]=="仟万")  
        result[i]="仟";  
    }  
      
      
      
    for(i=0;i<len;i++)//可以输出了   
    {  
        if(flag[i])  
        cout<<result[i];  
    }  
    cout<<endl;  
      
    return 0;  
}  