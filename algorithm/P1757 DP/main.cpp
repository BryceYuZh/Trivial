#include <iostream>
#include <algorithm>
using namespace std;
struct Object{
    int wei;
    int val;
    int group;
};
int f[1005] = {0};
int comp(Object a, Object b)
{
    return a.group < b.group;
}
Object obj[1005];
int find_first(int group)
{
    int j = 1;
   while(1)
   {
       if (j > group)
           return 0;
       if (j == group)
           break;
       j++;
   }
    return j;
}
int main() {
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> obj[i].wei >> obj[i].val >> obj[i].group;
    }
    sort(obj + 1, obj + 1 + n, comp);
    int num_group = obj[n].group;
    for (int i = 1; i <= num_group; i++)
    {
        for (int w = m; w >= 0; w--)
        {
            int max = -1;
            int j = find_first(i);
            while (j == 0)
            {
                i++;
                j = find_first(i);
            }
            while (1) // i is the current group number, m is the max weight
            {
                if (w < obj[j].wei)
                {
                    j++;
                    continue;
                }
                if (max < f[w - obj[j].wei] + obj[j].val)
                    max = f[w - obj[j].wei] + obj[j].val;
                j++;
                if (j > n)
                    break;
                if (obj[j].group != i)
                    break;
            }
            f[w] = max;
        }
    }

    cout << f[m];
    return 0;
}

/*
 * 首先我们用一个数组w[i]来保存每个物品的重量，c[i]表示每个物品的价值，
 * 定义二维数组a[p][0]表示第p组的物品有a[p][0]件，里面存储这个物品的序号为[i]，
 * 定义一个变量t来保存一共有多少组物品。

    #include<iostream>
    #include<cstdio>
    #include<cmath>
    #include<algorithm>
    #include<cstring>

    using namespace std;

    int w[10001],t,c[10001],v,f[10001],a[10001][1001],m,n,p;

    int main()
    {
        scanf("%d%d",&m,&n);
        for(int i=1; i<=n; i++)
        {
            scanf("%d%d%d",&w[i],&c[i],&p);
            a[p][++a[p][0]]=i;
            t=max(t,p);
        }
        for(int k=1; k<=t; k++)//控制组数
            for(int j=m; j>=0; j--)//容量
                for(int i=1; i<=a[k][0]; i++)//枚举
                    if(w[a[k][i]]<=j)//先判断能不能放
                        f[j]=max(f[j],f[j-w[a[k][i]]]+c[a[k][i]]);
        printf("%d",f[m]);
}*/