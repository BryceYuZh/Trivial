#include <iostream>
#include <cstdio>
using namespace std;
// Bellman-Ford
// 如果是稠密图复杂度会很高
int main()
{
    int n, m;
    cin >> n >> m;
    int u[200000], v[200000];
    double w[200000];
    double w1;
    for (int i = 1; i <= m; i++)
    {
        cin >> u[i] >> v[i] >> w1;
        w[i] =(1.0 - w1 / 100.0);
    }
    int a, b;
    cin >> a >> b;
    double dis[4000] = {0};
//    for (int i = 1; i < 3000; i++)
//        dis[i] = 999999;
    dis[a] = 1;
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (dis[u[j]] < dis[v[j]] * w[j])
                dis[u[j]] = dis[v[j]] * w[j];
            if (dis[v[j]] < dis[u[j]] * w[j])
                dis[v[j]] = dis[u[j]] * w[j];
        }
    }
    double pay = 100 / dis[b];
    printf("%0.8lf", pay);
    return 0;
}
//2151ms, 3344KB


/* 模版
 #include <iostream>
#define INF 1e9

void DFSPrint(int bak[], int k)
{
    if (bak[k] == k)
    {
        printf("%d ", k);
        return;
    }
    DFSPrint(bak, bak[k]);
    printf("%d ", k);
    return;
}

int main()
{
    int i, j, n, m;
    int dis[10], bak[10], u[10], v[10], w[10];
    int check;

    // 读入n和m, n表示顶点个数,m表示边的条数
    scanf("%d %d", &n, &m);

    // 读入边
    for (i = 1; i <= m; ++i)
    {
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
    }

    // 初始化bak[]数组，前驱结点均为自己
    // 初始化dis[]数组，源点为1号顶点
    for (i = 1; i <= n; ++i)
    {
        bak[i] = i;
        dis[i] = INF;
    }
    dis[1] = 0;

    // Bellman-Ford算法
    for (j = 1; j <= n-1; ++j)  // 最多循环n-1轮（图退化为链表）
    {
        check = 0;  // 用来标记在本轮松弛中数组dis是否发生更新
        for (i = 1; i <= m; ++i)
        {
            if (dis[u[i]] != INF && dis[u[i]] + w[i] < dis[v[i]])  // relax
            {
                dis[v[i]] = dis[u[i]] + w[i];
                bak[v[i]] = u[i];
                check = 1;
            }
        }

        if (check == 0)
        {
            break;
        }
    }

    // 检测负权回路,若存在,则在对边进行一次遍历后必定会有relax的操作
    int flag = 0;
    for (i = 1; i <= m; ++i)
    {
        if (dis[u[i]] + w[i] < dis[v[i]])
        {
            flag = 1;
        }
    }

    if (flag)
    {
        printf("该图有负权回路");
    }
    else
    {
        // 输出最终结果
        printf("最终结果为:\n");
        for (i = 1; i <= n; ++i)
        {
            printf("1号顶点到%d号顶点的最短距离为:%d\n", i, dis[i]);
        }
        printf("\n打印1号顶点到5号顶点的最短路径:\n");

        DFSPrint(bak, 5);
    }

    return 0;
}
 */