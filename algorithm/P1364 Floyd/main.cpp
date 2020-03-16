#include <iostream>
#define MAX 999999
using namespace std;
int main() {
    int map[105][105];
    for (int i = 1; i <= 104; i++)
        for (int j = 1; j <= 104; j++)
        {
            if(i == j)
                map[i][j] = 0;
            else
            {
                map[i][j] = MAX;
                map[j][i] = MAX;
            }
        }
    int loc[200] = {0};
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> loc[i];
        int l, r;
        cin >> l >> r;
        if (l != 0)
        {
            map[i][l] = 1;
            map[l][i] = 1;
        }
        if (r != 0)
        {
            map[i][r] = 1;
            map[r][i] = 1;
        }
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <=n; j++)
                if (map[i][j] > map[i][k] + map[k][j])
                    map[i][j] = map[i][k] + map[k][j];

    int min = MAX, sum;
    for (int i = 1; i <= n; i++)
    {
        sum = 0;
        for (int j = 1; j <= n; j++)
            sum += loc[j] * map[i][j];
        min = min > sum ? sum : min;
    }
    cout << min;
    return 0;
}