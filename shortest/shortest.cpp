#include "shortestpath.h"

shortestpath::shortestpath()
{
    for(int i=0;i<25;i++)
    {
        for(int j=0;j<25;j++)
        {
            P[i][j]=false;
            for(int m=0;m<25;m++)
            {
                P1[i][j][m]=false;
            }
        }
    }
   starcity="";
   overcity="";
   G.city[0]= "jiangjin";
   G.city[1]="qijiang";
   G.city[2]="nanchuan";
   G.city[3]="changshou";
   G.city[4]="dianjiang";
   G.city[5]="fuling";
   G.city[6]="wulong";
   G.city[7]="xiushan";
   G.city[8]="penshui";
   G.city[9]="youyang";
   G.city[10]="qianjiang";
   G.city[11]="fengdu";
   G.city[12]="shizhu";
   G.city[13]="zhongxian";
   G.city[14]="yunyang";
   G.city[15]="wanzhou";
   G.city[16]="wushan";
   G.city[17]="fengjie";
   G.city[18]="wuxi";
   G.city[19]="chengkou";
   G.city[20]="liangping";
   G.city[21]="kaixian";
   G.city[22]="hechuan";
   G.city[23]="yongchuan";
   G.city[24]="rongchang";
   G.arcnum = 20;
    G.vexnum = 25;
    for (int i = 0; i<25; i++)
    {
        for (int j = 0; j<25; j++)
        {
            if ((i == 0 && j == 1)||(i==1 && j==0))
            {
                G.arcs[0][1].path = 68;
                G.arcs[1][0].path = 68;
            }
            else if ((i == 0 && j== 2) || (i == 2 && j == 0))
            {
                G.arcs[i][j].path = 102;
                G.arcs[j][i].path = 102;
            }
         /*   else if ((i == 0 && j == 20) || (i == 20 && j == 0))
            {
                G.arcs[i][j].path = 370;
                G.arcs[i][j].path = 370;
            }*/
            else if ((i == 1 && j == 2) || (i == 2 && j == 1))
            {
                G.arcs[i][j].path = 36;
                G.arcs[j][i].path = 36;
            }
            else if ((i == 2 && j == 5) || (i == 5 && j == 2))
            {
                G.arcs[i][j].path = 97;
                G.arcs[j][i].path = 97;
            }
  /*          else if ((i == 2 && j == 3) || (i == 3 && j == 2))
            {
                G.arcs[i][j].path = 117;
                G.arcs[j][i].path = 117;
            }*/
            else if ((i == 3 && j == 4) || (i == 4 && j == 3))
            {
                G.arcs[i][j].path = 68;
                G.arcs[j][i].path = 68;
            }
            else if ((i == 3 && j == 5) || (i == 5 && j == 3))
            {
                G.arcs[i][j].path = 42;
                G.arcs[j][i].path = 42;
            }
            else if ((i == 4 && j == 20) || (i == 20 && j == 4))
            {
                G.arcs[i][j].path = 45;
                G.arcs[j][i].path = 45;
            }
            else if ((i == 6 && j == 5) || (i == 5 && j == 6))
            {
                G.arcs[i][j].path = 144;
                G.arcs[j][i].path = 144;
            }
  /*          else if ((i == 7 && j == 6) || (i == 6 && j == 7))
            {
                G.arcs[i][j].path = 255;
                G.arcs[j][i].path = 255;
            }*/
  /*          else if ((i == 5 && j == 8 )|| (i == 8 && j == 5))
            {
                G.arcs[i][j].path = 176;
                G.arcs[j][i].path = 176;
            }*/
            else if ((i == 5 && j == 11) || (i == 11 && j == 5))
            {
                G.arcs[i][j].path = 145;
                G.arcs[j][i].path = 145;
            }
            else if ((i == 9 && j == 8) || (i == 8 && j == 9))
            {
                G.arcs[i][j].path = 140;
                G.arcs[j][i].path = 140;
            }
            else if ((i == 8 && j == 10) || (i == 10 && j == 8))
            {
                G.arcs[i][j].path = 86;
                G.arcs[j][i].path = 86;
            }
            else if ((i == 10 && j == 12) || (i == 12 && j == 10))
            {
                G.arcs[i][j].path = 199;
                G.arcs[j][i].path = 199;
            }
            else if ((i == 13 && j == 12) || (i == 12 && j == 13))
            {
                G.arcs[i][j].path = 58;
                G.arcs[j][i].path = 58;
            }
            else if ((i == 11 && j == 13) || (i == 13 && j == 11))
            {
                G.arcs[i][j].path = 88;
                G.arcs[j][i].path = 88;
            }
            else if ((i == 13 && j == 20) || (i == 20&& j == 13))
            {
                G.arcs[i][j].path = 79;
                G.arcs[j][i].path = 79;
            }
            else if ((i == 13 && j == 15) || (i == 15 && j == 13))
            {
                G.arcs[i][j].path = 96;
                G.arcs[j][i].path = 96;
            }
          /*  else if ((i == 12 && j == 14) || (i == 14 && j == 12))
            {
                G.arcs[i][j].path = 170;
                G.arcs[j][i].path = 170;
            }*/
            else if ((i == 16 && j == 14) || (i == 14 && j == 16))
            {
                G.arcs[i][j].path = 135;
                G.arcs[j][i].path = 135;
            }
            else if ((i == 16 && j == 17) || (i == 17 && j == 16))
            {
                G.arcs[i][j].path = 66;
                G.arcs[j][i].path = 66;
            }
            else if ((i == 16 && j == 18 )|| (i == 18 && j == 16))
            {
                G.arcs[i][j].path = 95;
                G.arcs[j][i].path = 95;
            }
            else if ((i == 18 && j == 19) || (i == 19&& j == 18))
            {
                G.arcs[i][j].path = 242;
                G.arcs[j][i].path = 242;
            }
  /*          else if ((i == 20 && j == 22) || (i == 22 && j == 20))
            {
                G.arcs[i][j].path = 245;
                G.arcs[j][i].path = 245;
            }*/
            else if ((i == 22 && j == 23) || (i == 23 && j == 22))
            {
                G.arcs[i][j].path = 123;
                G.arcs[j][i].path = 123;
            }
            else if ((i == 22 && j == 24) || (i == 24 && j == 22))
            {
                G.arcs[i][j].path = 110;
                G.arcs[j][i].path = 110;
            }
            else if ((i == 15 && j == 14) || (i == 14 && j == 15))
            {
                G.arcs[i][j].path = 68;
                G.arcs[j][i].path = 68;
            }
            else if ((i == 15 && j == 21) || (i == 21 && j == 15))
            {
                G.arcs[i][j].path = 64;
                G.arcs[j][i].path = 64;
            }
            else if ((i == 7 && j == 9) || (i == 9 && j == 7))
            {
                G.arcs[i][j].path = 61;
                G.arcs[j][i].path = 61;
            }
            else if ((i == 10 && j == 9) || (i == 9 && j == 10))
            {
                G.arcs[i][j].path = 102;
                G.arcs[j][i].path = 102;
            }
            else if ((i == 12 && j == 15) || (i == 15 && j == 12))
            {
                G.arcs[i][j].path = 124;
                G.arcs[j][i].path = 124;
            }
            else if ((i == 8 && j == 11) || (i == 11 && j == 8))
            {
                G.arcs[i][j].path = 162;
                G.arcs[j][i].path = 162;
            }
            else if ((i == 6 && j == 8) || (i == 8 && j == 6))
            {
                G.arcs[i][j].path = 97;
                G.arcs[j][i].path = 97;
            }
            else if ((i == 23 && j == 24) || (i == 23 && j == 24))
            {
                G.arcs[i][j].path = 41;
                G.arcs[j][i].path = 41;
            }
            else if ((i == 0 && j == 23) || (i == 23 && j == 0))
            {
                G.arcs[i][j].path = 71;
                G.arcs[j][i].path = 71;
            }
            else if ((i == 2 && j == 22) || (i == 22 && j == 2))
            {
                G.arcs[i][j].path = 155;
                G.arcs[j][i].path = 155;
            }
            else if ((i == 3 && j == 22) || (i == 22 && j == 3))
            {
                G.arcs[i][j].path = 131;
                G.arcs[j][i].path = 131;
            }
            else if ((i == 20 && j == 21) || (i == 21 && j == 20))
            {
                G.arcs[i][j].path = 135;
                G.arcs[j][i].path = 135;
            }
            else if ((i == 19 && j == 21) || (i == 21 && j == 19))
            {
                G.arcs[i][j].path = 210;
                G.arcs[j][i].path = 210;
            }
            else if ((i == 14 && j == 17) || (i == 17 && j == 14))
            {
                G.arcs[i][j].path = 85;
                G.arcs[j][i].path = 85;
            }
            else if ((i == 14 && j == 21) || (i == 21 && j == 14))
            {
                G.arcs[i][j].path = 67;
                G.arcs[j][i].path = 67;
            }
    /*        else if ((i == 22 && j == 21) || (i == 21 && j == 22))
            {
                G.arcs[i][j].path = 279;
                G.arcs[j][i].path = 279;
            }*/
            else
                G.arcs[i][j].path = 999999;
        }
    }
}
void shortestpath::StortPath(MGraph G, QString s, QString *p,bool P[25][25], int *D)
{
    int v;
    for (int j = 0; j < 25; j++)
    {
        if (s == p[j])
            v = j;
    }
    bool final[25];
    for (int m = 0; m<G.vexnum; ++m)
    {
        final[m] = false;
        D[m] = G.arcs[v][m].path;
        for (int w = 0; w<G.vexnum; ++w) { P[m][w] = false; }
        if (D[m] < 999999) { P[m][v] = true; P[m][m] = true; }
    }
    D[v] = 0; final[v] = true;
    int c;
    for (int i = 1; i<G.vexnum; ++i)
    {
        int min = 999999;
        for (int m = 0; m<G.vexnum; ++m)
        {
            if (!final[m])
            {
                if (D[m]<min) { c = m; min = D[m]; }
            }
        }
        final[c] = true;
        for (int m = 0; m < G.vexnum; m++)
        {
            if (!final[m] && ((min + G.arcs[c][m].path) < D[m]))
            {
                D[m] = min + G.arcs[c][m].path;
                for (int i = 0; i < G.vexnum; i++)
                {
                  P[m][i] = P[c][i];
                }
                P[m][m] = true;
            }
        }
    }
}
void shortestpath::StortPath1(MGraph G,bool p[][25][25], int d[][25])
{
    for (int v = 0; v < G.vexnum; v++)
    {
        for (int w = 0; w < G.vexnum; w++)
        {
            d[v][w] = G.arcs[v][w].path;
            for (int u = 0; u < G.vexnum; u++)  p[v][w][u] = false;
            if (d[v][w] < 999999)
            {
                p[v][w][v] = true;  p[v][w][w] = true;
            }
        }
    }
    for (int u = 0; u < G.vexnum; u++)
    {
        for (int v = 0; v < G.vexnum; v++)
        {
            for (int w = 0; w < G.vexnum; w++)
            {
                if (d[v][u] + d[u][w] < d[v][w])
                {
                    d[v][w] = d[v][u] + d[u][w];
                    for (int i = 0; i < G.vexnum; i++)
                    {
                        p[v][w][i] = p[v][u][i] || p[u][w][i];
                    }
                }
            }
        }
    }
}
