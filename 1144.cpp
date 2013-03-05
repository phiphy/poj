#include <cstdio>
#include <cstring>
#include <algorithm>

const int N(104);
const int root(1);
int d[N], low[N], a[N];
int g[N][N];
int n, root_children, k;

void dfs(int u)
{
    d[u] = low[u] = ++k;
    for (int i = 1; i <= g[u][0]; ++i) {
        int v = g[u][i];
        if (!d[v]) {
            dfs(v);
            if (u == root) {
                ++root_children;
            } else {
                low[u] = std::min(low[u], low[v]);
                if (low[v] >= d[u])
                    a[u] = 1;
            }
        } else {
            low[u] = std::min(low[u], d[v]);
        }
    }
}

int main()
{
    freopen("a.in", "r", stdin);
    int u, v;
    char c;
    while (scanf("%d", &n), n) {
        for (int i = 0; i <= n; ++i)
            g[i][0] = 0;
        memset(d, 0, sizeof(d));
        memset(low, 0, sizeof(low));
        memset(a, 0, sizeof(d));
        k = root_children = 0;
        while (scanf("%d", &u), u) {
            while ((c = getchar()) != '\n') {
                scanf("%d", &v);
                g[u][++g[u][0]] = v;
                g[v][++g[v][0]] = u;
            }
        }
        dfs(root);
        if (root_children > 1)
            a[root] = 1;
        for (int i = 1; i <= n; ++i)
            a[0] += a[i];
        printf("%d\n", a[0]);
    }
    return 0;
}
