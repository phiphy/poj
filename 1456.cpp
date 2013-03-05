#include <cstdio>
#include <cstring>
#include <algorithm>

const int N(10002);
int used[N];
struct Prod {
    int p, d;
} prods[N];
bool operator<(const Prod &p1, const Prod &p2) { return p1.p > p2.p; }

int main()
{
    //freopen("a.in", "r", stdin);
    int n, i, j, maxp;
    while (scanf("%d", &n) != EOF) {
        for (i = 0; i < n; ++i)
            scanf("%d%d", &(prods[i].p), &(prods[i].d));
        std::sort(prods, prods + n);
        memset(used, 0, sizeof(used));
        for (maxp = 0, i = 0; i < n; ++i) {
            for (j = prods[i].d; j > 0; --j) {
                if (!used[j]) {
                    used[j] = 1;
                    maxp += prods[i].p;
                    break;
                }
            }
        }
        printf("%d\n", maxp);
    }
    return 0;
}
