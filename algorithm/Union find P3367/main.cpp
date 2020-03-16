#include <iostream>
using namespace std;
int pre[20000] = {0};
int find(int x, int * pre)
{
    int r = x;
    while (pre[r] != r )
    {
        r = pre[r];     //find their root
    }
    int i = x, j;
    while (i != r)
    {
        j = pre[i];
        pre[i] = r;     // update the root
        i = j;
    }
    return r;
}

int join(int x, int y, int * pre)
{
    int rx, ry;
    rx = find(x, pre);
    ry = find(y, pre);
    if (rx != ry)
    {
        pre[rx] = ry;
    }
    return 1;
}
int main() {

    for (int i = 1; i <= 20000; i++)
    {
        pre[i] = i;
    }
    int n,m;
    int z, x, y;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> z >> x >> y;
        if (z == 2)
        {
            int rx, ry;
            rx = find(x, pre);
            ry = find(y, pre);
            if (rx == ry)
                cout << "Y\n";
            else
                cout << "N\n";
        }
        if (z == 1) {
            join(x, y, pre);
        }
    }
    return 0;
}