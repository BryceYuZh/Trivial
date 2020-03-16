#include <iostream>
#include <algorithm>
using namespace std;
struct edge{
    int e1;
    int e2;
    int val;
};
int comp (edge x, edge y)
{
    return x.val < y.val;
}
int find (int x, int * pre)
{

    int r = x;
    while (pre[r] != r)
    {
        r = pre[r];
    }
    int i = x, m;
    while (i != r)
    {
        m = pre[i];
        pre[i] = r;
        i = m;
    }
    return r;
}
//int join(int x, int y, int * pre)
//{
//    int rx = find(x, pre), ry = find(y, pre);
//    if (rx == ry)
//        return 1;
//    else
//    {
//        pre[x] = y;
//        return 2;
//    }
//}
int main()
{
    int pre[7000];
    for (int i = 1; i <= 6000; i++)
    {
        pre[i] = i;
    }
    edge e[200005];
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> e[i].e1 >> e[i].e2 >> e[i].val;
    }
    sort (e+1, e+1+m, comp);
    int ans = 0, count = 0;
    for (int i = 1; i <= m; i++)
    {
        int r1 = find(e[i].e1, pre), r2 = find(e[i].e2, pre);
        if (r1 == r2)
            continue;
//        join(e[i].e1, e[i].e2, pre);
        pre[r1] = e[i].e2;
        ans += e[i].val;
        count++;
        if (count == n - 1)
            break;
    }
    cout << ans;
    return 0;
}