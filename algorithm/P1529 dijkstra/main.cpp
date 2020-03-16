#include<cstdio>
#include <iostream>
#include<algorithm>
#define MAXN 999999999
using namespace std;

int dis[100], tu[100][100];//从z出发的dis值和邻接矩阵
int p, vis[100] = {0};//边数目、节点标记
char r;

void di(int x,int y,int w)//存图 邻接矩阵
{
    if(w < tu[x][y])//读入的第二条边比第一条边的权值小，就替换
    {
        tu[x][y] = w;
        tu[y][x] = w;
    }
}

void dijkstra()
{
    int m = 0;// 把m的定义拉出循环 就直接可以过不连通
    for (int i = 1; i <= 52; i++)
    {
        int min = MAXN;
        for (int ii = 1; ii <= 52; ii++) {
            if (min > dis[ii] && vis[ii] == 0) {
                min = dis[ii];
                m = ii;
            }
        }// 找最小
//        if (m == 0)
//            break;
        //这个图可能不连通
        vis[m] = 1;
        for (int j = 1; j <= 52; j++)//松弛
        {
            if (vis[j] == 0 && dis[j] >= dis[m] + tu[m][j])
            {
                dis[j] = dis[m] + tu[m][j];
            }
        }
    }
}

int main()
{
    cin >> p;

    for(int i = 1;i <= 52;i++)
        for(int j = 1;j <= 52;j++)
            tu[i][j] = MAXN;
    for(int i = 1; i <= p; i++)
    {
        char x, y;//两个点
        int c;//权值
        int xx, yy;
        cin >> x >> y >> c;
        if(x >= 'a' && x <= 'z')
            xx = x - 'a' + 1;
        else
            xx = x - 'A' + 27;

        if(y >= 'a' && y <= 'z')
            yy = y - 'a' + 1;
        else
            yy = y - 'A' + 27;
        di(xx, yy, c);
    }


    for (int i = 1; i <= 52; i++)
        dis[i] = MAXN;
    dis[52] = 0;

    dijkstra();

    int hh = MAXN, point;
    for(int i = 27; i <= 51; i++)//判断大写并输出
    {
        if(dis[i] < hh)
        {
            hh = dis[i];
            point = i;
        }
    }
    r = (char)(point - 27 + 'A');
    printf("%c %d\n", r, hh);
}