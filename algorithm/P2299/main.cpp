#include <iostream>
using namespace std;
# define MAXN 99999999
# define MAXD 89999999
// 防不连通
int n, m;
int u[300000], v[300000], w[300000];
int vis[3000], dis[3000];
int map[3000][3000];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                map[i][j] = 0;
            else
            {
                map[i][j] = MAXD;
                map[j][i] = MAXD;
            }
        }
    }
    int from, to, wei;
    for (int i = 1; i <= m; i++)
    {
        cin >> from >> to >> wei;
        if (wei < map[from][to]) {
            map[from][to] = wei;
            map[to][from] = wei;
        }
    }

    //**** dijkstra
    //initialization
    for (int i = 1; i <= n; i++)
    {
        dis[i] = MAXD;
        vis[i] = 0;
    }
    dis[1] = 0;
    //********
    for (int i = 1; i <= n; i++)
    {
        // 找最小dis
        int min = MAXN, jj = 0; // MAXN 比 MAXD 大一点
        for (int j = 1; j <= n; j++){
            if (min > dis[j] && vis[j] == 0)
            {
                min = dis[j];
                jj = j;
                //cout << jj;
            }
        }
//        if (jj == 0)
//            break;
        vis[jj] = 1;

        for (int k = 1; k <= n; k++)
        {
            if (dis[k] > dis[jj] + map[jj][k])
                dis[k] = dis[jj] + map[jj][k];
        }
    }
    cout << dis[n];
    return 0;
}