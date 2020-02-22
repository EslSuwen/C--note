/*
 * @Coding: utf-8 \n
 * @Despcription:  \n
 * @Author: Suwen HS\n
 * @LastEditors: Suwen HS\n
 * @Date: 2019-03-17 21:25:39
 * @LastEditTime: 2019-03-18 10:32:39
 */
//https://www.zhihu.com/question/23995189/answer/613096905
/* #include <iostream>
#include <stdio.h>
using namespace std;
int main()

{
    int f[105] = {0}, a[105] = {0}, i, x, p, n, ans = 0;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin>>a[i], f[i] = 1;
    }
    for (x = 1; x <= n; x++)
    {
        for (p = 1; p < x; p++)
        {
            if (a[p] < a[x])
                f[x] = max(f[x], f[p] + 1);
        }
        printf("f[%d]=%d\n", x, f[x]);
    }
    for (x = 1; x <= n; x++)
        ans = max(ans, f[x]);
    cout << "ans=" << ans << endl;
    return 0;
} */
#include <iostream>
using namespace std;
const int MAXN = 1000 + 10;
int n, Data[MAXN];
int dp[MAXN];
int from[MAXN];
void output(int x)
{
    if (!x)
        return;
    output(from[x]);
    cout << Data[x] << " ";
    //迭代输出
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> Data[i];

    // DP
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1;
        from[i] = 0;
        for (int j = 1; j < i; j++)
            if (Data[j] < Data[i] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                from[i] = j; //逐个记录前驱
            }
    }

    int ans = dp[1], pos = 1;
    for (int i = 1; i <= n; i++)
        if (ans < dp[i])
        {
            ans = dp[i];
            pos = i; //由于需要递归输出
                     //所以要记录最长上升子序列的最后一
                     //个元素，来不断回溯出路径来
        }
    cout << ans << endl;
    output(pos);

    return 0;
}