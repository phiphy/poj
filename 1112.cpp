#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

const int N(104), INF(1000000);
int n;
int t[N];       // team
int tc[N];      // team count
int g[N][N];    // graph
int b[N][N];    // block
int a[N];       // tmp array
int bn;         // block number
int dp[N][N];   // use dp to calculate results
int m[N][N];    // dp marks, use to find path back

void bar()
{
    int i, j, d, x, y;
    for (i = 0; i < N; ++i)
        for (j = 0; j < N; ++j)
            dp[i][j] = INF;
    dp[0][b[0][1]] = b[0][1] - b[0][2];
    for (i = 1; i < bn; ++i) {
        x = b[i][1];
        y = b[i][2];
        d = x - y;
        for (j = std::min(x, y); j <= n; ++j) {
            if ((j - x >= 0) && ((dp[i-1][j-x] + d) < dp[i][j])) {
                dp[i][j] = dp[i-1][j-x] + d;
                m[i][j] = m[i-1][j-y];
            }
            if ((j - y >= 0) && ((dp[i-1][j-y] - d) < dp[i][j])) {
                dp[i][j] = dp[i-1][j-y] - d;
                m[i][j] = 1 - m[i-1][j-y];
            }
        }
    }

    for (x = INF, i = 0, j = 0; i <= n; ++i) {
        if (abs(dp[bn-1][i]) < x) {
            x = abs(dp[bn-1][i]);
            j = i;
        }
    }
    memset(a, 0, sizeof(a));
    a[bn-1] = m[bn-1][j];
    for (i = bn-2; i >= 0; --i) {
        j -= b[i+1][a[i+1] + 1];
        a[i] = m[i][j];
    }
    for (i = 0; i < bn; ++i) {
        if (a[i] == 0) {
            for (j = N-1; b[i][j]; --j) {
                t[b[i][j]] = 1;
                ++tc[1];
            }
        } else {
            for (j = 3; b[i][j]; ++j) {
                t[b[i][j]] = 1;
                ++tc[1];
            }
        }
    }
}

int f()
{
    int c[N], q[N];
    int i, j, k, u, v, x, y;
    int cn[3];
    memset(a, 0, sizeof(a));    // visited
    for (i = 1; i <= n; ++i) {
        if (!a[i]) {    // bfs, first visit i
            memset(c, 0, sizeof(c));    // tmp color assign
            memset(cn, 0, sizeof(cn));  // color number
            a[i] = 1;
            c[i] = 1;
            ++cn[1];
            for (x = 0, y = 1, q[0] = i; x < y;) {
                u = q[x++];
                for (k = 1; k <= g[u][0]; ++k) {
                    v = g[u][k];
                    if (a[v]) { // v has visited before
                        if (c[v] == c[u])
                            return -1;
                    } else {
                        a[v] = 1;
                        c[v] = 3 - c[u];
                        ++cn[c[v]];
                        q[y++] = v;
                    }
                }
            }
            b[bn][1] = cn[1];
            b[bn][2] = cn[2];
            for (j = 1, x = 2, y = N; j <= n; ++j) {
                if (c[j] == 1)
                    b[bn][++x] = j;
                else if (c[j] == 2)
                    b[bn][--y] = j;
            }
            ++bn;
        }
    }
    bar();
    return 0;
}

int main()
{
    int i, j;
    scanf("%d", &n);
    for (i = 1, j = 0; i <= n; ++i) {
        memset(a, 0, sizeof(a));
        a[i] = 1;
        while (scanf("%d", &j), j)
            a[j] = 1;
        for (j = 1; j <= n; ++j) {
            if (!a[j]) {    // i don't know j
                g[i][++g[i][0]] = j;
                g[j][++g[j][0]] = i;
            }
        }
    }
    if (f()) {
        printf("No solution\n");
    } else {
        tc[0] = n - tc[1];
        for (i = 0; i < 2; ++i) {
            printf("%d", tc[i]);
            for (j = 1; j <= n; ++j)
                if (t[j] == i)
                    printf(" %d", j);
            printf("\n");
        }
    }
    return 0;
}
