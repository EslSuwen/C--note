/*
 * @Author: Suwen
 * @Description:  
 * @LastEditors: Suwen
 * @Date: 2019-02-20 09:29:55
 * @LastEditTime: 2019-02-20 09:32:35
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class AClass
{
public:
    int num;
    string name;
};
struct AStruct 
{
    int num;
    string name;
};
void TestStruct()
{
 //类的使用
    AClass Ac;
    vector<AClass> vc;
    Ac.num=10;
    Ac.name="name";
    vc.push_back(Ac);
    AClass d;  
    for (vector<AClass>::iterator it=vc.begin();it<vc.end();++it)  
    {  
        d=*it;  
        // cout<<it->num<<endl; 
    } 
 //结构体的使用
    AStruct As;
    vector<AStruct> vs;
    As.num=10;
    As.name="name";
    vs.push_back(As);
    AStruct ds;  
    for (vector<AStruct>::iterator it=vs.begin();it<vs.end();++it)  
    {  
        ds=*it;  
        cout<<ds.num<<endl; 
    } 
}
void TestPoint()
{
 //类的使用
    AClass *Ac=new AClass;
    vector<AClass *> vc;
    Ac->num=10;
    Ac->name="name";
    vc.push_back(Ac);
    AClass *d;  
    for (vector<AClass*>::iterator it=vc.begin();it<vc.end();++it)  
    {  
        d=*it;  
        cout<<d->num<<endl; 
    } 
}
int main()
{
    TestStruct();
    TestPoint();
    getchar();
    return 0;
}
