#include<iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 10010;//节点最大值
const int inf = 1000000000;//边权最大值
struct node{
    int nxt, val;//下一条边编号，这条边的值
};
int n, m, s;//节点数，边数，源点
int vis[maxn] = {0}, dis[maxn];//经过标记，长度

vector <node> e[maxn];//vector代替邻接表

queue <int> q;//queue优化
int main(){
    cin >> n >> m >> s;
    for(int i = 1; i <= m; i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        node tmp;
        tmp.nxt = y;
        tmp.val = z;
        //新建边，边权为z，边编号为y
        e[x].push_back(tmp);
        //加入x的vector
    }
    for(int i = 1; i <= n; i++)
        dis[i]=inf;     //全体初始最大化
    dis[s] = 0;
    q.push(s);
    vis[s] = 1;
    //初始化源点
    while(!q.empty())
    {
        int x = q.front();  //取队头
        q.pop();    //对头出队
        for (int i = 0; i < e[x].size(); i++)
        {
            //循环vector[e[x]]的每一条边
            int u = e[x][i].nxt, v = e[x][i].val;
            //u为e[x][i]的编号，v为e[x][i]的权值
            if(dis[u] > dis[x] + v)
            {
                dis[u] = dis[x] + v;    //如果d[u]不如d[x]+v短，则更改d[u]的权
                if(!vis[u])
                {
                    q.push(u);  //u入队
                    vis[u] = 1;   //标记u被经过
                }
            }
        }
        vis[x] = 0;
    }
    for(int i = 1; i <= n; i++)
        if(dis[i] < inf)
            cout << dis[i] << " ";
        else
            cout << "2147483647 ";

    return 0;
}
/*
struct NODE{
    int w;
    int e;
    int next; //next[i]表示与第i条边同起点的上一条边的储存位置
}edge[MAXN];
int cnt;
int head[MAXN];
void add(int u,int v,int w){
    edge[cnt].w=w;
    edge[cnt].e=v;    //edge[i]表示第i条边的终点
    edge[cnt].next=head[u]; //head[i]表示以i为起点的最后一条边的储存位置
    head[u]=cnt++;
}
int main() {
    memset(head, 0, sizeof(head));
    cnt = 1;
    int n;
    cin >> n;
    int a, b, c;
    while (n--) {
        cin >> a >> b >> c;
        add(a, b, c);
    }
    int start;
    cin >> start;
    for (int i = head[start]; i != 0; i = edge[i].next)
        cout << start << "->" << edge[i].e << " " << edge[i].w << endl;
    return 0;
}*/