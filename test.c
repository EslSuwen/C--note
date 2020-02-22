/*
 * @Coding: utf-8 \n
 * @Despcription:  \n
 * @Author: Suwen SP \n
 * @Date: 2019-10-12 11:41:57
 * @LastEditors: Suwen SP\n
 * @LastEditTime: 2019-10-12 11:42:25
 */
#include<stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct pcb
{
  int name;
  int needtime;
  int arrivetime;
  int pri;
  int state;
  int cputime;
}plist;
void action(plist * nowpro);
void action(plist * nowpro)
{
   delay(1000);
   printf("now is process %d    ",nowpro->name);
   nowpro->needtime--;
   if(nowpro->needtime==0)
   {
     printf(" the process %d is end\n",nowpro->name);
    /* nowpro->state=1;  */
    printf("-----------------------------\n");
   }
   else
   {
     printf("process %d needtime is %d\n",nowpro->name,nowpro->needtime);
     printf("-----------------------------\n");
   }
}
 void  creatpro(int n,plist * process )
{
   int j;
   for(j=0;j<n;j++)
   {
     process[j].name= j;
     process[j].needtime=rand()%10+1;
     process[j].arrivetime=rand()%10;
     process[j].pri=rand()%4;
     process[j].state=0;
     process[j].cputime=0;
   }
}
void show( int n,plist * process)
{
    int j;
    for (j=0 ;j<n;j++)
    {
       printf("name of process%d\t",process[j].name);
       printf("needtime %d\t",process[j].needtime);
       printf("arrivetime %d\t",process[j].arrivetime);
       printf("pri %d\n",process[j].pri);
       printf("state %d\t",process[j].state);
       printf("cputime %d\n",process[j].cputime);
    }
}
int main()
{
   void  creatpro(int n,plist * process );
   void show( int n,plist * process);
   void fcfs(int n,plist * process);
   void sjf(int n,plist * process);
   void rr(int n,plist * pro1);
   void hrrn(int n,plist * pro1);
   int n;  /*the number of process*/
   int k;
   plist process[10];
   printf("please input the number of process from 0 to 10\n");
   scanf("%d",&n);
   creatpro(n,process);
   show(n,process);
    printf("please choose the what you want to use\n");
    printf("1 FCFS\t 2 SJF\t 3 HRRN\t 4 RR\n");
    scanf("%d",&k);
    switch(k)
    {
      case 1:  fcfs(n,process);     break;
      case 2:  sjf(n,process);      break;
      case 3:  hrrn(n,process);     break;
      case 4:  rr(n,process);       break;
      default : break;
    }
   return 0;
}
void fcfs(int n,plist * pro1)
{
   void show( int n,plist * process);

   int i,j,k;
   int m=0;
   int time;
   plist temp;
   plist pro2[10];
   for(i=0;i<n;i++)
   {
      k=0;
     while(pro1[k].state==1)
     {
         k++;
     }
     temp=pro1[k];
     for(j=k+1;j<n;j++)
     {
       if(temp.arrivetime>pro1[j].arrivetime&&pro1[j].state!=1)
       {
          temp=pro1[j];
          k=j;
       }
     }
     pro2[m++]=temp;
     pro1[k].state=1;
   }
   show(n,pro2);
   for(i=0;i<n;i++)
   {
      while(pro2[i].needtime>0)
      {
         action(&pro2[i]);
      }
   }
}
void sjf(int n,plist * pro1)
{
   void show( int n,plist * process);
   int i,j,k;
   int m=0;
   plist temp;
   plist pro2[10];
   for(i=0;i<n;i++)
   {
     k=0;
     while(pro1[k].state==1)
     {
        k++;
     }
     temp=pro1[k];
     for(j=k+1;j<n;j++)
     {
        if(temp.needtime>pro1[j].needtime&&pro1[j].state!=1)
       {
          temp=pro1[j];
          k=j;
       }
     }
     pro2[m++]=temp;
     pro1[k].state=1;
   }
   show(n,pro2);
   for(i=0;i<n;i++)
   {
      while(pro2[i].needtime>0)
      {
         action(&pro2[i]);
      }
   }
}
void rr(int n,plist * pro1)
{
  void show( int n,plist * process);

   int i,j,k;
   int m=0;
   int time;
   plist temp;
   plist pro2[10];
   for(i=0;i<n;i++)
   {
      k=0;
     while(pro1[k].state==1)
     {
         k++;
     }
     temp=pro1[k];
     for(j=k+1;j<n;j++)
     {
       if(temp.arrivetime>pro1[j].arrivetime&&pro1[j].state!=1)
       {
          temp=pro1[j];
          k=j;
       }
     }
     pro2[m++]=temp;
     pro1[k].state=1;
   }
   show(n,pro2);
   time=pro2[0].needtime;
   for(i=0;i<n;i++)
   {
      if(time<pro2[i].needtime)
      {
         time=pro2[i].needtime;
      }
   }
   while(time>0)
   {
      for(i=0;i<n;i++)
      {
          if(pro2[i].needtime>0)
          {
            action(&pro2[i]);
          }
      }
      time--;
   }
}
void hrrn(int n,plist * pro1)
{

    int cal(int a ,plist * pro2);
    int i,k,j,m;
    int curtime=0;
    plist temp;
    for(i=0;i<n;i++)
    {
       k=0;
     while(pro1[k].state==1)
     {k++;}
      temp=pro1[k];
     m=cal(curtime,&temp);
      for(j=0;j<n;j++)
      {

         if(pro1[j].state!=1)
        {
           pro1[j].pri=cal(curtime,&pro1[j]);
           if(m>pro1[j].pri)
           {
              temp=pro1[j];
              m=pro1[j].pri;
              k=j;
           }
         }
      }

      while(pro1[k].needtime>0)
      {
         action(&pro1[k]);
         curtime++;
      }
      pro1[k].state=1;

    }
}

int cal(int a ,plist * pro2)
 {
     int pr;
     if((a-pro2->arrivetime)<=0)
     { pr=1;   }
      else
     {

            pr=(a-pro2->arrivetime+pro2->needtime)/pro2->needtime;
     }
     return pr;
 }