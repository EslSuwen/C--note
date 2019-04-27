#include <iostream>
using namespace std;
#include <math.h> //用到了求绝对值的函数abs
#include <stdio.h>
//迷宫地图
//X: 墙壁，小狗不能进入
//S: 小狗所处的位置
//D: 迷宫的门
//. : 空的方格
char map[9][9];
int n, m, t, di, dj; //(di,dj):门的位置
bool escape;
int dir[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}}; //分别表示下、上、左、右四个方向

//表示起始位置为(si,sj)，要求在第cnt秒达到门的位置
void dfs(int si, int sj, int cnt)
{
    int i, temp;
    if (si > n || sj > m || si <= 0 || sj <= 0)
        return;
    if (si == di && sj == dj && cnt == t)
    {
        escape = 1;
        return;
    }
    //abs(x-ex)+abs(y-ey)表示现在所在的格子到目标格子的距离(不能走对角线)
    //t-cnt是实际还需要的步数，将他们做差
    //如果temp < 0或者temp为奇数，那就不可能到达！
    temp = (t - cnt) - abs(si - di) - abs(sj - dj);
    if (temp < 0 || temp % 2)
        return;

    for (i = 0; i < 4; i++)
    {
        if (map[si + dir[i][0]][sj + dir[i][1]] != 'X')
        {
            map[si + dir[i][0]][sj + dir[i][1]] = 'X';

            dfs(si + dir[i][0], sj + dir[i][1], cnt + 1);

            if (escape)
                return;

            map[si + dir[i][0]][sj + dir[i][1]] = '.';
        }
    }
    return;
}

int main()
{

    int i, j, si, sj; //循环变量及小狗的起始位置
    while (scanf("%d%d%d", &n, &m, &t))
    {
        if (n == 0 && m == 0 && t == 0)
            break; //测试数据结束
        int wall = 0;
        char temp;
        scanf("%c", &temp); //见备注
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= m; j++)
            {
                scanf("%c", &map[i][j]);
                if (map[i][j] == 'S')
                {
                    si = i;
                    sj = j;
                }
                else if (map[i][j] == 'D')
                {
                    di = i;
                    dj = j;
                }
                else if (map[i][j] == 'X')
                    wall++;
            }
            scanf("%c", &temp);
        }
        if (n * m - wall <= t) //搜索前的剪枝
        {
            printf("NO\n");
            continue;
        }
        escape = 0;
        map[si][sj] = 'X';
        dfs(si, sj, 0);
        if (escape)
            printf("YES\n"); //成功逃脱
        else
            printf("NO\n");
    }
    return 0;
}