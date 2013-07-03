/*
 * poj 1038
 *
 */
#include <cstdio>
#include <algorithm>

const int N(156), M(16);
int n, m, k, maxv, nm;
int a[N][M];
const int chip[2][11] = {{1, 0, 2, 0, 0, 1, 1, 1, 2, 1, 3}, 
    {1, 0, 0, 1, 1, 1, 0, 2, 1, 2, 2}};

bool test_put(int x, int y, int idx)
{
    for (int i = 0; i < 10; i += 2)
        if (a[x+chip[idx][i]][y+chip[idx][i+1]])
            return false;
    return true;
}
void put(int x, int y, int idx, int v)
{
    for (int i = 0; i < 10; i += 2)
        a[x+chip[idx][i]][y+chip[idx][i+1]] = v;
}

int dfs(int x, int y)
{
    if (x >= n) {
        x = 1;
        ++y;
    }
    if ((y >= m ) || ((nm - x*y)/6 <= maxv))
        return 0;
    int ret(0);
    if (!a[x][y]) {
        for (int i = 0; i < 2; ++i) {
            if (test_put(x, y, i)) {
                put(x, y, i, 1);
                ret = std::max(ret, 1 + dfs(x+chip[i][10], y));
                put(x, y, i, 0);
            }
        }
    }
    ret = std::max(ret, dfs(x+1, y));
    maxv = std::max(ret, maxv);
    return ret;
}

int main()
{
    int d, x, y;
    scanf("%d", &d);
    while (d--) {
        scanf("%d%d%d", &n, &m, &k);
        nm = n * m;
        for (x = 1; x <= n; ++x)
            for (y = 1; y <= m; ++y)
                a[x][y] = 0;
        for (x = n+1; x <= n+2; ++x)
            for (y = 1; y <= m; ++y)
                a[x][y] = 1;
        for (y = m+1; y <= m+2; ++y)
            for (x = 1; x <= n+2; ++x)
                a[x][y] = 1;
        while (k--) {
            scanf("%d%d", &x, &y);
            a[x][y] = 1;
        }
        maxv = 0;
        printf("%d\n", dfs(1, 1));
    }
    return 0;
}
