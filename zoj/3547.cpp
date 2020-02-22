#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<stdio.h>
#include<math.h>
#define ll long long
#define INF 2147483647
#define N 50
#define PI acos(-1)
#define EPS 1e-8
#define MAX 10000
#define mod 1000000007
using namespace std;


int prime[MAX],p[MAX+5],k,num[30];
ll sum,x,y,n;


void isprime()//筛选出素数
{
    k=0;
    memset(prime,0,sizeof(prime));
    for(ll i=2; i<=MAX; i++)
    {
        if(!prime[i])
        {
            p[k]=i;
            k++;
            for(ll j=i*i; j<MAX; j=j+i)
                prime[j]=1;
        }
    }
}
void Ex_gcd(ll a, ll b, ll &x, ll &y)//求逆元
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return;
    }
    ll x1, y1;
    Ex_gcd(b, a%b, x1, y1);
    x = y1;
    y = x1-(a/b)*y1;
}
ll n4(ll v)//n^4的用公式
{
    return v * (v  + 1) % mod * (v * 2 + 1) % mod * (v * v * 3 % mod + v * 3 - 1 + mod) % mod * x % mod;
}
void dfs(int cnt, ll p, int pos, ll s)//容斥原理
{
    if(cnt % 2 == 1)
        sum = (sum + n4(n / s) * s % mod * s % mod * s % mod * s % mod) % mod;
    else
        sum = (sum - n4(n / s) * s % mod * s % mod * s % mod * s % mod + mod) % mod;
    for(int i = pos; i < p; ++i)
        dfs(cnt + 1, p, i + 1, s * num[i] % mod);
}
int main()
{
    isprime();
    Ex_gcd(30,mod,x,y);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int tmp=n;
        sum=n4(n);
        int top=0;
        for(int i=0; i<k; i++)
        {
            if(p[i]>tmp)
                break;
            if(tmp%p[i]==0)
                num[top++]=p[i];
            while(tmp%p[i]==0)
                tmp=tmp/p[i];
        }
        if(tmp>1)
            num[top++]=tmp;
        for(int i=0; i<top; i++)
            dfs(0, top, i + 1, num[i]);
        cout<<sum<<endl;
    }
    return 0;
}